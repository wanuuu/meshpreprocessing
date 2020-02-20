#include <iostream>
#include <unistd.h>
#include "model.h"
#include "meshsimplify.h"


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


    mergePolygon(meshmodel.faces.at(2),meshmodel.faces.at(3));
    
    return 0;
}