#include<iostream>
#include<sstream>
#include<fstream>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include "loadMesh.h"
#include <vector>

using namespace std;

// face obj related

bool isNeighbor(vector<int> vt1,vector<int> vt2)
{
    vector<int> intersect;
    set_intersection(vt1.begin(),vt1.end(),vt2.begin(),vt2.end(),inserter(intersect,intersect.end()));

    if(intersect.size()>=2)
    {
        return true;
    }
    else
    {
        return false;
    }
    

}
bool isFalt(double normal[])
{
    if (normal[0] == normal[1] ==0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
void cross(double a[], double b[],double normal[])
{
   normal[0] = (a[1]*b[2])-(a[2]*b[1]);
   normal[1] = (a[2]*b[0])-(a[0]*b[2]);
   normal[2] = (a[0]*b[1])-(a[1]*b[0]);
    //cout<<product[0]<<" "<<product[1]<<" "<<product[2]<<endl;

}
face::face()
{
    area = 0;
    isflat = false;
    isbaseface = false;

}
void face::getNormal(vector<vertice> vert)
{

    double vector1[3],vector2[3],normalvector[3];
    vertice v1,v2,v3;

    v1 = vert.at(0);
    v2 = vert.at(1);
    v3 = vert.at(2);

    double p1[] = {v1.x,v1.y,v1.z};
    double p2[] = {v2.x,v2.y,v2.z};
    double p3[] = {v3.x,v3.y,v3.z};

    vector1[0] = p3[0]-p1[0];
    vector1[1] = p3[1]-p1[1];
    vector1[2] = p3[2]-p1[2];

    vector2[0] = p2[0]-p1[0];
    vector2[1] = p2[1]-p1[1];
    vector2[2] = p2[2]-p1[2];

    cross(vector1,vector2,normalvector);
    //cout<<normalvector[0]<<" "<<normalvector[1]<<" "<<normalvector[2]<<endl;
    for (int i = 0;i<3;i++)
    {
        normal[i] = normalvector[i];
    }  
 
}
void face::getArea(vector<vertice> vert)
{
    if(vert.size()<3)
    {
        cout<<"Not a polygon !"<<endl;
    }
    double atmp = 0;

    vertice po = vert.at(0);
    for (int i = 1;i < vert.size()-1;i++)
    {
        vertice p1 = vert.at(i);
        vertice p2 = vert.at(i+1);
        double a[3],b[3];

        a[0] = p1.x-po.x;
        a[1] = p1.y-po.y;
        a[2] = p1.z-po.z;

        b[0] = p2.x-po.x;
        b[1] = p2.y-po.y;
        b[2] = p2.z-po.z;

        double areatmp[3];
        cross(a,b,areatmp);
        atmp += sqrt(pow(areatmp[0],2)+pow(areatmp[1],2)+pow(areatmp[2],2));
    }
    area = 0.5*atmp;
}

vector<int> getbaseface(vector<face> faces)
{
    vector<int> basetmp;
    double minZ = -100;

    for(int i = 0;i<faces.size();i++)
    {
        for(int j = 0;j<faces.at(i).vertex.size();j++)
        {
            if(minZ == -100)
            {
                minZ = faces.at(i).vertex.at(j).z;
            }
            else if(faces.at(i).vertex.at(j).z < minZ)
            {
                minZ = faces.at(i).vertex.at(j).z;
            }
        }
    }

    for(int i = 0;i<faces.size();i++)
    {
        int c = 0;
        for(int j = 0;j<faces.at(i).vertex.size();j++)
        {
            if(faces.at(i).vertex.at(j).z <= minZ)
            {
                c++;
            }
        }

        if(c >= 3)
        {
            basetmp.push_back(i);
        }
    }
    return basetmp;
}

//model obj related
model::model()
{
    vertex_n = 0;
    face_n = 0;
}
void model::loadmesh(string filename)
{   //cout<<filename<<endl;
    
    ifstream modelfile(filename.c_str());
    string line;
    vector<vertice> vtmp;
    int vcount = 0;
    int fcount = 0;

    cout<<"start reading file....."<<endl;


    while(getline(modelfile,line))
    {   
        string rtmp;
        vector<string> lines;
        stringstream l(line);
        int i = 0;
        while(getline(l,rtmp,' '))
        {
            lines.push_back(rtmp);
        }

        if(lines.size()!=0)
        {
            if(lines.at(0)=="#"||lines.at(0)=="vt"||lines.at(0).empty())
            {
                continue;
            }
            else if(lines.at(0)=="v")
            {
                vertice v ;
                v.x = stod(lines[1]);
                v.y = stod(lines[2]);
                v.z = stod(lines[3]);
                vtmp.push_back(v);
            }
            else if(lines.at(0)=="f")
            {

                face ftmp;
                for(int j= 1;j<lines.size();j++)
                {
                    if(!lines.at(j).empty())
                    {
                        //cout<<j<<" "<<lines[j]<<endl;
                        string vt;
                        stringstream ss(lines[j]);
                        getline(ss,vt,'/');
                        int vindex = stoi(vt)-1;
                        //cout<<vindex<<endl;
                        ftmp.vtindex.push_back(vindex);
                        ftmp.vertex.push_back(vtmp.at(vindex));

                    }
                }
                sort(ftmp.vtindex.begin(),ftmp.vtindex.end());
                ftmp.getNormal(ftmp.vertex);
                ftmp.getArea(ftmp.vertex);
                ftmp.isflat = isFalt(ftmp.normal);
                faces.push_back(ftmp);
            }

            
        }

    }
               
    vertex_n = vtmp.size();
    face_n = faces.size();

    for(int i = 0;i< face_n;i++)
    {
        for(int j = i+1;j< face_n;j++)
        {
            bool b = isNeighbor(faces.at(i).vtindex,faces.at(j).vtindex);
            if(b==true)
            {
                faces.at(i).neighbor.push_back(j);
                faces.at(j).neighbor.push_back(i);
            }
        }
    }
    for(int i = 0;i<faces.size();i++)
    {
        sort(faces.at(i).vtindex.begin(),faces.at(i).vtindex.end());
    }

    baseface = getbaseface(faces);
    for (int i = 0;i<baseface.size();i++)
    {
        int index = baseface.at(i);
        faces.at(index).isbaseface = true;
    }
      
    cout<<"reading complete."<<endl;
}