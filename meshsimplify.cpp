#include <iostream>
#include <algorithm>
#include <iterator>
#include <math.h>
#include <vector>
#include "vec3d.h"
#include "model.h"
#include "face.h"

#include "meshsimplify.h"

using namespace std;
//Mesh Simplification

Meshsimplify::Meshsimplify()
{

}
Meshsimplify::~Meshsimplify()
{

}
void Meshsimplify::startSimplify(model ori,model newMesh,Camera cam,double dis2building)
{
    vector<vertice> vtmp;
    vector<face> ftmp;
    double camFootprintArea = 0.0;
    double fpl,fpw;

    fpw = round(2 * dis2building * tan(cam.Fov/2));
    fpl = round(2 * dis2building * tan((cam.Fov/cam.Ratio)/2));

    camFootprintArea = fpw * fpl;

}
//頂點的交集
vector<vertice> v_intersection(vector<vertice> v1,vector<vertice> v2)
{
    vector <vertice> v;

    for (int i = 0;i<v1.size();i++)
    {
        for (int j = 0;j<v2.size();j++)
        {
            if(v1.at(i).pos == v2.at(j).pos)
            {
                v.push_back(v1.at(i));
                
            }
            
        }
    }

    return v;
}
//頂點的聯集
vector<vertice> v_union(vector<vertice> v1, vector<vertice> v2)
{
    vector<Vec3d> vtmp;
    vector<vertice> v;
    for(int i = 0;i < v1.size();i++)
    {
        vtmp.push_back(v1.at(i).pos);
    }
    for(int i = 0;i<v2.size();i++)
    {
        vtmp.push_back(v2.at(i).pos);
    }
    sort(vtmp.begin(),vtmp.end());
    auto it = unique(vtmp.begin(),vtmp.end());
    vtmp.erase(it,vtmp.end());

    for (int i = 0;i<vtmp.size();i++)
    {
        vertice vt;
        vt.pos = vtmp.at(i);
        v.push_back(vt);
    }
    return v;

}
// union - intersection
vector<vertice> removeShared(vector<vertice> uni,vector<vertice> inter)
{
    vector<vertice> points;
    for (int i = 0;i<uni.size();i++)
    {
        for(int j = 0;j<inter.size();j++)
        {
            if(uni.at(i).pos == inter.at(j).pos)
            {
                uni.erase(uni.begin()+i);
            }
        }
    }

    points = uni;
    return points;
}
//合併兩多邊形
void mergePolygon(face f1,face f2)
{
    face megrgeface;

    vector<vertice> points,v_inter,v_uni;
    //remove shared points = v_union - v_inter
    v_inter = v_intersection(f1.vertex,f2.vertex);
    v_uni = v_union(f1.vertex,f2.vertex);
    points = removeShared(v_uni,v_inter);

    //對 x,y,z 排序
    //先排y
    //再排Ｘ
}
void Meshsimplify::output(model newMesh,string file )
{

}