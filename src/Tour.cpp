#include "Tour.h"

Tour::Tour(bool co):Piece(co){
    type = tour;
}

bool Tour::coupValide(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, const Echiquier& echiquier)const{

    return (
        (echiquier.coupValideHorizontal(x_actuel, y_actuel, x_coup, y_coup) ||
         echiquier.coupValideVertical(x_actuel, y_actuel, x_coup, y_coup)));
}

