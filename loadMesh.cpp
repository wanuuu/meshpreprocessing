#include<iostream>
#include<sstream>
#include<fstream>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include "loadMesh.h"

using namespace std;

double* cross(double *a, double *b)
{
    double product[3];

    product[0] = (a[1]*b[2])-(a[2]*b[1]);
    product[1] = (a[2]*b[0])-(a[0]*b[2]);
    product[2] = (a[0]*b[1])-(a[1]*b[0]);
    //cout<<product[0]<<" "<<product[1]<<" "<<product[2]<<endl;
    return product;
}

face::face()
{
    area = 0;
    isflat = false;
    isbaseface = false;

}

void face::getNormal(vector<vertice> vert)
{

    double vector1[3],vector2[3];
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

    normal = cross(vector1,vector2);
    //cout<<normal<<endl;  
 
}

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
                ftmp.getNormal(ftmp.vertex);
                //ftmp.getArea();
                faces.push_back(ftmp);
            }

            
        }
        
        vertex_n = vtmp.size();
        face_n = faces.size();
      
    }
       
    cout<<"reading complete."<<endl;
}