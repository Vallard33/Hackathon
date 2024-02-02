#include <fstream>
#include <iostream>
#include <map>
#include "TileElement.hpp"


using namespace std;

TileElement* createLigne (string contenu, int colonnes) {
    std::map<char, TileElement> dico;
    TileElement* ligne = new TileElement[colonnes];
    dico['.']=Empty();
    dico['|']=Wall();
    dico['+']=Door();
    dico['#']=Corridor();
    dico['=']=Stairs();
    for (int i = 0; i<colonnes; i++) {
        char c = contenu[i];
        ligne[i] = dico[c];
    };
    return ligne;
};

TileElement** createMap (int lignes, int colonnes) {
    TileElement** map = new TileElement*[lignes];
    ifstream fichier("map.txt", ios::in);
    if(fichier) { //Pour vérifier si l'ouverture à fonctionner
        for (int i = 0; i < lignes; i++){
            string contenu;
            getline(fichier, contenu);
            map[i] = createLigne (contenu, colonnes);
        }
        fichier.close();
        return map;
    }
        else {
                cerr << "Impossible d'ouvrir le fichier !" << endl;
                return 0;
    } 
};

