#ifndef __GAME_H
#define __GAME_H

#include <vector>
#include "TileElement.hpp"

class Game{
    int boardWidth;
    int boardHeight;
    TileElement** board;
    vector<Monster> monsters;
    Player player;

    Game();
    ~Game();
    void update();
    void draw();
};

#endif