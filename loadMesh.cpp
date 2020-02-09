#include<iostream>
#include<sstream>
#include<fstream>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include "loadMesh.h"

using namespace std;



face::face()
{
    isflat = false;
    isbaseface = false;

}

void face::getNormal()
{
    vertice p1 = vertex[0];
    vertice p2 = vertex[1];
    vertice p3 = vertex[2];
 
}

model::model()
{
    vertex_n = 0;
    face_n = 0;
}

void model::loadmesh(string filename)
{
    
}