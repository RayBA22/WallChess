#ifndef ECHEC_IHM_GRAPHIQUE_H
#define ECHEC_IHM_GRAPHIQUE_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include "Jeu.h"


class IHM_Graphique {
private:
    Jeu jeu;
    bool IA;
    bool sauvegarde;

    float widthWindow;
    float heightWindow;
    float tailleEchiquier;
    float tailleCase;
    sf::Vector2f baseEchiquier;
    sf::RenderWindow *window;

    sf::Sprite echiquier;
    sf::Sprite* sprite;
    bool* statique;
    int n=-1;
    bool murJoue=true;
    bool coupJoue=false;
    bool sauver=false;

    sf::Texture damier;
    sf::Texture tourBlancTexture;
    sf::Texture chevalierBlancTexture;
    sf::Texture fouBlancTexture;
    sf::Texture roiBlancTexture;
    sf::Texture dameBlancTexture;
    sf::Texture pionBlancTexture;
    sf::Texture tourNoirTexture;
    sf::Texture chevalierNoirTexture;
    sf::Texture fouNoirTexture;
    sf::Texture roiNoirTexture;
    sf::Texture dameNoirTexture;
    sf::Texture pionNoirTexture;
    sf::Texture murTexture;

    sf::Music move;
    sf::Music illegal;
    sf::Music capture;
    sf::Music gameStart;
    sf::Music gameEnd;
    sf::Music moveCheck;
    sf::Music notify;
    sf::Music promote;
    sf::Music castle;
    sf::Music tenseconds;

    void chargerEchiquier();
    void chargerPieces();
    void configPiece(sf::Sprite &spr, sf::Texture& texture, float x, float y) const;
    void refreshSprite();
    void chargerMusique();
    void affichage();
public:
    IHM_Graphique(sf::RenderWindow& window, bool IA, bool sauvegarde);
    ~IHM_Graphique();
    void boucleJeu();


    //afficheEchiquier : setEchiquierVisible
    //initialisePieces : setPieceVisible



};


#endif
