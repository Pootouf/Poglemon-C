#include <SDL.h>
#include <SDL_mixer.h>

#include "Bouton.h"
#include "Poglemon.h"
#include "Pc.h"
#include <string>
#include "Menuequipe.h"

using namespace std;


void PC(Poglemon *pc[960], SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Poglemon *poglemon1, Poglemon *poglemon2, Poglemon *poglemon3, Poglemon *poglemon4, Poglemon *poglemon5, Poglemon *poglemon6){

    Bouton *poglemon[30];
    Bouton fond(resolutionecranx/2, resolutionecrany/2, resolutionecranx, resolutionecrany, pRenderer, 2);
    Bouton flecheGauche(resolutionecranx/9.6, resolutionecrany/2, resolutionecranx/7, resolutionecrany/2.16, pRenderer, 6);
    Bouton flecheDroite(resolutionecranx/1.12, resolutionecrany/2, resolutionecranx/7, resolutionecrany/2.16, pRenderer, 7);
    Bouton quitter(resolutionecranx/1.13, resolutionecrany/1.17, resolutionecranx/6.4, resolutionecrany/8.64, pRenderer, 1);


    int positionBoutonx = resolutionecranx/4.27;
    int positionBoutony = resolutionecrany/3.6;

    Mix_Chunk* sonBouton = Mix_LoadWAV("sounds/bouton.wav");

    Bouton boite(resolutionecranx/2, resolutionecrany/8.3, 0, 0, pRenderer, 1);

    for(int x = 0; x<=5; x++){
        for(int y = 0; y<=25; y+=6){
            poglemon[x+y] = new Bouton(positionBoutonx, positionBoutony, resolutionecranx/12, resolutionecrany/6.75, pRenderer, 5);
            positionBoutony += resolutionecrany/6.55;
        }
        positionBoutonx += resolutionecranx/9.6;
        positionBoutony = resolutionecrany/3.6;
    }

    bool isOpen = true;
    SDL_Event events;
    int numeroBoite = 1;

    int x, y;

    while(isOpen){
        AffichePC(pc, pRenderer, resolutionecranx, resolutionecrany, poglemon, fond, boite, numeroBoite, flecheGauche, flecheDroite, quitter);
        while (SDL_PollEvent(&events)) {
            switch(events.type){
                case SDL_MOUSEMOTION:
                    for(int k = 0; k<30; k++){
                        poglemon[k]->ChangeCouleurBouton(poglemon[k]->hoverBouton(events));
                    }
                    flecheGauche.ChangeCouleurBouton(flecheGauche.hoverBouton(events));
                    flecheDroite.ChangeCouleurBouton(flecheDroite.hoverBouton(events));
                    quitter.ChangeCouleurBouton(quitter.hoverBouton(events));
                    x = events.motion.x;
                    y = events.motion.y;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if(flecheGauche.hoverBouton(events) && numeroBoite==1){
                        Mix_PlayChannel(1, sonBouton, 0);
                        numeroBoite = 32;
                        break;
                    }
                    if(flecheGauche.hoverBouton(events) && numeroBoite>1){
                        Mix_PlayChannel(1, sonBouton, 0);
                        --numeroBoite;
                        break;
                    }
                    if(flecheDroite.hoverBouton(events) && numeroBoite==32){
                        Mix_PlayChannel(1, sonBouton, 0);
                        numeroBoite = 1;
                        break;
                    }
                    if(flecheDroite.hoverBouton(events) && numeroBoite<32){
                        Mix_PlayChannel(1, sonBouton, 0);
                        ++numeroBoite;
                        break;
                    }
                    if(quitter.hoverBouton(events)){
                        destructeurMenuPC(poglemon, fond, boite, flecheGauche, flecheDroite, quitter);
                        isOpen = false;
                        Mix_FreeChunk(sonBouton);
                        break;
                    }
                    for(int k = 0; k<30; k++){
                        if(poglemon[k]->hoverBouton(events) && pc[k+ 30*(numeroBoite-1)]->exist()){
                            if(x>= resolutionecranx/2){
                                x-= resolutionecranx/9.6;
                            }else{x+=resolutionecranx/9.6;}
                            if(y>= resolutionecrany/2){
                                y-=resolutionecrany/2.7;
                            }
                            Mix_PlayChannel(1, sonBouton, 0);
                            numeroBoite = menuPoglemonPC(pc , x, y, pc[k+ 30*(numeroBoite-1)], pRenderer, resolutionecranx, resolutionecrany, numeroBoite, poglemon1, poglemon2, poglemon3, poglemon4, poglemon5, poglemon6);
                            SDL_Log("Numero: %d", numeroBoite);
                            Mix_PlayChannel(1, sonBouton, 0);

                        }
                    }

            }
        }
    }


}


