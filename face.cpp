#include "face.h"

vertice::vertice()
{
    
}
vertice::vertice(double x,double y,double z)
{
    pos = Vec3d(x,y,z);
}

face::face()
{
    area = 0;
    isflat = false;
    isbaseface = false;
}

void face::getNormal(vector<vertice> vert)
{
    Vec3d  vector1 ,vector2;
    vertice v1,v2,v3;

    v1 = vert.at(0);
    v2 = vert.at(1);
    v3 = vert.at(2);

    vector1 = v3.pos - v1.pos;
    vector2 = v2.pos - v1.pos;

    normal = vector1.getCrossVec(vector2);

    //cout<<normal.x<<" "<<normal.y <<" "<<normal.z<<endl;
}

void face::getArea(vector<vertice> vert)
{
    if (vert.size() < 3)
    {
        cout<<"Not a polygon ! "<<endl;
    }

    double atmp = 0;

    vertice po = vert.at(0);

    for ( int i = 1;i < vert.size()-1;i++)
    {
        vertice p1 = vert.at(i);
        vertice p2 = vert.at(i+1);

        Vec3d a,b;

        a = p1.pos - po.pos;
        b = p2.pos - po.pos;

        Vec3d areatmp;

        areatmp = a.getCrossVec(b);
        atmp+= sqrt(pow(areatmp.x,2)+pow(areatmp.y,2)+pow(areatmp.z,2));
    }
    area = 0.5*atmp;
}