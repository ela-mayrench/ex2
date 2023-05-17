#include <string>

class Player
{
private:
    std::string name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_FORCE = 5;
    
public:
    Player(std::string name,int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);//constructor

    ~Player() = default; //distructor
    Player(const Player &) = default; //copy constructor
    Player & operator=(const Player &) = default; //operator = 

    void printInfo();

    void levelUp();

    int getLevel() const;

    void buff(int num);

    void heal(int num);

    void damage(int num);

    bool isKnockedOut();

    void addCoins(int num);

    bool pay(int num);

    int getAttackStrength();
};

