#include <SDL.h>
#include <SDL_image.h>
#include <cstdlib>
#include <iostream>

#include "Affichage.h"
#include "Personnage.h"
#include "Sol.h"


#define TAILLE_MAP 3600





Personnage::Personnage(SDL_Renderer* pRenderer){


    velocity = 5;
    frame = 0;
    status = 4;

    //Initialisation des textures
    SDL_Surface* joueurSurface = IMG_Load("textures/player1.png");
    tabJoueurBas[0] = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);

    joueurSurface = IMG_Load("textures/player2.png");
    tabJoueurBas[1] = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);

    joueurSurface = IMG_Load("textures/player3.png");
    tabJoueurBas[2] = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);

    joueurSurface = IMG_Load("textures/player4.png");
    tabJoueurBas[3] = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);

    joueurSurface = IMG_Load("textures/playercote3.png");
    tabJoueurHaut[0] = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);

    joueurSurface = IMG_Load("textures/playercote3-2.png");
    tabJoueurHaut[1] = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);

    joueurSurface = IMG_Load("textures/playercote3-3.png");
    tabJoueurHaut[2] = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);

    joueurSurface = IMG_Load("textures/playercote3-4.png");
    tabJoueurHaut[3] = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);

    joueurSurface = IMG_Load("textures/playercote1.png");
    tabJoueurGauche = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);

    joueurSurface = IMG_Load("textures/playercote2.png");
    tabJoueurDroite = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);


}

void Personnage::AffichageJoueur(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany){

    int positionx = 10*(resolutionecranx/20);
    int positiony = 6*(resolutionecrany/12);


    SDL_Rect src{0,0,96,90};
    SDL_Rect dest{positionx,positiony,(int)resolutionecranx/20,(int)resolutionecrany/12};

    if(status == 4){//Affichage si joueur vers le bas
        SDL_RenderCopy(pRenderer, tabJoueurBas[frame], &src, &dest);
    }

    if(status == 1){//Affichage si joueur vers le haut
        SDL_RenderCopy(pRenderer, tabJoueurHaut[frame], &src, &dest);
    }

    if(status == 2){//Affichage si joueur vers la gauche
        SDL_RenderCopy(pRenderer, tabJoueurGauche, &src, &dest);
    }

    if(status == 3){//Affichage si joueur vers la droite
        SDL_RenderCopy(pRenderer, tabJoueurDroite, &src, &dest);
    }
}




bool Personnage::DetectionCollision(int positionx, int positiony, int map[TAILLE_MAP][TAILLE_MAP], int movement, bool collision){

    if(collision == false){ //Desactivation des collisions si collision sur false
        return false;
    }

    int coordx = positionx/96; // on récupere les coordonnées de notre personnage sur la map
    int coordy = positiony/90;


    //Si on va vers le haut
    if(movement == 1){
        status = 1;
        bool isnotchemin = true;;

        if(map[coordx][coordy-1] != 1 && map[coordx][coordy-1] != 0 && map[coordx][coordy-1] != 4){
            for(int k = 0; k<16; k++){
                if(map[coordx][coordy-1] == 100+k){
                    isnotchemin = false;
                }
            }
            return isnotchemin;
        }
    }

    //Si on va vers la gauche
    if(movement == 2){
        status = 2;
        bool isnotchemin = true;;

        if(map[coordx-1][coordy] != 1 && map[coordx-1][coordy] != 0 && map[coordx-1][coordy] != 4){
            for(int k = 0; k<16; k++){
                if(map[coordx-1][coordy] == 100+k){
                    isnotchemin = false;
                }
            }
            return isnotchemin;
        }
    }

    //Si on va vers la droite
    if(movement == 3){
        status = 3;
        bool isnotchemin = true;;

        if(map[coordx+1][coordy] != 1 && map[coordx+1][coordy] != 0 && map[coordx+1][coordy] != 4){
            for(int k = 0; k<16; k++){
                if(map[coordx+1][coordy] == 100+k){
                    isnotchemin = false;
                }
            }
            return isnotchemin;
        }
    }

    //Si on va vers le bas
    if(movement == 4){
        status = 4;
        bool isnotchemin = true;;

        if(map[coordx][coordy+1] != 1 && map[coordx][coordy+1] != 0 && map[coordx][coordy+1] != 4){
            for(int k = 0; k<16; k++){
                if(map[coordx][coordy+1] == 100+k){
                    isnotchemin = false;
                }
            }
            return isnotchemin;
        }
    }

    return false;

}




