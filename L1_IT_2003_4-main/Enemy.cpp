#include "Enemy.h"

Enemy::Enemy() {
    random = rand() % 3 + 1; // NOLINT(cert-msc30-c, cert-msc50-cpp)
    if ( random == 1 ){ //увеличивать статы от уровня героя
        name = "Zombie";
        HP = 10;
        maxHP = 10;
        atk = 2;
    }
    if ( random == 2 ){
        name = "Goblin";
        HP = 5;
        maxHP = 5;
        atk = 1;
    }
    if ( random == 3 ){
        name = "Skeleton";
        HP = 5;
        maxHP = 5;
        atk = 2;
    }
}

void Enemy::enemyChange() {
    random = rand() % 3 + 1; // NOLINT(cert-msc30-c, cert-msc50-cpp)
    if ( random == 1 ){
        name = "Zombie";
        HP = 10;
        maxHP = 10;
        atk = 2;
    }
    if ( random == 2 ){
        name = "Goblin";
        HP = 5;
        maxHP = 5;
        atk = 1;
    }
    if ( random == 3 ){
        name = "Skeleton";
        HP = 5 ;
        maxHP = 5;
        atk = 2;
    }
}

string Enemy::showStats(){

    string string1 = "Enemy: " + name + "\n" + "HP: " + to_string(HP) + "/" + to_string(maxHP) +
                     "\n" + "Attack Damage: " + to_string(atk) + "\n";

    return string1;

}

void Enemy::levelUp(int level){
    //условие что от левела будет апаться
    maxHP = maxHP + (3 * level);
    HP = maxHP;
    atk = atk + level;
}

int Enemy::getHp() const {
    return HP;
}

int Enemy::getMaxHp() const {
    return maxHP;
}

int Enemy::getAtk() const {
    return atk;
}

void Enemy::setHp(int hp) {
    HP = hp;
}
