#include "Game.h"
#include <thread>

Game::Game(){
    option = 0;
    playing = true;
    thinking = false;
    //some code
}

void Game::mainMenu() {
    cout << "===============================\n";
    cout << "Main menu" << endl;
    cout << "===============================\n";
    cout << "1. Start" << endl;
    cout << "0. Quit" << endl;
    cout << "===============================\n" << endl;

    cout << "Choose option: \n";
    cin >> option;
    switch (option) {
        case 0: playing = false; break;
        case 1: {
            startGame();
            playMenu();
        };
        default: break;

    }
}

void Game::playMenu(){

    while (option != 0) {
        cout << "===============================\n";
        cout << "Play menu" << endl;
        cout << "===============================\n";
        cout << "1. Explore" << endl;
        cout << "2. Show stats" << endl;
        cout << "0. Quit" << endl;
        cout << "===============================\n" << endl;
        cout << "Choose option: \n";
        cin >> option;
        switch (option) {
            case 0:
                mainMenu();
                break;
            case 1:
                exploreMenu();
                break;
            case 2: {
                showStats();
                break;
            }
            default:
                break;

        }
    }
}

void Game::exploreMenu(){

    while (option != 0) {
        cout << "===============================\n";
        cout << "Explore menu" << endl;
        cout << "===============================\n";
        cout << enemy.showStats() + "\n";
        cout << "1. Fight" << endl;
        cout << "2. Rest (heal HP)" << endl;
        cout << "0. Go back" << endl << endl;
        setThinking(true);
        makeItHappen();
        cout << "Choose option: \n";
        cin >> option;
        switch (option) {
            case 0:
                option = 5;
                playMenu();
                break;
            case 1: {
                fight();
                fightLog();
                character.gainExp(5);
                getItem();
                checkIfAlive();
                break;
            }
            case 2:{
                heal();
                break;
            }
            default:
                break;
        }
        setThinking(false);
        Game::thought.join();
    }
}


void Game::startGame(){
    cout << "Enter your name: \n";
    string name;
    cin >> name;
    character.initialize(name);
}

void Game::getItem(){
    Item item;
    character.setItem(*item.createItem("Sword",1));
}

void Game::fight(){
    character.setHp(character.getHp()-enemy.getAtk());
    enemy.setHp(enemy.getHp()-character.getAtk());
}
void Game::fightLog(){
    if(enemy.getHp() > 0){
        cout << "\n===============================\n";
        cout << "You have suffered " << enemy.getAtk() << " damage!\n";
        cout << "You have dealt " << character.getAtk() << " damage!\n";
        cout << "Enemy HP: " << enemy.getHp() << " / " << enemy.getMaxHp() << "\n";
        cout << "Your HP: " << character.getHp() << " / " << character.getMaxHp() << "\n";
    }
    else{
        cout << "\n===============================\n";
        cout << "You have killed an enemy!\n";
        cout << "Your HP: " << character.getHp() << " / " << character.getMaxHp() << "\n";
        enemy.enemyChange();
        enemy.levelUp(character.getLevel());
    }
}

void Game::showStats(){
    cout << character.showStats();
}

void Game::checkIfAlive(){
    if(character.getHp() <= 0){
        cout << "\n\n\n\nGame over. RIP dat pussy!\n\n\n\n";
        setPlaying(false);
        option = 0;
    }
}

int Game::getOption() const{
    return option;
}

void Game::heal(){
    cout << "You have healed for " << character.getMaxHp() - character.getHp() << " HP\n";
    character.setHp(character.getMaxHp());
    cout << "HP: " << character.getHp() << "\n";
}

bool Game::isPlaying() const {
    return playing;
}

void Game::setPlaying(bool playing) {
    Game::playing = playing;
}

void Game::randomThought() {
    using namespace std::literals::chrono_literals;
    while(thinking){
        random = 1 + rand() % 5; // NOLINT(cert-msc30-c, cert-msc50-cpp)
        switch (random) {
            case 1: cout << "\nWhat to do, what to do?\n"; break;
            case 2: cout << "\nHm, what to eat after that?\n"; break;
            case 3: cout << "\nHey you, yes, don't sleep!\n"; break;
            case 4: cout << "\nI haven't slept for ages!\n"; break;
            case 5: cout << "\nWhat will you do, player?\n"; break;
            default: break;
        }
        std::this_thread::sleep_for(20s);
    }
}

bool Game::isThinking() const {
    return thinking;
}

void Game::setThinking(bool thinking) {
    Game::thinking = thinking;
}

