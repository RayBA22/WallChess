#ifndef ECHEC_PION_H
#define ECHEC_PION_H

#include "Piece.h"
#include "Echiquier.h"

class Pion :public Piece {

    public:
        Pion(bool co);
        bool coupValide(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, const Echiquier& echiquier)const;

};


#endif
