#ifndef ECHEC_JEU_H
#define ECHEC_JEU_H

#include "Echiquier.h"

class Jeu
{
public:
    // verifie apres chaque tour si il y a un echec et mat
    Echiquier echiquier;
    bool couleur;
    int nbtour, joker[2];


    Jeu();
    void initialisation(bool nouvelle_partie);
    bool echecEtMat() const;
    void changerCouleur();
    bool getCouleur();
    void jouer_coup();
    entier get_xRoi(bool co) const;
    entier get_yRoi(bool co) const;
    bool getCouleurPiece(entier x, entier y) const;
    TypePiece getTypePiece(entier x, entier y) const;
    bool presencePiece(entier x, entier y) const;
    bool coup(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup);
    bool coupMur(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup);
    bool estMur(entier x, entier y) const;

    bool mortRoi()const;
    void retour();
    void sauver();

    void coupAI();
};

#endif
