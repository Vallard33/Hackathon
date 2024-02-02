#include <cstdlib>
#include <iostream>

#include "Game.hpp"
#include "TileElement.hpp"
#include "Entity.hpp"


Game::Game(){
    this->boardHeight = 40;
    this->boardWidth = 80;
    board = new TileElement*[this->boardHeight];
    for (int i = 0; i < boardHeight; i++){
        board[i] = new TileElement[this->boardWidth];
        for (int j = 0; j < this->boardWidth; j++){
            this->board[i][j] = Empty();
        }
    }
}

Game::~Game(){
    for (int i = 0; i < boardHeight; i++){
        delete[] this->board[i];
    }
    delete[] this->board;
}

void Game::draw(){
    // std::system("clear"); // nettoyage du terminal
    // On print les elements un par un 
    for (int i = 0; i < this->boardHeight; i++){
        for (int j = 0; j < this->boardWidth; j++){
            // Sur la case du joueur on print @ et non le terrain
            if (i == this->player.y && j == this->player.x){
                std::cout << '@';
            } else {
                std::cout << this->board[i][j].printElement();
            }
        }
        std::cout << std::endl;
    }
}