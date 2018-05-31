/*
Niniejszy program jest wolnym oprogramowaniem; możesz go
rozprowadzać dalej i / lub modyfikować na warunkach Powszechnej
Licencji Publicznej GNU, wydanej przez Fundację Wolnego
Oprogramowania - według wersji 2 tej Licencji lub(według twojego
wyboru) którejś z późniejszych wersji.

Niniejszy program rozpowszechniany jest z nadzieją, iż będzie on
użyteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyślnej
gwarancji PRZYDATNOŚCI HANDLOWEJ albo PRZYDATNOŚCI DO OKREŚLONYCH
ZASTOSOWAŃ.W celu uzyskania bliższych informacji sięgnij do
Powszechnej Licencji Publicznej GNU.

Z pewnością wraz z niniejszym programem otrzymałeś też egzemplarz
Powszechnej Licencji Publicznej GNU(GNU General Public License);
jeśli nie - napisz do Free Software Foundation, Inc., 59 Temple
Place, Fifth Floor, Boston, MA  02110 - 1301  USA
*/

#define GLM_FORCE_RADIANS

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <lodepng.h>
#include "constants.h"
#include "allmodels.h"
#include "myCube.h"
#include "drzewo.h"
#include "cone.h"

using namespace glm;

cone stozek;

GLuint tex; //Uchwyt na teksturę
float wzrost = 1;
float tempo_wzrostu=0.02;
float max_wysokosc_drzewa=5;
float aspect=1.0f; //Aktualny stosunek szerokości do wysokości okna
float speed_x=0; //Szybkość kątowa obrotu obiektu w radianach na sekundę wokół osi x
float speed_y=0; //Szybkość kątowa obrotu obiektu w radianach na sekundę wokół osi y
galaz lista_galezi[5];
//Procedura obsługi błędów
void error_callback(int error, const char* description) {
	fputs(description, stderr);
}

//Procedura obługi zmiany rozmiaru bufora ramki
void windowResize(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height); //Obraz ma być generowany w oknie o tej rozdzielczości
    if (height!=0) {
	aspect=(float)width/(float)height; //Stosunek szerokości do wysokości okna
    } else {
	aspect=1;
    }
}



//Procedura obsługi klawiatury
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if (action == GLFW_PRESS) {
        if (key == GLFW_KEY_LEFT) speed_y=PI/2;
        if (key == GLFW_KEY_RIGHT) speed_y=-PI/2;
        if (key == GLFW_KEY_UP) speed_x=PI/2;
        if (key == GLFW_KEY_DOWN) speed_x=-PI/2;
    }

    if (action == GLFW_RELEASE) {
        if (key == GLFW_KEY_LEFT) speed_y=0;
        if (key == GLFW_KEY_RIGHT) speed_y=0;
        if (key == GLFW_KEY_UP) speed_x=0;
        if (key == GLFW_KEY_DOWN) speed_x=0;
    }
}

