
#include<iostream>
#include<cassert>
#include<cstdlib>
#include <stdlib.h>
#include<ctime>
#include "Bag.h"


Bag::Bag()
{
    mNumOfTiles = 100;
    srand(time(nullptr));
    char letters[] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int  counts[]  = {2,   9 , 2,  2,  4,  12, 2,  3,  2,  9,  1,  1,  4,  2,  6,  8,  2,  1,  6,  4,  6,  4,  2,  2,  1,  2,  1};
	int points[]   = {0,   1,  3,  3,  2,  1,  4,  2,  4,  1,  8,  5,  1,  3,  1,  1,  3,  10, 1,  1,  1,  1,  4,  4,  8,  4, 10};
    int n=0;
    for(int i=0; i<27; i++)
		for(int j=0; j<counts[i]; j++, n++)
			mTiles[n] = new Tile(letters[i], points[i]);
}

Bag::~Bag()
{
    for(int i=0; i<100; i++)
		delete mTiles[i];
}

Tile* Bag::mFetchTile()
{
	if(mNumOfTiles)
	{
		int i = rand()%mNumOfTiles;
		Tile* temp = mTiles[i];          // return this
		mTiles[i] = mTiles[mNumOfTiles - 1]; // move last tile to random index
		mTiles[mNumOfTiles - 1] = temp;         // move random tile to last
		mNumOfTiles--;
		return temp;
	}
	else
		return nullptr;
}

void Bag::mReset()
{
    mNumOfTiles=100;
}
bool Bag::IsEmpty()
{
    return mNumOfTiles==0;

}
