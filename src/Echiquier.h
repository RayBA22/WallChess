
#ifndef _ECHIQUIER_
#define _ECHIQUIER_

#include "Piece.h"
#include <fstream>
#include <string>
#include <cstdio> 
using namespace std;


class Echiquier
{
public:
    entier xRoi_blanc, xRoi_noir, yRoi_blanc, yRoi_noir;
    // ptet un tab 2D pour les pieces mangées

    Piece *plateau[8][8], *murEchiquier;
    int prise[2][6];
    Echiquier();
    ~Echiquier();
    bool initialisation(bool nouvelle_partie);
    void init(bool nouvelle_partie);
    bool estDansEchiquier(entier x, entier y) const;
    bool presencePiece(entier x, entier y) const;
    Piece *getPiece(entier x, entier y) const;
    bool coupValideDiagonal(entier xActuel, entier yActuel, entier xCoup, entier yCoup) const;
    bool coupValideHorizontal(entier xActuel, entier yActuel, entier xCoup, entier yCoup) const;
    bool coupValideVertical(entier xActuel, entier yActuel, entier xCoup, entier yCoup) const;
    bool sontEnnemi(entier xP1, entier yP1, entier xP2, entier yP2) const;
    // changer peut etre le type pour indiquer quelle piece a été "mangée"
    bool coup(entier xActuel, entier yActuel, entier xCoup, entier yCoup, bool couleur);
    bool roiEnEchec(entier xRoi, entier yRoi) const;
    entier getXRoi(bool co) const;
    entier getYRoi(bool co) const;
    bool getCouleurPiece(entier x, entier y) const;
    TypePiece getTypePiece(entier x, entier y) const;

    bool estMur(entier x, entier y) const;
    bool coupMur(entier xActuel, entier yActuel, entier xCoup, entier yCoup, bool co);
    void changercouleurMur();

    bool mortRoi(bool co)const;


    Piece* creerPiece(TypePiece type, bool co);
    void sauver();
    void charger();
    void retour();
    void detruire();


    bool coupAI(bool co);
};

#endif