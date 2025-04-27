#include "Cavalier.h"



Cavalier::Cavalier(bool co):Piece(co){
    type = cavalier;
}

bool Cavalier::coupValide(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, const Echiquier& echiquier) const{

    return (echiquier.estDansEchiquier(x_coup, y_coup) &&
            ((((x_coup-x_actuel)*(x_coup-x_actuel))==4 && ((y_coup-y_actuel)*(y_coup-y_actuel))==1) ||
    ((((x_coup-x_actuel)*(x_coup-x_actuel))==1 && ((y_coup-y_actuel)*(y_coup-y_actuel)==4) ))));
}