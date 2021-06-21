
#include "tile.h"
#include<iostream>
#include<cassert>

using namespace std;

Tile::Tile(char l, int s)
{
    letter=l;
    score=s;
}

Tile::~Tile(){}

char Tile::getLetter()
{
	return letter;
}

int Tile::getScore()
{
	return score;
}

void Tile::show()
{
	cout << "   " << letter << "   ";
}

void Tile::mEmpty(char l){
    letter=l;
    score=0;
}

