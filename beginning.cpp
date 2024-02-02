#include "TileElement.hpp";
#include "Entity.hpp";
#include <fstream>;
#include <iostream>;
#include <map>;

using namespace std;

TileElement* createLigne (string contenu, int colonnes) {
    std::map<char, TileElement> dico;
    TileElement* ligne = new TileElement[colonnes];
    dico["."]=Empty();
    dico['|']=Wall();
    dico['+']=Door();
    dico['#']=Corridor();
    dico['=']=Stairs();
    for (int i = 0; i<colonnes; i++) {
        char c = contenu[i];
        ligne[i] = dico[c];
    };
    return ligne;
}

TileElement** createMap () {
    int colonnes = 10;
    int lignes = 10;
    TileElement** map = new TileElement*[lignes];
    ifstream fichier("map.txt", ios::in);
    if(fichier) { //Pour vérifier si l'ouverture à fonctionner
        for (int i = 0; i < lignes; i++){
        string contenu;
        getline(fichier, contenu);
        map[i] = createLigne (contenu, colonnes);
        return map;
        fichier.close();
        }
    }
        else {
                cerr << "Impossible d'ouvrir le fichier !" << endl;
    } 
}

