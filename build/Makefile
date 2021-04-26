CXXFLAGS=-std=c++11
LDFLAGS=-lncurses
main: ../src/main.cpp
	g++ $(CXXFLAGS) ../src/main.cpp $(wildcard ../lib/*.cpp) $(LDFLAGS) -o ../bin/main
