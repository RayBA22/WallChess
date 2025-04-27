#ifndef ECHEC_CAVALIER_H
#define ECHEC_CAVALIER_H

#include "Echiquier.h"
#include "Piece.h"


class Cavalier: public Piece {
    public:
        
        Cavalier(bool co);
        bool coupValide(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, const Echiquier& echiquier) const override;
};


#endif
