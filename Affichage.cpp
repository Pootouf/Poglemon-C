#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "Bouton.h"

#define TAILLE_MAP 3600

void AffichageSol(SDL_Renderer* pRenderer, int map[TAILLE_MAP][TAILLE_MAP], int positionjoueurx, int positionjoueury, int resolutionecranx, int resolutionecrany, int deplacementX, int deplacementY){



    //Initialisation de la texture herbe
    SDL_Surface* herbeSurface = IMG_Load("textures/herbe.png");
    SDL_Texture* herbe = SDL_CreateTextureFromSurface(pRenderer, herbeSurface);
    SDL_FreeSurface(herbeSurface);

    //Initialisation de la texture fleur
    SDL_Surface* fleurSurface = IMG_Load("textures/fleur.png");
    SDL_Texture* fleur = SDL_CreateTextureFromSurface(pRenderer, fleurSurface);
    SDL_FreeSurface(fleurSurface);

    //Initialisation de la texture arbre
    SDL_Surface* arbreSurface = IMG_Load("textures/arbre.png");
    SDL_Texture* arbre = SDL_CreateTextureFromSurface(pRenderer, arbreSurface);
    SDL_FreeSurface(arbreSurface);

    positionjoueurx = (positionjoueurx/96)*(resolutionecranx/20);
    positionjoueury = (positionjoueury/90)*(resolutionecrany/12);

    int coordx = (int)positionjoueurx/(resolutionecranx/20);
    int coordy = (int)positionjoueury/(resolutionecrany/12);

    //Boucle pour afficher les textures sur tout l'écran
    for(int x = coordx - 3; x<=coordx + 21; x++){
        for(int y = coordy - 3; y<=coordy + 13; y++){
            int positionx = x*(resolutionecranx/20) - positionjoueurx - deplacementX;
            int positiony = y*(resolutionecrany/12) - positionjoueury - deplacementY;

            if(map[x][y] == 0){
                SDL_Rect src{0,0,96,90};
                SDL_Rect dest{positionx,positiony,resolutionecranx/20,resolutionecrany/12};
                SDL_RenderCopy(pRenderer, herbe, &src, &dest);
            }
            if(map[x][y] == 1){
                SDL_Rect src{0,0,96,90};
                SDL_Rect dest{positionx,positiony,resolutionecranx/20,resolutionecrany/12};
                SDL_RenderCopy(pRenderer, fleur, &src, &dest);
            }
            if(map[x][y] == 3){
                SDL_Rect src{0,0,96*2,90*2};
                SDL_Rect dest{positionx,positiony,resolutionecranx/10,resolutionecrany/6};
                SDL_RenderCopy(pRenderer, arbre, &src, &dest);
            }
        }
    }

    //Destruction des textures
    SDL_DestroyTexture(herbe);
    SDL_DestroyTexture(fleur);
    SDL_DestroyTexture(arbre);
}



