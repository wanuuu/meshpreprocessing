#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include "loadMesh.h"
#include "meshsimplify.h"

using namespace std;

//Camera Related
Camera::Camera()
{
    
    Focal = 6;
    Ratio = 1.6;
    Fov = 0;
}

void Camera::setCamera(double focal,double ratio,double fov)
{
    Focal = focal;
    Ratio = ratio;
    Fov = fov;
}

//Mesh Simplification

MeshSimplify::MeshSimplify()
{

}
MeshSimplify::~MeshSimplify()
{

}
void MeshSimplify::startSimplify(model ori,model newMesh,Camera cam,double dis2building)
{
    vector<vertice> vtmp;
    vector<face> ftmp;
    double camFootprintArea = 0.0;
    double fpl,fpw;

    fpw = round(2 * dis2building * tan(cam.Fov/2));
    fpl = round(2 * dis2building * tan((cam.Fov/cam.Ratio)/2));

    camFootprintArea = fpw * fpl;

}
void MeshSimplify::output(model newMesh,string file )
{

}