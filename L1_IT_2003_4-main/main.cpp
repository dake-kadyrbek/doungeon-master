//Develop text-based RPG game:
//Classes:
//Character: name, HP, maxHP, Atk, Level, exp
//Enemy:
//Game: mainMenu(), int option (for menu), bool playing
//#include <iostream>'
//using namespace foo;
//using namespace boo;
#include "Game.h"
//static bool is_Finished = false;
//
//void randomThought(){
//    using namespace std::literals::chrono_literals;
//
//    while(!is_Finished){
//        switch (rand() % 5 + 1) {
//            case 1: cout << "\nWhat to do, what to do?\n"; break;
//            case 2: cout << "\nHm, what to eat after that?\n"; break;
//            case 3: cout << "\nHey you, yes, don't sleep!\n"; break;
//            case 4: cout << "\nI haven't slept for ages!\n"; break;
//            case 5: cout << "\nWhat will you do, player?\n"; break;
//            default: break;
//        }
//        std::this_thread::sleep_for(5s);
//    }
//}


int main() {
    Game game;
//    std::thread thought(randomThought);
    while (game.isPlaying()) {
        game.mainMenu();
    }
//    is_Finished = true;
//    thought.join();

    return 0;
}
