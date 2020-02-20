//face class
#ifndef FACE_H
#define FACE_H


#include <iostream>
#include <vector>
#include <string.h>
#include "vec3d.h"

using namespace std;

class vertice
{
    public:

        vertice();
        vertice(double,double,double);
        Vec3d pos;
};
class face
{

    public:
        face();
        vector<vertice> vertex;
        vector<int> vtindex;
        vector<int> neighbor;
        Vec3d normal;
        double area;
        bool isflat;
        bool isbaseface;

        void getNormal(vector<vertice> vert);
        void getArea(vector<vertice> vert);
};




#endif