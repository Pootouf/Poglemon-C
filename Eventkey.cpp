#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <cstdlib>
#include <string>


//Initialisation des autres fichiers n�cessaires
#include "Affichage.h"
#include "Resolution.h"
#include "Personnage.h"

using namespace std;

int PressionTouche(SDL_Renderer** pRenderer, SDL_Window** pWindow, bool keys[322], int *resolutionx, int *resolutiony, string valeurTouche[322]){

    int v = 0;

    int toucheTab[6];
    string valeur[6] = {"Z", "Q", "D", "S", "I", "Espace"};

    for(int x = 0; x<=5; x++){
        for(int k = 0; k<=321; k++){
            if(valeurTouche[k] == valeur[x]){
                toucheTab[x] = k;
            }

        }
    }

    while(v==0){
        if (keys[toucheTab[4]]){
            return 6;
        }// Regarde si le scancode I est enfonc�

        if (keys[toucheTab[5]]){
            return 7;
        }// Regarde si le scancode Espace est enfonc�

        if (keys[toucheTab[0]]){
            return 1;
        } // Regarde si le scancode W est enfonc�
        if (keys[toucheTab[1]]){
            return 2;
        } // Regarde si le scancode Q est enfonc�

        if (keys[toucheTab[2]]){
            return 3;
        } // Regarde si le scancode D est enfonc�

        if (keys[toucheTab[3]]){
            return 4;
        } // Regarde si le scancode S est enfonc�

        if (keys[SDLK_k]){
            return 45;
        } // Regarde si le scancode K est enfonc� (DEBUG)

        if (keys[SDLK_l]){
            return 46;
        } // Regarde si le scancode L est enfonc� (DEBUG)

        break;
    }

    return 0;

}

void intTouche(string valeurTouche[322], int toucheTab[6]){

    string valeur[6] = {"Z", "Q", "D", "S", "I", "Espace"};

    for(int x = 0; x<=5; x++){
        for(int k = 0; k<=321; k++){
            if(valeurTouche[k] == valeur[x]){
                toucheTab[x] = k;
            }

        }
    }


}



