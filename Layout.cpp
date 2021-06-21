#include<bits/stdc++.h>
#include <stdlib.h>
//#include <windows.h>
using namespace std;


void Turns(Grid &oPlayGrid,Player &player1,Player &player2,Trie oDict);

char letters[] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int points[]   = {0,   1,  3,  3,  2,  1,  4,  2,  4,  1,  8,  5,  1,  3,  1,  1,  3,  10, 1,  1,  1,  1,  4,  4,  8,  4, 10};


map <char,int> mpLScore;

 void Rules();
 int IncreseScore(int x,int y,char d,string word,Grid &oPlayGrid);
 void Turns(Grid &oPlayGrid,Player &player1,Player &player2,Trie oDict);
 bool checkAdj(int row, int col, char dir, string word, Grid &oPlayGrid);


char board[15][15] = {};


void updateGrid(int r, int c, char dir, string word){
		if (dir == 'h'){
            for (int i =0; i < word.size(); i++) board[r][c+i] = word[i];
		}
		else if (dir == 'v'){
            for (int i =0; i < word.size(); i++) board[r+i][c] = word[i];
		}
}


void gameLayout(){
	int choice;
	cout << char(201) << spaceMultiplier(char(205), 115) << char(187);
	cout <<endl<<char(186) << spaceMultiplier(' ',50) << char(201) << spaceMultiplier(char(205), 9) << char(187) <<endl;
	cout <<char(186) << spaceMultiplier(' ',50) << char(186) << " Scrabble " << char(186) << endl;
	cout <<char(186) << spaceMultiplier(' ',50)<< char(200) << spaceMultiplier(char(205), 9) << char(188);
	cout <<endl<<char(186) << spaceMultiplier(' ',20) <<"||***|| Hello! Welcome to Our Scrabble Game. We hope you enjoy it! ||***||" << endl;
	cout << char(186) <<" Please Select what you want to do:" << endl << char(186) << spaceMultiplier(' ',10) << "1. Play" << spaceMultiplier(' ',5) << "2. Learn Rules" << endl << char(186) << spaceMultiplier( ' ',17) << "3. Quit" << endl << char(186) <<">> I choose no.: ";
	cin >> choice;
	if(choice ==2)
        Rules();
    if (choice ==3){
        cout<<"We hope you stay here more next time :) \n Bye ";
        exit (EXIT_FAILURE);
    }

}
      string null=" ";

void PlayerNames(string &player1=null ,string &player2=null){
cout << char(186) << " What are your names?"<< endl << char(186) << " player 1: ";
	cin >> player1;
	cout << char(186) << " Player 2: ";
	cin >> player2;
}



void Rules(){
	string rules[] = {"1.The first player combines two or more of his or her letters to form a word and \n places it on the board to read either across or down with one letter on the center \nsquare. Diagonal words are not allowed." ,
"2.Complete your turn by counting and announcing your score for that turn. Then,\n draw as many new letters as you played; always keep seven letters on your rack, \nas long as there are enough tiles left in the bag.",
"3.Play passes to the left. The second player, and then each in turn, adds one or \nmore letters to those already played to form new words. All letters played on a turn \n must be placed in one row across or down the board, to form at least one complete \nword. If, at the same time, they touch others letters in adjacent rows, those must\n also form complete words, crossword fashion, with all such letters. The player gets\n full credit for all words formed or modified on his or her turn."
};
cout << char(186) << " Rules:" << endl;
cout << char(186) <<spaceMultiplier(char(205), 7) << endl;
for (int i = 0; i < 3; i++) cout << char(186) << " " <<setw(40)<< rules[i] << endl << endl;
cout << char(186) <<" Now lets play the game..";
}


