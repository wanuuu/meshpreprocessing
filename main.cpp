#include <iostream>
#include <unistd.h>
#include "model.h"


using namespace std;

int main(int argc, char * argv[])
{
    while(argc < 2)
    {
        cout<<"Usage: "<<argv[0]<<" <Model File Name>"<<endl;
        return 1;
    }

    char currpath[50];
    string modelpath = "/model/";  
    getcwd(currpath,sizeof(currpath));
    string filename = currpath+modelpath+argv[1];
    
    model meshmodel;
    meshmodel.loadmesh(filename);

    cout<<meshmodel.nVectex<<" "<<meshmodel.nFace<<endl;
    cout<<meshmodel.faces.at(0).area<<endl;
    cout<<meshmodel.faces.at(0).normal.x<<" "<<meshmodel.faces.at(0).normal.y<<" "<< meshmodel.faces.at(0).normal.z<<endl;

    return 0;
}