#include <SDL.h>
#include <stdlib.h>
#include <SDL_mixer.h>

#include "Poglemon.h"
#include "Bouton.h"
#include "Combat.h"
#include "Menuequipe.h"


int detectionCombat(){

    int p = rand() % 101;

    if(p <= (1.25/187.5)*100){
        return 1;
    }else if(p <= (3.33/187.5)*100){
        return 2;
    }else if(p <= (6.75/187.5)*100){
        return 3;
    }else if(p <= (8.5/187.5)*100){
        return 4;
    }else if(p <= (10/187.5)*100){
        return 5;
    }

    return 0;
}


int combat(SDL_Renderer* pRenderer, int zone, int rand, int resolutionecranx, int resolutionecrany, Poglemon* poglemon1, bool dresseur, Poglemon* poglemon2, Poglemon* poglemon3, Poglemon* poglemon4, Poglemon* poglemon5, Poglemon* poglemon6){

    Poglemon* joueur;

    int changePog = 1;

    Poglemon* pogParticipant[6];
    Poglemon pogVide(pRenderer, 0, "", 0, false);
    for(int k = 0; k<6; k++){
        pogParticipant[k] = &pogVide;
    }
    pogParticipant[0] = poglemon1;

    if((*poglemon1).estko()){
        if((*poglemon2).estko()){
            if((*poglemon3).estko()){
                if((*poglemon4).estko()){
                    if((*poglemon5).estko()){
                        if((*poglemon6).estko()){
                            return -1;
                        }else{joueur = poglemon6;}
                    }else{joueur = poglemon5;}
                }else{joueur = poglemon4;}
            }else{joueur = poglemon3;}
        }else{joueur = poglemon2;}
    }else{joueur = poglemon1;}

    int pogennemyid;
    int pogennemyniv;
    bool pause = true;
    SDL_Event events;

    int statutCombat = 0;

    bool menuattaqueouvert = false;

    if(zone == 2){
        if (rand == 5){
            pogennemyid = 1;
            pogennemyniv = 2;
        }
        if (rand == 4){
            pogennemyid = 1;
            pogennemyniv = 3;
        }
        if (rand == 3){
            pogennemyid = 4;
            pogennemyniv = 3;
        }
        if (rand == 2){
            pogennemyid = 4;
            pogennemyniv = 1;
        }
        if (rand == 1){
            pogennemyid = 7;
            pogennemyniv = 4;
        }
    }

    Poglemon pogennemy(pRenderer, pogennemyid, "", pogennemyniv, true);

    Bouton menu(resolutionecranx/2, resolutionecrany/2, resolutionecranx, resolutionecrany, pRenderer, 8);
    Bouton sac(resolutionecranx/8.17, resolutionecrany/1.24, resolutionecranx/5.65, resolutionecrany/3.18, pRenderer, 9);
    Bouton equipe(resolutionecranx/1.14, resolutionecrany/1.24, resolutionecranx/5.65, resolutionecrany/3.18, pRenderer, 10);
    Bouton attaque(resolutionecranx/2, resolutionecrany/1.37, resolutionecranx/2.91, resolutionecrany/4.07, pRenderer, 11);
    Bouton fuite(resolutionecranx/2, resolutionecrany/1.1, resolutionecranx/10.1, resolutionecrany/8.31, pRenderer, 12);
    Bouton annuler(resolutionecranx/2, resolutionecrany/1.1, resolutionecranx/4.17, resolutionecrany/9.23, pRenderer, 14);

    Bouton attaque1(resolutionecranx/5.82, resolutionecrany/1.45, resolutionecranx/3.8, resolutionecrany/7.66, pRenderer, 1);
    Bouton attaque2(resolutionecranx/1.24, resolutionecrany/1.45, resolutionecranx/3.8, resolutionecrany/7.66, pRenderer, 1);
    Bouton attaque3(resolutionecranx/5.82, resolutionecrany/1.2, resolutionecranx/3.8, resolutionecrany/7.66, pRenderer, 1);
    Bouton attaque4(resolutionecranx/1.24, resolutionecrany/1.2, resolutionecranx/3.8, resolutionecrany/7.66, pRenderer, 1);

    Mix_Chunk* sonBouton = Mix_LoadWAV("sounds/bouton.wav");

    while(pause == true){
        AfficheMenuCombat(pRenderer, resolutionecranx, resolutionecrany, menu, sac, equipe, attaque, fuite, annuler, attaque1, attaque2, attaque3, attaque4, *joueur, pogennemy, menuattaqueouvert);
        while (SDL_PollEvent(&events)) {
            switch(events.type){
                case SDL_MOUSEMOTION:
                    sac.ChangeCouleurBouton(sac.hoverBouton(events));
                    equipe.ChangeCouleurBouton(equipe.hoverBouton(events));
                    attaque.ChangeCouleurBouton(attaque.hoverBouton(events));
                    fuite.ChangeCouleurBouton(fuite.hoverBouton(events));
                    annuler.ChangeCouleurBouton(annuler.hoverBouton(events));
                    attaque1.ChangeCouleurBouton(attaque1.hoverBouton(events));
                    attaque2.ChangeCouleurBouton(attaque2.hoverBouton(events));
                    attaque3.ChangeCouleurBouton(attaque3.hoverBouton(events));
                    attaque4.ChangeCouleurBouton(attaque4.hoverBouton(events));
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    statutCombat = 0;
                    if(fuite.hoverBouton(events) && !menuattaqueouvert){
                        pause = false;
                        destructeurMenuCombat(menu, sac, equipe, attaque, fuite, attaque1, attaque2, attaque3, attaque4, annuler, pogennemy);
                        Mix_FreeChunk(sonBouton);
                        break;
                    }
                    if(attaque.hoverBouton(events) && !menuattaqueouvert){
                        menuattaqueouvert = true;
                        Mix_PlayChannel(1, sonBouton, 0);
                    }
                    if(annuler.hoverBouton(events) && menuattaqueouvert){
                        menuattaqueouvert = false;
                        Mix_PlayChannel(1, sonBouton, 0);
                    }
                    if(equipe.hoverBouton(events) && !menuattaqueouvert){
                        Mix_PlayChannel(1, sonBouton, 0);
                        Poglemon* joueur2 = deplaceCombat(pRenderer, resolutionecranx, resolutionecrany, poglemon1, poglemon2, poglemon3, poglemon4, poglemon5, poglemon6, joueur, false);
                        if(joueur2 != joueur){
                            joueur = joueur2;
                            for(int k = 0; k<6; k++){
                                if(joueur == pogParticipant[k]){
                                    break;
                                }
                                if(!(*pogParticipant[k]).exist()){
                                    changePog++;
                                    pogParticipant[k] = joueur;
                                    break;
                                }
                            }
                            AfficheMenuCombat(pRenderer, resolutionecranx, resolutionecrany, menu, sac, equipe, attaque, fuite, annuler, attaque1, attaque2, attaque3, attaque4, *joueur, pogennemy, menuattaqueouvert);
                            statutCombat = tourCombat(joueur, &pogennemy, 3, true, resolutionecranx, resolutionecrany, pRenderer, menu, sac, equipe, attaque, fuite, annuler, attaque1, attaque2, attaque3, attaque4, menuattaqueouvert);
                            if(statutCombat == 1){
                                for(int k = 0; k<6; k++){
                                    if(joueur == pogParticipant[k] && (*joueur).estko()){
                                        changePog--;
                                        pogParticipant[k] = &pogVide;
                                        break;
                                    }
                                }
                                joueur = deplaceCombat(pRenderer, resolutionecranx, resolutionecrany, poglemon1, poglemon2, poglemon3, poglemon4, poglemon5, poglemon6, joueur, true);
                                pause = true;
                                menuattaqueouvert = false;
                                AfficheMenuCombat(pRenderer, resolutionecranx, resolutionecrany, menu, sac, equipe, attaque, fuite, annuler, attaque1, attaque2, attaque3, attaque4, *joueur, pogennemy, menuattaqueouvert);
                                tourCombat(joueur, &pogennemy, 3, true, resolutionecranx, resolutionecrany, pRenderer, menu, sac, equipe, attaque, fuite, annuler, attaque1, attaque2, attaque3, attaque4, menuattaqueouvert);
                                break;
                            }
                        }
                    }
                    if(attaque1.hoverBouton(events) && menuattaqueouvert && (*joueur).renvoiepp(1) > 0){
                        statutCombat = tourCombat(joueur, &pogennemy, 1, false, resolutionecranx, resolutionecrany, pRenderer, menu, sac, equipe, attaque, fuite, annuler, attaque1, attaque2, attaque3, attaque4, menuattaqueouvert);
                    }
                    if(attaque2.hoverBouton(events) && menuattaqueouvert && (*joueur).renvoiepp(2) > 0){
                        statutCombat = tourCombat(joueur, &pogennemy, 2, false, resolutionecranx, resolutionecrany, pRenderer, menu, sac, equipe, attaque, fuite, annuler, attaque1, attaque2, attaque3, attaque4, menuattaqueouvert);
                    }
                    if(attaque3.hoverBouton(events) && menuattaqueouvert && (*joueur).renvoiepp(3) > 0){
                        statutCombat = tourCombat(joueur, &pogennemy, 3, false, resolutionecranx, resolutionecrany, pRenderer, menu, sac, equipe, attaque, fuite, annuler, attaque1, attaque2, attaque3, attaque4, menuattaqueouvert);
                    }
                    if(attaque4.hoverBouton(events) && menuattaqueouvert && (*joueur).renvoiepp(4) > 0){
                        statutCombat = tourCombat(joueur, &pogennemy, 4, false, resolutionecranx, resolutionecrany, pRenderer, menu, sac, equipe, attaque, fuite, annuler, attaque1, attaque2, attaque3, attaque4, menuattaqueouvert);
                    }
                    if(statutCombat != 0){
                        pause = false;
                        AfficheMenuCombat(pRenderer, resolutionecranx, resolutionecrany, menu, sac, equipe, attaque, fuite, annuler, attaque1, attaque2, attaque3, attaque4, *joueur, pogennemy, menuattaqueouvert);
                        if(statutCombat == 2){
                            for(int k = 0; k<6; k++){
                                if((*pogParticipant[k]).exist()){
                                    (*pogParticipant[k]).gainXp(pogennemy.renvoiebasexp(), pogennemy.niveauCombat(), resolutionecranx, resolutionecrany, pRenderer, changePog);
                                }
                            }
                            SDL_Log("Victoire");
                        }else{
                            if(!(*poglemon1).estko() || !(*poglemon2).estko() || !(*poglemon3).estko() || !(*poglemon4).estko() || !(*poglemon5).estko() || !(*poglemon6).estko()){
                                for(int k = 0; k<6; k++){
                                    if(joueur == pogParticipant[k] && (*joueur).estko()){
                                        changePog--;
                                        pogParticipant[k] = &pogVide;
                                        break;
                                    }
                                }
                                joueur = deplaceCombat(pRenderer, resolutionecranx, resolutionecrany, poglemon1, poglemon2, poglemon3, poglemon4, poglemon5, poglemon6, joueur, true);
                                pause = true;
                                menuattaqueouvert = false;
                                AfficheMenuCombat(pRenderer, resolutionecranx, resolutionecrany, menu, sac, equipe, attaque, fuite, annuler, attaque1, attaque2, attaque3, attaque4, *joueur, pogennemy, menuattaqueouvert);
                                tourCombat(joueur, &pogennemy, 3, true, resolutionecranx, resolutionecrany, pRenderer, menu, sac, equipe, attaque, fuite, annuler, attaque1, attaque2, attaque3, attaque4, menuattaqueouvert);
                                break;
                            }
                        }
                        AfficheMenuCombat(pRenderer, resolutionecranx, resolutionecrany, menu, sac, equipe, attaque, fuite, annuler, attaque1, attaque2, attaque3, attaque4, *joueur, pogennemy, menuattaqueouvert);
                        destructeurMenuCombat(menu, sac, equipe, attaque, fuite, attaque1, attaque2, attaque3, attaque4, annuler, pogennemy);
                        Mix_FreeChunk(sonBouton);
                        SDL_Delay(2000);
                    }
                    break;
            }
        }
    }
    return 1;
}


