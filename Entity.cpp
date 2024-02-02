#include "Entity.hpp"

void Entity::updatePosition(int newPosx, int newPosy)
{
    x = newPosx;
    y = newPosy;
}

void Entity::updateHeal(int damage)
{
    if (damage < health)
    {
        health = health - damage;
    }
    else
    {
        health = 0;
    }
}

int Entity::damages()
{
    return strength;
}

int Player::damages()
{
    if (currentWeapon == nullptr)
    {
        return strength;
    }
    return currentWeapon->damage + strength;
}

void Player::hit(Monster* enemy)
{
    enemy->updateHeal(damages());
}

int Monster::damages(Player* thePlayer)
{
    if (thePlayer->currentArmor == nullptr)
    {
        return strength;
    }
    return strength - thePlayer->currentArmor->protection;
}

void Monster::hit(Player* enemy)
{
    enemy->updateHeal(damages(enemy));
}