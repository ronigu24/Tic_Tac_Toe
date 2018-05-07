#include "Board.h"

//Constructor Functions -

Board::Board(int value){

	this->size = value;
	mat = new char*[value];

	for(int i = 0; i < value ;i++)
	{
		mat[i] = new char[value];
	}

	for(int i = 0; i < value; i++)
	{
		for(int j = 0; j < value; j++)
		{
			mat[i][j] = '.';
		}
	}
}

Board::Board(const Board& b){

	this->size = b.size;
		mat = new char*[size];

		for(int i = 0; i < size ;i++)
		{
			mat[i] = new char[size];
		}

		for(int i = 0; i < size; i++)
		{
			for(int j = 0; j < size; j++)
			{
				mat[i][j]=b.mat[i][j];
			}
		}


}

//Destruction Function -
Board::~Board(){

	for(int i = 0; i < this->size; i++){
		delete[] mat[i];
	}
	delete[] mat;
}


//Operators - 
char& Board::operator[](list<int> index){

	int a = index.front();
	int b = index.back();

	if(a < size && a >= 0 && b < size && b >= 0)
	{
		return mat[a][b];
	}

	else
	{
		throw IllegalCoordinateException(a,b);
	}
}

Board& Board::operator=(char value){

	if(value != 'X' && value != 'O' && value != '.')
	{
		throw IllegalCharException(value);
	}
	else
	{

		for(int i = 0; i < this->size; i++){
			for(int j = 0; j < this->size; j++){
				mat[i][j] = value;
			}
		}
	}
	return *this;
}



Board& Board::operator=(const Board& db){
	Board b{db};
	return *this;
}

//Exceptions - 
string IllegalCoordinateException::theCoordinate() const{
	return to_string(this->a) + "," + to_string(this->b);
}

IllegalCoordinateException::IllegalCoordinateException(int i, int j){
	this->a = i;
	this->b = j;
}

IllegalCharException::IllegalCharException(char c){
	this->value = c;
}

char IllegalCharException::theChar() const{
	return this->value;
}
