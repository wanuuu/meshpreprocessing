#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include "loadMesh.h"


using namespace std;

class MeshSimplify
{
    public:

        MeshSimplify(void);
        ~MeshSimplify(void);

        void startSimplify(model,model,Camera,double);//ori,new,camera,dis2building
        void output(model,string);
};

class Camera
{
    public:

        Camera();
        double Focal;
        double Ratio;
        double Fov;

        void setCamera(double,double,double);


};