//model classs

#ifndef MODEL_H
#define MODEL_H

#include<vector>
#include<string.h>
#include "face.h"

using namespace std;

class model
{
    public:

        model();

        vector <vertice> vertex;
        vector <face> faces;
        vector <int> baseface;

        int nVectex,nFace;
        void loadmesh(string filename);
};

#endif