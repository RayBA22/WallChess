#include "Fou.h"


Fou::Fou(bool co):Piece(co){
    type = fou;
}

bool Fou::coupValide(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, const Echiquier& echiquier)const{

    return (echiquier.estDansEchiquier(x_coup, y_coup) &&
            echiquier.coupValideDiagonal(x_actuel, y_actuel, x_coup, y_coup));

        
}