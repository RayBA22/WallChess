#include "IHM_console.h"

void IHM_console::afficherEchiquier() const
{   
    cout << endl << " ";
    for (entier k = 0; k < 8; k++)
        cout << " " << k << " |";
    cout << "\n";
    TypePiece id;
    bool couleur;
    for (entier j = 0; j < 8; j++)
    {
        cout << " ";
        for (entier i = 0; i < 8; i++)
        {
            if (!jeu.presencePiece(i, j))
                cout << " " << symbole[0][vide] << " |";
            else{
                id = jeu.getTypePiece(i, j);
                couleur = jeu.getCouleurPiece(i, j);
                cout << " " << symbole[couleur][id] << " |";
                }
        }
        cout << j << endl;
    }
}

void IHM_console::boucleJeu()
{
    bool coup, reste = true;
    cout << "voulez vous ecraser l'ancienne partie tapez 1" << endl;
    cin >> coup;
    jeu.initialisation(coup);
    int x_actuel, y_actuel, x_coup, y_coup;
    afficherEchiquier();
    while (reste)
    {
        if (!jeu.getCouleur()){
            cout << "revenir ? " << endl;
            cin >> reste;
            if (reste) jeu.echiquier.retour();
            do
            {
                
                cout << "entrez les coordonnées de la piece: " << endl;
                cin >> x_actuel >> y_actuel;
                cout << "entrez les coordonnées du coup: " << endl;
                cin >> x_coup >> y_coup;
                coup = jeu.coup(x_actuel, y_actuel, x_coup, y_coup);
                cout << coup << endl;
            } while (!coup);

            afficherEchiquier();
            do
            {
                
                cout << "entrez les coordonnées du mur: " << endl;
                cin >> x_actuel >> y_actuel;
                cout << "entrez les coordonnées du coup: " << endl;
                cin >> x_coup >> y_coup;
                coup = jeu.coupMur(x_actuel, y_actuel, x_coup, y_coup);
                cout << coup << endl;
            } while (!coup);


        }
        
        else{
            jeu.coupAI();
            }


        jeu.changerCouleur();
        jeu.sauver();
        
        
        afficherEchiquier();
        cout << "tapez 1 pour continuer ou 0 pour arreter" << endl;
        cin >> reste;

        
        reste = reste * !jeu.mortRoi();
    }

    if (jeu.mortRoi())
        cout << "Le Roi " << symbole[!jeu.getCouleur()][(int)roi] << "est mort !" << endl;
}


