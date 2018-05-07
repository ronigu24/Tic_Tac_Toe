#include <iostream>
#include <list>
#include <exception>
#include <string>

using namespace std;


class Board{

public:
    int size;
	char **mat;


	Board(int value);
	Board(const Board& b);
	~Board();


	char& operator[](list<int> index);
	Board& operator=(char);
	Board& operator=(const Board& db);
	friend ostream& operator<<(ostream& os, const Board &m);



};

inline ostream& operator<<(ostream& os, const Board &b) {
	for(int i = 0; i < b.size; i++){
		for(int j = 0; j < b.size; j++){
			cout << b.mat[i][j];
		}
		cout << endl;
	}
	return os;
}



class IllegalCoordinateException : public exception{
	int a,b;

	public:

		IllegalCoordinateException(int i, int j);
		string theCoordinate() const;

};

class IllegalCharException : public exception{
	char value;

	public:
		IllegalCharException(char c);
		char theChar() const;

};
