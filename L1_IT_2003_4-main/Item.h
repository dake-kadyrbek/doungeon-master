#include <iostream>
using namespace std;
#include <string>


class Item {
public:
    Item();
    Item * createItem(string name, int atk);

    const string &getName() const;

    void setName(const string &name);

    int getAtk() const;

    void setAtk(int atk);

    int getHp() const;

    void setHp(int hp);

private:
    string name;
    int atk;
    int HP;
};