void AfficheMenuCombat(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton menu, Bouton sac, Bouton equipe, Bouton attaque, Bouton fuite, Bouton annuler, Bouton attaque1, Bouton attaque2, Bouton attaque3, Bouton attaque4, Poglemon joueur, Poglemon ennemy, bool menuattaqueouvert){

    menu.AffichageBouton(pRenderer);
    if(!menuattaqueouvert){
        sac.AffichageBouton(pRenderer);
        equipe.AffichageBouton(pRenderer);
        attaque.AffichageBouton(pRenderer);
        fuite.AffichageBouton(pRenderer);
    }
    if(menuattaqueouvert){
        annuler.AffichageBouton(pRenderer);
        attaque1.AffichageBouton(pRenderer);
        attaque2.AffichageBouton(pRenderer);
        attaque3.AffichageBouton(pRenderer);
        attaque4.AffichageBouton(pRenderer);
        joueur.AfficheAttaqueCombat(pRenderer, resolutionecranx, resolutionecrany);
    }

    joueur.AffichePogCombat(true, resolutionecranx, resolutionecrany, pRenderer);
    ennemy.AffichePogCombat(false, resolutionecranx, resolutionecrany, pRenderer);

    joueur.AfficheNomCombat(pRenderer, resolutionecranx, resolutionecrany, true);
    ennemy.AfficheNomCombat(pRenderer, resolutionecranx, resolutionecrany, false);


    SDL_RenderPresent(pRenderer);
    SDL_Delay(5);
}

