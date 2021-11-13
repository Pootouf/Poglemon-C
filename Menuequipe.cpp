#include <SDL.h>
#include <SDL_mixer.h>

#include "Bouton.h"
#include "Menuequipe.h"
#include "Poglemon.h"


void menuEquipe(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Poglemon *poglemon1, Poglemon *poglemon2, Poglemon *poglemon3, Poglemon *poglemon4, Poglemon *poglemon5, Poglemon *poglemon6, Poglemon *pc[960]){

    Bouton menu(resolutionecranx/2, resolutionecrany/2, resolutionecranx, resolutionecrany, pRenderer, 2);
    Bouton boutonpoglemon1(resolutionecranx/19.2 + (resolutionecranx/2.53)/2, resolutionecrany/21.6 + (resolutionecrany/4.15)/2, resolutionecranx/2.53, resolutionecrany/3.8, pRenderer, 3);
    Bouton boutonpoglemon2(resolutionecranx/1.8 + (resolutionecranx/2.53)/2, resolutionecrany/21.6 + (resolutionecrany/4.15)/2, resolutionecranx/2.53, resolutionecrany/3.8, pRenderer, 3);
    Bouton boutonpoglemon3(resolutionecranx/19.2 + (resolutionecranx/2.53)/2, resolutionecrany/3.13 + (resolutionecrany/4.15)/2, resolutionecranx/2.53, resolutionecrany/3.8, pRenderer, 3);
    Bouton boutonpoglemon4(resolutionecranx/1.8 + (resolutionecranx/2.53)/2, resolutionecrany/3.13 + (resolutionecrany/4.15)/2, resolutionecranx/2.53, resolutionecrany/3.8, pRenderer, 3);
    Bouton boutonpoglemon5(resolutionecranx/19.2 + (resolutionecranx/2.53)/2, resolutionecrany/1.69 + (resolutionecrany/4.15)/2, resolutionecranx/2.53, resolutionecrany/3.8, pRenderer, 3);
    Bouton boutonpoglemon6(resolutionecranx/1.8 + (resolutionecranx/2.53)/2, resolutionecrany/1.69 + (resolutionecrany/4.15)/2, resolutionecranx/2.53, resolutionecrany/3.8, pRenderer, 3);
    Bouton quitter(resolutionecranx/2, resolutionecrany/1.1, resolutionecranx/3.2, resolutionecrany/10.8, pRenderer, 1);

    bool menuPause = true;

    Mix_Chunk* sonBouton = Mix_LoadWAV("sounds/bouton.wav");

    SDL_Event events;

    int retourMenu;

    int x, y;

    while(menuPause == true){
        AfficheMenuEquipe(pRenderer, resolutionecranx, resolutionecrany, menu, boutonpoglemon1, boutonpoglemon2, boutonpoglemon3, boutonpoglemon4, boutonpoglemon5, boutonpoglemon6, quitter, *poglemon1, *poglemon2, *poglemon3, *poglemon4, *poglemon5, *poglemon6);
        while (SDL_PollEvent(&events)) {
            switch(events.type){
                case SDL_MOUSEMOTION:
                    boutonpoglemon1.ChangeCouleurBouton(boutonpoglemon1.hoverBouton(events));
                    boutonpoglemon2.ChangeCouleurBouton(boutonpoglemon2.hoverBouton(events));
                    boutonpoglemon3.ChangeCouleurBouton(boutonpoglemon3.hoverBouton(events));
                    boutonpoglemon4.ChangeCouleurBouton(boutonpoglemon4.hoverBouton(events));
                    boutonpoglemon5.ChangeCouleurBouton(boutonpoglemon5.hoverBouton(events));
                    boutonpoglemon6.ChangeCouleurBouton(boutonpoglemon6.hoverBouton(events));
                    quitter.ChangeCouleurBouton(quitter.hoverBouton(events));
                    x = events.motion.x;
                    y = events.motion.y;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if(quitter.hoverBouton(events)){
                        menuPause = false;
                        Mix_FreeChunk(sonBouton);
                        destructeurMenuEquipe(menu, boutonpoglemon1, boutonpoglemon2, boutonpoglemon3, boutonpoglemon4, boutonpoglemon5, boutonpoglemon6, quitter);
                        break;
                    }
                    if(boutonpoglemon1.hoverBouton(events) || boutonpoglemon2.hoverBouton(events) || boutonpoglemon3.hoverBouton(events) || boutonpoglemon4.hoverBouton(events) || boutonpoglemon5.hoverBouton(events) || boutonpoglemon6.hoverBouton(events)){
                        if(x>= resolutionecranx/2){
                            x-= resolutionecranx/9.6;
                        }else{x+=resolutionecranx/9.6;}
                        if(y>= resolutionecrany/2){
                            y-=resolutionecrany/2.7;
                        }

                        Mix_PlayChannel(1, sonBouton, 0);

                        if(boutonpoglemon1.hoverBouton(events) && (*poglemon1).exist()){
                            retourMenu = menuPoglemon(x, y, poglemon1, pRenderer, resolutionecranx, resolutionecrany, poglemon1, poglemon2, poglemon3, poglemon4, poglemon5, poglemon6, pc);
                        }
                        if(boutonpoglemon2.hoverBouton(events)&& (*poglemon2).exist()){
                            retourMenu = menuPoglemon(x, y, poglemon2, pRenderer, resolutionecranx, resolutionecrany, poglemon1, poglemon2, poglemon3, poglemon4, poglemon5, poglemon6, pc);
                        }
                        if(boutonpoglemon3.hoverBouton(events)&& (*poglemon3).exist()){
                            retourMenu = menuPoglemon(x, y, poglemon3, pRenderer, resolutionecranx, resolutionecrany, poglemon1, poglemon2, poglemon3, poglemon4, poglemon5, poglemon6, pc);
                        }
                        if(boutonpoglemon4.hoverBouton(events)&& (*poglemon4).exist()){
                            retourMenu = menuPoglemon(x, y, poglemon4, pRenderer, resolutionecranx, resolutionecrany, poglemon1, poglemon2, poglemon3, poglemon4, poglemon5, poglemon6, pc);
                        }
                        if(boutonpoglemon5.hoverBouton(events)&& (*poglemon5).exist()){
                            retourMenu = menuPoglemon(x, y, poglemon5, pRenderer, resolutionecranx, resolutionecrany, poglemon1, poglemon2, poglemon3, poglemon4, poglemon5, poglemon6, pc);
                        }
                        if(boutonpoglemon6.hoverBouton(events)&& (*poglemon6).exist()){
                            retourMenu = menuPoglemon(x, y, poglemon6, pRenderer, resolutionecranx, resolutionecrany, poglemon1, poglemon2, poglemon3, poglemon4, poglemon5, poglemon6, pc);
                        }

                        Mix_PlayChannel(1, sonBouton, 0);
                        x -= resolutionecranx/9.6;

                    }

            }
        }
    }
}

