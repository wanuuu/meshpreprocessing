all:main.out

CC = g++ -g
INSTDIR = /usr/loacl/bin
INCLUDE = .
CXXFLAGS += -std=c++11 
LIBS += -framework CoreFoundation

main.out: main.o loadMesh.o
	$(CC) -o main.out main.o loadMesh.o
main.o: main.cpp loadMesh.h
	$(CC) -I$(INCLUDE) $(CXXFLAGS) -c main.cpp
loadMesh.o : loadMesh.cpp loadMesh.h
	$(CC) -I$(INCLUDE) $(CXXFLAGS) -c loadMesh.cpp

meshfimplify.o meshfimplify.cpp meshfimplify.h
	$(CC) -I$(INCLUDE) $(CXXFLAGS) -c meshfimplify.cpp

clean:
	rm -f main.out main.o loadMesh.o meshfimplify.o

