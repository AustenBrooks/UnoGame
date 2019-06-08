#include <iostream>
#include <vector>
#include "card.h"
#include "gameManager.h"

using namespace std;

void buildDeck(vector<Card*> &deck){
    for(int c = RED; c<=YELLOW; ++c){
        for(int n=0; n<10; ++n){
            deck.push_back(new NumberCard((ColorType)c,n));
        }
        deck.push_back(new ReverseCard((ColorType)c));
        deck.push_back(new SkipCard((ColorType)c));
        deck.push_back(new Draw2((ColorType)c));
        deck.push_back(new WildCard());
    }
}

void drawCard(vector<Card*> &deck, vector<Card*> &hand, int numDraw){
    Card* temp;
    for(int i=0;i<numDraw;++i){
        temp=deck.at(deck.size()-1);
        deck.pop_back();
        hand.push_back(temp);
    }
}

void shuffle(vector<Card*> &deck){
    Card* temp;
    int index1, index2;
    for(int i=0;i<500;++i){
        index1=rand()%deck.size();
        index2=rand()%deck.size();
        
        temp=deck.at(index1);
        deck.at(index1)=deck.at(index2);
        deck.at(index2)=temp;
    }
}

void renderHand(vector<Card*> hand){
    if(hand.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < hand.size(); j++){
                cout << hand.at(j)->render(i) << " ";
            }
            cout << endl;
        }
    }
    else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}
void renderDiscard(vector<Card*> discard){
    for(int i = 0; i <= 7; i++){
       cout<<  discard.at(discard.size()-1)->render(i)<<endl;
    }
}
void takeTurn(vector<Card*> &deck, vector<Card*> &hand, vector<Card*> &discard, GameManager &gameManager){
    for(int j = 0; j < gameManager.numCardsToPlay; j++){
        cout<<"What would you like to do?"<<endl;
        int i;
        bool invalidChoice=true;
        int input;
        
        while(invalidChoice){
            for(i=0;i<hand.size();++i){
                cout<<i<<" Play Card"<<endl;
            }
            cout<< i << " Draw a Card"<<endl;
            cin>>input;
            
            if(input>i||input<0)
                cout<<"Invalid Choice"<<endl;
            else if(input == i)
                invalidChoice=false;
            else if(hand.at(input)->play(*discard.at(discard.size()-1), gameManager))
                invalidChoice=false;
            else
                cout<<"Invalid Choice"<<endl;
            
        }
        if (input<i){
            Card* temp;
            temp = hand.at(input);
            discard.push_back(temp);
            hand.erase(hand.begin() + input);
        }
        else if(input==i){
            drawCard(deck,hand,1);
        }
    }
}
bool handIsEmpty(vector<Card*> hand){
    if(hand.size()==0)
        return true;
    else
        return false;
}
int main(){
    srand(time(0));

    GameManager gameManager(3); //creates game for num of players
    
    vector<Card*> discard;
    vector<Card*> deck;
    vector<vector<Card*>> hands(gameManager.numPlayers);
    
    buildDeck(deck);
    shuffle(deck);
    
    for(int i=0; i<hands.size();++i)
        drawCard(deck,hands.at(i),7);

    drawCard(deck,discard,1);
    
    while(1){
        if(gameManager.numCardsToDraw>0){
            drawCard(deck,hands.at(gameManager.currentPlayerIndex),gameManager.numCardsToDraw);
            gameManager.numCardsToDraw=0;
            gameManager.nextTurn();
        }
        cout<< "Player "<<gameManager.currentPlayerIndex<<"'s Turn" <<endl;
        renderDiscard(discard);
        renderHand(hands.at(gameManager.currentPlayerIndex));
        takeTurn(deck,hands.at(gameManager.currentPlayerIndex),discard,gameManager);
        
        if(handIsEmpty(hands.at(gameManager.currentPlayerIndex))){
            break;
        }
        
        gameManager.nextTurn();

    }
    cout<<"Player Number " << gameManager.currentPlayerIndex<< " Wins"<<endl;
    return 0;
}