#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>

#include "Bouton.h"
#include "Chaine.h"
#include <string>

using namespace std;


Bouton::Bouton(int positionboutonx, int positionboutony, int largeur, int hauteur, SDL_Renderer* pRenderer, int numTexture){

    positionx = positionboutonx;
    positiony = positionboutony;
    w = largeur;
    h = hauteur;
    index = 0;
    numeroTexture = numTexture;

    SDL_Surface* boutonSurface;
    SDL_Surface* boutonSurfaceHover;


    if(numeroTexture == 1){
        boutonSurface = IMG_Load("textures/bouton.png");
        boutonSurfaceHover = IMG_Load("textures/boutonHover.png");

    }else if(numeroTexture == 2){
        boutonSurface = IMG_Load("textures/cadreBoitePC.png");
        boutonSurfaceHover = IMG_Load("textures/cadreBoitePC.png");

    }else if(numeroTexture == 3){
        boutonSurface = IMG_Load("textures/boutonEquipe.png");
        boutonSurfaceHover = IMG_Load("textures/boutonEquipeHover.png");

    }else if(numeroTexture == 4) {
        boutonSurface = IMG_Load("textures/iconeMenu.png");
        boutonSurfaceHover = IMG_Load("textures/iconeMenuHover.png");

    }else if(numeroTexture == 5) {
        boutonSurface = IMG_Load("textures/boutonPC.png");
        boutonSurfaceHover = IMG_Load("textures/boutonPCHover.png");

    }else if(numeroTexture == 6) {
        boutonSurface = IMG_Load("textures/flecheGauche.png");
        boutonSurfaceHover = IMG_Load("textures/flecheGaucheHover.png");

    }else if(numeroTexture == 7) {
        boutonSurface = IMG_Load("textures/flecheDroite.png");
        boutonSurfaceHover = IMG_Load("textures/flecheDroiteHover.png");

    }else if(numeroTexture == 8){
        boutonSurface = IMG_Load("textures/cadreCombat.png");
        boutonSurfaceHover = IMG_Load("textures/cadreCombat.png");

    }else if(numeroTexture == 9){
        boutonSurface = IMG_Load("textures/boutonsac.png");
        boutonSurfaceHover = IMG_Load("textures/boutonsachover.png");

    }else if(numeroTexture == 10){
        boutonSurface = IMG_Load("textures/boutonequipecombat.png");
        boutonSurfaceHover = IMG_Load("textures/boutonequipecombathover.png");

    }else if(numeroTexture == 11){
        boutonSurface = IMG_Load("textures/boutonattaque.png");
        boutonSurfaceHover = IMG_Load("textures/boutonattaquehover.png");

    }else if(numeroTexture == 12){
        boutonSurface = IMG_Load("textures/boutonfuite.png");
        boutonSurfaceHover = IMG_Load("textures/boutonfuitehover.png");

    }else if(numeroTexture == 13){
        boutonSurface = IMG_Load("textures/cadreCombat2.png");
        boutonSurfaceHover = IMG_Load("textures/cadreCombat2.png");

    }else if(numeroTexture == 14){
        boutonSurface = IMG_Load("textures/boutonannuler.png");
        boutonSurfaceHover = IMG_Load("textures/boutonannulerhover.png");

    }

    textureBouton = SDL_CreateTextureFromSurface(pRenderer, boutonSurface);
    SDL_FreeSurface(boutonSurface);

    textureBoutonHover = SDL_CreateTextureFromSurface(pRenderer, boutonSurfaceHover);
    SDL_FreeSurface(boutonSurfaceHover);

    bouton = textureBouton;

}

void Bouton::DestroyBouton(){

    SDL_DestroyTexture(textureBouton);
    SDL_DestroyTexture(textureBoutonHover);

}


void Bouton::AffichageBouton(SDL_Renderer* pRenderer){

    SDL_Rect position{0, 0, 700, 125};


    SDL_QueryTexture(bouton, nullptr, nullptr, &position.w, &position.h);


    SDL_Rect dest;
    dest.x = positionx - w/2;
    dest.y = positiony - h/2;
    dest.w = w;
    dest.h = h;

    SDL_RenderCopy(pRenderer, bouton, &position, &dest);




}


void Bouton::AffichageTexte(SDL_Renderer* pRenderer, const string texte, int taille, SDL_Color color){

    //Chargement Texture Texte

    TTF_Font* fontMinecraft = TTF_OpenFont("Minecraft.TTF", taille); //Chargement police

    SDL_Rect position;


    SDL_Surface* text = TTF_RenderText_Blended(fontMinecraft, texte.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(pRenderer, text);
    SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);

    position.x = positionx - (position.w/2);
    position.y = positiony - (position.h/2);



    SDL_RenderCopy(pRenderer, texture, nullptr, &position);


    TTF_CloseFont(fontMinecraft);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(text);



}


void Bouton::ChangeCouleurBouton(bool hover){

    if(numeroTexture != 2){
        if(hover == true){
            bouton = textureBoutonHover;
        }else{
            bouton = textureBouton;
        }
    }
}

