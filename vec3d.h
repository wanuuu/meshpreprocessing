//3d空間中的計算 加減乘除 內外積
#ifndef VEC3D_H
#define VEC3D_H
#include <math.h>

class Vec3d
{
    public:

        Vec3d(double X = 0,double Y = 0, double Z = 0):x(X),y(Y),z(Z){};
        ~Vec3d();
        double x,y,z;

        friend Vec3d operator + (const Vec3d&,const Vec3d&);
        friend Vec3d operator - (const Vec3d&,const Vec3d&);
        friend Vec3d operator * (const Vec3d&,const Vec3d&);
        friend Vec3d operator / (const Vec3d&,const Vec3d&);
        friend Vec3d operator + (const Vec3d&,const double&);
        friend Vec3d operator - (const Vec3d&,const double&);
        friend Vec3d operator * (const Vec3d&,const double&);
        friend Vec3d operator / (const Vec3d&,const double&);

        Vec3d getCrossVec(const Vec3d&);
        double getDotVec(const Vec3d&);

};


#endif
