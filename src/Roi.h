#ifndef ECHEC_ROI_H
#define ECHEC_ROI_H

#include "Echiquier.h"
#include "Piece.h"


class Roi: public Piece {
    public:
        Roi(bool co);

        
        bool coupValide(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, const Echiquier& echiquier) const override;
        
};


#endif
