#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>

using namespace std;

class Camera
{
    public:

        Camera();
        ~Camera();
        double Focal;
        double Ratio;
        double Fov;

        void setCamera(double,double,double);


};

#endif