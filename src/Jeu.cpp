#include "Jeu.h"

Jeu::Jeu()
{
    couleur = false;
    nbtour = 0;
    joker[0] = 3;
    joker[1] = 3;
}

void Jeu::initialisation(bool nouvelle_partie)
{
    couleur = echiquier.initialisation(nouvelle_partie);

}

void Jeu::changerCouleur()
{
    couleur = !couleur;
    echiquier.changercouleurMur();
}

bool Jeu::echecEtMat() const
{
    return 1;
}

entier Jeu::get_xRoi(bool co) const
{
    return echiquier.getXRoi(co);
}
entier Jeu::get_yRoi(bool co) const
{
    return echiquier.getYRoi(co);
}
bool Jeu::getCouleurPiece(entier x, entier y) const
{

    return echiquier.getCouleurPiece(x, y);
}
TypePiece Jeu::getTypePiece(entier x, entier y) const
{
    return echiquier.getTypePiece(x, y);
}

bool Jeu::presencePiece(entier x, entier y) const
{

    return echiquier.presencePiece(x, y);
}

bool Jeu::coup(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup)
{
    return echiquier.coup(x_actuel, y_actuel, x_coup, y_coup, couleur);
}

bool Jeu::coupMur(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup)
{

    return echiquier.coupMur(x_actuel, y_actuel, x_coup, y_coup, couleur);
}



bool Jeu::mortRoi()const{
    return echiquier.mortRoi(!couleur);
}

void Jeu::retour(){
    
    if (joker[couleur] > 0)

        echiquier.retour();
        joker[couleur] --;
}

void Jeu::coupAI(){ 
    if (couleur)
        echiquier.coupAI(couleur);
}

bool Jeu::getCouleur(){

    return couleur;
}

void Jeu::sauver(){
    echiquier.sauver();
}

bool Jeu::estMur(entier x, entier y) const {
    return echiquier.estMur(x,y);
}