void AffichePC(Poglemon *pc[960], SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton *poglemon[30], Bouton fond, Bouton boite, int numeroBoite, Bouton flecheGauche, Bouton flecheDroite, Bouton quitter){

    fond.AffichageBouton(pRenderer);

    for(int k = 0; k<30; k++){
        poglemon[k]->AffichageBouton(pRenderer);
    }

    int positionx = resolutionecranx/4.27;
    int positiony = resolutionecrany/3.6;

    for(int x = 0; x<=5; x++){
        for(int y = 30*(numeroBoite-1); y<30*numeroBoite; y+=6){
            pc[x+y]->AffichePoglePC(pRenderer, positionx, positiony, resolutionecranx, resolutionecrany);
            positiony += resolutionecrany/6.55;
        }
        positionx += resolutionecranx/9.6;
        positiony = resolutionecrany/3.6;
    }

    flecheGauche.AffichageBouton(pRenderer);
    flecheDroite.AffichageBouton(pRenderer);
    quitter.AffichageBouton(pRenderer);
    quitter.AffichageTexte(pRenderer, "Quitter", resolutionecranx/32, SDL_Color{0,0,0,255});

    boite.AffichageTexte(pRenderer, string("Boite ") + to_string(numeroBoite), resolutionecranx/16, SDL_Color{0,0,0,255});

    SDL_RenderPresent(pRenderer);

    SDL_Delay(5);

}


void destructeurMenuPC(Bouton *poglemon[30], Bouton fond, Bouton boite, Bouton flecheGauche, Bouton flecheDroite, Bouton quitter){

    for(int k = 0; k<30; k++){
        delete poglemon[k];
        poglemon[k] ->DestroyBouton();
    }
    fond.DestroyBouton();
    boite.DestroyBouton();
    flecheGauche.DestroyBouton();
    flecheDroite.DestroyBouton();
    quitter.DestroyBouton();
}


