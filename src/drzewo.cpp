#include "include/drzewo.h"
#include <cstdlib>
#include <time.h>
#include "allmodels.h"
#define GLM_FORCE_RADIANS
#include "constants.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include "allmodels.h"
#include "include/cone.h"


using namespace glm;


int min_wys_drzewa = 3;
int max_wys_drzewa = 3;
int grubosc_drzewa_tmp=1;

void drzewo::rysuj_protopadloscian(mat4 V, mat4 M, float wzrost){
    /*mat4 Mk = M;
    Mk = scale(Mk, vec3(a/2.0f, b/2.0f,c/2.0f));
    glLoadMatrixf(value_ptr(V*Mk));
    Models::cube.drawSolid();*/

    mat4 Mk=M;
    Mk=rotate(Mk,90.0f*PI/180.0f,vec3(-1.0f,0.0f,0.0f));
    Mk=scale(Mk, vec3(1.0f,1.0f,(wzrost+10.0f)));
    glLoadMatrixf(value_ptr(V*Mk));

    cone stozek;
    stozek.drawCone();
}

drzewo::drzewo()
    {

    srand (time(NULL));
    losuj_wysokosc_drzewa();
    grubosc_drzewa=grubosc_drzewa_tmp;
    int i;


    for (i=0;i<=(il_galezi-1);i++)
        {
          printf("i: %d \n",i);
          galezie [i]=galaz();
        }
    }


drzewo::losuj(int mini, int maxi)
    {
    int range = maxi-mini + 1;
	return rand()%range + mini;
    }



void drzewo::losuj_wysokosc_drzewa()
{
     int r=losuj(min_wys_drzewa, max_wys_drzewa);
     wysokosc_drzewa=r;
     return;
}

void drzewo::rysuj_galaz(mat4 M_Matki,float wys_matki, mat4 V, float wzrost, galaz G)
{
    mat4 M= mat4 (1.0);
    M = translate (M_Matki, vec3(0.0f,G.wys_galezi_na_matce*wys_matki/2,0.0f));
    M = rotate(M, G.kat_na_matce , glm::vec3(0.0f, 1.0f, 0.0f));
    M = rotate(M, G.kat_do_pionu, glm::vec3(1.0f, 0.0f, 0.0f));
    M = translate (M, vec3(0.0f, (G.dlugosc_galezi/2), 0.0f));
    rysuj_protopadloscian(V, M, G.dlugosc_galezi);

}

void drzewo::rysuj_drzewo(mat4 Mz, mat4 V, float wzrost)
{
    mat4 M = Mz;
    //M = translate(Mz, vec3(0.0f, wzrost*float(wysokosc_drzewa)/2.0f, 0.0f));
    //M=scale(M, vec3(1.0f,wzrost*float(wysokosc_drzewa),1.0f));
    rysuj_protopadloscian(V, M, wzrost);


    // to bedzie dla galezi

    int i;
    for (i=0;i<=il_galezi-1;i++)
    {
        //rysuj_galaz(M,float(wzrost*wysokosc_drzewa), V, wzrost, galezie[i]);
    }




};

drzewo::~drzewo()
{
        //dtor
}