void AfficheMenuEquipe(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton menu, Bouton boutonpoglemon1, Bouton boutonpoglemon2, Bouton boutonpoglemon3, Bouton boutonpoglemon4, Bouton boutonpoglemon5, Bouton boutonpoglemon6, Bouton quitter, Poglemon poglemon1, Poglemon poglemon2, Poglemon poglemon3, Poglemon poglemon4, Poglemon poglemon5, Poglemon poglemon6){

    menu.AffichageBouton(pRenderer);
    boutonpoglemon1.AffichageBouton(pRenderer);
    boutonpoglemon2.AffichageBouton(pRenderer);
    boutonpoglemon3.AffichageBouton(pRenderer);
    boutonpoglemon4.AffichageBouton(pRenderer);
    boutonpoglemon5.AffichageBouton(pRenderer);
    boutonpoglemon6.AffichageBouton(pRenderer);
    quitter.AffichageBouton(pRenderer);

    poglemon1.AffichePogEquipe(1, resolutionecranx, resolutionecrany, pRenderer);
    poglemon2.AffichePogEquipe(2, resolutionecranx, resolutionecrany, pRenderer);
    poglemon3.AffichePogEquipe(3, resolutionecranx, resolutionecrany, pRenderer);
    poglemon4.AffichePogEquipe(4, resolutionecranx, resolutionecrany, pRenderer);
    poglemon5.AffichePogEquipe(5, resolutionecranx, resolutionecrany, pRenderer);
    poglemon6.AffichePogEquipe(6, resolutionecranx, resolutionecrany, pRenderer);

    quitter.AffichageTexte(pRenderer, "Revenir", resolutionecranx/32, SDL_Color{0,0,0,255});

    SDL_RenderPresent(pRenderer);

    SDL_Delay(5);

}