int menuPoglemonPC(Poglemon *pc[960], int x, int y, Poglemon* pog, SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, int numBoite, Poglemon *poglemon1, Poglemon *poglemon2, Poglemon *poglemon3, Poglemon *poglemon4, Poglemon *poglemon5, Poglemon *poglemon6){

    Bouton resume(x, y, resolutionecranx/3.84, resolutionecrany/10.8, pRenderer, 1);
    Bouton deplacer(x, y + resolutionecrany/9, resolutionecranx/3.84, resolutionecrany/10.8, pRenderer, 1);
    Bouton envoyerequipe(x, y + resolutionecrany/4.5, resolutionecranx/3.84, resolutionecrany/10.8, pRenderer, 1);
    Bouton revenir(x, y + resolutionecrany/3, resolutionecranx/3.84, resolutionecrany/10.8, pRenderer, 1);

    bool isOpen = true;
    SDL_Event events;
    Mix_Chunk* sonBouton = Mix_LoadWAV("sounds/bouton.wav");

    while(isOpen){
        AfficheMenuPoglemonPC(pRenderer, resolutionecranx, resolutionecrany, resume, deplacer, envoyerequipe, revenir);
        while (SDL_PollEvent(&events)) {
            switch(events.type){
                case SDL_MOUSEMOTION:
                    resume.ChangeCouleurBouton(resume.hoverBouton(events));
                    deplacer.ChangeCouleurBouton(deplacer.hoverBouton(events));
                    envoyerequipe.ChangeCouleurBouton(envoyerequipe.hoverBouton(events));
                    revenir.ChangeCouleurBouton(revenir.hoverBouton(events));
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if(revenir.hoverBouton(events)){
                        isOpen = false;
                        destructeurMenuPoglemonPC(resume, deplacer, envoyerequipe, revenir);
                        Mix_FreeChunk(sonBouton);
                        return numBoite;
                    }
                    if(envoyerequipe.hoverBouton(events)){
                        if(!poglemon1->exist()){
                            EchangePogle(poglemon1, pog, pRenderer);
                        }else if(!poglemon2->exist()){
                            EchangePogle(poglemon2, pog, pRenderer);
                        }else if(!poglemon3->exist()){
                            EchangePogle(poglemon3, pog, pRenderer);
                        }else if(!poglemon4->exist()){
                            EchangePogle(poglemon4, pog, pRenderer);
                        }else if(!poglemon5->exist()){
                            EchangePogle(poglemon5, pog, pRenderer);
                        }else if(!poglemon6->exist()){
                            EchangePogle(poglemon6, pog, pRenderer);
                        }
                        isOpen = false;
                        destructeurMenuPoglemonPC(resume, deplacer, envoyerequipe, revenir);
                        Mix_FreeChunk(sonBouton);
                        return numBoite;

                    }
                    if(resume.hoverBouton(events)){
                        Mix_PlayChannel(1, sonBouton, 0);
                        pog->PoglemonStats(pRenderer, resolutionecranx, resolutionecrany);
                        Mix_PlayChannel(1, sonBouton, 0);
                        isOpen = false;
                        Mix_FreeChunk(sonBouton);
                        destructeurMenuPoglemonPC(resume, deplacer, envoyerequipe, revenir);
                        return numBoite;
                    }
                    if(deplacer.hoverBouton(events)){
                        isOpen = false;
                        Mix_PlayChannel(1, sonBouton, 0);
                        destructeurMenuPoglemonPC(resume, deplacer, envoyerequipe, revenir);
                        Mix_FreeChunk(sonBouton);
                        return deplacePC(pc, pRenderer, resolutionecranx, resolutionecrany, pog, numBoite);
                    }
            }
        }
    }
}


void AfficheMenuPoglemonPC(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton resume, Bouton deplacer, Bouton pc, Bouton revenir){


    resume.AffichageBouton(pRenderer);
    deplacer.AffichageBouton(pRenderer);
    pc.AffichageBouton(pRenderer);
    revenir.AffichageBouton(pRenderer);

    resume.AffichageTexte(pRenderer, "Resumer", resolutionecranx/32, SDL_Color{0,0,0,255});
    deplacer.AffichageTexte(pRenderer, "Deplacer", resolutionecranx/32, SDL_Color{0,0,0,255});
    pc.AffichageTexte(pRenderer, "Envoyer Equipe", resolutionecranx/32, SDL_Color{0,0,0,255});
    revenir.AffichageTexte(pRenderer, "Revenir", resolutionecranx/32, SDL_Color{0,0,0,255});

    SDL_RenderPresent(pRenderer);

    SDL_Delay(5);

}



void destructeurMenuPoglemonPC(Bouton resume, Bouton deplacer, Bouton pc, Bouton revenir){

    resume.DestroyBouton();
    deplacer.DestroyBouton();
    pc.DestroyBouton();
    revenir.DestroyBouton();

}


