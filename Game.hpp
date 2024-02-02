#ifndef __GAME_H
#define __GAME_H

#include <vector>
#include "TileElement.hpp"
#include "Entity.hpp"
#include "beginning.hpp"

class Game{
    public:
        int boardWidth;
        int boardHeight;
        TileElement** board;
        bool** explored;
        std::vector<Monster> monsters;
        Player player;
        Monster*** monsters;

        Game();
        ~Game();
        void update();
        void draw();
        void print_inventory();
};

#endif