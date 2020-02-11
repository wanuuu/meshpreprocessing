#ifndef LOADMESH_H
#define LOADMESH_H

#include<iostream>
#include<vector>
#include<string.h>


using namespace std;

struct vertice{

    double x,y,z;
};

class face{

    public :
        face();
        vector<vertice> vertex;
        vector<int> vtindex; 
        vector<int> neighbor;
        double normal[3];
        double area;
        bool isflat;
        bool isbaseface ;

        void getNormal(vector<vertice> vert);
        void getArea(vector<vertice> vert);
};

class model{

    public:
        model();
        vector<face> faces;
        vector<int> baseface;
        int vertex_n,face_n;

        void loadmesh(string filename);


};

extern void cross(double[],double[],double[]);

#endif