//Procedura inicjująca
void initOpenGLProgram(GLFWwindow* window) {

	glfwSetFramebufferSizeCallback(window, windowResize); //Zarejestruj procedurę obsługi zmiany rozdzielczości bufora ramki
    glfwSetKeyCallback(window, key_callback); //Zarejestruj procedurę obsługi klawiatury

	glClearColor(0,0,0,1); //Ustaw kolor czyszczenia ekranu

	//glEnable(GL_LIGHTING); //Włącz tryb cieniowania
	glEnable(GL_LIGHT0); //Włącz zerowe źródło światła
	glEnable(GL_DEPTH_TEST); //Włącz używanie budora głębokości
	glEnable(GL_COLOR_MATERIAL); //Włącz śledzenie kolorów przez materiał
    glEnable(GL_TEXTURE_2D); //Włącz teksturowanie

    glEnable(GL_NORMALIZE);

    // czy Ty jestes do cieniowana
    /*float amb[]={0,0,0,1};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb );
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 50);
    float diff[]={0.7,0.5,0.5,1};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
    float spe[]={0,0,0,1};
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spe);*/


	//Wczytanie do pamięci komputera
    std::vector<unsigned char> image;   //Alokuj wektor do wczytania obrazka
    unsigned width, height;   //Zmienne do których wczytamy wymiary obrazka
    //Wczytaj obrazek
    unsigned error = lodepng::decode(image, width, height, "kora.png");

    //Import do pamięci karty graficznej
    glGenTextures(1,&tex); //Zainicjuj jeden uchwyt
    glBindTexture(GL_TEXTURE_2D, tex); //Uaktywnij uchwyt
    //Wczytaj obrazek do pamięci KG skojarzonej z uchwytem
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,
     GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*) image.data());

    //Ustaw bilinear filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void rysuj_protopadloscian(mat4 V, mat4 M, float a, float b, float c){
    mat4 Mk = M;
    Mk = scale(Mk, vec3(a/2.0f, b/2.0f,c/2.0f));
    glLoadMatrixf(value_ptr(V*Mk));
    Models::cube.drawSolid();
}

void rysuj_stozek(mat4 V, mat4 M, float alfa){
	M = rotate(M, alfa, vec3(0.0f,0.0f,1.0f));
	M = translate(M, vec3(1.0f, 0.0f, 0.0f));
	rysuj_protopadloscian(V, M, 3.0f, 0.25f, 0.25);
/*
	M = translate(M, vec3(1.0f, 0.0f, 0.0f));
	M = rotate(M, alfa, vec3(0.0f,0.0f,1.0f));
	M = translate(M, vec3(1.0f, 0.0f, 0.0f));
	rysuj_protopadloscian(V, M, 2.0f, 0.5f, 1.0f);

	M = translate(M, vec3(1.0f, 0.0f, 0.0f));
	M = rotate(M, alfa, vec3(0.0f,0.0f,1.0f));
	M = translate(M, vec3(1.0f, 0.0f, 0.0f));
	rysuj_protopadloscian(V, M, 2.0f, 0.5f, 1.0f);*/
}


