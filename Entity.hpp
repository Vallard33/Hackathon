#ifndef __ENTITY_H
#define __ENTITY_H

#include "TileElement.hpp"

const int INVENTORY_CAPACITY = 10;

class Entity
{
public:
    int x;
    int y;
    int healthLimit;
    int health;
    int strength;

    Entity(){};
    Entity(int initialX, int initialY, int initialHealthLimit, int initialHealth, int initialStrength)
        : x(initialX), y(initialY), healthLimit(initialHealthLimit), health(initialHealth), strength(initialStrength) {}

    void updatePosition(int newPosx , int newPosy);
    void updateHeal(int damage);

    virtual int damages();
    virtual void hit(Entity* ennemy){};
};


class Player : public Entity
{
public:
    int objectsNumber;
    Object** inventory;
    Weapon* currentWeapon; // None if no weapon
    Armor* currentArmor; // None if no armor
    int stamina; // Low if the player is exhausted, he has to eat in this case

    Player(){};
    Player(int posx, int posy, int healthLimitPlayer, int healthPlayer, int strengthPlayer, int staminaPlayer)
        : Entity(posx, posy, healthLimitPlayer, healthPlayer, strengthPlayer), objectsNumber(0), currentWeapon(nullptr), currentArmor(nullptr), stamina(staminaPlayer)
    {
        // Allocate memory for the inventory array
        inventory = new Object*[INVENTORY_CAPACITY];
        for (int i = 0; i < INVENTORY_CAPACITY; ++i) {
            inventory[i] = nullptr; // Initialize each element to nullptr
        }
    }
    ~Player()
    {
        delete[] inventory;
    };

    int damages();
    void hit(Monster* ennemy);
};

class Monster : public Entity
{
public:
    Monster(){};
    Monster(int posx , int posy , int healthLimitMonster , int healthMonster , int strengthMonster)
        : Entity(posx, posy, healthLimitMonster, healthMonster, strengthMonster) {};

    int damages(Player* thePlayer);
    void hit(Player* ennemy);
};

#endif