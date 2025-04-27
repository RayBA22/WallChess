
#include "Echiquier.h"
#include "Pion.h"
#include "Tour.h"
#include "Fou.h"
#include "Cavalier.h"
#include "Dame.h"
#include "Roi.h"
#include "Mur.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Echiquier::Echiquier()
{

    for (entier i = 0; i < 8; i++)
        for (entier j = 0; j < 8; j++)
            plateau[i][j] = nullptr;

    for (entier i = 0; i < 2; i++)
        for (entier j = 0; j < 6; j++)
            prise[i][j] = 0;
}

Echiquier::~Echiquier()
{
    detruire();
}

void Echiquier::detruire()
{
    for (entier i = 0; i < 8; i++)
        for (entier j = 0; j < 8; j++)
            if (presencePiece(i, j))
                delete plateau[i][j];
}

bool Echiquier::initialisation(bool nouvelle_partie) // a corriger (new utilisé plusieurs fois sur la meme piece)
{

    srand((unsigned int)(time(nullptr)));
    entier i, j;
    for (i = 0; i < 8; i++)
    {
        plateau[i][1] = new Pion(0);
        plateau[i][6] = new Pion(1);
    }

    for (i = 0; i < 8; i += 7)
        for (j = 0; j < 8; j += 7)
            plateau[i][j] = new Tour(j);

    for (i = 1; i < 8; i += 5)
        for (j = 0; j < 8; j += 7)
            plateau[i][j] = new Cavalier(j);

    for (i = 2; i < 6; i += 3)
        for (j = 0; j < 8; j += 7)
            plateau[i][j] = new Fou(j);

    for (j = 0; j < 8; j += 7)
    {
        plateau[3][j] = new Dame(j);
        plateau[4][j] = new Roi(j);
    }

    murEchiquier = new Mur(0);
    // plateau[rand() % 9][rand() % 2 + 2] = murEchiquier; // probzlemnt faux
    plateau[0][3] = murEchiquier;

    init(nouvelle_partie);

    return murEchiquier->getCouleur();
}

entier Echiquier::getXRoi(bool co) const
{
    if (co)
        return xRoi_noir;
    else
        return xRoi_blanc;
}

entier Echiquier::getYRoi(bool co) const
{
    if (co)
        return yRoi_noir;
    else
        return yRoi_blanc;
}

TypePiece Echiquier::getTypePiece(entier x, entier y) const
{
    if (presencePiece(x, y))
        return plateau[x][y]->getType();
    return vide;
}

bool Echiquier::getCouleurPiece(entier x, entier y) const
{
    return plateau[x][y]->getCouleur();
}

bool Echiquier::estDansEchiquier(entier x, entier y) const
{
    return ((x < 64 && x >= 0) && (y < 64 && y >= 0));
}

bool Echiquier::presencePiece(entier x, entier y) const
{

    return (plateau[x][y] != nullptr);
}

Piece *Echiquier::getPiece(entier x, entier y) const
{

    return plateau[x][y];
}

bool Echiquier::coupValideDiagonal(entier xActuel, entier yActuel, entier xCoup, entier yCoup) const
{

    if (((xActuel - xCoup) * (xActuel - xCoup)) != ((yActuel - yCoup) * (yActuel - yCoup)))
        return false;

    entier sensx, sensy;
    if (xActuel < xCoup)
        sensx = 1;
    else
        sensx = -1;
    if (yActuel < yCoup)
        sensy = 1;
    else
        sensy = -1;
    xActuel += sensx;
    yActuel += sensy;

    while ((xActuel != xCoup) && (yActuel != yCoup))
    {
        if (presencePiece(xActuel, yActuel))
            return false;

        xActuel += sensx;
        yActuel += sensy;
    }
    return true;
}

