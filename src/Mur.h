#ifndef _MUR_
#define _MUR_

#include "Piece.h"
#include "Echiquier.h"

class Mur : public Piece
{

public:
    Mur(bool co);
    bool coupValide(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, const Echiquier &echiquier) const;
};

#endif