#ifndef __GAME_H
#define __GAME_H

#include <vector>
#include "TileElement.hpp"
#include "Entity.hpp"

class Game{
    public:
        int boardWidth;
        int boardHeight;
        TileElement** board;
        std::vector<Monster> monsters;
        Player player;

        Game();
        ~Game();
        void update();
        void draw();
};

#endif