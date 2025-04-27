#include "Piece.h"

Piece::Piece(bool co) : couleur(co) {}

bool Piece::coupValide(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, const Echiquier &echiquier) const
{
    return 1;
}

bool Piece::getCouleur() const
{
    return couleur;
}

TypePiece Piece::getType() const
{
    return type;
}

void Piece::changercouleur()
{
    couleur = !couleur;
}