bool Bouton::hoverBouton(SDL_Event events){

    int x = events.motion.x;
    int y = events.motion.y;

    if(x >= positionx - w/2 && x <= positionx + w/2){
        if(y >= positiony - h/2 && y <= positiony + h/2){
            return true;
        }
    }

    return false;

}

bool Bouton::hoverBoutonStatic(int x, int y){


    if(x >= positionx - w/2 && x <= positionx + w/2){
        if(y >= positiony - h/2 && y <= positiony + h/2){
            return true;
        }
    }

    return false;

}


void Bouton::AffichageTexteDialogue(SDL_Renderer* pRenderer, string texte, int taille, SDL_Color color, int resolutionecranx, int resolutionecrany){

    //Chargement Texture Texte

    TTF_Font* fontMinecraft = TTF_OpenFont("Minecraft.TTF", taille); //Chargement police

    SDL_Rect position;

    vector<string> chaine;
    split(&texte , ';', &chaine);

    int k = 0;
    position.x = resolutionecranx/28;
    position.y = resolutionecrany/1.35;
    SDL_Surface* text;
    SDL_Texture* texture;


    while(k <= chaine.size() - 1){


        text = TTF_RenderText_Blended(fontMinecraft, chaine[k].c_str(), color);
        texture = SDL_CreateTextureFromSurface(pRenderer, text);
        SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);

        SDL_RenderCopy(pRenderer, texture, nullptr, &position);

        position.y += taille;

        ++k;

        SDL_DestroyTexture(texture);
        SDL_FreeSurface(text);

    }

    TTF_CloseFont(fontMinecraft);

}

void Bouton::reset(int positionboutonx, int positionboutony, int largeur, int hauteur, SDL_Renderer* pRenderer){

    DestroyBouton();

    positionx = positionboutonx;
    positiony = positionboutony;
    w = largeur;
    h = hauteur;

    SDL_Surface* boutonSurface;
    SDL_Surface* boutonSurfaceHover;


    if(numeroTexture == 1){
        boutonSurface = IMG_Load("textures/bouton.png");
        boutonSurfaceHover = IMG_Load("textures/boutonHover.png");

    }else if(numeroTexture == 2){
        boutonSurface = IMG_Load("textures/cadreBoitePC.png");
        boutonSurfaceHover = IMG_Load("textures/cadreBoitePC.png");

    }else if(numeroTexture == 3){
        boutonSurface = IMG_Load("textures/boutonEquipe.png");
        boutonSurfaceHover = IMG_Load("textures/boutonEquipeHover.png");

    }else if(numeroTexture == 4) {
        boutonSurface = IMG_Load("textures/iconeMenu.png");
        boutonSurfaceHover = IMG_Load("textures/iconeMenuHover.png");

    }else if(numeroTexture == 5) {
        boutonSurface = IMG_Load("textures/boutonPC.png");
        boutonSurfaceHover = IMG_Load("textures/boutonPCHover.png");

    }else if(numeroTexture == 6) {
        boutonSurface = IMG_Load("textures/flecheGauche.png");
        boutonSurfaceHover = IMG_Load("textures/flecheGaucheHover.png");

    }else if(numeroTexture == 7) {
        boutonSurface = IMG_Load("textures/flecheDroite.png");
        boutonSurfaceHover = IMG_Load("textures/flecheDroiteHover.png");

    }else if(numeroTexture == 8){
        boutonSurface = IMG_Load("textures/cadreCombat.png");
        boutonSurfaceHover = IMG_Load("textures/cadreCombat.png");

    }else if(numeroTexture == 9){
        boutonSurface = IMG_Load("textures/boutonsac.png");
        boutonSurfaceHover = IMG_Load("textures/boutonsachover.png");

    }else if(numeroTexture == 10){
        boutonSurface = IMG_Load("textures/boutonequipecombat.png");
        boutonSurfaceHover = IMG_Load("textures/boutonequipecombathover.png");

    }else if(numeroTexture == 11){
        boutonSurface = IMG_Load("textures/boutonattaque.png");
        boutonSurfaceHover = IMG_Load("textures/boutonattaquehover.png");

    }else if(numeroTexture == 12){
        boutonSurface = IMG_Load("textures/boutonfuite.png");
        boutonSurfaceHover = IMG_Load("textures/boutonfuitehover.png");

    }else if(numeroTexture == 13){
        boutonSurface = IMG_Load("textures/cadreCombat2.png");
        boutonSurfaceHover = IMG_Load("textures/cadreCombat2.png");

    }else if(numeroTexture == 14){
        boutonSurface = IMG_Load("textures/boutonannuler.png");
        boutonSurfaceHover = IMG_Load("textures/boutonannulerhover.png");

    }

    textureBouton = SDL_CreateTextureFromSurface(pRenderer, boutonSurface);
    SDL_FreeSurface(boutonSurface);

    textureBoutonHover = SDL_CreateTextureFromSurface(pRenderer, boutonSurfaceHover);
    SDL_FreeSurface(boutonSurfaceHover);

    bouton = textureBouton;


}

void Bouton::changeTexture(int nouveaunum, SDL_Renderer* pRenderer){
    numeroTexture = nouveaunum;
    reset(positionx, positiony, w, h, pRenderer);
}