void Turns(Grid &oPlayGrid,Player &player1,Player &player2,Trie oDict){
    bool turn = true;
    bool FirstTurn=true;
    bool PlayerTurn = true;
    int RoundCounter = 0;
    while(turn){

        if(RoundCounter==6||player1.GetBag().IsEmpty()||player2.GetBag().IsEmpty()){
            break;
        }
        player1.RefillRack();
        int row,col; char dir; string word;
        oPlayGrid.printGrid();
        if(PlayerTurn){
            player1.RefillRack();
            cout << char(186) << " Now it's " << player1.mGetName() << "'s turn.." << endl;
            cout << char(186) <<" Your Rack now has: \t";
            player1.GetRack().mPrintRack();cout<<endl;
            BackToChoose1:
            cout<<char(186) << "Do you want to play or to exchange letters? (P/E) ";
            char playORexchange;cin >> playORexchange;
            if (playORexchange == 'P'||playORexchange == 'p'){
            char addMoreWords = 'Y';
            while (addMoreWords == 'Y'||addMoreWords == 'y'){
                    if(FirstTurn){
                        cout << char(186) << " This is the first turn, enter the direction[ex. h] : ";
                        row=col=7;
                        cin >>dir;
                        FirstTurn=false;

                    }
                    else {
                        cout << char(186) << " Please enter the row and column of the first letter and the direction[ex. 4 3 h] : ";
                        cin >> row >> col >> dir;
                    }
                        cout << char(186) << " Your word is: (it you want to exchange enter \'e\')";
                        cin >> word;
                        if(word=="e")
                            goto BackToChoose1;

                        cout << char(186) << " You entered " << word << " in ( " << row << " , " << col << " )" << endl;
                        if(oDict.WordExist(&word[0]) && checkAdj(row, col, dir, word, oPlayGrid)){
                            if(checkUnique(row, col, dir, word, oPlayGrid, player1.GetRack())){
                                player1.SetScore(IncreseScore(row, col, dir, word,oPlayGrid));
                                cout << char(186) << spaceMultiplier(' ', 30)<< "(: (: Valid Game Move! :) :) " << endl;
                                oPlayGrid.printGrid();
                                cout << char(186) <<" Your Rack now has: \t";
                                player1.GetRack().mPrintRack();cout<<endl;
                                RoundCounter=0;
                                cout << char(186) << " Do you want to add anymore words? (Y/N) ";
                                cin >> addMoreWords;

                            }
                            else cout << char(186) << "Sorry this is not valid. The cells are not available or your rack is not sufficient" << endl ;
                        }
                        else cout << char(186) << "Sorry this is not valid. Word does not exist or is not adjacent" << endl ;
                }
                cout<< "Score of "<<player1.mGetName()<<" is "<<player1.GetScore()<<endl;
                cout<< "Score of "<<player2.mGetName()<<" is "<<player2.GetScore()<<endl;
            }
            else if  (playORexchange=='e'||playORexchange=='E'){
                cout << char(186) << "How many cards you want to exchange ?\n";
                int tt; cin >>tt;
                for (int i = 0; i < tt; i++){
                    cout << char(186) << " Please enter the char you want to exchange\n";
                    char dd; cin >>dd;
                    if(player1.GetRack().LetterExist(dd)){
                        player1.GetRack().mRemoveCard(dd);
                    }
                    else{
                        cout<<"Letter "<<dd<<" not exist in rack, please reenter\n";
                        i--;

                    }

                }
                player1.RefillRack();
                RoundCounter++;
            }
            PlayerTurn = false;
        }
else if(!PlayerTurn){
            player2.RefillRack();
            cout << char(186) << " Now it's " << player2.mGetName() << "'s turn.." << endl;
            cout << char(186) <<" Your Rack now has: \t";
            player2.GetRack().mPrintRack();cout<<endl;
            BackToChoose2: //Flag to come back here
            cout<<char(186) << "Do you want to play or to exchange letters? (P/E) ";
            char playORexchange;cin >> playORexchange;
            if (playORexchange == 'P'||playORexchange == 'p'){
            char addMoreWords = 'Y';
            while (addMoreWords == 'Y'||addMoreWords == 'y'){
                    if(FirstTurn){
                        cout << char(186) << " This is the first turn, enter the direction[ex. h] : ";
                        row=col=7;
                        cin >>dir;
                        FirstTurn=false;

                    }
                    else {
                        cout << char(186) << " Please enter the row and column of the first letter and the direction[ex. 4 3 h] : ";
                        cin >> row >> col >> dir;
                    }
                        cout << char(186) << " Your word is: (it you want to exchange enter \'e\')";
                        cin >> word;
                        if(word=="e")
                            goto BackToChoose2;

                        cout << char(186) << " You entered " << word << " in ( " << row << " , " << col << " )" << endl;
                        if(oDict.WordExist(&word[0]) && checkAdj(row, col, dir, word, oPlayGrid)){
                            if(checkUnique(row, col, dir, word, oPlayGrid, player2.GetRack())){
                                player2.SetScore(IncreseScore(row, col, dir, word,oPlayGrid));
                                cout << char(186) << spaceMultiplier(' ', 30)<< "(: (: Valid Game Move! :) :) " << endl;
                                oPlayGrid.printGrid();
                                cout << char(186) <<" Your Rack now has: \t";
                                player2.GetRack().mPrintRack();cout<<endl;
                                RoundCounter=0;
                                cout << char(186) << " Do you want to add anymore words? (Y/N) ";
                                cin >> addMoreWords;

                            }
                            else cout << char(186) << "Sorry this is not valid. The cells are not available or your rack is not sufficent" << endl ;
                        }
                        else cout << char(186) << "Sorry this is not valid. Word doesnot exist or is not adjacent" << endl ;
                }
                cout<< "Score of "<<player1.mGetName()<<" is "<<player1.GetScore()<<endl;
                cout<< "Score of "<<player2.mGetName()<<" is "<<player2.GetScore()<<endl;
            }
            else if  (playORexchange=='e'||playORexchange=='E'){
                cout << char(186) << "How many cards you want to exchange ?\n";
                int tt; cin >>tt;
                for (int i = 0; i < tt; i++){
                    cout << char(186) << " Please enter the char you want to exchange\n";
                    char dd; cin >>dd;
                    if(player2.GetRack().LetterExist(dd)){
                        player2.GetRack().mRemoveCard(dd);
                    }
                    else{
                        cout<<"Letter "<<dd<<" not exist in rack, please reenter\n";
                        i--;

                    }

                }
                player2.RefillRack();
                RoundCounter++;
            }
            PlayerTurn = true;
        }



}

if(player1.GetScore()>player2.GetScore()) {
    cout<<" The winner is " << player1.mGetName()<<"\t Congratulation! :D";
}
else if(player1.GetScore()<player2.GetScore()) {
    cout<<" The winner is " << player2.mGetName()<<"\t Congratulation! :D";
}
else {
    cout<<" The result is draw! Congratulation for both of you! :D\n\n\t\t\t BYE ";
}
}


