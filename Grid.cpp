#include<bits/stdc++.h>
#include"Grid.h"
#include<string>

using namespace std;

Grid::Grid(){

}

int Grid::GetPremium(int x,int y)
{

    return premium[pair<int,int>(x,y)];
}

string spaceMultiplier(char obj, int number){
	string object = string(1, obj);
	for (int i = 0; i < number; i++) object += string(1, obj);
	return object;
}


void Grid::printGrid(){
	int i,j;
		cout << char(186) << spaceMultiplier(' ', 7);
		for (i = 0; i < 15; i++) cout << setw(3) << i;
		cout << endl << char(186) << spaceMultiplier(' ', 7) << char(201) << spaceMultiplier(char(205), 43) << char(187) <<endl;
		for (i = 0; i < 15; i++){
			cout << char(186) << spaceMultiplier(' ', 4) << setw(2)<< i << " " << char(186) ;
			for (j = 0; j < 15; j++){
				string temp;
				if (board[i][j] == 0) cout << ". " << char(186);
				else  cout << board[i][j] << " " << char(186);
			}
			cout << endl;
		}
		cout << char(186) << spaceMultiplier(' ', 7) << char(200) << spaceMultiplier(char(205), 43) << char(188) <<endl;
		return;
}

char Grid::getElement(int row, int col){
	return board[row][col];
}

void Grid::insertToGrid(int r, int c, char letter) {
	board[r][c] = letter;
}


bool Grid::updateGrid(int r, int c, char dir, string word,Rack oRack){
    IsEmpty = false;
	bool added = false;
		if (dir == 'h'||dir == 'H'){
            for (int i =0; i < word.size(); i++){
			    if ( getElement(r, c+i) == word[i]) added =true;
				else if(getElement(r, c+i) == 0 && oRack.LetterExist(word[i])){
                    insertToGrid(r, c+i, word[i]);
                    oRack.mRemoveCard(word[i]);
                    added = true;
				}
//				else return false;
		}
		}
		else if (dir == 'v'||dir == 'V'){
            for (int i =0; i < word.size(); i++){
			    if ( getElement(r+i, c) == word[i]) added =true;
				else if(getElement(r+i, c) == 0 && oRack.LetterExist(word[i])){
                    insertToGrid(r+i, c, word[i]);
                    oRack.mRemoveCard(word[i]);
                    added = true;
				}
//				else return false;
		}
		}
	return added;
}


bool checkUnique(int r, int c, char dir, string word, Grid &mainBoard,Rack oRack){
	bool added = false;
	for (int i =0; i < word.size(); i++){
		if (dir == 'h'||dir == 'H'){
            if (c+word.size() > 14) return false;
			if (mainBoard.getElement(r, c+i) == 0 && oRack.LetterExist(word[i])){
                    added = true;
			}
//			else if(mainBoard.getElement(r, c+i) == word[i]) return true;
			else if (mainBoard.getElement(r, c+i) == 0 && !oRack.LetterExist(word[i])) {
                cout<<"The element does not exist in your rack\n";
                return false;
			}

            else if (mainBoard.getElement(r, c+i) != word[i]) return false;
		}
		else if (dir == 'v'||dir == 'V'){
            if (r+word.size() > 14) return false;
			if (mainBoard.getElement(r+i, c) == 0 && oRack.LetterExist(word[i])){
                    added = true;
			}
//			else if(mainBoard.getElement(r+i, c) == word[i]) return true;
			else if (mainBoard.getElement(r+i, c) == 0 && !oRack.LetterExist(word[i])) {
                cout<<"The element does not exist in your rack\n";
                return false;
			}

            else if (mainBoard.getElement(r+i, c) != word[i]) return false;
		}
	}
	if(added) {
		cout << "Word have been added\n";
		return mainBoard.updateGrid(r, c, dir, word, oRack);
	}
	else cout << "Word have not added, try again\n";
	return added;
}



void Grid::SetPremium(){

    premium[make_pair(0,0)]=1;
    premium[make_pair(0,7)]=1;
    premium[make_pair(0,14)]=1;
    premium[make_pair(14,7)]=1;
    premium[make_pair(14,0)]=1;
    premium[make_pair(7,0)]=1;
    premium[make_pair(7,14)]=1;
    premium[make_pair(14,14)]=1;
    premium[make_pair(1,1)]=2;
    premium[make_pair(2,2)]=2;
    premium[make_pair(3,3)]=2;
    premium[make_pair(4,4)]=2;
    premium[make_pair(12,2)]=2;
    premium[make_pair(9,4)]=2;
    premium[make_pair(2,12)]=2;
    premium[make_pair(4,10)]=2;
    premium[make_pair(10,10)]=2;
    premium[make_pair(11,11)]=2;
    premium[make_pair(12,12)]=2;
    premium[make_pair(13,13)]=2;
    premium[make_pair(13,1)]=2;
    premium[make_pair(10,3)]=2;
    premium[make_pair(1,13)]=2;
    premium[make_pair(3,11)]=2;
    premium[make_pair(7,7)]=2;
    premium[make_pair(1,5)]=3;
    premium[make_pair(1,9)]=3;
    premium[make_pair(5,1)]=3;
    premium[make_pair(5,5)]=3;
    premium[make_pair(5,9)]=3;
    premium[make_pair(5,13)]=3;
    premium[make_pair(9,1)]=3;
    premium[make_pair(9,5)]=3;
    premium[make_pair(9,9)]=3;
    premium[make_pair(9,13)]=3;
    premium[make_pair(13,5)]=3;
    premium[make_pair(13,9)]=3;
    premium[make_pair(0,3)]=4;
    premium[make_pair(0,11)]=4;
    premium[make_pair(2,6)]=4;
    premium[make_pair(3,7)]=4;
    premium[make_pair(6,2)]=4;
    premium[make_pair(6,8)]=4;
    premium[make_pair(7,3)]=4;
    premium[make_pair(8,2)]=4;
    premium[make_pair(8,8)]=4;
    premium[make_pair(11,0)]=4;
    premium[make_pair(3,0)]=4;
    premium[make_pair(2,8)]=4;
    premium[make_pair(3,14)]=4;
    premium[make_pair(6,6)]=4;
    premium[make_pair(6,12)]=4;
    premium[make_pair(7,11)]=4;
    premium[make_pair(8,6)]=4;
    premium[make_pair(8,12)]=4;
    premium[make_pair(11,7)]=4;
    premium[make_pair(11,14)]=4;
    premium[make_pair(12,6)]=4;
    premium[make_pair(12,8)]=4;
    premium[make_pair(14,3)]=4;
    premium[make_pair(14,11)]=4;
}