int deplacePC(Poglemon *pc[960], SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Poglemon* pog, int numBoite){

    Bouton *poglemon[30];
    Bouton fond(resolutionecranx/2, resolutionecrany/2, resolutionecranx, resolutionecrany, pRenderer, 2);
    Bouton flecheGauche(resolutionecranx/9.6, resolutionecrany/2, resolutionecranx/7, resolutionecrany/2.16, pRenderer, 6);
    Bouton flecheDroite(resolutionecranx/1.12, resolutionecrany/2, resolutionecranx/7, resolutionecrany/2.16, pRenderer, 7);
    Bouton quitter(resolutionecranx/1.13, resolutionecrany/1.17, resolutionecranx/6.4, resolutionecrany/8.64, pRenderer, 1);


    int positionBoutonx = resolutionecranx/4.27;
    int positionBoutony = resolutionecrany/3.6;

    Mix_Chunk* sonBouton = Mix_LoadWAV("sounds/bouton.wav");

    Bouton boite(resolutionecranx/2, resolutionecrany/8.3, 0, 0, pRenderer, 1);

    for(int x = 0; x<=5; x++){
        for(int y = 0; y<=25; y+=6){
            poglemon[x+y] = new Bouton(positionBoutonx, positionBoutony, resolutionecranx/12, resolutionecrany/6.75, pRenderer, 5);
            positionBoutony += resolutionecrany/6.55;
        }
        positionBoutonx += resolutionecranx/9.6;
        positionBoutony = resolutionecrany/3.6;
    }

    bool isOpen = true;
    SDL_Event events;
    int numeroBoite = numBoite;

    int x, y;

    while(isOpen){
        AffichePC(pc, pRenderer, resolutionecranx, resolutionecrany, poglemon, fond, boite, numeroBoite, flecheGauche, flecheDroite, quitter);
        while (SDL_PollEvent(&events)) {
            switch(events.type){
                case SDL_MOUSEMOTION:
                    for(int k = 0; k<30; k++){
                        poglemon[k]->ChangeCouleurBouton(poglemon[k]->hoverBouton(events));
                    }
                    flecheGauche.ChangeCouleurBouton(flecheGauche.hoverBouton(events));
                    flecheDroite.ChangeCouleurBouton(flecheDroite.hoverBouton(events));
                    quitter.ChangeCouleurBouton(quitter.hoverBouton(events));
                    x = events.motion.x;
                    y = events.motion.y;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if(flecheGauche.hoverBouton(events) && numeroBoite==1){
                        Mix_PlayChannel(1, sonBouton, 0);
                        numeroBoite = 32;
                        break;
                    }
                    if(flecheGauche.hoverBouton(events) && numeroBoite>1){
                        Mix_PlayChannel(1, sonBouton, 0);
                        --numeroBoite;
                        break;
                    }
                    if(flecheDroite.hoverBouton(events) && numeroBoite==32){
                        Mix_PlayChannel(1, sonBouton, 0);
                        numeroBoite = 1;
                        break;
                    }
                    if(flecheDroite.hoverBouton(events) && numeroBoite<32){
                        Mix_PlayChannel(1, sonBouton, 0);
                        ++numeroBoite;
                        break;
                    }
                    if(quitter.hoverBouton(events)){
                        destructeurMenuPC(poglemon, fond, boite, flecheGauche, flecheDroite, quitter);
                        isOpen = false;
                        Mix_FreeChunk(sonBouton);
                        return numBoite;
                    }
                    for(int k = 0; k<30; k++){
                        if(poglemon[k]->hoverBouton(events)){
                            EchangePogle(pog, pc[k + 30*(numeroBoite-1)], pRenderer);
                            isOpen = false;
                            Mix_FreeChunk(sonBouton);
                            destructeurMenuPC(poglemon, fond, boite, flecheGauche, flecheDroite, quitter);
                            return numeroBoite;
                        }
                    }

            }
        }
    }
}




