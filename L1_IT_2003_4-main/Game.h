#include <iostream>
using namespace std;
#include <string>
#include "Character.h"
#include "Enemy.h"
#include <thread>

class Game {
public:
    Game();
    void mainMenu();
    int getOption() const;
    bool isPlaying() const;
    void playMenu();
    void setPlaying(bool playing);
    void makeItHappen(){
        thought = std::thread(&Game::randomThought, this);
    }

    bool isThinking() const;

    void setThinking(bool thinking);

private:
    int option; //choice of player
    bool playing; //if player is playing game?
    bool thinking;
    int random;
    Character character;
    Enemy enemy;

    void showStats();

    void randomThought();

    std::thread thought;

    void startGame();

    void exploreMenu();

    void getItem();

    void fight();

    void fightLog();

    void heal();

    void checkIfAlive();
};