void destructeurMenuEquipe(Bouton menu, Bouton boutonpoglemon1, Bouton boutonpoglemon2, Bouton boutonpoglemon3, Bouton boutonpoglemon4, Bouton boutonpoglemon5, Bouton boutonpoglemon6, Bouton quitter){
    menu.DestroyBouton();
    boutonpoglemon1.DestroyBouton();
    boutonpoglemon2.DestroyBouton();
    boutonpoglemon3.DestroyBouton();
    boutonpoglemon4.DestroyBouton();
    boutonpoglemon5.DestroyBouton();
    boutonpoglemon6.DestroyBouton();
    quitter.DestroyBouton();

}


int menuPoglemon(int x, int y, Poglemon* pog, SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Poglemon *poglemon1, Poglemon *poglemon2, Poglemon *poglemon3, Poglemon *poglemon4, Poglemon *poglemon5, Poglemon *poglemon6, Poglemon *pc[960]){

    Bouton resume(x, y, resolutionecranx/3.84, resolutionecrany/10.8, pRenderer, 1);
    Bouton deplacer(x, y + resolutionecrany/9, resolutionecranx/3.84, resolutionecrany/10.8, pRenderer, 1);
    Bouton envoyerpc(x, y + resolutionecrany/4.5, resolutionecranx/3.84, resolutionecrany/10.8, pRenderer, 1);
    Bouton revenir(x, y + resolutionecrany/3, resolutionecranx/3.84, resolutionecrany/10.8, pRenderer, 1);

    bool isOpen = true;
    SDL_Event events;
    Mix_Chunk* sonBouton = Mix_LoadWAV("sounds/bouton.wav");

    while(isOpen){
        AfficheMenuPoglemon(pRenderer, resolutionecranx, resolutionecrany, resume, deplacer, envoyerpc, revenir);
        while (SDL_PollEvent(&events)) {
            switch(events.type){
                case SDL_MOUSEMOTION:
                    resume.ChangeCouleurBouton(resume.hoverBouton(events));
                    deplacer.ChangeCouleurBouton(deplacer.hoverBouton(events));
                    envoyerpc.ChangeCouleurBouton(envoyerpc.hoverBouton(events));
                    revenir.ChangeCouleurBouton(revenir.hoverBouton(events));
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if(revenir.hoverBouton(events)){
                        isOpen = false;
                        destructeurMenuPoglemon(resume, deplacer, envoyerpc, revenir);
                        Mix_FreeChunk(sonBouton);
                        return 0;
                    }
                    if(envoyerpc.hoverBouton(events)){
                        isOpen = false;
                        destructeurMenuPoglemon(resume, deplacer, envoyerpc, revenir);
                        Mix_FreeChunk(sonBouton);
                        int x = -1;
                        for(int k = 0; k<960; k++){
                            if(!pc[k]->exist()){
                                x = k;
                                break;
                            }
                        }
                        if(x != -1 && poglemon2->exist()){
                            (*pog).soin();
                            EchangePogle(pog, pc[x], pRenderer);
                        }
                        OrdreEquipe(poglemon1, poglemon2, poglemon3, poglemon4, poglemon5, poglemon6, pRenderer);
                        return 0;
                    }
                    if(resume.hoverBouton(events)){
                        Mix_PlayChannel(1, sonBouton, 0);
                        (*pog).PoglemonStats(pRenderer, resolutionecranx, resolutionecrany);
                        Mix_PlayChannel(1, sonBouton, 0);
                        isOpen = false;
                        Mix_FreeChunk(sonBouton);
                        destructeurMenuPoglemon(resume, deplacer, envoyerpc, revenir);
                        return 0;
                    }
                    if(deplacer.hoverBouton(events)){
                        isOpen = false;
                        Mix_PlayChannel(1, sonBouton, 0);
                        destructeurMenuPoglemon(resume, deplacer, envoyerpc, revenir);
                        choixDeplacement(pRenderer, resolutionecranx, resolutionecrany, poglemon1, poglemon2, poglemon3, poglemon4, poglemon5, poglemon6, pog);
                        Mix_FreeChunk(sonBouton);
                        return 3;
                    }

            }
        }
    }

}

void AfficheMenuPoglemon(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton resume, Bouton deplacer, Bouton pc, Bouton revenir){


    resume.AffichageBouton(pRenderer);
    deplacer.AffichageBouton(pRenderer);
    pc.AffichageBouton(pRenderer);
    revenir.AffichageBouton(pRenderer);

    resume.AffichageTexte(pRenderer, "Resumer", resolutionecranx/32, SDL_Color{0,0,0,255});
    deplacer.AffichageTexte(pRenderer, "Deplacer", resolutionecranx/32, SDL_Color{0,0,0,255});
    pc.AffichageTexte(pRenderer, "Envoyer PC", resolutionecranx/32, SDL_Color{0,0,0,255});
    revenir.AffichageTexte(pRenderer, "Revenir", resolutionecranx/32, SDL_Color{0,0,0,255});

    SDL_RenderPresent(pRenderer);

    SDL_Delay(5);

}



