#ifndef MESHSIMPLIFY_H
#define MESHSIMPLIFY_H

#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include "face.h"
#include "model.h"
#include "camera.h"


using namespace std;


class Meshsimplify
{
    public:

        Meshsimplify(void);
        ~Meshsimplify(void);

        void startSimplify(model,model,Camera,double);//ori,new,camera,dis2building
        void output(model,string);
};


void mergePolygon(face f1,face f2);

#endif