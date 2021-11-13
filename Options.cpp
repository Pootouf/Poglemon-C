#include <SDL.h>
#include <cstdlib>
#include <iostream>
#include <SDL_mixer.h>

#include "Bouton.h"
#include "Options.h"
#include "Resolution.h"
#include <string>
#include "Eventkey.h"

using namespace std;

#define TAILLE_MAP 3600


int menuOptions(SDL_Renderer** pRenderer, SDL_Window** pWindow, int* resolutionecranx, int* resolutionecrany, string valeurTouche[322], string stringTouche[322]){

    Bouton touche(*resolutionecranx/2, *resolutionecrany/2.5, *resolutionecranx/2.67, *resolutionecrany/8.64, *pRenderer, 1);
    Bouton resolution(*resolutionecranx/2, *resolutionecrany/1.7, *resolutionecranx/2.67, *resolutionecrany/8.64, *pRenderer, 1);
    Bouton option(*resolutionecranx/2, *resolutionecrany/4, *resolutionecranx/2.67, *resolutionecrany/8.64, *pRenderer, 1);
    Bouton retour(*resolutionecranx/2, *resolutionecrany/1.3, *resolutionecranx/2.67, *resolutionecrany/8.64, *pRenderer, 1);

    SDL_Event events;

    bool menuPause = true;

    while(menuPause == true){
        AfficheOptions(*pRenderer, *resolutionecranx, *resolutionecrany, touche, resolution, option, retour);
        while (SDL_PollEvent(&events)) {
            switch(events.type){
                case SDL_MOUSEMOTION:
                    touche.ChangeCouleurBouton(touche.hoverBouton(events));
                    resolution.ChangeCouleurBouton(resolution.hoverBouton(events));
                    retour.ChangeCouleurBouton(retour.hoverBouton(events));
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(touche.hoverBouton(events)){
                        destructeurMenuOptions(touche, resolution, option, retour);
                        int retourOption = OptionsTouche(*pRenderer, *resolutionecranx, *resolutionecrany, valeurTouche, stringTouche);
                        if(retourOption == 0){
                            return 0;
                        }
                    }
                    if(resolution.hoverBouton(events)){
                        destructeurMenuOptions(touche, resolution, option, retour);
                        int retourOption = OptionsResolution(pRenderer, pWindow, resolutionecranx, resolutionecrany);
                        if(retourOption == 0){
                            return 3;
                        }
                    }
                    if(retour.hoverBouton(events)){
                        destructeurMenuOptions(touche, resolution, option, retour);
                        return 0;
                    }
                    break;
            }
        }
    }
    return 0;
}

void destructeurMenuOptions(Bouton touche, Bouton resolution, Bouton option, Bouton retour){
    touche.DestroyBouton();
    resolution.DestroyBouton();
    option.DestroyBouton();
    retour.DestroyBouton();
}




void AfficheOptions(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton touche, Bouton resolution, Bouton option, Bouton retour){

    SDL_SetRenderDrawColor(pRenderer, 128, 128, 128, 255);
    SDL_RenderClear(pRenderer);

    touche.AffichageBouton(pRenderer);
    resolution.AffichageBouton(pRenderer);
    retour.AffichageBouton(pRenderer);


    touche.AffichageTexte(pRenderer, "Touche", resolutionecranx/32, SDL_Color{0,0,0,255});
    resolution.AffichageTexte(pRenderer, "Resolution", resolutionecranx/32, SDL_Color{0,0,0,255});
    option.AffichageTexte(pRenderer, "OPTIONS", resolutionecranx/19.2, SDL_Color{0,0,0,255});
    retour.AffichageTexte(pRenderer, "Retour", resolutionecranx/32, SDL_Color{0,0,0,255});

    SDL_RenderPresent(pRenderer);

    SDL_Delay(5);
}

