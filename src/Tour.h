#ifndef ECHEC_TOUR_H
#define ECHEC_TOUR_H

#include "Echiquier.h"
#include "Piece.h"


class Tour: public Piece {

    public:
        Tour(bool co);
        bool coupValide(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, const Echiquier& echiquier)const;
};


#endif
