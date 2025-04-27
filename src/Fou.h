#ifndef ECHEC_FOU_H
#define ECHEC_FOU_H

#include "Echiquier.h"
#include "Piece.h"


class Fou: public Piece {
    public:
        Fou(bool co);
        bool coupValide(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, const Echiquier& echiquier)const;



};
#endif
