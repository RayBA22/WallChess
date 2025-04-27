#ifndef _IHMC_
#define _IHMC_

#include "Echiquier.h"
#include "Jeu.h"

#include <string>
#include <iostream>

using namespace std;

class IHM_console
{

public:
    string symbole[2][8] = {{"♙", "♗", "♘", "♖", "♕", "♔", "□", " "}, {"♟", "♝", "♞", "♜", "♛", "♚", "■", " "}};
    Jeu jeu;

    void afficherEchiquier() const;
    void boucleJeu();
};

#endif