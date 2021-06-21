#include"RACK.H"


Rack::Rack(){}
//Rack::Rack(Bag* bagOfPlayer)
//{
//    for(int i=0;i<7;i++){
//        mCards[i]=bagOfPlayer->mFetchTile();
//    }
//}

Rack::~Rack()
{
}

bool Rack::mRemoveCard(char l)
{
    for(int i=0;i<7;i++){
        if(l==mCards[i]->getLetter()){
            mCards[i]->mEmpty('_');
            return true;
        }
    }
    return false;
}

void Rack::mRefillRack(Bag* bagOfPlayer)
{
    for(int i=0;i<7;i++){
        if(mCards[i]==0){
            mCards[i]=bagOfPlayer->mFetchTile();
        }
    }
}

void Rack::mPrintRack(){
    for(int i=0;i<7;i++){
        cout<<mCards[i]->getLetter()<<" ";
    }
    cout<<"\n";
}

void Rack::insertTile(Tile* x, int i){
    mCards[i]=x;
}

Tile* Rack::GetCard(int i){
return mCards[i];

}

bool Rack::LetterExist(char l){
    for(int i=0;i<7;i++){
        if(mCards[i]->getLetter()==l) return true;
    }
    return false;
}
