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

//destructor
Mtmchkin::~Mtmchkin(){
    for (int card = 0; card < m_numOfCards; card++)
    {
        m_cardsArray[card].~Card();
    }

    delete(m_cardsArray);
    m_player.~Player();

}

int Mtmchkin::getNumOfCards() const{
    return m_numOfCards;

}

Player Mtmchkin::getPlayer() const{
    Player newPlayer(m_player);
    return newPlayer;
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
    Card* m_cardsArray=game.getCardArr();
    m_status = game.getGameStatus();

}
/*
Mtmchkin& Mtmchkin::operator=(Mtmchkin& newMtmchkin) {
    m_player(newMtmchkin.getPlayer());
    Mtmchkin::~Mtmchkin();
    m_numOfCards = newMtmchkin.getNumOfCards();
    Card* m_cardsArray=newMtmchkin.getCardArr();
    m_status = newMtmchkin.getGameStatus();
}

Mtmchkin new("g",,);
Mtmchkin old("g",,);
old = new;
*/
