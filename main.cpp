#include <cstdlib>
#include "Game.hpp"


int main(){
    Game game;
    game.draw();

    while (true){
        game.update();
    }

    return 0;
}