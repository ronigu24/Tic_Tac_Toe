CXX=clang++-5.0
CXXFLAGS=-std=c++17

all:
	$(CXX) $(CXX+) main.cpp Board.cpp Board.h *.o
	./a.out 
