all:
  clang++-5.0 -std=c++14 main.cpp Board.cpp Board.h *.o
  ./a.out
