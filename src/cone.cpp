
#include "include/cone.h"
#define GLM_FORCE_RADIANS

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>

cone::cone()
{
   vertices=coneNamespace::vertices;
   texCoords=coneNamespace::texCoords;
}




void cone::drawCone() {
    int geomVertexCount=216;
    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_TEXTURE_COORD_ARRAY );
    //glEnableClientState( GL_COLOR_ARRAY );
    glVertexPointer( 3, GL_FLOAT, 0, vertices);
    glTexCoordPointer( 2, GL_FLOAT, 0, texCoords);
    // glColorPointer( 3, GL_FLOAT, 0, geomColors);
    glDrawArrays(GL_TRIANGLES,0, geomVertexCount);
    glDisableClientState( GL_VERTEX_ARRAY );
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

namespace coneNamespace{
    float vertices[] ={
        1,0,0,
        0,0,1,
        0.996195,0.0871557,0,
        0.996195,0.0871557,0,
        0,0,1,
        0.984808,0.173648,0,
        0.984808,0.173648,0,
        0,0,1,
        0.965926,0.258819,0,
        0.965926,0.258819,0,
        0,0,1,
        0.939693,0.34202,0,
        0.939693,0.34202,0,
        0,0,1,
        0.906308,0.422618,0,
        0.906308,0.422618,0,
        0,0,1,
        0.866025,0.5,0,
        0.866025,0.5,0,
        0,0,1,
        0.819152,0.573576,0,
        0.819152,0.573576,0,
        0,0,1,
        0.766044,0.642788,0,
        0.766044,0.642788,0,
        0,0,1,
        0.707107,0.707107,0,
        0.707107,0.707107,0,
        0,0,1,
        0.642788,0.766044,0,
        0.642788,0.766044,0,
        0,0,1,
        0.573576,0.819152,0,
        0.573576,0.819152,0,
        0,0,1,
        0.5,0.866025,0,
        0.5,0.866025,0,
        0,0,1,
        0.422618,0.906308,0,
        0.422618,0.906308,0,
        0,0,1,
        0.34202,0.939693,0,
        0.34202,0.939693,0,
        0,0,1,
        0.258819,0.965926,0,
        0.258819,0.965926,0,
        0,0,1,
        0.173648,0.984808,0,
        0.173648,0.984808,0,
        0,0,1,
        0.0871557,0.996195,0,
        0.0871557,0.996195,0,
        0,0,1,
        -4.37114e-008,1,0,
        -4.37114e-008,1,0,
        0,0,1,
        -0.0871558,0.996195,0,
        -0.0871558,0.996195,0,
        0,0,1,
        -0.173648,0.984808,0,
        -0.173648,0.984808,0,
        0,0,1,
        -0.258819,0.965926,0,
        -0.258819,0.965926,0,
        0,0,1,
        -0.34202,0.939693,0,
        -0.34202,0.939693,0,
        0,0,1,
        -0.422618,0.906308,0,
        -0.422618,0.906308,0,
        0,0,1,
        -0.5,0.866025,0,
        -0.5,0.866025,0,
        0,0,1,
        -0.573577,0.819152,0,
        -0.573577,0.819152,0,
        0,0,1,
        -0.642788,0.766044,0,
        -0.642788,0.766044,0,
        0,0,1,
        -0.707107,0.707107,0,
        -0.707107,0.707107,0,
        0,0,1,
        -0.766044,0.642788,0,
        -0.766044,0.642788,0,
        0,0,1,
        -0.819152,0.573576,0,
        -0.819152,0.573576,0,
        0,0,1,
        -0.866025,0.5,0,
        -0.866025,0.5,0,
        0,0,1,
        -0.906308,0.422618,0,
        -0.906308,0.422618,0,
        0,0,1,
        -0.939693,0.34202,0,
        -0.939693,0.34202,0,
        0,0,1,
        -0.965926,0.258819,0,
        -0.965926,0.258819,0,
        0,0,1,
        -0.984808,0.173648,0,
        -0.984808,0.173648,0,
        0,0,1,
        -0.996195,0.0871557,0,
        -0.996195,0.0871557,0,
        0,0,1,
        -1,-8.74228e-008,0,
        -1,-8.74228e-008,0,
        0,0,1,
        -0.996195,-0.0871558,0,
        -0.996195,-0.0871558,0,
        0,0,1,
        -0.984808,-0.173648,0,
        -0.984808,-0.173648,0,
        0,0,1,
        -0.965926,-0.258819,0,
        -0.965926,-0.258819,0,
        0,0,1,
        -0.939693,-0.34202,0,
        -0.939693,-0.34202,0,
        0,0,1,
        -0.906308,-0.422618,0,
        -0.906308,-0.422618,0,
        0,0,1,
        -0.866025,-0.5,0,
        -0.866025,-0.5,0,
        0,0,1,
        -0.819152,-0.573577,0,
        -0.819152,-0.573577,0,
        0,0,1,
        -0.766044,-0.642788,0,
        -0.766044,-0.642788,0,
        0,0,1,
        -0.707107,-0.707107,0,
        -0.707107,-0.707107,0,
        0,0,1,
        -0.642788,-0.766044,0,
        -0.642788,-0.766044,0,
        0,0,1,
        -0.573576,-0.819152,0,
        -0.573576,-0.819152,0,
        0,0,1,
        -0.5,-0.866025,0,
        -0.5,-0.866025,0,
        0,0,1,
        -0.422618,-0.906308,0,
        -0.422618,-0.906308,0,
        0,0,1,
        -0.34202,-0.939693,0,
        -0.34202,-0.939693,0,
        0,0,1,
        -0.258819,-0.965926,0,
        -0.258819,-0.965926,0,
        0,0,1,
        -0.173648,-0.984808,0,
        -0.173648,-0.984808,0,
        0,0,1,
        -0.0871556,-0.996195,0,
        -0.0871556,-0.996195,0,
        0,0,1,
        1.31134e-007,-1,0,
        1.31134e-007,-1,0,
        0,0,1,
        0.0871559,-0.996195,0,
        0.0871559,-0.996195,0,
        0,0,1,
        0.173648,-0.984808,0,
        0.173648,-0.984808,0,
        0,0,1,
        0.258819,-0.965926,0,
        0.258819,-0.965926,0,
        0,0,1,
        0.34202,-0.939693,0,
        0.34202,-0.939693,0,
        0,0,1,
        0.422618,-0.906308,0,
        0.422618,-0.906308,0,
        0,0,1,
        0.5,-0.866025,0,
        0.5,-0.866025,0,
        0,0,1,
        0.573577,-0.819152,0,
        0.573577,-0.819152,0,
        0,0,1,
        0.642788,-0.766044,0,
        0.642788,-0.766044,0,
        0,0,1,
        0.707107,-0.707107,0,
        0.707107,-0.707107,0,
        0,0,1,
        0.766045,-0.642788,0,
        0.766045,-0.642788,0,
        0,0,1,
        0.819152,-0.573576,0,
        0.819152,-0.573576,0,
        0,0,1,
        0.866026,-0.5,0,
        0.866026,-0.5,0,
        0,0,1,
        0.906308,-0.422618,0,
        0.906308,-0.422618,0,
        0,0,1,
        0.939693,-0.34202,0,
        0.939693,-0.34202,0,
        0,0,1,
        0.965926,-0.258819,0,
        0.965926,-0.258819,0,
        0,0,1,
        0.984808,-0.173648,0,
        0.984808,-0.173648,0,
        0,0,1,
        0.996195,-0.0871556,0,
        0.996195,-0.0871556,0,
        0,0,1,
        1,0,0
    };