//Procedura rysująca zawartość sceny
void drawScene(GLFWwindow* window,float angle_x, float angle_y, drzewo D, float wzrost) {

	//************Tutaj umieszczaj kod rysujący obraz******************
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Wyczyść bufor kolorów i bufor głębokości

	//Przygotuj macierze rzutowania i widoku dla renderowanego obrazu
	mat4 P=perspective(50.0f*PI/180.0f, 1.0f, 1.0f, 50.0f); //Wylicz macierz rzutowania

	mat4 V=lookAt( //Wylicz macierz widoku
	vec3(0.0f,0.0f,-9.0f),
	vec3(0.0f,0.0f,0.0f),
	vec3(0.0f,1.0f,0.0f));

	glMatrixMode(GL_PROJECTION); //Włącz tryb modyfikacji macierzy rzutowania
	glLoadMatrixf(value_ptr(P)); //Skopiuj macierz rzutowania
	glMatrixMode(GL_MODELVIEW); //Włącz tryb modyfikacji macierzy model-widok. UWAGA! Macierz ta będzie ładowana przed narysowaniem każdego modelu

    glClearColor(0.647, 0.862, 0.933 ,0.5);
    glClear(GL_COLOR_BUFFER_BIT);

    glDisable(GL_TEXTURE_2D);


    //ziemia
    mat4 Mz = mat4(1.0f);
    Mz=rotate(Mz,angle_x,vec3(1.0f,0.0f,0.0f));
    Mz=rotate(Mz,angle_y,vec3(0.0f,1.0f,0.0f));
    mat4 Mz_skalowane=scale(Mz, vec3(5000.0f, 0.0f, 5000.0f));
    glLoadMatrixf(value_ptr(V*Mz_skalowane));
    glColor3d(0.0,0.7,0.0);
    Models::cube.drawSolid();

    glColor3d(1.0,1.0,1.0);
    glEnable(GL_TEXTURE_2D);

    mat4 M=Mz;
    M=rotate(M,90.0f*PI/180.0f,vec3(-1.0f,0.0f,0.0f));
    M=scale(M, vec3(1.0f,1.0f,4.0f));
    glLoadMatrixf(value_ptr(V*M));

    stozek.drawCone();




    // pien

    //D.rysuj_drzewo(Mz, V, wzrost);

	glfwSwapBuffers(window);

}
int main(void)
{
	GLFWwindow* window; //Wskaźnik na obiekt reprezentujący okno
    drzewo D = drzewo();
    printf ("Wysokosc drzewa: %d \n", D.wysokosc_drzewa);


    //galaz G=galaz();
    printf ("Galaz 1 \n kat_do_pionu; %f \n dlugosc_galezi; %f \n, wys_galezi_na_matce %f \n, kat_na_matce %f \n, grubosc_galezi: %f \n", D.galezie[0].kat_do_pionu, D.galezie[0].dlugosc_galezi, D.galezie[0].wys_galezi_na_matce,D.galezie[0].kat_na_matce, D.galezie[0].grubosc_galezi);
    printf ("Galaz 2 \n kat_do_pionu; %f \n dlugosc_galezi; %f \n, wys_galezi_na_matce %f \n, kat_na_matce %f \n, grubosc_galezi: %f \n", D.galezie[1].kat_do_pionu, D.galezie[1].dlugosc_galezi, D.galezie[1].wys_galezi_na_matce,D.galezie[1].kat_na_matce, D.galezie[1].grubosc_galezi);



	glfwSetErrorCallback(error_callback);//Zarejestruj procedurę obsługi błędów

	if (!glfwInit()) { //Zainicjuj bibliotekę GLFW
		fprintf(stderr, "Nie można zainicjować GLFW.\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(500, 500, "OpenGL", NULL, NULL);  //Utwórz okno 500x500 o tytule "OpenGL" i kontekst OpenGL.

	if (!window) //Jeżeli okna nie udało się utworzyć, to zamknij program
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window); //Od tego momentu kontekst okna staje się aktywny i polecenia OpenGL będą dotyczyć właśnie jego.
	glfwSwapInterval(1); //Czekaj na 1 powrót plamki przed pokazaniem ukrytego bufora

	GLenum err;
	if ((err=glewInit()) != GLEW_OK) { //Zainicjuj bibliotekę GLEW
		fprintf(stderr, "Nie można zainicjować GLEW: %s\n", glewGetErrorString(err));
		exit(EXIT_FAILURE);
	}

	initOpenGLProgram(window); //Operacje inicjujące


	float angle_x=0.0f; //Aktualny kąt obrotu obiektu wokół osi x
	float angle_y=0.0f; //Aktualny kąt obrotu obiektu wokół osi y
	glfwSetTime(0); //Wyzeruj timer

	//Główna pętla
	while (!glfwWindowShouldClose(window)) //Tak długo jak okno nie powinno zostać zamknięte
	{
	    angle_x+=speed_x*glfwGetTime(); //Oblicz przyrost kąta obrotu i zwiększ aktualny kąt
        angle_y+=speed_y*glfwGetTime(); //Oblicz przyrost kąta obrotu i zwiększ aktualny kąt
	    glfwSetTime(0); //Wyzeruj timer
		drawScene(window,angle_x,angle_y,D, wzrost); //Wykonaj procedurę rysującą
		glfwPollEvents(); //Wykonaj procedury callback w zalezności od zdarzeń jakie zaszły.

		if (wzrost<=max_wysokosc_drzewa)
            {
             wzrost=wzrost+tempo_wzrostu;
            }

	}

    glDeleteTextures(1,&tex);
	glfwDestroyWindow(window); //Usuń kontekst OpenGL i okno
	glfwTerminate(); //Zwolnij zasoby zajęte przez GLFW
	exit(EXIT_SUCCESS);
}
