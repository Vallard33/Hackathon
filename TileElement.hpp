#ifndef __TILEELEMENT_H
#define __TILEELEMENT_H

#include <iostream>

class TileElement{
protected :
    char rep;
public :
    char printElement ();
};

class Terrain: TileElement{
};

class Object: TileElement{
};



#endif