#include "Roi.h"

Roi::Roi(bool co):Piece(co){
    type = roi;
}

bool Roi::coupValide(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, const Echiquier& echiquier) const {
    //Roque 
    //En passant
    
    return (echiquier.estDansEchiquier(x_coup, y_coup) && (((x_coup - x_actuel) * (x_coup - x_actuel)) <= 1) && (((y_coup - y_actuel) * (y_coup - y_actuel)) <= 1));

}



