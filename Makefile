all:main.out

CC = g++ -g
INSTDIR = /usr/loacl/bin
INCLUDE = .
CXXFLAGS += -std=c++11 
LIBS += -framework CoreFoundation

main.out: main.o model.o face.o vec3d.o
	$(CC) -o main.out main.o model.o face.o vec3d.o
main.o: main.cpp model.h face.h vec3d.h
	$(CC) -I$(INCLUDE) $(CXXFLAGS) -c main.cpp
model.o : model.cpp model.h face.o vec3d.o
	$(CC) -I$(INCLUDE) $(CXXFLAGS) -c model.cpp
face.o : face.cpp face.h vec3d.o
	$(CC) -I$(INCLUDE) $(CXXFLAGS) -c face.cpp
vec3d.o : vec3d.cpp vec3d.h
	$(CC) -I$(INCLUDE) $(CXXFLAGS) -c vec3d.cpp
meshfimplify.o : meshfimplify.cpp meshfimplify.h
	$(CC) -I$(INCLUDE) $(CXXFLAGS) -c meshfimplify.cpp
clean:
	rm -f main.out main.o model.o face.o vec3d.o meshfimplify.o