int IncreseScore(int x,int y,char d,string word,Grid &oPlayGrid){
    int wordcofficient=1;
    int score=0;
    if (d=='h'||d=='H'){
    for (int i=0;i<word.size();i++){
        if(oPlayGrid.GetPremium(x,y+i)==1){
            wordcofficient *=3;
        }
        else if(oPlayGrid.GetPremium(x,y+i)==2)
        {
            wordcofficient *=2;
        }
        else if(oPlayGrid.GetPremium(x,y+i)==3)
        {
            score += (2*mpLScore[word[i]]);
        }
        else if(oPlayGrid.GetPremium(x,y+i)==4)
        {
            score += mpLScore[word[i]];
        }
        score += (mpLScore[word[i]]);
        }
        score = score * wordcofficient;
}
    else if (d=='v'||d=='V'){
    for (int i=0;i<word.size();i++){
        if(oPlayGrid.GetPremium(x+i,y)==1){
            wordcofficient *=3;
        }
        else if(oPlayGrid.GetPremium(x+i,y)==2)
        {
            wordcofficient *=2;
        }
        else if(oPlayGrid.GetPremium(x+i,y)==3)
        {
            score += (2*mpLScore[word[i]]);
        }
        else if(oPlayGrid.GetPremium(x+i,y)==4)
        {
            score += mpLScore[word[i]];
        }

        score += (mpLScore[word[i]]);
        }
        score = score * wordcofficient;

}
return score;
    }

bool checkAdj(int row, int col, char dir, string word, Grid &oPlayGrid){
    bool adj = false;
    if (oPlayGrid.IsEmpty) return true;
    if (dir == 'h'){
        for (int i =0; i<word.size(); i++){
            if (oPlayGrid.getElement(row, col+i) != 0) return true;
        }
        return false;
        }
    else if (dir == 'v'||dir == 'V'){
        for (int i =0; i<word.size(); i++){
            if (oPlayGrid.getElement(row+i, col) != 0) return true;
        }
        return false;
        }
}


void BuildTree(Trie &dict){
  string temp;

    ifstream fDictionary( "dictionary.txt" );
    for(int i =0;i<61211;i++){
        getline(fDictionary, temp);
        dict.Append(&temp[0]);
    }
}


