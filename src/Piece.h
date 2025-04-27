#ifndef _PIECE_
#define _PIECE_

class Echiquier;

enum TypePiece
{
    pion,
    fou,
    cavalier,
    tour,
    dame,
    roi,
    mur,
    vide
};
typedef short int entier;

class Piece
{
public:
    bool couleur;
    TypePiece type;

    Piece(bool co);
    virtual bool coupValide(entier x_actuel, entier y_actuel, entier x_coup, entier y_coup, const Echiquier &echiquier) const;
    bool getCouleur() const;
    TypePiece getType() const;
    void changercouleur();
};

#endif