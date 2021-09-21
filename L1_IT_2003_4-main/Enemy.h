#include <string>
using namespace std;
class Enemy {
public:
    Enemy();
    string showStats();

    int getHp() const;

    int getAtk() const;

    void setHp(int hp);

    void enemyChange();

    int getMaxHp() const;

    void levelUp(int level);

private:
    string name;
    int HP;
    int maxHP;
    int atk;
    int random;
};
