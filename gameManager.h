#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H


class GameManager{
    public:
    int numPlayers;
    int currentPlayerIndex;
    int numCardsToPlay;
    int numCardsToDraw;
    bool turnOrderIsForward;
    
    GameManager(int);
    void nextTurn();
};

#endif