void Personnage::PressionToucheMouvement(int Movement, int *positionx, int *positiony, SDL_Renderer* pRenderer, int map[TAILLE_MAP][TAILLE_MAP], int resolutionecranx, int resolutionecrany, Personnage porg, Sol sol, Bouton iconeMenu){

    int positionAffichagex = 0;
    int positionAffichagey = 0;
    int offset;


    //Touche W
    if(Movement == 1){
        status = 1;

        for(int k=1; k<11; k++){
            *positiony -= 9;
            positionAffichagey += 1;

            offset = 90;
            if(positionAffichagey==10){offset=0;}

            positionAffichagey %= 10;

            SDL_RenderClear(pRenderer);
            sol.AffichageSol(pRenderer, map, *positionx, *positiony + offset, resolutionecranx, resolutionecrany, 0, -positionAffichagey*(resolutionecrany/120)+(resolutionecrany/120));
            porg.AffichageJoueur(pRenderer, resolutionecranx, resolutionecrany);
            iconeMenu.AffichageBouton(pRenderer);
            SDL_RenderPresent(pRenderer);
            SDL_Delay(velocity);
        }
    }

    //Touche A
    if(Movement == 2){
        status = 2;

        for(int k=1; k<13; k++){
            *positionx -= 8;
            positionAffichagex += 1;
            offset = 96;

            if(positionAffichagex==12){offset=0;}

            positionAffichagex %= 12;

            SDL_RenderClear(pRenderer);
            sol.AffichageSol(pRenderer, map, *positionx + offset, *positiony, resolutionecranx, resolutionecrany, -positionAffichagex*(resolutionecranx/240)+(resolutionecranx/240), 0);
            porg.AffichageJoueur(pRenderer, resolutionecranx, resolutionecrany);
            iconeMenu.AffichageBouton(pRenderer);
            SDL_RenderPresent(pRenderer);
            SDL_Delay(velocity);
        }
    }

    //Touche D
    if(Movement == 3){
        status = 3;

        for(int k=1; k<13; k++){
            *positionx += 8;
            positionAffichagex += 1;
            positionAffichagex %= 12;
            SDL_RenderClear(pRenderer);
            sol.AffichageSol(pRenderer, map, *positionx, *positiony, resolutionecranx, resolutionecrany, positionAffichagex*(resolutionecranx/240), 0);
            porg.AffichageJoueur(pRenderer, resolutionecranx, resolutionecrany);
            iconeMenu.AffichageBouton(pRenderer);
            SDL_RenderPresent(pRenderer);
            SDL_Delay(velocity);
        }
    }

    //Touche S
    if(Movement == 4){
        status = 4;

        for(int k=1; k<11; k++){
            *positiony += 9;
            positionAffichagey += 1;
            positionAffichagey %= 10;
            SDL_RenderClear(pRenderer);
            sol.AffichageSol(pRenderer, map, *positionx, *positiony, resolutionecranx, resolutionecrany,0 , positionAffichagey*(resolutionecrany/120));
            porg.AffichageJoueur(pRenderer, resolutionecranx, resolutionecrany);
            iconeMenu.AffichageBouton(pRenderer);
            SDL_RenderPresent(pRenderer);
            SDL_Delay(velocity);
        }
    }
    //On augmente l'index de 1, pour choisir une nouvelle texture
    ++frame;
    if( frame > 3)
    {
        frame = 0;
    }
    printf("X:%d, Y:%d Bloc:%d\n",*positionx/96 + 10,*positiony/90 + 6, map[*positionx/96 + 10][*positiony/90 + 6]);
    CalculZone(*positionx/96+ 10, *positiony/90 + 6);

}

