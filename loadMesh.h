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
        bool isflat;
        bool isbaseface ;

        void getNormal();
};

class model{

    public:
        model();
        vector<face> faces;
        void loadmesh(string filename);
        int vertex_n,face_n;


};



#endif