bool Echiquier::coupValideHorizontal(entier xActuel, entier yActuel, entier xCoup, entier yCoup) const
{

    if (yActuel != yCoup)
        return false;

    int sensx;
    if (xActuel < xCoup)
        sensx = 1;
    else
        sensx = -1;
    xActuel += sensx;
    while (xActuel != xCoup)
    {
        if (presencePiece(xActuel, yActuel))
            return false;

        xActuel += sensx;
    }
    return true;
}

bool Echiquier::coupValideVertical(entier xActuel, entier yActuel, entier xCoup, entier yCoup) const
{

    if (xActuel != xCoup)
        return false;

    int sensy;
    if (yActuel < yCoup)
        sensy = 1;
    else
        sensy = -1;
    yActuel += sensy;
    while (yActuel != yCoup)
    {
        if (presencePiece(xActuel, yActuel))
            return false;

        yActuel += sensy;
    }
    return true;
}

bool Echiquier::sontEnnemi(entier xP1, entier yP1, entier xP2, entier yP2) const
{
    return (plateau[xP1][yP1]->getCouleur() != plateau[xP2][yP2]->getCouleur());
}

bool Echiquier::estMur(entier x, entier y) const
{
    if (!presencePiece(x, y))
        return false;
    return (plateau[x][y]->getType() == mur);
}

bool Echiquier::coup(entier xActuel, entier yActuel, entier xCoup, entier yCoup, bool couleur)
{

    if (!presencePiece(xActuel, yActuel))
    {
        return false;
    }
    if (plateau[xActuel][yActuel]->getCouleur() != couleur)
    {
        return false;
    }

    if (estMur(xActuel, yActuel) || estMur(xCoup, yCoup))
    {

        return false;
    }

    if (!plateau[xActuel][yActuel]->coupValide(xActuel, yActuel, xCoup, yCoup, *this))
    {
        return false;
    }

    if (presencePiece(xCoup, yCoup))
    {

        if (sontEnnemi(xActuel, yActuel, xCoup, yCoup))
        {
            prise[plateau[xCoup][yCoup]->getCouleur()][plateau[xCoup][yCoup]->getType()]++;
            delete plateau[xCoup][yCoup];
            plateau[xCoup][yCoup] = plateau[xActuel][yActuel];
            plateau[xActuel][yActuel] = nullptr;
            // information sur la pièce prise revenir plus tard retourner l'ientifiant/type de la piece
            return true;
        }

        // condition du else ils st pas ennemi ptet faut renvoyer un msg
        else
        {

            return false;
        }
    }
    else
    {
        plateau[xCoup][yCoup] = plateau[xActuel][yActuel];
        plateau[xActuel][yActuel] = nullptr;
        return true;
    }

    return false;
}

void Echiquier::changercouleurMur()
{
    murEchiquier->changercouleur();
}

bool Echiquier::coupMur(entier xActuel, entier yActuel, entier xCoup, entier yCoup, bool co)
{

    if (presencePiece(xCoup, yCoup) || !estMur(xActuel, yActuel) || plateau[xActuel][yActuel]->getCouleur() != co)
        return false;

    plateau[xCoup][yCoup] = plateau[xActuel][yActuel];
    plateau[xActuel][yActuel] = nullptr;
    return true;
}

// y'a plus de roi en échec
bool Echiquier::roiEnEchec(entier xRoi, entier yRoi) const
{
    bool couleur_Roi = plateau[xRoi][yRoi]->getCouleur();
    for (entier i = 0; i < 8; i++)
        for (entier j = 0; j < 8; j++)
            if (presencePiece(i, j))
            {
                if ((plateau[i][j]->getCouleur() != couleur_Roi) && (plateau[i][j]->coupValide(i, j, xRoi, yRoi, *this)))
                {
                    return true;
                }
            }

    return false;
}

bool Echiquier::mortRoi(bool co) const
{

    return (prise[co][roi] > 0);
}

