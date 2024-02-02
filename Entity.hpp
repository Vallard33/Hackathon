#ifndef __ENTITY_H
#define __ENTITY_H

#include "TileElement.hpp"

const int INVENTORY_CAPACITY;

class Entity
{
protected:
    int x;
    int y;
    int healthLimit;
    int health;
    int strength;

public:
    Entity(int initialX, int initialY, int initialHealthLimit, int initialHealth, int initialStrength)
        : x(initialX), y(initialY), healthLimit(initialHealthLimit), health(initialHealth), strength(initialStrength) {}

    void updatePosition(int newPosx , int newPosy);
};


class Player : public Entity
{
    int objectsNumber;
    Object** inventory;
    Object* currentWeapon; // TODO : Replace Object by good type // None if no weapon
    Object* currentArmor; // TODO : Replace Object by good type // None if no armor
    int stamina; // Low if the player is exhausted, he has to eat in this case

public :
    Player(int posx, int posy, int healthLimitPlayer, int healthPlayer, int strengthPlayer, int staminaPlayer)
        : Entity(posx, posy, healthLimitPlayer, healthPlayer, strengthPlayer), objectsNumber(0), currentWeapon(nullptr), currentArmor(nullptr), stamina(staminaPlayer)
    {
        // Allocate memory for the inventory array
        inventory = new Object*[INVENTORY_CAPACITY];
        for (int i = 0; i < INVENTORY_CAPACITY; ++i) {
            inventory[i] = nullptr; // Initialize each element to nullptr
        }
    }
};

class Monster : public Entity
{
    Monster(int posx , int posy , int healthLimitMonster , int healthMonster , int strengthMonster)
        : Entity(posx, posy, healthLimitMonster, healthMonster, strengthMonster) {}
};

#endif