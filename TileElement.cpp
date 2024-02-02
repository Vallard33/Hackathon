#include "TileElement.hpp"

char TileElement :: printElement(){
    return rep;
}

Wall::Wall (){
    rep = '|';
};

Empty::Empty (){
    rep = '.';
};

Door::Door (){
    rep = '+';
};

Corridor::Corridor (){
    rep = '#';
}

Stairs::Stairs (){
    rep = '=';
}