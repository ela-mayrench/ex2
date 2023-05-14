#include <string>
#include "Player.h"

class Player
{
private:
    std::string name;
    int level;
    int force;
    int maxHP;
    int HP;
    int coins;
    
public:
    Player(std::string name,int maxHP = 100, int force = 5) : level(1),coins(0),name(name){
        //if the input values are legal
        if (maxHP > 0){
            Player::maxHP = maxHP;
            Player::HP = maxHP;
        }
        if(force >= 0){
            Player::force = force;
        }
    }
    ~Player();

    void printInfo(){        
        printPlayerInfo(Player::name.c_str(), Player::level,  Player::force, Player::HP,  Player::coins);
    }

    void levelUp(){
        if (Player::level < 10){
            Player::level++;
        }
    }

    int getLevel(){
        return Player::level;
    }

    //adds to force the num that accepts as argument
    void buff(int num){
        Player::force += num;
    }

    void heal(int num){
        if(num>0){
            if ((Player::HP + num)>Player::maxHP){
                Player::HP = Player::maxHP;
            }
            else{
                Player::HP += num;
            }
        }
    }

    void damage(int num){
        if(num>0){
            if ((Player::HP - num) < 0){
                Player::HP = 0;
            }
            else{
                Player::HP -= num;
            }
        }
    }

    bool isKnockedOut(){
        if(Player::HP == 0)
            return true;
        else
            return false;
    }

    void addCoins(int num){
        Player::coins += num;
    }

    bool pay(int num){
        if(Player::coins-num < 0){ //if the player doesnt have enough money to pay
            return false;
        }
        else{
            Player::coins-=num;
            return true;
        }
    }

    int getAttackStrength(){
        int strength = Player::level + Player::force; 
        return strength;
    }
};

