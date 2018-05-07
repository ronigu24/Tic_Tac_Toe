CXX=clang++-5.0
CXXFLAGS=-std=c++14

all:
	$(CXX) $(CXX+) main.cpp Board.cpp Board.h -o a.out
	./a.out 
