#ifndef DRZEWO_H
#define DRZEWO_H
#include <list>
#include "galaz.h"
#define GLM_FORCE_RADIANS

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include "allmodels.h"


using namespace glm;

using namespace:: std;
class drzewo
{
    public:
        drzewo();
        virtual ~drzewo();
        void losuj_wysokosc_drzewa();
        int il_galezi=5;
        galaz galezie[5];
        int wysokosc_drzewa;
        int grubosc_drzewa;
        void rysuj_galaz(mat4 M_matki, float wys_matki, mat4 V, float wzrost, galaz G);
        void rysuj_drzewo(mat4 Mz, mat4 V, float wzrost);
        int losuj(int mini, int maxi);
        void rysuj_protopadloscian(mat4 V, mat4 M, float a, float b, float c);
};

#endif // DRZEWO_H
