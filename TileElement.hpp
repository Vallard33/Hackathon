#ifndef __TILEELEMENT_H
#define __TILEELEMENT_H

#include <iostream>
#include <string>
using namespace std;


class TileElement{
protected :
    char rep;
public :
    char printElement ();
    TileElement(){};
    ~TileElement(){};
};

class Terrain: public TileElement{
};
class Wall: public Terrain{
    Wall();
};
class Empty: public Terrain{
    public:
        Empty ();
};
class Door: public Terrain{
    Door ();
};
class Corridor: public Terrain{
    Corridor ();
};
class Stairs: public Terrain{
    Stairs ();
};

class Object: public TileElement{
protected :
    string name;
public :
    Object(){};
    ~Object(){};
};

class Potion : public Object{
    int heal; 
    Potion(string s, int n);
};

class Gold : public Object{
    int value;
    Gold(string s, int n);
};

class Weapon : public Object{
    int damage;
    Weapon(string s, int n);
};

class Armor : public Object{
    int protection;
    Armor(string s, int n);
};

class Food : public Object{
    int staminaPoints;
    Food(string s, int n);
};




#endif