#include<iostream>
#include"Player.cpp"
#include"Grid.cpp"
#include"Tire_algorithm.cpp"
#include "Layout.cpp"

using namespace std;

int main(){
for(int i=0; i<27; i++){
    mpLScore[letters[i]] = points[i];
}
    string player_1,player_2;
    Trie oDict;
    BuildTree(oDict);
    gameLayout();
    PlayerNames(player_1,player_2);
    Player oPlayer1(player_1);     Player oPlayer2(player_2);
    Grid oPlayGrid;
    oPlayGrid.SetPremium();
    oPlayer1.StartRack();     oPlayer2.StartRack();
    oPlayer1.RefillRack();    oPlayer2.RefillRack();
    Turns(oPlayGrid,oPlayer1,oPlayer2,oDict);

}
