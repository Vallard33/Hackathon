#ifndef __TILEELEMENT_H
#define __TILEELEMENT_H

#include <iostream>

class TileElement{
protected :
    char rep;
public :
    char printElement ();
};

class Terrain: public TileElement{
};

class Wall: Terrain{
    Wall();
};
class Empty: Terrain{
    Empty ();
};
class Door: Terrain{
    Door ();
};
class Corridor: Terrain{
    Corridor ();
};
class Stairs: Terrain{
    Stairs ();
};
class Object: public TileElement{
};



#endif