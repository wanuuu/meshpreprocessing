#include <iostream>
#include <sstream>
#include <fstream>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#include "face.h"
#include "vec3d.h"
#include "model.h"

using namespace std;

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
bool isFlat(Vec3d normal)
{
    if(normal.x == normal.y == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

vector<int> getbaseface(vector<face> faces)
{
    vector<int> basetmp;
    double minz = -100;

    for(int i =0;i<faces.size();i++)
    {
        for(int j =0;j<faces.at(i).vertex.size();j++)
        {
            if(minz == -100)
            {
                minz = faces.at(i).vertex.at(j).pos.z;
            }
            else if(faces.at(i).vertex.at(j).pos.z < minz)
            {
                minz = faces.at(i).vertex.at(j).pos.z;
            }
            
        }
    }  

    for (int i = 0;i<faces.size();i++)
    {
        int c = 0;
        for (int j = 0;j<faces.at(i).vertex.size();j++)
        {
            if(faces.at(i).vertex.at(j).pos.z <= minz)
            {
                c++;
            }
        }

        if(c >=3)
        {
            basetmp.push_back(i);
        }
    }

    return basetmp;  
}

model::model()
{
    nVectex = 0;
    nFace = 0;

}
void model::loadmesh(string filename)
{
    ifstream modelfile(filename.c_str());

    string line;
    vector<vertice> vtmp;
    int i = 0;
    cout<<"start reading file ..."<<endl;

    while (getline(modelfile,line))
    {   
        /* code */
        string rtmp;
        vector<string> lines;
        stringstream l(line);
        while(getline(l,rtmp,' '))
        {
            lines.push_back(rtmp);
        }
        //cout<<lines.size()<<endl;
        if(lines.size()!=0)
        {
            if(lines.at(0) == "#" || lines.at(0) == "vt"||lines.at(0).empty())
            {
                //cout<<"ignore." <<endl;
                continue;
            }

            else if(lines.at(0) == "v")
            {    
                //cout<<"vertice .."<<endl;
                vertice v(stod(lines[1]),stod(lines[2]),stod(lines[3]));
                v.id = i+1;
                i++;
                vtmp.push_back(v);
                vertex.push_back(v);

            }
            else if(lines.at(0) == "f")
            {
                //cout<<"face..."<<endl;
                face ftmp;
                for(int j = 1;j<lines.size();j++)
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
                //cout<<ftmp.vtindex.size()<<endl;
                sort(ftmp.vtindex.begin(),ftmp.vtindex.end());
                ftmp.getNormal(ftmp.vertex);
                ftmp.getArea(ftmp.vertex);
                ftmp.isflat = isFlat(ftmp.normal);
                faces.push_back(ftmp);
                    
            }
        }
    }

    nVectex = vertex.size();
    nFace= faces.size();

    for (int i = 0;i<nFace;i++)
    {
        for(int j = j+1;j<nFace;j++)
        {
            bool b = isNeighbor(faces.at(i).vtindex,faces.at(j).vtindex);
            if(b == true)
            {
                faces.at(i).neighbor.push_back(j);
                faces.at(j).neighbor.push_back(j);
            }
        }
    }

    for (int i =0;i<nFace;i++)
    {
        sort(faces.at(i).vtindex.begin(),faces.at(i).vtindex.end());
    }

    baseface = getbaseface(faces);
    for (int i = 0;i<baseface.size();i++)
    {
        int index = baseface.at(i);
        faces.at(index).isbaseface = true;
    }
     
     cout<<"reading complete. "<<endl;
}