int OptionsResolution(SDL_Renderer** pRenderer, SDL_Window** pWindow, int* resolutionecranx, int* resolutionecrany){

    Mix_Chunk* sonBouton = Mix_LoadWAV("sounds/bouton.wav");
    Mix_PlayChannel(1, sonBouton, 0);

    Bouton resolution(*resolutionecranx/2, *resolutionecrany/6, *resolutionecranx/2.67, *resolutionecrany/8.64, *pRenderer, 1);
    Bouton resolution1080(*resolutionecranx/4, *resolutionecrany/2.5, *resolutionecranx/2.67, *resolutionecrany/8.64, *pRenderer, 1);
    Bouton resolution720(*resolutionecranx/1.5, *resolutionecrany/1.5, *resolutionecranx/2.67, *resolutionecrany/8.64, *pRenderer, 1);
    Bouton resolution576(*resolutionecranx/4, *resolutionecrany/1.5, *resolutionecranx/2.67, *resolutionecrany/8.64, *pRenderer, 1);
    Bouton resolution1440(*resolutionecranx/1.5, *resolutionecrany/2.5, *resolutionecranx/2.67, *resolutionecrany/8.64, *pRenderer, 1);
    Bouton confirmer(*resolutionecranx/4, *resolutionecrany/1.1, *resolutionecranx/2.67, *resolutionecrany/8.64, *pRenderer, 1);
    Bouton retour(*resolutionecranx/1.5, *resolutionecrany/1.1, *resolutionecranx/2.67, *resolutionecrany/8.64, *pRenderer, 1);

    int resolutionx, resolutiony;

    SDL_Event events;

    bool menuPause = true;

    while(menuPause == true){
        AfficheOptionsResolution(*pRenderer, *resolutionecranx, *resolutionecrany, resolution, resolution1080, resolution720, resolution576, resolution1440, confirmer, retour);
        while (SDL_PollEvent(&events)) {
            switch(events.type){
                case SDL_MOUSEMOTION:
                    resolution.ChangeCouleurBouton(resolution.hoverBouton(events));
                    resolution1080.ChangeCouleurBouton(resolution1080.hoverBouton(events));
                    resolution720.ChangeCouleurBouton(resolution720.hoverBouton(events));
                    resolution576.ChangeCouleurBouton(resolution576.hoverBouton(events));
                    resolution1440.ChangeCouleurBouton(resolution1440.hoverBouton(events));
                    confirmer.ChangeCouleurBouton(confirmer.hoverBouton(events));
                    retour.ChangeCouleurBouton(retour.hoverBouton(events));
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(resolution1080.hoverBouton(events)){
                        Mix_PlayChannel(1, sonBouton, 0);
                        resolutionx = 1920;
                        resolutiony = 1080;
                    }
                    if(resolution720.hoverBouton(events)){
                        Mix_PlayChannel(1, sonBouton, 0);
                        resolutionx = 1080;
                        resolutiony = 720;
                    }
                    if(resolution576.hoverBouton(events)){
                        Mix_PlayChannel(1, sonBouton, 0);
                        resolutionx = 720;
                        resolutiony = 576;
                    }
                    if(resolution1440.hoverBouton(events)){
                        Mix_PlayChannel(1, sonBouton, 0);
                        resolutionx = 2560;
                        resolutiony = 1440;
                    }
                    if(confirmer.hoverBouton(events)){
                        destructeurMenuOptionsResolution(resolution, resolution1080, resolution720, resolution576, resolution1440, confirmer, retour);
                        initialisationFenetre(resolutionx, resolutiony, SDL_WINDOW_SHOWN, pWindow, pRenderer, true, resolutionecranx, resolutionecrany);
                        Mix_FreeChunk(sonBouton);
                        return 0;
                    }
                    if(retour.hoverBouton(events)){
                        Mix_FreeChunk(sonBouton);
                        destructeurMenuOptionsResolution(resolution, resolution1080, resolution720, resolution576, resolution1440, confirmer, retour);
                        return 0;
                    }
                    break;
            }
        }
    }
    return 0;


}

void destructeurMenuOptionsResolution(Bouton resolution, Bouton resolution1080, Bouton resolution720, Bouton resolution576, Bouton resolution1440, Bouton confirmer, Bouton retour){
    resolution.DestroyBouton();
    resolution1080.DestroyBouton();
    resolution720.DestroyBouton();
    resolution576.DestroyBouton();
    resolution1440.DestroyBouton();
    confirmer.DestroyBouton();
    retour.DestroyBouton();
}

void AfficheOptionsResolution(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton resolution, Bouton resolution1080, Bouton resolution720, Bouton resolution576, Bouton resolution1440, Bouton confirmer, Bouton retour ){

    SDL_SetRenderDrawColor(pRenderer, 128, 128, 128, 255);
    SDL_RenderClear(pRenderer);


    resolution1080.AffichageBouton(pRenderer);
    resolution720.AffichageBouton(pRenderer);
    resolution576.AffichageBouton(pRenderer);
    resolution1440.AffichageBouton(pRenderer);
    confirmer.AffichageBouton(pRenderer);
    retour.AffichageBouton(pRenderer);


    resolution.AffichageTexte(pRenderer, "RESOLUTION", resolutionecranx/19.2, SDL_Color{0,0,0,255});
    resolution1080.AffichageTexte(pRenderer, "1920x1080", resolutionecranx/32, SDL_Color{0,0,0,255});
    resolution720.AffichageTexte(pRenderer, "1280x720", resolutionecranx/32, SDL_Color{0,0,0,255});
    resolution576.AffichageTexte(pRenderer, "720x576", resolutionecranx/32, SDL_Color{0,0,0,255});
    resolution1440.AffichageTexte(pRenderer, "2560x1440", resolutionecranx/32, SDL_Color{0,0,0,255});
    confirmer.AffichageTexte(pRenderer, "Confirmer", resolutionecranx/32, SDL_Color{0,0,0,255});
    retour.AffichageTexte(pRenderer, "Retour", resolutionecranx/32, SDL_Color{0,0,0,255});

    SDL_RenderPresent(pRenderer);

    SDL_Delay(5);

}


