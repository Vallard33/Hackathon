#include "TileElement.hpp"

char TileElement :: printElement(){
    return rep;
}

Potion :: Potion(string s, int n){
    rep = 'j';
    name = s;
    heal = n;
}

Gold :: Gold(string s, int n){
    rep = '*';
    value = n;
    name = s;
}

Weapon :: Weapon(string s, int n){
    rep = '!';
    damage = n;
    name = s;
}

Armor :: Armor(string s, int n){
    rep = 'a';
    name = s;
    protection = n;
}

Food :: Food(string s, int n){
    rep = 'f';
    name = s;
    staminaPoints = n;
}