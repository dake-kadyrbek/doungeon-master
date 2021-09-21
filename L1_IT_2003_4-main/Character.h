#include <iostream>
using namespace std;
#include <string>
#include "Item.h"
#include <thread>

class Character {
public:
    Character();
    void initialize(string name);
    void levelUp();
    string showStats();

    const Item &getItem() const;

    void setItem(const Item &item);
    void gainExp(int exp);

    int getHp() const;

    const string &getName() const;

    int getMaxHp() const;

    int getAtk() const;

    void setHp(int hp);

    int getLevel() const;

private:
    string name;
    int HP;
    int maxHP;
    int atk;
    int exp;
    int level;
    Item item;
};
