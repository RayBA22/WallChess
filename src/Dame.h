#ifndef _DAME_
#define _DAME_


#include "Echiquier.h"
#include "Piece.h"


class Dame: public Piece
{
    public:

        Dame(bool co);
        bool coupValide(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, const Echiquier& echiquier) const override;
      
}; 





#endif