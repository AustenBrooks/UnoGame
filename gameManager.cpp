#include "gameManager.h"


GameManager::GameManager(int numPlayers){
    this-> numPlayers=numPlayers;
    this-> currentPlayerIndex=0;
    this-> numCardsToPlay=1;
    this-> numCardsToDraw=0;
    this-> turnOrderIsForward=true;
}

void GameManager::nextTurn(){
    if(turnOrderIsForward){
        currentPlayerIndex++;
        if(currentPlayerIndex>=numPlayers){
            currentPlayerIndex=0;
        }
    }
    else{
        currentPlayerIndex--;
        if(currentPlayerIndex<0){
            currentPlayerIndex=numPlayers-1;
        }
    }
}