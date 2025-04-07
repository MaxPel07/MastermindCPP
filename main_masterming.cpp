/*
ETML
Auteur  : Maxime Pelloquin
Date    : 4.4.2025
Description : Ce programme est une réplique du jeu Mastermind.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    // Variable pour redémarrer le jeu
    char restartAnswer; 

    do
    {
        // nombre max d'essaie
        int nbMaxAttemps = 10;

        // valeur d'entrée de l'utilisateur
        string tryUser;

        // valeur de la combinaison secrète
        string code;

        // Liste des couleurs possibles
        string colors = "CRGBYM";

        cout << "Bienvenue sur Mastermind !" << endl;
        cout << "Couleurs possible : GYWRMCB" << endl;
        cout << "Devinez le code en 4 couleurs." << endl;

        // Permet d’initialiser la série avec une graine qui dépend du temps
        srand((unsigned int)time(0));

        // Génération d'une combinaison aléatoire de 4 couleurs
        for (int i = 0; i < 4; i++)
        {
            code += colors[rand() % colors.size()];
        }

        cout << code << endl;
        // boucle de x essaie du joueur
        for (int nbTries = 1; nbTries <= nbMaxAttemps; nbTries++)
        {
            cout << "Essai " << nbTries << endl;
            cin >> tryUser;
            for (char& c : tryUser) {
                c = toupper(c);
            }

            int ok = 0;
            int badPosition = 0;

            // Tableau pour suivre les indices déjà utilisés dans la combinaison secrète
            bool usedIndices[4];

            // Comparaison entre la proposition de l'utilisateur et la combinaison secrète
            if (tryUser == code)
            {
                cout << "Bravo ! Vous avez trouvé la bonne combinaison" << endl;
                break;
            }
            else
            {
                bool usedCode[4] = { false };
                bool usedTry[4] = { false };

                // 1. Vérification des couleurs bien placées
                for (int i = 0; i < 4; i++) {
                    if (tryUser[i] == code[i]) {
                        ok++;
                        usedCode[i] = true;
                        usedTry[i] = true;
                    }
                }

                // 2. Vérification des couleurs correctes mais mal placées
                for (int i = 0; i < 4; i++) {
                    if (!usedTry[i]) {
                        for (int j = 0; j < 4; j++) {
                            if (!usedCode[j] && tryUser[i] == code[j]) {
                                badPosition++;
                                usedCode[j] = true;
                                break; // une seule correspondance par lettre
                            }
                        }
                    }
                }


                // Affichage du résultat de l'essai
                cout << "=> " << ok << " couleur(s) bien placée(s)" << endl;
                cout << "=> " << badPosition << " couleur(s) correcte(s) mais mal placée(s)" << endl;
            }
            
            if (tryUser != code)
            {
                cout << "Mauvaise réponse" << endl;
            }
        }

        cout << "Voulez-vous rejouer ? (o/n)" << endl;
        cin >> restartAnswer;

        // Validation de l'entrée utilisateur
        while(restartAnswer != 'o' && restartAnswer != 'n')
        {
            cout << "Entrée invalide. Veuillez entrer 'o' pour oui ou 'n' pour non." << endl;
            cin >> restartAnswer;
        }
        
    }while(restartAnswer == 'o');
}