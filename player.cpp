#include<iostream>
#include"player.h"
using namespace std;


Player::Player(string name){
    mName = name;
    mScore= 0;
}

int Player::GetScore(){
return mScore;
}

string Player:: mGetName(){
return mName;

}


void Player::UpdateScore(int score){
mScore+=score;
}

Rack Player::GetRack(){

return mRackOFPlayer;

}


void Player::StartRack(){
    for(int i=0;i<7;i++){
        mRackOFPlayer.insertTile(mBagOfPlayer.mFetchTile(),i);
    }
}

void Player::RefillRack(){

for(int i=0;i<7;i++){
        if((mRackOFPlayer.GetCard(i)->getLetter())=='_'){
        mRackOFPlayer.insertTile(mBagOfPlayer.mFetchTile(),i);
        }
    }
}


void Player::SetScore(int x){
    mScore+=x;
}

Bag Player::GetBag(){

return mBagOfPlayer;

}