void destructeurMenuCombat(Bouton menu, Bouton sac, Bouton equipe, Bouton attaque, Bouton fuite, Bouton annuler, Bouton attaque1, Bouton attaque2, Bouton attaque3, Bouton attaque4, Poglemon ennemy){
    menu.DestroyBouton();
    sac.DestroyBouton();
    equipe.DestroyBouton();
    attaque.DestroyBouton();
    fuite.DestroyBouton();
    ennemy.destructeurPoglemon();
    annuler.DestroyBouton();
    attaque1.DestroyBouton();
    attaque2.DestroyBouton();
    attaque3.DestroyBouton();
    attaque1.DestroyBouton();
}



int tourCombat(Poglemon* joueur, Poglemon* ennemy, int attaquenum, bool estenfuite, int resolutionecranx, int resolutionecrany, SDL_Renderer* pRenderer, Bouton menu, Bouton sac, Bouton equipe, Bouton attaque, Bouton fuite, Bouton annuler, Bouton attaque1, Bouton attaque2, Bouton attaque3, Bouton attaque4, bool menuattaqueouvert){

    //Calcul attaque ennemie
    int attaquenumE;
    int randattaque = 1;
    for(int k = 1; k<=4; k++){
        if((*ennemy).renvoieid(k) != 0 && (*ennemy).renvoiepp(k) != 0){
            randattaque = k;
        }
    }
    attaquenumE = rand() % randattaque;
    if((*ennemy).renvoiepp(attaquenumE) == 0){
        attaquenumE = 4;
    }
    while((*ennemy).renvoiepp(attaquenumE) == 0){
        if(attaquenumE>1){
            attaquenumE -=1;
        }else{
               (*ennemy).rajoutepp(1);
            attaquenumE = 1;
            break;
        }
    }

    //Debut du tour
    if(estenfuite == false){
        if((*joueur).vitesseCombat() >= (*ennemy).vitesseCombat()){
            //Attaque joueur
            attaquepoglemon(joueur, ennemy, attaquenum, resolutionecranx, resolutionecrany, pRenderer);
            if((*ennemy).estko()){
                return 2;
            }
            AfficheMenuCombat(pRenderer, resolutionecranx, resolutionecrany, menu, sac, equipe, attaque, fuite, annuler, attaque1, attaque2, attaque3, attaque4, *joueur, *ennemy, menuattaqueouvert);
            //Attaque ennemie
            attaquepoglemon(ennemy, joueur, attaquenumE, resolutionecranx, resolutionecrany, pRenderer);
            if((*joueur).estko()){
                return 1;
            }
        }else{
            //Attaque ennemie
            attaquepoglemon(ennemy, joueur, attaquenumE, resolutionecranx, resolutionecrany, pRenderer);
            if((*joueur).estko()){
                return 1;
            }
            AfficheMenuCombat(pRenderer, resolutionecranx, resolutionecrany, menu, sac, equipe, attaque, fuite, annuler, attaque1, attaque2, attaque3, attaque4, *joueur, *ennemy, menuattaqueouvert);
            //Attaque joueur
            attaquepoglemon(joueur, ennemy, attaquenum, resolutionecranx, resolutionecrany, pRenderer);
            if((*ennemy).estko()){
            return 2;
            }
        }
    }else{
        //Attaque ennemie
        attaquepoglemon(ennemy, joueur, attaquenumE, resolutionecranx, resolutionecrany, pRenderer);
        if((*joueur).estko()){
                return 1;
        }
    }
    return 0;
}


