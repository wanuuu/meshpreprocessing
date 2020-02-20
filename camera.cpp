#include "camera.h"

//Camera Related
Camera::Camera()
{
    
    Focal = 6;
    Ratio = 1.6;
    Fov = 0;
}
Camera::~Camera()
{
    
}
void Camera::setCamera(double focal,double ratio,double fov)
{
    Focal = focal;
    Ratio = ratio;
    Fov = fov;
}