void destructeurMenuPoglemon(Bouton resume, Bouton deplacer, Bouton pc, Bouton revenir){

    resume.DestroyBouton();
    deplacer.DestroyBouton();
    pc.DestroyBouton();
    revenir.DestroyBouton();

}


void choixDeplacement(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Poglemon *poglemon1, Poglemon *poglemon2, Poglemon *poglemon3, Poglemon *poglemon4, Poglemon *poglemon5, Poglemon *poglemon6, Poglemon *pog){

    Bouton menu_d(resolutionecranx/2, resolutionecrany/2, resolutionecranx, resolutionecrany, pRenderer, 2);
    Bouton boutonpoglemon1_d(resolutionecranx/19.2 + (resolutionecranx/2.53)/2, resolutionecrany/21.6 + (resolutionecrany/4.15)/2, resolutionecranx/2.53, resolutionecrany/3.8, pRenderer, 3);
    Bouton boutonpoglemon2_d(resolutionecranx/1.8 + (resolutionecranx/2.53)/2, resolutionecrany/21.6 + (resolutionecrany/4.15)/2, resolutionecranx/2.53, resolutionecrany/3.8, pRenderer, 3);
    Bouton boutonpoglemon3_d(resolutionecranx/19.2 + (resolutionecranx/2.53)/2, resolutionecrany/3.13 + (resolutionecrany/4.15)/2, resolutionecranx/2.53, resolutionecrany/3.8, pRenderer, 3);
    Bouton boutonpoglemon4_d(resolutionecranx/1.8 + (resolutionecranx/2.53)/2, resolutionecrany/3.13 + (resolutionecrany/4.15)/2, resolutionecranx/2.53, resolutionecrany/3.8, pRenderer, 3);
    Bouton boutonpoglemon5_d(resolutionecranx/19.2 + (resolutionecranx/2.53)/2, resolutionecrany/1.69 + (resolutionecrany/4.15)/2, resolutionecranx/2.53, resolutionecrany/3.8, pRenderer, 3);
    Bouton boutonpoglemon6_d(resolutionecranx/1.8 + (resolutionecranx/2.53)/2, resolutionecrany/1.69 + (resolutionecrany/4.15)/2, resolutionecranx/2.53, resolutionecrany/3.8, pRenderer, 3);
    Bouton quitter_d(resolutionecranx/2, resolutionecrany/1.1, resolutionecranx/3.2, resolutionecrany/10.8, pRenderer, 1);

    bool menuPause = true;

    Mix_Chunk* sonBouton = Mix_LoadWAV("sounds/bouton.wav");

    SDL_Event events;

    while(menuPause == true){
        AfficheMenuEquipe(pRenderer, resolutionecranx, resolutionecrany, menu_d, boutonpoglemon1_d, boutonpoglemon2_d, boutonpoglemon3_d, boutonpoglemon4_d, boutonpoglemon5_d, boutonpoglemon6_d, quitter_d, *poglemon1, *poglemon2, *poglemon3, *poglemon4, *poglemon5, *poglemon6);
        while (SDL_PollEvent(&events)) {
            switch(events.type){
                case SDL_MOUSEMOTION:
                    boutonpoglemon1_d.ChangeCouleurBouton(boutonpoglemon1_d.hoverBouton(events));
                    boutonpoglemon2_d.ChangeCouleurBouton(boutonpoglemon2_d.hoverBouton(events));
                    boutonpoglemon3_d.ChangeCouleurBouton(boutonpoglemon3_d.hoverBouton(events));
                    boutonpoglemon4_d.ChangeCouleurBouton(boutonpoglemon4_d.hoverBouton(events));
                    boutonpoglemon5_d.ChangeCouleurBouton(boutonpoglemon5_d.hoverBouton(events));
                    boutonpoglemon6_d.ChangeCouleurBouton(boutonpoglemon6_d.hoverBouton(events));
                    quitter_d.ChangeCouleurBouton(quitter_d.hoverBouton(events));
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if(quitter_d.hoverBouton(events)){
                        menuPause = false;
                        Mix_FreeChunk(sonBouton);
                        destructeurMenuEquipe(menu_d, boutonpoglemon1_d, boutonpoglemon2_d, boutonpoglemon3_d, boutonpoglemon4_d, boutonpoglemon5_d, boutonpoglemon6_d, quitter_d);
                        break;
                    }
                    if(boutonpoglemon1_d.hoverBouton(events) && (*poglemon1).exist()){
                        EchangePogle(pog, poglemon1, pRenderer);
                        menuPause = false;
                        Mix_FreeChunk(sonBouton);
                        destructeurMenuEquipe(menu_d, boutonpoglemon1_d, boutonpoglemon2_d, boutonpoglemon3_d, boutonpoglemon4_d, boutonpoglemon5_d, boutonpoglemon6_d, quitter_d);
                        break;
                    }
                    if(boutonpoglemon2_d.hoverBouton(events) && (*poglemon2).exist()){
                        EchangePogle(pog, poglemon2, pRenderer);
                        menuPause = false;
                        Mix_FreeChunk(sonBouton);
                        destructeurMenuEquipe(menu_d, boutonpoglemon1_d, boutonpoglemon2_d, boutonpoglemon3_d, boutonpoglemon4_d, boutonpoglemon5_d, boutonpoglemon6_d, quitter_d);
                        break;
                    }
                    if(boutonpoglemon3_d.hoverBouton(events) && (*poglemon3).exist()){
                        EchangePogle(pog, poglemon3, pRenderer);
                        menuPause = false;
                        Mix_FreeChunk(sonBouton);
                        destructeurMenuEquipe(menu_d, boutonpoglemon1_d, boutonpoglemon2_d, boutonpoglemon3_d, boutonpoglemon4_d, boutonpoglemon5_d, boutonpoglemon6_d, quitter_d);
                        break;
                    }
                    if(boutonpoglemon4_d.hoverBouton(events) && (*poglemon4).exist()){
                        EchangePogle(pog, poglemon4, pRenderer);
                        menuPause = false;
                        Mix_FreeChunk(sonBouton);
                        destructeurMenuEquipe(menu_d, boutonpoglemon1_d, boutonpoglemon2_d, boutonpoglemon3_d, boutonpoglemon4_d, boutonpoglemon5_d, boutonpoglemon6_d, quitter_d);
                        break;
                    }
                    if(boutonpoglemon5_d.hoverBouton(events) && (*poglemon5).exist()){
                        EchangePogle(pog, poglemon5, pRenderer);
                        menuPause = false;
                        Mix_FreeChunk(sonBouton);
                        destructeurMenuEquipe(menu_d, boutonpoglemon1_d, boutonpoglemon2_d, boutonpoglemon3_d, boutonpoglemon4_d, boutonpoglemon5_d, boutonpoglemon6_d, quitter_d);
                        break;
                    }
                    if(boutonpoglemon6_d.hoverBouton(events) && (*poglemon6).exist()){
                        EchangePogle(pog, poglemon6, pRenderer);
                        menuPause = false;
                        Mix_FreeChunk(sonBouton);
                        destructeurMenuEquipe(menu_d, boutonpoglemon1_d, boutonpoglemon2_d, boutonpoglemon3_d, boutonpoglemon4_d, boutonpoglemon5_d, boutonpoglemon6_d, quitter_d);
                        break;
                    }
            }
        }
    }

}