int OptionsTouche(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, string valeurTouche[322], string stringTouche[322]){

    Mix_Chunk* sonBouton = Mix_LoadWAV("sounds/bouton.wav");
    Mix_PlayChannel(1, sonBouton, 0);

    Bouton Touche(resolutionecranx/2, resolutionecrany/10.8, resolutionecranx/2.67, resolutionecrany/8.64, pRenderer, 1);
    Bouton ToucheZ(resolutionecranx/2, resolutionecrany/3.6, resolutionecranx/2.67, resolutionecrany/8.64, pRenderer, 1);
    Bouton ToucheQ(resolutionecranx/2, resolutionecrany/2.48, resolutionecranx/2.67, resolutionecrany/8.64, pRenderer, 1);
    Bouton ToucheD(resolutionecranx/2, resolutionecrany/1.89, resolutionecranx/2.67, resolutionecrany/8.64, pRenderer, 1);
    Bouton ToucheS(resolutionecranx/2, resolutionecrany/1.53, resolutionecranx/2.67, resolutionecrany/8.64, pRenderer, 1);
    Bouton ToucheI(resolutionecranx/2, resolutionecrany/1.29, resolutionecranx/2.67, resolutionecrany/8.64, pRenderer, 1);
    Bouton ToucheEspace(resolutionecranx/2, resolutionecrany/1.11, resolutionecranx/2.67, resolutionecrany/8.64, pRenderer, 1);
    Bouton confirmer(resolutionecranx/1.2, resolutionecrany/1.11, resolutionecranx/3.5, resolutionecrany/8.64, pRenderer, 1);
    Bouton defaut(resolutionecranx/6, resolutionecrany/1.11, resolutionecranx/3.5, resolutionecrany/8.64, pRenderer, 1);


    SDL_Event events;
    int x, y;


    bool menuPause = true;

    while(menuPause == true){
        AfficheOptionsTouche(pRenderer, resolutionecranx, resolutionecrany, Touche, ToucheZ, ToucheQ, ToucheD, ToucheS, ToucheI, ToucheEspace, confirmer, defaut, valeurTouche, stringTouche);
        while (SDL_PollEvent(&events)) {


            switch(events.type){
                case SDL_KEYDOWN:
                    if(ToucheZ.hoverBoutonStatic(x, y)){
                        recupTouche(events, valeurTouche, stringTouche, 1);
                    }
                    if(ToucheQ.hoverBoutonStatic(x, y)){
                        recupTouche(events, valeurTouche, stringTouche, 2);
                    }
                    if(ToucheD.hoverBoutonStatic(x, y)){
                        recupTouche(events, valeurTouche, stringTouche, 3);
                    }
                    if(ToucheS.hoverBoutonStatic(x, y)){
                        recupTouche(events, valeurTouche, stringTouche, 4);
                    }
                    if(ToucheI.hoverBoutonStatic(x, y)){
                        recupTouche(events, valeurTouche, stringTouche, 5);
                    }
                    if(ToucheEspace.hoverBoutonStatic(x, y)){
                        recupTouche(events, valeurTouche, stringTouche, 6);
                    }
                case SDL_MOUSEMOTION:
                    x = events.motion.x;
                    y = events.motion.y;
                    ToucheZ.ChangeCouleurBouton(ToucheZ.hoverBouton(events));
                    ToucheQ.ChangeCouleurBouton(ToucheQ.hoverBouton(events));
                    ToucheD.ChangeCouleurBouton(ToucheD.hoverBouton(events));
                    ToucheS.ChangeCouleurBouton(ToucheS.hoverBouton(events));
                    ToucheI.ChangeCouleurBouton(ToucheI.hoverBouton(events));
                    ToucheEspace.ChangeCouleurBouton(ToucheEspace.hoverBouton(events));
                    confirmer.ChangeCouleurBouton(confirmer.hoverBouton(events));
                    defaut.ChangeCouleurBouton(defaut.hoverBouton(events));
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(confirmer.hoverBouton(events)){
                        Mix_FreeChunk(sonBouton);
                        destructeurMenuOptionsTouche(Touche, ToucheZ, ToucheQ, ToucheD, ToucheS, ToucheI, ToucheEspace, confirmer, defaut);
                        return 0;
                    }
                    if(defaut.hoverBouton(events)){
                        Mix_PlayChannel(1, sonBouton, 0);
                        for(int k = 0; k<=321; k++){
                            valeurTouche[k] = {""};
                            stringTouche[k] = {""};
                        }
                        valeurTouche[SDLK_z] = "Z";
                        valeurTouche[SDLK_q] = "Q";
                        valeurTouche[SDLK_s] = "S";
                        valeurTouche[SDLK_d] = "D";
                        valeurTouche[SDLK_i] = "I";
                        valeurTouche[SDLK_SPACE] = "Espace";
                        stringTouche[SDLK_z] = "z";
                        stringTouche[SDLK_q] = "q";
                        stringTouche[SDLK_s] = "s";
                        stringTouche[SDLK_d] = "d";
                        stringTouche[SDLK_i] = "i";
                        stringTouche[SDLK_SPACE] = "Espace";
                    }
                    break;
            }
        }
    }
    return 0;


}

