#include "Mtmchkin.h"


Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) : m_player(playerName), m_currCard(0),m_numOfCards(numOfCards){
    m_cardsArray = new Card[numOfCards];

    for (int card = 0; card < numOfCards; card++)
    {
        Card currCard(cardsArray[card]);
        m_cardsArray[card] = currCard;
    }
    m_status = GameStatus::MidGame;
}

void Mtmchkin::updateGameStatus(){
    if(m_player.getLevel()>=10){
        m_status=GameStatus::Win;
    }
    else if(m_player.isKnockedOut()){
        m_status=GameStatus::Loss;
    }
    else
        m_status=GameStatus::MidGame;
}


//the func takes the "highest" card in the deck (currCard), then currCard++
//we also update the gamestatus after every encounter
void Mtmchkin::playNextCard(){
    m_cardsArray[m_currCard%m_numOfCards].printInfo();
    m_cardsArray[m_currCard%m_numOfCards].applyEncounter(m_player);
    m_player.printInfo();
    updateGameStatus();
    m_currCard++;
}

bool Mtmchkin::isOver() const{
    if(m_status==GameStatus::MidGame){
        return false;
    }
    return true;
}

GameStatus Mtmchkin::getGameStatus() const{
    return m_status;
}

int Mtmchkin::getCurrCard(){
    return m_currCard;
}
//destructor
Mtmchkin::~Mtmchkin(){
    delete[] m_cardsArray;
}

int Mtmchkin::getNumOfCards() const{
    return m_numOfCards;

}

Player Mtmchkin::getPlayer() const{
    //Player newPlayer(m_player);
    return m_player;
}


Card* Mtmchkin::getCardArr() const{
    Card* newCardsArray = new Card[m_numOfCards];

    for (int card = 0; card < m_numOfCards; card++)
    {
        newCardsArray[card] = Card(m_cardsArray[card]);
    }
    return newCardsArray;
}

//copy constructor for mtmchkin
Mtmchkin::Mtmchkin(const Mtmchkin& game) : m_player(game.getPlayer()) {
    m_numOfCards = game.getNumOfCards();
    m_cardsArray=game.getCardArr();
    m_status = game.getGameStatus();

}

Mtmchkin& Mtmchkin::operator=(Mtmchkin& otherMtmchkin) {

    //delete current fields in this game
    delete[] m_cardsArray;
    m_player.~Player();

    m_numOfCards = otherMtmchkin.getNumOfCards();

    //allocate a new cards array with the same array as in otherMtmchkin
    m_cardsArray = new Card[m_numOfCards];

    for (int card = 0; card < m_numOfCards; card++)
    {
        Card currCard(m_cardsArray[card]);
        m_cardsArray[card] = currCard;
    }

    m_status = otherMtmchkin.getGameStatus();
    m_player = otherMtmchkin.getPlayer();
    m_currCard = otherMtmchkin.getCurrCard(); 

    return *this;

}











  /*  m_player(newMtmchkin.getPlayer());
    Mtmchkin::~Mtmchkin();
    m_numOfCards = newMtmchkin.getNumOfCards();
    Card* m_cardsArray=newMtmchkin.getCardArr();
    m_status = newMtmchkin.getGameStatus();
}*/