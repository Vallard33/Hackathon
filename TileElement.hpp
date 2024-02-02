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
public :
    Wall();
};
class Empty: public Terrain{
public :
    Empty ();
};
class Door: public Terrain{
public :
    Door ();
};
class Corridor: public Terrain{
public :
    Corridor ();
};
class Stairs: public Terrain{
public :
    Stairs ();
};

class Object: public TileElement{
public :
    string name;
    Object(){};
    ~Object(){};
};

class Potion : public Object{
public :
    int heal; 
    Potion(string s, int n);
};

class Gold : public Object{
public :
    int value;
    Gold(string s, int n);
};

class Weapon : public Object{
public :
    int damage;
    Weapon(string s, int n);
};

class Armor : public Object{
public :
    int protection;
    Armor(string s, int n);
};

class Food : public Object{
public :
    int staminaPoints;
    Food(string s, int n);
};


#endif