void destructeurMenuOptionsTouche(Bouton Touche, Bouton ToucheZ, Bouton ToucheQ, Bouton ToucheD, Bouton ToucheS, Bouton ToucheI, Bouton ToucheEspace, Bouton confirmer, Bouton defaut){
    Touche.DestroyBouton();
    ToucheZ.DestroyBouton();
    ToucheQ.DestroyBouton();
    ToucheD.DestroyBouton();
    ToucheS.DestroyBouton();
    ToucheI.DestroyBouton();
    ToucheEspace.DestroyBouton();
    confirmer.DestroyBouton();
    defaut.DestroyBouton();
}

void AfficheOptionsTouche(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton Touche, Bouton ToucheZ, Bouton ToucheQ, Bouton ToucheD, Bouton ToucheS, Bouton ToucheI, Bouton ToucheEspace, Bouton confirmer, Bouton defaut, string valeurTouche[322], string stringTouche[322]){

    SDL_SetRenderDrawColor(pRenderer, 128, 128, 128, 255);
    SDL_RenderClear(pRenderer);


    ToucheZ.AffichageBouton(pRenderer);
    ToucheQ.AffichageBouton(pRenderer);
    ToucheD.AffichageBouton(pRenderer);
    ToucheS.AffichageBouton(pRenderer);
    ToucheI.AffichageBouton(pRenderer);
    ToucheEspace.AffichageBouton(pRenderer);
    confirmer.AffichageBouton(pRenderer);
    defaut.AffichageBouton(pRenderer);


    int toucheTab[6];
    string valeur[6] = {"Z", "Q", "D", "S", "I", "Espace"};

    for(int x = 0; x<=5; x++){
        for(int k = 0; k<=321; k++){
            if(valeurTouche[k] == valeur[x]){
                toucheTab[x] = k;
            }

        }
    }


    Touche.AffichageTexte(pRenderer, "Touche", resolutionecranx/19.2, SDL_Color{0,0,0,255});
    ToucheZ.AffichageTexte(pRenderer, "Haut: " + stringTouche[toucheTab[0]], resolutionecranx/32, SDL_Color{0,0,0,255});
    ToucheQ.AffichageTexte(pRenderer, "Gauche: " + stringTouche[toucheTab[1]], resolutionecranx/32, SDL_Color{0,0,0,255});
    ToucheD.AffichageTexte(pRenderer, "Droite: " + stringTouche[toucheTab[2]], resolutionecranx/32, SDL_Color{0,0,0,255});
    ToucheS.AffichageTexte(pRenderer, "Bas: " + stringTouche[toucheTab[3]], resolutionecranx/32, SDL_Color{0,0,0,255});
    ToucheI.AffichageTexte(pRenderer, "Menu: " + stringTouche[toucheTab[4]], resolutionecranx/32, SDL_Color{0,0,0,255});
    ToucheEspace.AffichageTexte(pRenderer, "Interargir: " + stringTouche[toucheTab[5]], resolutionecranx/32, SDL_Color{0,0,0,255});
    confirmer.AffichageTexte(pRenderer, "Confirmer", resolutionecranx/32, SDL_Color{0,0,0,255});
    defaut.AffichageTexte(pRenderer, "Defaut", resolutionecranx/32, SDL_Color{0,0,0,255});

    SDL_RenderPresent(pRenderer);

    SDL_Delay(5);

}


void recupTouche(SDL_Event events, string valeurTouche[322], string stringTouche[322], int touche){

    if(valeurTouche[events.key.keysym.sym] == "" && events.key.keysym.sym < 322){

        int toucheTab[6];
        string valeur[6] = {"Z", "Q", "D", "S", "I", "Espace"};

        intTouche(valeurTouche, toucheTab);

        valeurTouche[toucheTab[touche - 1]] = "";
        valeurTouche[events.key.keysym.sym] = valeur[touche - 1];
        stringTouche[toucheTab[touche - 1]] = "";
        stringTouche[events.key.keysym.sym] = events.key.keysym.sym;

        if(events.key.keysym.sym == SDLK_SPACE){
            stringTouche[events.key.keysym.sym] = "Espace";
        }
    }


}