void Echiquier::sauver()
{

    // sauvegarde de l'echiquier
    ofstream save("../sauvegarde/save1.txt", ios::app);
    if (!save.is_open())
        cout << "echec" << endl;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (plateau[i][j] != nullptr)
                save << plateau[i][j]->getType() << " " << plateau[i][j]->getCouleur() << " ";
            else
                save << vide << " " << vide << " ";
        }
    }

    // sauvegarde de prise
    for (int j = 0; j < 6; j++)
    {

        save << prise[0][j] << " " << prise[1][j] << " ";
    }

    save << "\n";

    save.seekp(0, ios::end);
    save.close();
}

Piece *Echiquier::creerPiece(TypePiece type, bool co)
{

    switch (type)
    {
    case pion:
        return new Pion(co);
        break;

    case fou:
        return new Fou(co);
        break;

    case cavalier:
        return new Cavalier(co);
        break;

    case tour:
        return new Tour(co);
        break;

    case dame:
        return new Dame(co);
        break;

    case roi:
        return new Roi(co);
        break;

    case mur:
        return new Mur(co);
        break;

    default:
        return nullptr;
        break;
    }
}

void Echiquier::charger()
{

    detruire();

    int type;
    int co;

    ifstream save("../sauvegarde/save1.txt");

    if (!save.is_open())
        cout << "fichier pas ouvert" << endl;

    save.seekg(0, ios::end);
    streampos fileSize = save.tellg();
    streampos position = fileSize - (streampos)281;
    save.seekg(position);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {

            save >> type >> co;
            // cout <<  "les trucs: " << type << " " << co << endl;
            plateau[i][j] = creerPiece((TypePiece)type, (bool)co);
            if (type == mur)
            {
                cout << co << endl;
                murEchiquier = plateau[i][j];
            }
        }
    }

    for (int j = 0; j < 6; j++)
    {

        save >> prise[0][j] >> prise[1][j];
    }

    save.close();
}

void Echiquier::init(bool nouvelle_partie)
{
    ofstream save("../sauvegarde/save1.txt", ios::app);

    if (!save.is_open())
        cout << "nononon" << endl;

    save.seekp(0, ios::end);
    streampos longueur = save.tellp();

    if (longueur == 0 || nouvelle_partie)
    {

        ofstream file("../sauvegarde/save1.txt", std::ofstream::out | std::ofstream::trunc); // effacer le contenu
        sauver();
    }
    else
        charger();
}

void Echiquier::retour()
{
    int nb = 0;
    string lastLine, secondLastLine, line;

    ifstream save1("../sauvegarde/save1.txt");
    if (!save1.is_open())
    {
        cerr << "erreur dans le fichier de sauvegarde" << endl;
        return;
    }

    while (getline(save1, line))
    {
        secondLastLine = lastLine;
        lastLine = line;
        nb++;
    }

    save1.close();
    save1.open("../sauvegarde/save1.txt");

    if (nb <= 2)
    {
        cout << "il faut plus que deux partie pour utiliser le joker" << endl;
        return;
    }

    ofstream tempFile("../sauvegarde/temp.txt");
    if (!tempFile.is_open())
    {
        cout << "erreur dans le fichier temporaire " << endl;
        return;
    }

    while (getline(save1, line))
    {
        if (line != secondLastLine && line != lastLine)
        {
            tempFile << line << endl;
        }
    }

    save1.close();
    tempFile.close();

    if (remove("../sauvegarde/save1.txt") != 0)
    {
        cout << "erreur1" << endl;
        return;
    }

    if (rename("../sauvegarde/temp.txt", "../sauvegarde/save1.txt") != 0)
    {
        cout << "erreur2" << endl;
        return;
    }

    charger();
}

/**/
bool Echiquier::coupAI(bool co)
{
    int xA, yA, xC, yC, t;
    
    do
    {
        xA = rand() % 8;
        yA = rand() % 8;
        

        xC = rand() % 8;
        yC = rand() % 8;
    } while (!coup(xA, yA, xC, yC, co));


    do
    {
        xA = rand() % 8;
        yA = rand() % 8;


        xC = rand() % 8;
        yC = rand() % 8;

    } while (!coupMur(xA, yA, xC, yC, co));

    return true;
}