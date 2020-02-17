#include "vec3d.h"

Vec3d::~Vec3d()
{

}

Vec3d operator +(const Vec3d& A,const Vec3d& B)
{
    return Vec3d( A.x + B.x, A.y + B.y, A.z + B.z);
}

Vec3d operator -(const Vec3d& A,const Vec3d& B)
{
    return Vec3d( A.x - B.x, A.y - B.y, A.z - B.z);
}

Vec3d operator *(const Vec3d& A,const Vec3d& B)
{
    return Vec3d( A.x * B.x, A.y * B.y, A.z * B.z);
}

Vec3d operator /(const Vec3d& A,const Vec3d& B)
{
    return Vec3d( A.x / B.x, A.y / B.y, A.z / B.z);
}

Vec3d operator +(const Vec3d& A,const double& t)
{
    return Vec3d( A.x + t,A.y + t,A.z + t);
}

Vec3d operator -(const Vec3d& A,const double& t)
{
    return Vec3d( A.x - t,A.y + t,A.z + t);
}

Vec3d operator *(const Vec3d& A,const double& t)
{
    return Vec3d( A.x * t,A.y * t,A.z * t);
}

Vec3d operator /(const Vec3d& A,const double& t)
{
    return Vec3d( A.x / t,A.y / t,A.z / t);
}

Vec3d Vec3d::getCrossVec(const Vec3d& A)
{
    return Vec3d()
}