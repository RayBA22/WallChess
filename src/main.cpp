#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "SFML/Audio.hpp"
#include "IHM_Graphique.h"
#include "IHM_console.h"

using namespace std;



int main() {
        string titre = "Jeu d'echec";

        sf::RenderWindow window(sf::VideoMode(800, 800), titre, sf::Style::Default);
        window.setVerticalSyncEnabled(true);

        sf::Font police;
        police.loadFromFile("../assets/font.ttf");

        sf::Text text0;
        text0.setFont(police);
        text0.setCharacterSize(60);
        text0.setFillColor(sf::Color::White);
        text0.setString("Wall Chess | Jeu d'echec");
        text0.setOrigin(text0.getGlobalBounds().width / 2.f , text0.getLocalBounds().height);
        text0.setPosition(window.getSize().y/2,100);

        sf::RectangleShape bouton1(sf::Vector2f(350,100));
        bouton1.setPosition((window.getSize().y-bouton1.getSize().x)/2-75,200);
        bouton1.setFillColor(sf::Color(0x81b64cFF));
        bouton1.setOutlineThickness(1);
        bouton1.setOutlineColor(sf::Color(0x50633eFF));
        sf::Text text1;
        text1.setFont(police);
        text1.setCharacterSize(30);
        text1.setFillColor(sf::Color::White);
        text1.setString("Joueur contre Joueur");
        text1.setOrigin(text1.getGlobalBounds().width / 2.f , text1.getLocalBounds().height);
        text1.setPosition(bouton1.getPosition() + (bouton1.getSize() / 2.f));

        sf::RectangleShape bouton2(sf::Vector2f(350,100));
        bouton2.setPosition((window.getSize().y-bouton2.getSize().x)/2-75,400);
        bouton2.setFillColor(sf::Color(0x403e3cFF));
        bouton2.setOutlineThickness(1);
        bouton2.setOutlineColor(sf::Color(0x292926FF));
        sf::Text text2;
        text2.setFont(police);
        text2.setCharacterSize(30);
        text2.setFillColor(sf::Color::White);
        text2.setString("Joueur contre Ordinateur");
        text2.setOrigin(text2.getGlobalBounds().width / 2.f , text2.getLocalBounds().height);
        text2.setPosition(bouton2.getPosition() + (bouton2.getSize() / 2.f));

        sf::RectangleShape bouton3(sf::Vector2f(200,100));
        bouton3.setPosition((window.getSize().y-bouton3.getSize().x)/2,600);
        bouton3.setFillColor(sf::Color(0x262522FF));
        bouton3.setOutlineThickness(1);
        bouton3.setOutlineColor(sf::Color(0x1f1e1cFF));
        sf::Text text3;
        text3.setFont(police);
        text3.setCharacterSize(55);
        text3.setFillColor(sf::Color(0x302e2bFF));
        text3.setString("Quitter");
        text3.setOutlineThickness(0);
        text3.setOutlineColor(sf::Color(0x1f1e1cFF));
        text3.setOrigin(text3.getGlobalBounds().width / 2.f , text3.getLocalBounds().height);
        text3.setPosition(bouton3.getPosition() + (bouton3.getSize() / 2.f));

        sf::RectangleShape bouton4(sf::Vector2f(100,100));
        bouton4.setPosition(bouton1.getPosition().x+400,bouton1.getPosition().y);
        bouton4.setFillColor(sf::Color(0x81b64cFF));
        bouton4.setOutlineThickness(1);
        bouton4.setOutlineColor(sf::Color(0x50633eFF));
        sf::Text text4;
        text4.setFont(police);
        text4.setCharacterSize(24);
        text4.setFillColor(sf::Color::White);
        text4.setString("Continuer");
        text4.setOrigin(text4.getGlobalBounds().width / 2.f , text4.getLocalBounds().height);
        text4.setPosition(bouton4.getPosition() + (bouton4.getSize() / 2.f));

        sf::RectangleShape bouton5(sf::Vector2f(100,100));
        bouton5.setPosition(bouton2.getPosition().x+400,bouton2.getPosition().y);
        bouton5.setFillColor(sf::Color(0x403e3cFF));
        bouton5.setOutlineThickness(1);
        bouton5.setOutlineColor(sf::Color(0x292926FF));
        sf::Text text5;
        text5.setFont(police);
        text5.setCharacterSize(24);
        text5.setFillColor(sf::Color::White);
        text5.setString("Continuer");
        text5.setOrigin(text5.getGlobalBounds().width / 2.f , text5.getLocalBounds().height);
        text5.setPosition(bouton5.getPosition() + (bouton5.getSize() / 2.f));



    while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if(event.mouseButton.button == sf::Mouse::Left) {
                        if(bouton1.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                            IHM_Graphique ihm(window, false, false);
                            ihm.boucleJeu();
                        } else if(bouton2.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                            IHM_Graphique ihm(window, true, false);
                            ihm.boucleJeu();
                        } else if(bouton3.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                            window.close();
                        } else if(bouton4.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                            IHM_Graphique ihm(window, false, true);
                            ihm.boucleJeu();
                        } else if(bouton5.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                            IHM_Graphique ihm(window, true, true);
                            ihm.boucleJeu();
                        }
                    }
                }
            }
            window.clear(sf::Color(0x302e2bFF));

            window.draw(bouton1);
            window.draw(bouton2);
            window.draw(bouton3);
            window.draw(bouton4);
            window.draw(bouton5);
            window.draw(text0);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);
            window.draw(text4);
            window.draw(text5);
            window.display();
        }
        return 0;
}