    float texCoords[]={
        1,0.5,
        0.5,0.5,
        0.998097,0.543578,
        0.998097,0.543578,
        0.5,0.5,
        0.992404,0.586824,
        0.992404,0.586824,
        0.5,0.5,
        0.982963,0.62941,
        0.982963,0.62941,
        0.5,0.5,
        0.969846,0.67101,
        0.969846,0.67101,
        0.5,0.5,
        0.953154,0.711309,
        0.953154,0.711309,
        0.5,0.5,
        0.933013,0.75,
        0.933013,0.75,
        0.5,0.5,
        0.909576,0.786788,
        0.909576,0.786788,
        0.5,0.5,
        0.883022,0.821394,
        0.883022,0.821394,
        0.5,0.5,
        0.853553,0.853553,
        0.853553,0.853553,
        0.5,0.5,
        0.821394,0.883022,
        0.821394,0.883022,
        0.5,0.5,
        0.786788,0.909576,
        0.786788,0.909576,
        0.5,0.5,
        0.75,0.933013,
        0.75,0.933013,
        0.5,0.5,
        0.711309,0.953154,
        0.711309,0.953154,
        0.5,0.5,
        0.67101,0.969846,
        0.67101,0.969846,
        0.5,0.5,
        0.629409,0.982963,
        0.629409,0.982963,
        0.5,0.5,
        0.586824,0.992404,
        0.586824,0.992404,
        0.5,0.5,
        0.543578,0.998097,
        0.543578,0.998097,
        0.5,0.5,
        0.5,1,
        0.5,1,
        0.5,0.5,
        0.456422,0.998097,
        0.456422,0.998097,
        0.5,0.5,
        0.413176,0.992404,
        0.413176,0.992404,
        0.5,0.5,
        0.37059,0.982963,
        0.37059,0.982963,
        0.5,0.5,
        0.32899,0.969846,
        0.32899,0.969846,
        0.5,0.5,
        0.288691,0.953154,
        0.288691,0.953154,
        0.5,0.5,
        0.25,0.933013,
        0.25,0.933013,
        0.5,0.5,
        0.213212,0.909576,
        0.213212,0.909576,
        0.5,0.5,
        0.178606,0.883022,
        0.178606,0.883022,
        0.5,0.5,
        0.146447,0.853553,
        0.146447,0.853553,
        0.5,0.5,
        0.116978,0.821394,
        0.116978,0.821394,
        0.5,0.5,
        0.090424,0.786788,
        0.090424,0.786788,
        0.5,0.5,
        0.0669873,0.75,
        0.0669873,0.75,
        0.5,0.5,
        0.0468461,0.711309,
        0.0468461,0.711309,
        0.5,0.5,
        0.0301537,0.67101,
        0.0301537,0.67101,
        0.5,0.5,
        0.0170371,0.629409,
        0.0170371,0.629409,
        0.5,0.5,
        0.00759611,0.586824,
        0.00759611,0.586824,
        0.5,0.5,
        0.00190264,0.543578,
        0.00190264,0.543578,
        0.5,0.5,
        0,0.5,
        0,0.5,
        0.5,0.5,
        0.00190267,0.456422,
        0.00190267,0.456422,
        0.5,0.5,
        0.00759614,0.413176,
        0.00759614,0.413176,
        0.5,0.5,
        0.0170371,0.37059,
        0.0170371,0.37059,
        0.5,0.5,
        0.0301537,0.32899,
        0.0301537,0.32899,
        0.5,0.5,
        0.0468461,0.288691,
        0.0468461,0.288691,
        0.5,0.5,
        0.0669873,0.25,
        0.0669873,0.25,
        0.5,0.5,
        0.090424,0.213212,
        0.090424,0.213212,
        0.5,0.5,
        0.116978,0.178606,
        0.116978,0.178606,
        0.5,0.5,
        0.146447,0.146447,
        0.146447,0.146447,
        0.5,0.5,
        0.178606,0.116978,
        0.178606,0.116978,
        0.5,0.5,
        0.213212,0.0904239,
        0.213212,0.0904239,
        0.5,0.5,
        0.25,0.0669873,
        0.25,0.0669873,
        0.5,0.5,
        0.288691,0.0468461,
        0.288691,0.0468461,
        0.5,0.5,
        0.32899,0.0301537,
        0.32899,0.0301537,
        0.5,0.5,
        0.370591,0.0170371,
        0.370591,0.0170371,
        0.5,0.5,
        0.413176,0.00759611,
        0.413176,0.00759611,
        0.5,0.5,
        0.456422,0.00190264,
        0.456422,0.00190264,
        0.5,0.5,
        0.5,0,
        0.5,0,
        0.5,0.5,
        0.543578,0.00190267,
        0.543578,0.00190267,
        0.5,0.5,
        0.586824,0.00759614,
        0.586824,0.00759614,
        0.5,0.5,
        0.62941,0.0170371,
        0.62941,0.0170371,
        0.5,0.5,
        0.67101,0.0301537,
        0.67101,0.0301537,
        0.5,0.5,
        0.711309,0.0468462,
        0.711309,0.0468462,
        0.5,0.5,
        0.75,0.0669873,
        0.75,0.0669873,
        0.5,0.5,
        0.786788,0.090424,
        0.786788,0.090424,
        0.5,0.5,
        0.821394,0.116978,
        0.821394,0.116978,
        0.5,0.5,
        0.853553,0.146447,
        0.853553,0.146447,
        0.5,0.5,
        0.883022,0.178606,
        0.883022,0.178606,
        0.5,0.5,
        0.909576,0.213212,
        0.909576,0.213212,
        0.5,0.5,
        0.933013,0.25,
        0.933013,0.25,
        0.5,0.5,
        0.953154,0.288691,
        0.953154,0.288691,
        0.5,0.5,
        0.969846,0.32899,
        0.969846,0.32899,
        0.5,0.5,
        0.982963,0.370591,
        0.982963,0.370591,
        0.5,0.5,
        0.992404,0.413176,
        0.992404,0.413176,
        0.5,0.5,
        0.998097,0.456422,
        0.998097,0.456422,
        0.5,0.5,
        1,0.5
        };
}
cone::~cone()
{
    //dtor
}