void Personnage::augmentIndex(){
    ++frame;
    if( frame > 3)
    {
        frame = 0;
    }
}

int Personnage::DetectionEvent(int positionx, int positiony, int map[TAILLE_MAP][TAILLE_MAP]){

    int coordx = positionx/96; // on récupere les coordonnées de notre personnage sur la map
    int coordy = positiony/90;

    //Si on va vers le haut
    if(status == 1){
        if(map[coordx][coordy-1] != 0 && map[coordx][coordy-1] != 1 && map[coordx][coordy-1] != 2 && map[coordx][coordy-1] != 3){
            return map[coordx][coordy-1];
        }
    }
    //Si on va vers la gauche
    if(status == 2){
        if(map[coordx-1][coordy] != 0 && map[coordx-1][coordy] != 1 && map[coordx-1][coordy] != 2 && map[coordx-1][coordy] != 3){
            return map[coordx-1][coordy];
        }
    }
    //Si on va vers la droite
    if(status == 3){
        if(map[coordx+1][coordy] != 0 && map[coordx+1][coordy] != 1 && map[coordx+1][coordy] != 2 && map[coordx+1][coordy] != 3){
            return map[coordx+1][coordy];
        }
    }
    //Si on va vers le bas
    if(status == 4){
        if(map[coordx][coordy+1] != 0 && map[coordx][coordy+1] != 1 && map[coordx][coordy+1] != 2 && map[coordx][coordy+1] != 3){
            return map[coordx][coordy+1];
        }
    }
    return 0;
}

void Personnage::DestroyPersonnage(){

    for(int k = 0; k<=3; k++){
        SDL_DestroyTexture(tabJoueurHaut[k]);
        SDL_DestroyTexture(tabJoueurBas[k]);
    }
    SDL_DestroyTexture(tabJoueurGauche);
    SDL_DestroyTexture(tabJoueurDroite);
}

void Personnage::Reset(SDL_Renderer* pRenderer){

    DestroyPersonnage();

    //Initialisation des textures
    SDL_Surface* joueurSurface = IMG_Load("textures/player1.png");
    tabJoueurBas[0] = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);

    joueurSurface = IMG_Load("textures/player2.png");
    tabJoueurBas[1] = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);

    joueurSurface = IMG_Load("textures/player3.png");
    tabJoueurBas[2] = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);

    joueurSurface = IMG_Load("textures/player4.png");
    tabJoueurBas[3] = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);

    joueurSurface = IMG_Load("textures/playercote3.png");
    tabJoueurHaut[0] = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);

    joueurSurface = IMG_Load("textures/playercote3.png");
    tabJoueurHaut[1] = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);

    joueurSurface = IMG_Load("textures/playercote3-2.png");
    tabJoueurHaut[2] = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);

    joueurSurface = IMG_Load("textures/playercote3-3.png");
    tabJoueurHaut[3] = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);

    joueurSurface = IMG_Load("textures/playercote1.png");
    tabJoueurGauche = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);

    joueurSurface = IMG_Load("textures/playercote2.png");
    tabJoueurDroite = SDL_CreateTextureFromSurface(pRenderer, joueurSurface);
    SDL_FreeSurface(joueurSurface);


}


void Personnage::CalculZone(int x, int y){

    zone = 0;

    if(x>=10 && x<=25 && y>=10 && y<=25){
        zone = 1;
    }
    if(x>=36 && x<=53 && y>=26 && y<=35){
        zone = 2;
    }

}

bool Personnage::DetectionHerbe(int x, int y, int map[TAILLE_MAP][TAILLE_MAP]){

    if(map[x][y] == 4){
        return true;
    }
    return false;
}
