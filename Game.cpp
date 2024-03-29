#include <cstdlib>
#include <iostream>
#include "Game.hpp"
#include "TileElement.hpp"
#include "Entity.hpp"
#include "beginning.hpp"
#include "keyboard.hpp"


Game::Game(){
    this->boardHeight = 15;
    this->boardWidth = 60;

    this->player = Player(1, 1, 100, 100, 5, 100);
    this->player.currentArmor = new Armor ("Casque", 1);
    this->player.currentWeapon = new Weapon ("Epee", 15);
    board = createMap(boardHeight,boardWidth );
    monsters = new Monster**[boardHeight];
    for (int i = 0; i < boardHeight; i++){
        monsters[i] = new Monster*[boardWidth];
        for (int j = 0; j < boardWidth; j++){
            monsters[i][j] = nullptr;
        }
    }
    monsters[3][5] = new Monster (10, 10 , 30, 30, 5);
    monsters[1][19] = new Monster (10, 10 , 30, 30, 5);
    monsters[7][11] = new Monster (10, 10 , 30, 30, 5);
    monsters[8][18] = new Monster (10, 10 , 30, 30, 5);
    monsters[9][45] = new Monster (10, 10 , 30, 30, 5);
    monsters[14][47] = new Monster (10, 10 , 30, 30, 5);

    this->explored = new bool*[this->boardHeight];
    for (int i = 0; i < this->boardHeight;i++){
        this->explored[i] = new bool[this->boardWidth];
        for (int j = 0; j < this->boardWidth; j++){
            this->explored[i][j] = false;
        }
    }
};
/*
    board = new TileElement*[this->boardHeight];
    for (int i = 0; i < boardHeight; i++){
        board[i] = new TileElement[this->boardWidth];
        for (int j = 0; j < this->boardWidth; j++){
            this->explored[i][j] = false;
        }
    }
}*/

Game::~Game(){
    for (int i = 0; i < boardHeight; i++){
        delete[] this->board[i];
        delete[] this->explored[i];
    }
    delete[] this->board;
    delete[] this->explored;
}

void Game::draw(){
    std::system("clear"); // nettoyage du terminal
    // On print les elements un par un 
    for (int i = 0; i < this->boardHeight; i++){
        for (int j = 0; j < this->boardWidth; j++){
            // Sur la case du joueur on print @ et non le terrain
            if (i == this->player.y && j == this->player.x){
                std::cout << "\033[91m@\033[0m";
            } 
            else if (monsters[i][j] != nullptr){
                if (this->explored[i][j]){
                    std::cout << 'M';
                }
                else{
                    std::cout<<' ';
                }
            }
            else {
                if (this->explored[i][j]){
                    std::cout << this->board[i][j].printElement();
                }
                else{
                    std::cout<<' ';
                }
                
            }
        }
        std::cout << std::endl;
    }

    //Affichage des PV, OR, nourriture etc...
    std::cout << "HP : " << this->player.health << "/" << this->player.healthLimit << endl;
    std::cout << "Strength : " << this->player.strength << endl;
    std::cout << "Stamina : " << this->player.stamina << endl;
}

void Game::print_inventory(){
    std::cout << "Current weapon :" << (this->player).currentWeapon->printElement() << ", damage : " << (this->player).currentWeapon->damage << endl;
    std::cout << "Current armor :" << (this->player).currentArmor->printElement() << ", protection : " << (this->player).currentArmor->protection << endl;
    std::cout << "Inventory :" << endl;
    for (int i = 0; i < this->player.objectsNumber; i++){
        std::cout << i+1 << this->player.inventory[i]->printElement() << endl;
    }
}

void Game::update(){
    draw();
    print_inventory();
    char key;
    if (keyEventBlocking()){
        std::cin >> key;
        if (key == 'z' || key == 'q' || key == 's' || key == 'd'){
            cout << "moving hero" << endl;
            if (key == 'z' && this->player.y > 0){
                if (board[this->player.y - 1][this->player.x].printElement() != '|'){
                    this->player.y--;
                }
            }
            else if (key == 's' && this->player.y < this->boardHeight-1){
                if (board[this->player.y + 1][this->player.x].printElement() != '|'){
                    this->player.y++;
                }
            }
            else if (key == 'q' && this->player.x > 0){
                if (board[this->player.y][this->player.x - 1].printElement() != '|'){
                    this->player.x--;
                }
            }
            else if (key == 'd' && this->player.x < this->boardWidth-1){
                if (board[this->player.y][this->player.x + 1].printElement() != '|'){
                    this->player.x++;
                }
            }
            
        }
        if (monsters[this->player.y][this->player.x+1] != nullptr){
            monsters[this->player.y][this->player.x+1]->hit(&this->player);
            (&this->player)->hit(monsters[this->player.y][this->player.x+1]);
        }
        if (monsters[this->player.y][this->player.x-1] != nullptr){
            monsters[this->player.y][this->player.x-1]->hit(&this->player);
            (&this->player)->hit(monsters[this->player.y][this->player.x-1]);
        }
        if (monsters[this->player.y+1][this->player.x] != nullptr){
            monsters[this->player.y+1][this->player.x]->hit(&this->player);
            (&this->player)->hit(monsters[this->player.y+1][this->player.x]);
        }
        if (monsters[this->player.y-1][this->player.x] != nullptr){
            monsters[this->player.y-1][this->player.x]->hit(&this->player);
            (&this->player)->hit(monsters[this->player.y-1][this->player.x]);
        }
        // updating explored zone
        int radius = 2;
        for (int dx = -radius; dx <= radius; dx++){
            for (int dy = -radius; dy <= radius; dy++){
                int x2, y2;
                x2 = this->player.x + dx;
                y2 = this->player.y + dy;
                if (0 <= x2 && x2 < this->boardWidth
                    && 0 <= y2 && y2 < this->boardHeight){
                    this->explored[y2][x2] = true;
                }
            }
        }
             
        }
    }