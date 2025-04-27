#include "Mur.h"

Mur::Mur(bool co) : Piece(co)
{
    type = mur;
}

bool Mur::coupValide(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, const Echiquier &echiquier) const
{
    

    return (echiquier.estDansEchiquier(x_coup, y_coup) && (!echiquier.presencePiece(x_coup, y_coup)));
}
