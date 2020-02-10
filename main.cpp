#include <iostream>
#include <unistd.h>
#include "loadMesh.h"

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

    return 0;
}