void EchangePogle(Poglemon* poglemon1, Poglemon* poglemon2, SDL_Renderer* pRenderer){

    Poglemon tmp(pRenderer, 0, "", 0, false);
    tmp = *poglemon1;
    *poglemon1 = *poglemon2;
    *poglemon2 = tmp;
    (*poglemon2).Reset(pRenderer);
    tmp.destructeurPoglemon();
}


void OrdreEquipe(Poglemon *poglemon1, Poglemon *poglemon2, Poglemon *poglemon3, Poglemon *poglemon4, Poglemon *poglemon5, Poglemon *poglemon6, SDL_Renderer* pRenderer){

    if(!poglemon1->exist() && poglemon2->exist()){
        EchangePogle(poglemon1, poglemon2, pRenderer);
    }
    if(!poglemon2->exist() && poglemon3->exist()){
        EchangePogle(poglemon2, poglemon3, pRenderer);
    }
    if(!poglemon3->exist() && poglemon4->exist()){
        EchangePogle(poglemon3, poglemon4, pRenderer);
    }
    if(!poglemon4->exist() && poglemon5->exist()){
        EchangePogle(poglemon4, poglemon5, pRenderer);
    }
    if(!poglemon5->exist() && poglemon6->exist()){
        EchangePogle(poglemon5, poglemon6, pRenderer);
    }

}