void attaquepoglemon(Poglemon* poglemonA, Poglemon* poglemonD, int attaqueNum, int resolutionecranx, int resolutionecrany, SDL_Renderer* pRenderer){

    TTF_Font* fontMinecraft = TTF_OpenFont("Minecraft.TTF", resolutionecranx/50); //Chargement police
    int attaque;

    int randPre = rand() % 101;
    if((*poglemonA).estphysique(attaqueNum)){
        attaque = (*poglemonA).attaqueCombat();
    }else{attaque = (*poglemonA).attaquespeCombat();}

    if((*poglemonA).precisionAttaque(attaqueNum) >= randPre){
        (*poglemonD).degat(attaque, (*poglemonA).puissanceAttaque(attaqueNum), (*poglemonA).niveauCombat(), (*poglemonA).estphysique(attaqueNum));
        (*poglemonA).enlevepp(attaqueNum);
        affichageTexte(fontMinecraft, (*poglemonA).renvoienompog() + " utilise l'attaque " + (*poglemonA).renvoienomattaque(attaqueNum), pRenderer, resolutionecranx/3.2, resolutionecrany/2.02);
        SDL_RenderPresent(pRenderer);
        SDL_Delay(1000);
    }else{
        affichageTexte(fontMinecraft, (*poglemonA).renvoienompog() + " rate l'attaque " + (*poglemonA).renvoienomattaque(attaqueNum), pRenderer, resolutionecranx/3.2, resolutionecrany/2.02);
        SDL_RenderPresent(pRenderer);
        SDL_Delay(1000);
    }

    TTF_CloseFont(fontMinecraft);
}


