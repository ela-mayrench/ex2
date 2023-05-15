#include "Player.h"
#include "utilities.h"

using std::string;


Player::Player(string name,int maxHP, int force) : m_level(1),m_coins(0),name(name),m_force(DEFAULT_FORCE),m_maxHP(DEFAULT_MAX_HP){
    //if the input values are legal
    if (maxHP > 0){
        m_maxHP = maxHP;
        m_HP = maxHP;
    }
    if(force >= 0){
        m_force = force;
    }
}

void Player::printInfo(){
    printPlayerInfo(name.c_str(), m_level,  m_force, m_HP,  m_coins);
}

void Player::levelUp(){
    if (m_level < 10){
        m_level++;
    }
}

int Player::getLevel(){
    return m_level;
}

//adds to force the num that accepts as argument
void Player::buff(int num){
    m_force += num;
}

void Player::heal(int num){
    if(num>0){
        if ((m_HP + num)>m_maxHP){
            m_HP = m_maxHP;
        }
        else{
            m_HP += num;
        }
    }
}

void Player::damage(int num){

    if(num <= 0)
        return;

    if ((m_HP - num) < 0){
        m_HP = 0;
    }
    else{
        m_HP -= num;
    }

}

bool Player::isKnockedOut(){
    return m_HP == 0;
}

void Player::addCoins(int num){
    m_coins += num;
}

bool Player::pay(int num){
    if(m_coins-num < 0){ //if the player doesnt have enough money to pay
        return false;
    }
    else{
        m_coins-=num;
        return true;
    }
}

int Player::getAttackStrength(){
    int strength = m_level + m_force;
    return strength;
}