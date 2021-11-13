#include <SDL.h>

#include "Bouton.h"
#include "Optionsjeu.h"
#include "Options.h"


int menuJeu(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany){

    Bouton equipe(resolutionecranx/1.17, resolutionecrany/13.5, resolutionecranx/5.33, resolutionecrany/8.64, pRenderer, 1);
    Bouton sac(resolutionecranx/1.17, resolutionecrany/5.02, resolutionecranx/5.33, resolutionecrany/8.64, pRenderer, 1);
    Bouton pc(resolutionecranx/1.17, resolutionecrany/3.09, resolutionecranx/5.33, resolutionecrany/8.64, pRenderer, 1);
    Bouton options(resolutionecranx/1.17, resolutionecrany/2.23, resolutionecranx/5.33, resolutionecrany/8.64, pRenderer, 1);
    Bouton revenir(resolutionecranx/1.17, resolutionecrany/1.42, resolutionecranx/5.33, resolutionecrany/8.64, pRenderer, 1);
    Bouton sauvegarder(resolutionecranx/1.17, resolutionecrany/1.74, resolutionecranx/5.33, resolutionecrany/8.64, pRenderer, 1);
    Bouton quitter(resolutionecranx/1.17, resolutionecrany/1.2, resolutionecranx/5.33, resolutionecrany/8.64, pRenderer, 1);
    Bouton iconeMenu(resolutionecranx - resolutionecranx/40, resolutionecrany/24, resolutionecranx/20, resolutionecrany/12, pRenderer, 4);


    SDL_Event events;

    bool menuPause = true;

    while(menuPause == true){
        AfficheMenuJeu(pRenderer, resolutionecranx, resolutionecrany, equipe, sac, pc, options, quitter, revenir, sauvegarder, iconeMenu);
        while (SDL_PollEvent(&events)) {
            switch(events.type){
                case SDL_MOUSEMOTION:
                    equipe.ChangeCouleurBouton(equipe.hoverBouton(events));
                    sac.ChangeCouleurBouton(sac.hoverBouton(events));
                    pc.ChangeCouleurBouton(pc.hoverBouton(events));
                    options.ChangeCouleurBouton(options.hoverBouton(events));
                    revenir.ChangeCouleurBouton(revenir.hoverBouton(events));
                    sauvegarder.ChangeCouleurBouton(sauvegarder.hoverBouton(events));
                    quitter.ChangeCouleurBouton(quitter.hoverBouton(events));
                    iconeMenu.ChangeCouleurBouton(iconeMenu.hoverBouton(events));
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(revenir.hoverBouton(events) || iconeMenu.hoverBouton(events)){
                        destructeurMenuJeu(equipe, sac, pc, options, quitter, revenir, sauvegarder, iconeMenu);
                        return 0;
                    }
                    if(options.hoverBouton(events)){
                        destructeurMenuJeu(equipe, sac, pc, options, quitter, revenir, sauvegarder, iconeMenu);
                        return 1;
                    }
                    if(equipe.hoverBouton(events)){
                        destructeurMenuJeu(equipe, sac, pc, options, quitter, revenir, sauvegarder, iconeMenu);
                        return 2;
                    }
                    if(quitter.hoverBouton(events)){
                        destructeurMenuJeu(equipe, sac, pc, options, quitter, revenir, sauvegarder, iconeMenu);
                        return 3;
                    }
                    if(sauvegarder.hoverBouton(events)){
                        destructeurMenuJeu(equipe, sac, pc, options, quitter, revenir, sauvegarder, iconeMenu);
                        return 4;
                    }
                    if(pc.hoverBouton(events)){
                        destructeurMenuJeu(equipe, sac, pc, options, quitter, revenir, sauvegarder, iconeMenu);
                        return 5;
                    }
                    break;
            }
        }
    }
    return 0;
}

void AfficheMenuJeu(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton equipe, Bouton sac, Bouton pc, Bouton options, Bouton quitter, Bouton revenir, Bouton sauvegarder, Bouton iconeMenu){


    equipe.AffichageBouton(pRenderer);
    sac.AffichageBouton(pRenderer);
    pc.AffichageBouton(pRenderer);
    options.AffichageBouton(pRenderer);
    revenir.AffichageBouton(pRenderer);
    sauvegarder.AffichageBouton(pRenderer);
    quitter.AffichageBouton(pRenderer);
    iconeMenu.AffichageBouton(pRenderer);

    equipe.AffichageTexte(pRenderer, "Equipe", resolutionecranx/32, SDL_Color{0,0,0,255});
    sac.AffichageTexte(pRenderer, "Sac", resolutionecranx/32, SDL_Color{0,0,0,255});
    pc.AffichageTexte(pRenderer, "PC", resolutionecranx/32, SDL_Color{0,0,0,255});
    options.AffichageTexte(pRenderer, "Options", resolutionecranx/32, SDL_Color{0,0,0,255});
    revenir.AffichageTexte(pRenderer, "Revenir", resolutionecranx/32, SDL_Color{0,0,0,255});
    sauvegarder.AffichageTexte(pRenderer, "Sauvegarder", resolutionecranx/36, SDL_Color{0,0,0,255});
    quitter.AffichageTexte(pRenderer, "Quitter", resolutionecranx/32, SDL_Color{0,0,0,255});



    SDL_RenderPresent(pRenderer);

    SDL_Delay(5);
}

void destructeurMenuJeu(Bouton equipe, Bouton sac, Bouton pc, Bouton options, Bouton quitter, Bouton revenir, Bouton sauvegarde, Bouton iconeMenu){
    equipe.DestroyBouton();
    sac.DestroyBouton();
    pc.DestroyBouton();
    options.DestroyBouton();
    quitter.DestroyBouton();
    revenir.DestroyBouton();
    sauvegarde.DestroyBouton();

}
