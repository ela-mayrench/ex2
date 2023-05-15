#include "Card.h"

Card::Card(CardType type, const CardStats& stats): m_effect(type), m_stats(stats){};

/*void encounterBattle(Player & player, const Card & card){
    if(card.cardStats.)
}*/

void Card::applyEncounter(Player & player) const{
    if(m_effect==CardType::Battle){
        if(player.getAttackStrength()>= m_stats.force){ //if we won the battle
            player.levelUp();
            player.addCoins(m_stats.loot);
            printBattleResult(true);
        }
        else{ //if we lost the battle
            player.damage(m_stats.hpLossOnDefeat);
            printBattleResult(false);
        }

    }
    else if(m_effect == CardType::Heal ){
        if(player.pay(m_stats.cost)){
            player.heal(m_stats.heal);
        }
    }
    else if( m_effect == CardType::Buff){
        if(player.pay(m_stats.cost)){
            player.buff(m_stats.buff);
        }
    }
    else if (m_effect == CardType::Treasure){
        player.addCoins(m_stats.loot);
    }
}

void Card::printInfo() const{
    if(m_effect==CardType::Battle){
        printBattleCardInfo( m_stats);
    }
    else if(m_effect == CardType::Heal ){
        printHealCardInfo(m_stats);
    }
    else if( m_effect == CardType::Buff){
        printBuffCardInfo(m_stats);
    }
    else if (m_effect == CardType::Treasure){
        printTreasureCardInfo(m_stats);
    }
}