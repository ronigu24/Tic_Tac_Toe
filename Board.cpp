#include "Board.h"

//Constructor Functions -


Board::Board(int value)
{
	this->n = value;
	mat = new Node*[value];

	for(int i = 0; i < n ;i++)
	{
		mat[i] = new Node[n];
	}
}

Board::Board(const Board& other)
{
	/*if(size()>0){
		this->~Board();
	}*/
	this->n = other.size();
	mat = new Node*[n];

	for(int i = 0; i < n ;i++)
	{
		mat[i] = new Node[n];
	}
	for(int i = 0; i < n ;i++)
	{
		for(int j = 0; j < n; j++)
		{
			mat[i][j] = other.mat[i][j];
		}
	}	
}

int Board::size() const
{
	return this->n;
}

Board::~Board()
{
	for(int i = 0; i < this->n; i++){
		delete[] mat[i];
	}
	delete[] mat;
}

Node& Board::operator[](list<int> index)
{
	int a = index.front();
	int b = index.back();

	BoardIndex bIndex(a,b);

	if(bIndex.i < n && bIndex.i >= 0 && bIndex.j < n && bIndex.j >= 0)
	{
		return mat[bIndex.i][bIndex.j];
	}

	else
	{
		throw IllegalCoordinateException(bIndex);
	}
}

Node& Board::operator[](const BoardIndex& coor) const
{
	int a = coor.i;
	int b = coor.j;

	BoardIndex bIndex(a,b);

	if(bIndex.i < n && bIndex.i >= 0 && bIndex.j < n && bIndex.j >= 0)
	{
		return mat[bIndex.i][bIndex.j];
	}

	else
	{
		throw IllegalCoordinateException(bIndex);
	}
}
Board& Board::operator=(char value)
{
	if(value != '.' && value != 'X' && value != 'O')
	{
		throw IllegalCharException(value);
	}
	else
	{
		for(int i = 0; i < this->n; i++){
			for(int j = 0; j < this->n; j++){
				this->mat[i][j].setSymbol(value);
			}
		}

	}
	return *this;
}

Board& Board::operator=(const Board& db)
{
	this->~Board();

	this->n = db.n;
	mat = new Node*[n];

	for(int i = 0; i < n ;i++)
	{
		mat[i] = new Node[n];
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			mat[i][j].setSymbol(db.mat[i][j].getSymbol());
		}
	}
	return *this;
}
Board& Board::operator=(int value){


	n = value;
	mat = new Node*[n];

	for(int i = 0; i < n ;i++)
	{
		mat[i] = new Node[n];
	}
	return *this;

}
struct RGB {
	uint8_t red, green, blue;
public:
	RGB() {}
	RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};
string Board::draw(int val){
	const int dimx = val, dimy = val;
	string filename="cpp.ppm";
	ofstream imageFile(filename, ios::out | ios::binary);
	imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
	RGB image[dimx*dimy];
	int charsize=val/n;


	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < val; j++)
		{
			image[charsize*val*i+j].green = (255);
			image[charsize*i+j*val].green = (255);

		}
	}



	for(int f=0;f<n;f++)
	{
		for(int g=0;g<n;g++)
		{
			if(mat[f][g].getSymbol()=='X')
			{
				for(int loc=1;loc<charsize;loc++)
				{
					image[val*charsize*f+val*loc+g*charsize+loc].red = (255);
					image[val*charsize*f+val*loc+charsize+g*charsize-loc].red = (255);

				}

			}
			else if(mat[f][g].getSymbol()=='O')
			{
				for(int loc=1;loc<charsize;loc++)
				{
					int rx=g*charsize/2+loc;
					int ry=f*(charsize/2);
					int dx = abs(rx- charsize*g+loc) ; // horizontal offset
					int dy = abs(ry- charsize*f+loc); // vertical offset
					if ( (dx*dx + dy*dy) <= ((charsize/2)*(charsize/2)) )
					{
						image[val*charsize*f+g*charsize+loc].blue = (255);
						//image[dx*dy].blue = (255);

					}

				}

			}
		}
	}
	image[0].red = 255;
	image[0].blue = 0;
	image[0].green = 0;
	///
	///image processing
	///
	imageFile.write(reinterpret_cast<char*>(&image), 3*dimx*dimy);
	imageFile.close();
	return filename;
}
