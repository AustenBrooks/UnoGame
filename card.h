#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <sstream>
#include "gameManager.h"

using namespace std;

enum ColorType {RED, BLUE, GREEN, YELLOW };

class Card{
    protected:
    ColorType color;
    int number;
    
    public:
    void setColor(ColorType);
    void setNumber(int);
    ColorType getColor();
    int getNumber();
    virtual string render(int);
    virtual bool play(Card, GameManager&);
};

class NumberCard : public Card{
    public:
    NumberCard(ColorType, int);
    string render(int);
    bool play(Card, GameManager&);
};

class ReverseCard : public Card{
    public:
    ReverseCard(ColorType);
    string render(int);
    bool play(Card, GameManager&);
};

class SkipCard : public Card{
    public:
    SkipCard(ColorType);
    string render(int);
    bool play(Card, GameManager&);
};

class Draw2 : public Card{
    public:
    Draw2(ColorType);
    string render(int);
    bool play(Card, GameManager&);
};

class WildCard : public Card{
    public:
    WildCard();
    string render(int);
    bool play(Card, GameManager&);
};

#endif