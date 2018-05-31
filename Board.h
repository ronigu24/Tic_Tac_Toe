#pragma once
#include<iostream>
#include<fstream>
#include <list>
#include <string>

#include "BoardNode.h"
#include "CoordinateException.h"
#include "CharException.h"
#include "BoardIndex.h"
using Coordinate = BoardIndex;

using namespace std;

class Board{

public:

	Node **mat;
	int n;
	Board(){
		n=0;
		mat=NULL;
	}
	Board(int value);
	Board(const Board& other);
	~Board();

	int size() const;

	Node& operator[](list<int> index);
	Node& operator[](const BoardIndex& coor) const;
	Board& operator=(char value);
	Board& operator=(const Board& db);
	Board& operator=(int value);
	friend ostream& operator<<(ostream& os, Board const &b);
	friend istream& operator>>(istream& is, Board  &b);
	friend bool operator==(const Board& b1, const Board& b2);
	string draw(int val);


	};

inline istream& operator>>(istream& is, Board &b){
	string f;
		is>>f;
		ifstream file;
		file.open(f);
		bool once=true;
		int i=0;
		string line;
	if(file.fail()){
		cout<<"fail";
	}
	else{
		while(file>>line)
		{
			if(once)
			{
				b=(int)line.length();
				once=false;
			}
			for(unsigned int j=0;j<line.length();j++)
			{
				b[{i,(int)j}]=line.at((int)j);
			}
			i++;
		}
	}
		file.close();
		return is;
}

inline ostream& operator<<(ostream& os, Board const &b) {

	int n = b.size();
	string s = "";

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			s+=b.mat[i][j];
		}
		s+="\n";
	}

	return os << s;
}


inline bool operator==(const Board& b1, const Board& b2){

	if(b1.size() != b2.size()){
		return false;
	}
	else
	{
		for(int i = 0; i < b1.size(); i++){
			for(int j = 0; j < b1.size(); j++){
				if(b1.mat[i][j].getSymbol() != b2.mat[i][j].getSymbol()){
					return false;
				}

			}
		}
		return true;
	}
}
