#include "card.h"

void Card::setColor(ColorType c){
    color = c;
}

void Card::setNumber(int n){
    number = n;
}
ColorType Card::getColor(){
    return color;
}
int Card::getNumber(){
    return number;
}

bool Card::play(Card discard, GameManager &gameManager){
    return false;
}

string Card::render(int line){
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: return "|           |";
        case 3: return "|           |";
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

NumberCard::NumberCard(ColorType c, int n){
    setColor(c);
    setNumber(n);
}

string NumberCard::render(int line){
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|     " <<  number << "     |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

bool NumberCard::play(Card discard, GameManager &gameManager){
    if(color == discard.getColor()||number==discard.getNumber()){
        return true;
    }
    else
        return false;
}

bool ReverseCard::play(Card discard, GameManager &gameManager){
    if(color == discard.getColor()||number==discard.getNumber()){
        gameManager.turnOrderIsForward= !gameManager.turnOrderIsForward;
        return true;
    }
    else
        return false;
}

ReverseCard::ReverseCard(ColorType c){
    setColor(c);
    setNumber(-1);
}

string ReverseCard::render(int line){
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3: return "|  <---     |";
        case 4: return "|  REVERSE  |";
        case 5: return "|     --->  |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
bool SkipCard::play(Card discard, GameManager &gameManager){
    if(color == discard.getColor()||number==discard.getNumber()){
        gameManager.nextTurn();
        return true;
    }
    else
        return false;
}

SkipCard::SkipCard(ColorType c){
    setColor(c);
    setNumber(-2);
}

string SkipCard::render(int line){
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3: return "|           |";
        case 4: return "|   SKIP    |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
bool Draw2::play(Card discard, GameManager &gameManager){
    if(color == discard.getColor()||number==discard.getNumber()){
        gameManager.numCardsToDraw=2;
        return true;
    }
    else
        return false;
}

Draw2::Draw2(ColorType c){
    setColor(c);
    setNumber(-3);
}

string Draw2::render(int line){
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3: return "|           |";
        case 4: return "|   DRAW 2  |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

bool WildCard::play(Card discard, GameManager &gameManager){
    cout<<"What color will you change it to?"<<endl;
    cout<<"0. Red, 1. Blue, 2. Green, 3. Yellow"<<endl;
    int input;
    while(1){
        cin >> input;
        if(input<0||input>3)
            cout<<"Invalid Choice"<<endl;
        else
            break;
    }
    setColor((ColorType)input);
    return true;
}
WildCard::WildCard(){
    setColor((ColorType) 5);
    setNumber(-4);
}

string WildCard::render(int line){
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3: return "|           |";
        case 4: return "|    WILD   |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}