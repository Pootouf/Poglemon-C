#include <SDL.h>
#include "Bouton.h"
#include <string>
#include <vector>
#include "Poglemon.h"
#include "Sol.h"
#include "Personnage.h"

#define TAILLE_MAP 3600

using namespace std;

int Event(int idEvent, int resolutionecranx, int resolutionecrany, SDL_Renderer* pRenderer, string valeurTouche[322],  int map[TAILLE_MAP][TAILLE_MAP], int positionx, int positiony, Sol sol, Personnage porg, Bouton iconeMenu){

    bool isOpen = true;
    bool isChoice;
    int eventPos = 0;
    Bouton dialogue(resolutionecranx/2, resolutionecrany/1.20, resolutionecranx, resolutionecrany/3.6, pRenderer, 1);
    Bouton confirmer(0, 0, 0, 0, pRenderer, 1);
    Bouton annuler(0, 0, 0, 0, pRenderer, 1);
    confirmer.DestroyBouton();
    annuler.DestroyBouton();
    SDL_Event events;
    vector<string> texte;

    int toucheTab[6];
    string valeur[6] = {"Z", "Q", "D", "S", "I", "Espace"};

    for(int x = 0; x<=5; x++){
        for(int k = 0; k<=321; k++){
            if(valeurTouche[k] == valeur[x]){
                toucheTab[x] = k;
            }

        }
    }

    if(idEvent == 7){
        texte.push_back("Voulez-vous soigner vos poglemon?");
        isChoice = true;
    }else{
    if(idEvent == 15){
        texte.push_back("Bonjour mon nom est dinde;Je suis le maitre;ragondinde");
        texte.push_back("je rejoins ton équipe");
        isChoice = false;
    }else{
    if(idEvent == 16){
        texte.push_back("Voulez vous choisir Poupinus?");
        texte.push_back("Vous choisissez Poupinus");
        isChoice = true;
    }else{
    if(idEvent == 17){
        texte.push_back("Voulez vous choisir Nuageon?");
        texte.push_back("Vous choisissez Nuageon");
        isChoice = true;
    }else{
    if(idEvent == 18){
        texte.push_back("Voulez vous choisir Pingouinou?");
        texte.push_back("Vous choisissez Pingouinou");
        isChoice = true;
    }else{return 0;}}}}}

    if(isChoice == true){
        confirmer = *(new Bouton(resolutionecranx/1.32, resolutionecrany/1.54, resolutionecranx/2.67, resolutionecrany/7.2, pRenderer, 1));
        annuler = *(new Bouton(resolutionecranx/3.6, resolutionecrany/1.54, resolutionecranx/2.67, resolutionecrany/7.2, pRenderer, 1));
    }


    while(isOpen){

        dialogue.AffichageBouton(pRenderer);
        if(isChoice == true){
            confirmer.AffichageBouton(pRenderer);
            annuler.AffichageBouton(pRenderer);
            confirmer.AffichageTexte(pRenderer, "Confirmer", resolutionecranx/32, SDL_Color{0,0,0,255});
            annuler.AffichageTexte(pRenderer, "Annuler", resolutionecranx/32, SDL_Color{0,0,0,255});
        }
        dialogue.AffichageTexteDialogue(pRenderer, texte[eventPos], resolutionecranx/32, SDL_Color{0,0,0,255}, resolutionecranx, resolutionecrany);
        SDL_RenderPresent(pRenderer);

        SDL_Delay(5);

        while (SDL_PollEvent(&events)) {
            switch(events.type){
                case SDL_MOUSEMOTION:
                    if(isChoice == true){
                        confirmer.ChangeCouleurBouton(confirmer.hoverBouton(events));
                        annuler.ChangeCouleurBouton(annuler.hoverBouton(events));
                    }
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    souris:
                    if(isChoice==true){
                        if(annuler.hoverBouton(events)){
                            isOpen = false;
                            dialogue.DestroyBouton();
                            delete &confirmer;
                            delete &annuler;
                            return 0;
                        }
                        if(confirmer.hoverBouton(events)){
                            isChoice = false;
                            delete &confirmer;
                            delete &annuler;
                            sol.AffichageSol(pRenderer, map, positionx, positiony, resolutionecranx, resolutionecrany, 0, 0);
                            porg.AffichageJoueur(pRenderer, resolutionecranx, resolutionecrany);
                            iconeMenu.AffichageBouton(pRenderer);
                        }
                    }
                    if(isChoice == false){
                        ++eventPos;
                        if(texte.size() == eventPos){
                            isOpen = false;
                            dialogue.DestroyBouton();
                            return idEvent;
                        }
                    }
                    break;



                case SDL_KEYDOWN:
                    if (toucheTab[5] == events.key.keysym.sym){
                       goto souris;
                    }
                    break;

            }
        }

    }
    return 0;
}



void FinEvent(int idEvent, Poglemon* poglemon1, Poglemon* poglemon2, Poglemon* poglemon3, Poglemon* poglemon4, Poglemon* poglemon5, Poglemon* poglemon6, Poglemon *pc[960], SDL_Renderer* pRenderer, int map[TAILLE_MAP][TAILLE_MAP]){

    if(idEvent == 7){
        (*poglemon1).soin();
        (*poglemon2).soin();
        (*poglemon3).soin();
        (*poglemon4).soin();
        (*poglemon5).soin();
        (*poglemon6).soin();
    }
    if(idEvent == 15){
        newPoglemon(poglemon1, poglemon2, poglemon3, poglemon4, poglemon5, poglemon6, pc, pRenderer, 999, "", 5);
        for(int k = 26; k<36; k++){
            map[17][k] = 0;
            map[16][k] = 0;
        }
    }
    if(idEvent == 16){
        newPoglemon(poglemon1, poglemon2, poglemon3, poglemon4, poglemon5, poglemon6, pc, pRenderer, 4, "", 5);
    }
    if(idEvent == 17){
        newPoglemon(poglemon1, poglemon2, poglemon3, poglemon4, poglemon5, poglemon6, pc, pRenderer, 1, "", 5);
    }
    if(idEvent == 18){
        newPoglemon(poglemon1, poglemon2, poglemon3, poglemon4, poglemon5, poglemon6, pc, pRenderer, 7, "", 5);
    }
    if(idEvent == 998){
        newPoglemon(poglemon1, poglemon2, poglemon3, poglemon4, poglemon5, poglemon6, pc, pRenderer, 10, "", 10);
    }
    if(idEvent == 999){
        newPoglemon(poglemon1, poglemon2, poglemon3, poglemon4, poglemon5, poglemon6, pc, pRenderer, 11, "", 51);
    }
}


