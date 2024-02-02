#include <cstdlib>
#include <iostream>

#include "Game.hpp"
#include "TileElement.hpp"
#include "Entity.hpp"
#include "keyboard.hpp"


Game::Game(){
    this->player = Player(40,20,0,0,0,0);
    this->boardHeight = 40;
    this->boardWidth = 80;
    board = new TileElement*[this->boardHeight];
    for (int i = 0; i < boardHeight; i++){
        board[i] = new TileElement[this->boardWidth];
        for (int j = 0; j < this->boardWidth; j++){
            this->board[i][j] = Empty();
        }
    
    }
    for (int i  = 0; i < boardHeight; i++){
        this->board[i][20] = Wall();
    }
}

Game::~Game(){
    for (int i = 0; i < boardHeight; i++){
        delete[] this->board[i];
    }
    delete[] this->board;
}

void Game::draw(){
    std::system("clear"); // nettoyage du terminal
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

void Game::update(){
    draw();
    char key;
    if (keyEventBlocking()){
        std::cin >> key;
        if (key == 'z' || key == 'q' || key == 's' || key == 'd'){
            cout << "moving hero" << endl;
            if (key == 'z'){
                if (board[this->player.y - 1][this->player.x].printElement() != '|'){
                    this->player.y--;
                }
            }
            else if (key == 's'){
                if (board[this->player.y + 1][this->player.x].printElement() != '|'){
                    this->player.y++;
                }
            }
            else if (key == 'q'){
                if (board[this->player.y][this->player.x - 1].printElement() != '|'){
                    this->player.x--;
                }
            }
            else if (key == 'd'){
                if (board[this->player.y][this->player.x + 1].printElement() != '|'){
                    this->player.x++;
                }
            }
        }
        draw();
    }
}