Poglemon* deplaceCombat(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Poglemon *poglemon1, Poglemon *poglemon2, Poglemon *poglemon3, Poglemon *poglemon4, Poglemon *poglemon5, Poglemon *poglemon6, Poglemon *joueur, bool ko){

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
                    if(quitter_d.hoverBouton(events) && ko==false){
                        menuPause = false;
                        Mix_FreeChunk(sonBouton);
                        destructeurMenuEquipe(menu_d, boutonpoglemon1_d, boutonpoglemon2_d, boutonpoglemon3_d, boutonpoglemon4_d, boutonpoglemon5_d, boutonpoglemon6_d, quitter_d);
                        return joueur;
                    }
                    if(boutonpoglemon1_d.hoverBouton(events) && (*poglemon1).exist() && !(*poglemon1).estko() && poglemon1!=joueur){
                        menuPause = false;
                        Mix_FreeChunk(sonBouton);
                        destructeurMenuEquipe(menu_d, boutonpoglemon1_d, boutonpoglemon2_d, boutonpoglemon3_d, boutonpoglemon4_d, boutonpoglemon5_d, boutonpoglemon6_d, quitter_d);
                        return poglemon1;
                    }
                    if(boutonpoglemon2_d.hoverBouton(events) && (*poglemon2).exist() && !(*poglemon2).estko() && poglemon2!=joueur){
                        menuPause = false;
                        Mix_FreeChunk(sonBouton);
                        destructeurMenuEquipe(menu_d, boutonpoglemon1_d, boutonpoglemon2_d, boutonpoglemon3_d, boutonpoglemon4_d, boutonpoglemon5_d, boutonpoglemon6_d, quitter_d);
                        return poglemon2;
                    }
                    if(boutonpoglemon3_d.hoverBouton(events) && (*poglemon3).exist() && !(*poglemon3).estko() && poglemon3!=joueur){
                        menuPause = false;
                        Mix_FreeChunk(sonBouton);
                        destructeurMenuEquipe(menu_d, boutonpoglemon1_d, boutonpoglemon2_d, boutonpoglemon3_d, boutonpoglemon4_d, boutonpoglemon5_d, boutonpoglemon6_d, quitter_d);
                        return poglemon3;
                    }
                    if(boutonpoglemon4_d.hoverBouton(events) && (*poglemon4).exist() && !(*poglemon4).estko() && poglemon4!=joueur){
                        menuPause = false;
                        Mix_FreeChunk(sonBouton);
                        destructeurMenuEquipe(menu_d, boutonpoglemon1_d, boutonpoglemon2_d, boutonpoglemon3_d, boutonpoglemon4_d, boutonpoglemon5_d, boutonpoglemon6_d, quitter_d);
                        return poglemon4;
                    }
                    if(boutonpoglemon5_d.hoverBouton(events) && (*poglemon5).exist() && !(*poglemon5).estko() && poglemon5!=joueur){
                        menuPause = false;
                        Mix_FreeChunk(sonBouton);
                        destructeurMenuEquipe(menu_d, boutonpoglemon1_d, boutonpoglemon2_d, boutonpoglemon3_d, boutonpoglemon4_d, boutonpoglemon5_d, boutonpoglemon6_d, quitter_d);
                        return poglemon5;
                    }
                    if(boutonpoglemon6_d.hoverBouton(events) && (*poglemon6).exist() && !(*poglemon6).estko() && poglemon6!=joueur){
                        menuPause = false;
                        Mix_FreeChunk(sonBouton);
                        destructeurMenuEquipe(menu_d, boutonpoglemon1_d, boutonpoglemon2_d, boutonpoglemon3_d, boutonpoglemon4_d, boutonpoglemon5_d, boutonpoglemon6_d, quitter_d);
                        return poglemon6;
                    }
            }
        }
    }

}


