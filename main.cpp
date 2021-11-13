#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Inclusion des fichiers annexes
#include "Affichage.h"
#include "Eventkey.h"
#include "Map.h"
#include "Resolution.h"
#include "Personnage.h"
#include "Menu.h"
#include "Options.h"
#include "Optionsjeu.h"
#include "Sol.h"
#include "Event.h"
#include "Menuequipe.h"
#include "Poglemon.h"
#include "Save.h"
#include "Save.h"
#include "Pc.h"
#include "Combat.h"

#define TAILLE_MAP 3600



// Map format global
int map[TAILLE_MAP][TAILLE_MAP];

//definit les resolutions d'ecran de base
int resolutionecranx = 1920;
int resolutionecrany = 1080;



int main(int argc, char* argv[])
{

    //Initialisation des modules
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    if (TTF_Init() < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
        return EXIT_FAILURE;
    }

    if (Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0) // création de la configuration de la carte son
    {
        SDL_Log("Erreur initialisation SDL_mixer : %s", Mix_GetError());
        SDL_Quit();
        return -1;
    }
    Mix_AllocateChannels(2);

    //FIN initialisation Modules





    //Initialisation Fenetre
    SDL_Window* pWindow{ nullptr };
    SDL_Renderer* pRenderer{ nullptr };


    if(recupResolution() != 0){
        SDL_Quit();
    }


    initialisationFenetre(resolutionecranx, resolutionecrany, SDL_WINDOW_SHOWN, &pWindow, &pRenderer, false, &resolutionecranx, &resolutionecrany);

    SDL_Surface* icone = IMG_Load("textures/icone.png");
    SDL_SetWindowIcon(pWindow, icone);
    SDL_FreeSurface(icone);
    SDL_SetWindowTitle(pWindow, "Poglemon 0.9.17");
    //FIN Initialisation Fenetre





    //Initialisation Variable
    SDL_Event events;
    bool isOpen{ true };

    //DEBUG: permet d'activer ou non les collisions (activer sur true)
    bool collision = true;

    //Permet de définir les touches de base, possibilité de les changer en jeu apres
    bool keys[322] = {false};
    string valeurTouche[322] = {""};
    string stringTouche[322] = {""};
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

    int toucheTab[6];

    intTouche(valeurTouche, toucheTab);

    typedef struct {
        int x;
        int y;
    }coords;

    //Definition d'un objet joueur
    Personnage porg(pRenderer);
    //Definition du sol
    Sol sol(pRenderer);

    coords positionJoueur;
    positionJoueur.x = 0;
    positionJoueur.y = 4*90;

    int touche;

    //Sert au comptage de l'animation du joueur
    double compteur_index = 0.0;

    Bouton iconeMenu(resolutionecranx - resolutionecranx/40, resolutionecrany/24, resolutionecranx/20, resolutionecrany/12, pRenderer, 4);

    //Definition des poglemon de l'equipe qui sont de base inexistant (poglemon vide)
    Poglemon poglemon1(pRenderer, 0, "", 0, false);
    Poglemon poglemon2(pRenderer, 0, "", 0, false);
    Poglemon poglemon3(pRenderer, 0, "", 0, false);
    Poglemon poglemon4(pRenderer, 0, "", 0, false);
    Poglemon poglemon5(pRenderer, 0, "", 0, false);
    Poglemon poglemon6(pRenderer, 0, "", 0, false);

    Poglemon *pc[960];

    //FIN Initialisation Variable







    //Initialisation Musique

    Mix_Chunk* music = Mix_LoadWAV("sounds/musique.WAV");
    Mix_Chunk* sonBouton = Mix_LoadWAV("sounds/bouton.wav");

    if (music == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Erreur chargement de la musique : %s", Mix_GetError());
        SDL_Quit();
        return -1;
    }

    Mix_PlayChannel(0, music, -1);
    Mix_Volume(0, 20);
    Mix_Volume(1, 150);

    //Fin initialisation musique





    //Initialisation menu
menustart:

    int retourMenu = menuStart(pRenderer, resolutionecranx, resolutionecrany);
    Mix_PlayChannel(1, sonBouton, 0);

    if(retourMenu == -1){
        SDL_Quit();
    }

    if(retourMenu == 0){
        //Initialisation map
        if(initialisationMap(map) != 0){
            SDL_Quit();
            return -1;
        }
        for(int k = 0; k<960; k++){
            pc[k] = new Poglemon(pRenderer, 0, "", 0, false);
        }
    }

    if(retourMenu == 1){
        for(int k = 0; k<960; k++){
            pc[k] = new Poglemon(pRenderer, 0, "", 0, false);
        }
        chargement(&poglemon1, &poglemon2, &poglemon3, &poglemon4, &poglemon5, &poglemon6, pRenderer, &positionJoueur.x, &positionJoueur.y, map, pc);
    }

    if(retourMenu == 2){
        int retourOptions = menuOptions(&pRenderer, &pWindow, &resolutionecranx, &resolutionecrany, valeurTouche, stringTouche);
        Mix_PlayChannel(1, sonBouton, 0);
        if(retourOptions == 3){
            SDL_Log("test");
            porg.Reset(pRenderer);
            sol.Reset(pRenderer);
            poglemon1.Reset(pRenderer);poglemon2.Reset(pRenderer);poglemon3.Reset(pRenderer);poglemon4.Reset(pRenderer);poglemon5.Reset(pRenderer);poglemon6.Reset(pRenderer);
            iconeMenu.reset(resolutionecranx - resolutionecranx/40, resolutionecrany/24, resolutionecranx/20, resolutionecrany/12, pRenderer);
        }
        goto menustart;
    }

    //Fin initialisation menu







     while (isOpen)
    {


         while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                isOpen = false;
                break;

            case SDL_MOUSEBUTTONDOWN:
                if(iconeMenu.hoverBouton(events)){ //Si menu ouvert
                    Mix_PlayChannel(1, sonBouton, 0);
                    keys[toucheTab[4]] = true;
                    break;
                }else{
                    keys[toucheTab[5]] = true;
                    break;
                }

            case SDL_KEYDOWN:
                if(events.key.keysym.sym < 322){
                    keys[events.key.keysym.sym] = true;
                }
                break;

            case SDL_KEYUP:
                if(events.key.keysym.sym < 322){
                    keys[events.key.keysym.sym] = false;
                }
                break;

            case SDL_MOUSEBUTTONUP:
                keys[toucheTab[5]] = false;
                break;

            case SDL_MOUSEMOTION:
                iconeMenu.ChangeCouleurBouton(iconeMenu.hoverBouton(events));
                break;



            }
        }

        touche = PressionTouche(&pRenderer, &pWindow, keys, &resolutionecranx, &resolutionecrany, valeurTouche);




        //Mise a jour de l'objet porg(joueur)
        for(int k = 1; k<=4; k++){
            if(touche == k){
                if(porg.DetectionCollision(positionJoueur.x + 10*96, positionJoueur.y + 6*90, map, k, collision) == false){
                    porg.PressionToucheMouvement(k, &positionJoueur.x, &positionJoueur.y, pRenderer, map, resolutionecranx, resolutionecrany, porg, sol, iconeMenu);
                    bool isHerbe = porg.DetectionHerbe(positionJoueur.x/96 + 10, positionJoueur.y/90 + 6, map);
                    if(isHerbe == true){
                        int tmp = detectionCombat();
                        if(tmp != 0){
                            combat(pRenderer, porg.zone, tmp, resolutionecranx, resolutionecrany, &poglemon1, false, &poglemon2, &poglemon3, &poglemon4, &poglemon5, &poglemon6);
                            for(int k = 0; k<=321; k++){keys[k] = 0;}
                            Mix_PlayChannel(1, sonBouton, 0);
                        }
                    }
                }
            }
        }

        //Give pogle
        if(touche == 45){
            FinEvent(999, &poglemon1, &poglemon2, &poglemon3, &poglemon4, &poglemon5, &poglemon6, pc, pRenderer, map);
            SDL_Delay(50);
        }
        if(touche == 46){
            FinEvent(998, &poglemon1, &poglemon2, &poglemon3, &poglemon4, &poglemon5, &poglemon6, pc, pRenderer, map);
            SDL_Delay(50);
        }


        //Ouverture menu
        if(touche == 6){
            int retourMenuJeu = menuJeu(pRenderer, resolutionecranx, resolutionecrany);
            Mix_PlayChannel(1, sonBouton, 0);
            if(retourMenuJeu == 1){
                menuOptions(&pRenderer, &pWindow, &resolutionecranx, &resolutionecrany, valeurTouche, stringTouche);
                Mix_PlayChannel(1, sonBouton, 0);
                porg.Reset(pRenderer);
                sol.Reset(pRenderer);
                poglemon1.Reset(pRenderer);poglemon2.Reset(pRenderer);poglemon3.Reset(pRenderer);poglemon4.Reset(pRenderer);poglemon5.Reset(pRenderer);poglemon6.Reset(pRenderer);
                iconeMenu.reset(resolutionecranx - resolutionecranx/40, resolutionecrany/24, resolutionecranx/20, resolutionecrany/12, pRenderer);
                for(int k = 0; k<960; k++){pc[k]->Reset(pRenderer);}
                intTouche(valeurTouche, toucheTab);
            }
            if(retourMenuJeu == 2){
                menuEquipe(pRenderer, resolutionecranx, resolutionecrany, &poglemon1, &poglemon2, &poglemon3, &poglemon4, &poglemon5, &poglemon6, pc);
                Mix_PlayChannel(1, sonBouton, 0);
            }
            if(retourMenuJeu == 3){
                isOpen = false;
                break;
            }
            if(retourMenuJeu == 4){
                save(map, poglemon1, poglemon2, poglemon3, poglemon4, poglemon5, poglemon6, positionJoueur.x, positionJoueur.y, pc);
            }
            if(retourMenuJeu == 5){
                PC(pc, pRenderer, resolutionecranx, resolutionecrany, &poglemon1, &poglemon2, &poglemon3, &poglemon4, &poglemon5, &poglemon6);
                Mix_PlayChannel(1, sonBouton, 0);
            }
            for(int k = 0; k<=321; k++){keys[k] = 0;}
        }




        //Interaction
        if(touche == 7){
            int retourEvent = porg.DetectionEvent(positionJoueur.x + 10*96, positionJoueur.y + 6*90, map);
            if(retourEvent != 0){
                retourEvent = Event(retourEvent, resolutionecranx, resolutionecrany, pRenderer, valeurTouche, map, positionJoueur.x, positionJoueur.y, sol, porg, iconeMenu);
                for(int k = 0; k<=321; k++){keys[k] = 0;}
                FinEvent(retourEvent, &poglemon1, &poglemon2, &poglemon3, &poglemon4, &poglemon5, &poglemon6, pc, pRenderer, map);
            }

        }



        //Augmente régulierement l'index
        compteur_index += 0.08;
        if((int)compteur_index == 1){
            compteur_index = 0;
            porg.augmentIndex();
        }




        //Affichage
        SDL_RenderClear(pRenderer);

        sol.AffichageSol(pRenderer, map, positionJoueur.x, positionJoueur.y, resolutionecranx, resolutionecrany, 0, 0);
        porg.AffichageJoueur(pRenderer, resolutionecranx, resolutionecrany);
        iconeMenu.AffichageBouton(pRenderer);

        SDL_RenderPresent(pRenderer);

        SDL_Delay(5);

    }

    //Fin du programme, on libere la mémoire
    Mix_FreeChunk(sonBouton);
    Mix_FreeChunk(music);
    porg.DestroyPersonnage();
    sol.DestroySol();
    for(int k = 0; k<960; k++){
        delete pc[k];
    }
    iconeMenu.DestroyBouton();
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}
