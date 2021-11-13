#include <SDL.h>

#include "Bouton.h"
#include "Menu.h"


int menuStart(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany){

    Bouton titre(resolutionecranx/2, resolutionecrany/6, resolutionecranx/2.67, resolutionecrany/8.64, pRenderer, 1);
    Bouton nPartie(resolutionecranx/2, resolutionecrany/3, resolutionecranx/2.67, resolutionecrany/8.64, pRenderer, 1);
    Bouton cPartie(resolutionecranx/2, resolutionecrany/2, resolutionecranx/2.67, resolutionecrany/8.64, pRenderer, 1);
    Bouton options(resolutionecranx/2, resolutionecrany/1.5, resolutionecranx/2.67, resolutionecrany/8.64, pRenderer, 1);
    Bouton quitter(resolutionecranx/2, resolutionecrany/1.2, resolutionecranx/2.67, resolutionecrany/8.64, pRenderer, 1);

    AfficheMenu(pRenderer, resolutionecranx, resolutionecrany, titre, nPartie, cPartie, options, quitter);


    SDL_Event events;

    bool menuPause = true;

    while(menuPause == true){
        AfficheMenu(pRenderer, resolutionecranx, resolutionecrany, titre, nPartie, cPartie, options, quitter);
        while (SDL_PollEvent(&events)) {
            switch(events.type){
                case SDL_MOUSEMOTION:
                    nPartie.ChangeCouleurBouton(nPartie.hoverBouton(events));
                    cPartie.ChangeCouleurBouton(cPartie.hoverBouton(events));
                    options.ChangeCouleurBouton(options.hoverBouton(events));
                    quitter.ChangeCouleurBouton(quitter.hoverBouton(events));
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(quitter.hoverBouton(events)){
                        destructeur(titre, nPartie, cPartie, options, quitter);
                        return -1;
                    }
                    if(options.hoverBouton(events)){
                        destructeur(titre, nPartie, cPartie, options, quitter);
                        return 2;
                    }
                    if(cPartie.hoverBouton(events)){
                        destructeur(titre, nPartie, cPartie, options, quitter);
                        return 1;
                    }
                    if(nPartie.hoverBouton(events)){
                        destructeur(titre, nPartie, cPartie, options, quitter);
                        return 0;
                    }
            }
        }
    }
    return 0;
}





void AfficheMenu(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton titre, Bouton nPartie, Bouton cPartie, Bouton options, Bouton quitter){

    SDL_SetRenderDrawColor(pRenderer, 128, 128, 128, 255);
    SDL_RenderClear(pRenderer);

    nPartie.AffichageBouton(pRenderer);
    cPartie.AffichageBouton(pRenderer);
    options.AffichageBouton(pRenderer);
    quitter.AffichageBouton(pRenderer);

    titre.AffichageTexte(pRenderer, "POGLEMON", resolutionecranx/19.2, SDL_Color{0,0,0,255});
    nPartie.AffichageTexte(pRenderer, "Nouvelle Partie", resolutionecranx/32, SDL_Color{0,0,0,255});
    cPartie.AffichageTexte(pRenderer, "Continuer la Partie", resolutionecranx/32, SDL_Color{0,0,0,255});
    options.AffichageTexte(pRenderer, "Options", resolutionecranx/32, SDL_Color{0,0,0,255});
    quitter.AffichageTexte(pRenderer, "Quitter", resolutionecranx/32, SDL_Color{0,0,0,255});



    SDL_RenderPresent(pRenderer);

    SDL_Delay(5);
}

void destructeur(Bouton titre, Bouton nPartie, Bouton cPartie, Bouton options, Bouton quitter){
    titre.DestroyBouton();
    nPartie.DestroyBouton();
    cPartie.DestroyBouton();
    options.DestroyBouton();
    quitter.DestroyBouton();
}



