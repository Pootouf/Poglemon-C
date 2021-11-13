#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "Sol.h"

#define TAILLE_MAP 3600
using namespace std;

string chemin[] = {"textures/chemin-tout.png" , "textures/chemin-est.png", "textures/chemin-est-ouest.png", "textures/chemin-nord.png", "textures/chemin-nord-est.png", "textures/chemin-nord-est-ouest.png", "textures/chemin-nord-ouest.png", "textures/chemin-nord-sud.png", "textures/chemin-nord-sud-est.png",
                    "textures/chemin-nord-sud-ouest.png", "textures/chemin-ouest.png", "textures/chemin-rien.png", "textures/chemin-sud.png", "textures/chemin-sud-est.png", "textures/chemin-sud-est-ouest.png", "textures/chemin-sud-ouest.png"};

Sol::Sol(SDL_Renderer* pRenderer){

    //Initialisation de la texture herbe
    SDL_Surface* herbeSurface = IMG_Load("textures/herbe.png");
    textureHerbe = SDL_CreateTextureFromSurface(pRenderer, herbeSurface);
    SDL_FreeSurface(herbeSurface);

    //Initialisation de la texture fleur
    SDL_Surface* fleurSurface = IMG_Load("textures/fleur.png");
    textureFleur = SDL_CreateTextureFromSurface(pRenderer, fleurSurface);
    SDL_FreeSurface(fleurSurface);

    //Initialisation de la texture arbre
    SDL_Surface* arbreSurface = IMG_Load("textures/arbre.png");
    textureArbre = SDL_CreateTextureFromSurface(pRenderer, arbreSurface);
    SDL_FreeSurface(arbreSurface);

    //Initialisation de la texture arbre
    SDL_Surface* arbreSurfaceBig = IMG_Load("textures/arbreBig.png");
    textureArbreBig = SDL_CreateTextureFromSurface(pRenderer, arbreSurfaceBig);
    SDL_FreeSurface(arbreSurfaceBig);

    //Initialisation de la texture arbre2
    SDL_Surface* arbreSurface2 = IMG_Load("textures/arbre2.png");
    textureArbre2 = SDL_CreateTextureFromSurface(pRenderer, arbreSurface2);
    SDL_FreeSurface(arbreSurface2);

    //Initialisation de la texture arbre3
    SDL_Surface* arbreSurface3 = IMG_Load("textures/arbre3.png");
    textureArbre3 = SDL_CreateTextureFromSurface(pRenderer, arbreSurface3);
    SDL_FreeSurface(arbreSurface3);

    //Initialisation de la texture hautesherbes
    SDL_Surface* hautesHerbesSurface = IMG_Load("textures/hautesHerbes.png");
    texturehautesHerbes = SDL_CreateTextureFromSurface(pRenderer, hautesHerbesSurface);
    SDL_FreeSurface(hautesHerbesSurface);

    //Initialisation de la texture porg
    SDL_Surface* porgSurface = IMG_Load("textures/dieuGlete.png");
    texturePorg = SDL_CreateTextureFromSurface(pRenderer, porgSurface);
    SDL_FreeSurface(porgSurface);

    //Initialisation de la texture poupinus
    SDL_Surface* poupinusSurface = IMG_Load("textures/poupinus.png");
    texturepoupinus = SDL_CreateTextureFromSurface(pRenderer, poupinusSurface);
    SDL_FreeSurface(poupinusSurface);

    //Initialisation de la texture nuageon
    SDL_Surface* nuageonSurface = IMG_Load("textures/nuageon.png");
    texturenuageon = SDL_CreateTextureFromSurface(pRenderer, nuageonSurface);
    SDL_FreeSurface(nuageonSurface);

    //Initialisation de la texture pingouinou
    SDL_Surface* pingouinouSurface = IMG_Load("textures/pingouinou.png");
    texturepingouinou = SDL_CreateTextureFromSurface(pRenderer, pingouinouSurface);
    SDL_FreeSurface(pingouinouSurface);

    //Initialisation de la texture centreSoin
    SDL_Surface* centreSoinSurface = IMG_Load("textures/centreSoin.png");
    texturecentreSoin = SDL_CreateTextureFromSurface(pRenderer, centreSoinSurface);
    SDL_FreeSurface(centreSoinSurface);

    //Initialisation chemin
    SDL_Surface* cheminSurface[16];
    for(int k = 0; k<16; k++){
        cheminSurface[k] = IMG_Load(chemin[k].c_str());
        textureChemin[k] = SDL_CreateTextureFromSurface(pRenderer, cheminSurface[k]);
        SDL_FreeSurface(cheminSurface[k]);
    }

}

void Sol::AffichageSol(SDL_Renderer* pRenderer, int map[TAILLE_MAP][TAILLE_MAP], int positionjoueurx, int positionjoueury, int resolutionecranx, int resolutionecrany, int deplacementX, int deplacementY){

    positionjoueurx = (positionjoueurx/96)*(resolutionecranx/20);
    positionjoueury = (positionjoueury/90)*(resolutionecrany/12);

    int coordx = (int)positionjoueurx/(resolutionecranx/20);
    int coordy = (int)positionjoueury/(resolutionecrany/12);

    //Boucle pour afficher les textures sur tout l'écran
    for(int x = coordx - 3; x<=coordx + 21; x++){
        for(int y = coordy - 3; y<=coordy + 13; y++){
            int positionx = x*(resolutionecranx/20) - positionjoueurx - deplacementX;
            int positiony = y*(resolutionecrany/12) - positionjoueury - deplacementY;

            if(map[x][y] == 0){
                SDL_Rect src{0,0,96,90};
                SDL_Rect dest{positionx,positiony,resolutionecranx/20,resolutionecrany/12};
                SDL_RenderCopy(pRenderer, textureHerbe, &src, &dest);
            }
            if(map[x][y] == 1){
                SDL_Rect src{0,0,96,90};
                SDL_Rect dest{positionx,positiony,resolutionecranx/20,resolutionecrany/12};
                SDL_RenderCopy(pRenderer, textureFleur, &src, &dest);
            }
            if(map[x][y] == 3){
                SDL_Rect src{0,0,96*2,90*2};
                SDL_Rect dest{positionx,positiony,resolutionecranx/10,resolutionecrany/6};
                SDL_RenderCopy(pRenderer, textureArbre, &src, &dest);
            }
            if(map[x][y] == 4){
                SDL_Rect src{0,0,96,90};
                SDL_Rect dest{positionx,positiony,resolutionecranx/20,resolutionecrany/12};
                SDL_RenderCopy(pRenderer, texturehautesHerbes, &src, &dest);
            }
            if(map[x][y] == 5){
                SDL_Rect src{0,0,96*2,90*2};
                SDL_Rect dest{positionx,positiony,resolutionecranx/10,resolutionecrany/6};
                SDL_RenderCopy(pRenderer, textureArbre2, &src, &dest);
            }
            if(map[x][y] == 6){
                SDL_Rect src{0,0,96*2,90*2};
                SDL_Rect dest{positionx,positiony,resolutionecranx/10,resolutionecrany/6};
                SDL_RenderCopy(pRenderer, textureArbre3, &src, &dest);
            }
            if(map[x][y] == 7){
                SDL_Rect src{0,0,96,90};
                SDL_Rect dest{positionx,positiony,resolutionecranx/20,resolutionecrany/12};
                SDL_RenderCopy(pRenderer, textureHerbe, &src, &dest);
                SDL_RenderCopy(pRenderer, texturecentreSoin, &src, &dest);
            }
            if(map[x][y] == 15){
                SDL_Rect src{0,0,96,90};
                SDL_Rect dest{positionx,positiony,resolutionecranx/20,resolutionecrany/12};
                SDL_RenderCopy(pRenderer, textureHerbe, &src, &dest);
                SDL_RenderCopy(pRenderer, texturePorg, &src, &dest);
            }
            if(map[x][y] == 16){
                SDL_Rect src{0,0,96,90};
                SDL_Rect dest{positionx,positiony,resolutionecranx/20,resolutionecrany/12};
                SDL_RenderCopy(pRenderer, textureHerbe, &src, &dest);
                SDL_RenderCopy(pRenderer, texturepoupinus, &src, &dest);
            }
            if(map[x][y] == 17){
                SDL_Rect src{0,0,96,90};
                SDL_Rect dest{positionx,positiony,resolutionecranx/20,resolutionecrany/12};
                SDL_RenderCopy(pRenderer, textureHerbe, &src, &dest);
                SDL_RenderCopy(pRenderer, texturenuageon, &src, &dest);
            }
            if(map[x][y] == 18){
                SDL_Rect src{0,0,96,90};
                SDL_Rect dest{positionx,positiony,resolutionecranx/20,resolutionecrany/12};
                SDL_RenderCopy(pRenderer, textureHerbe, &src, &dest);
                SDL_RenderCopy(pRenderer, texturepingouinou, &src, &dest);
            }
            SDL_Rect src{0,0,96,90};
            SDL_Rect dest{positionx,positiony,resolutionecranx/20,resolutionecrany/12};
            for(int k = 0; k<16; k++){
                if(map[x][y] == 100 + k){
                    SDL_RenderCopy(pRenderer, textureChemin[k], &src, &dest);
                }
            }
        }
    }
}

void Sol::DestroySol(){

    SDL_DestroyTexture(textureHerbe);
    SDL_DestroyTexture(textureArbre);
    SDL_DestroyTexture(textureFleur);
    SDL_DestroyTexture(texturePorg);
}

void Sol::Reset(SDL_Renderer* pRenderer){

    DestroySol();

    //Initialisation de la texture herbe
    SDL_Surface* herbeSurface = IMG_Load("textures/herbe.png");
    textureHerbe = SDL_CreateTextureFromSurface(pRenderer, herbeSurface);
    SDL_FreeSurface(herbeSurface);

    //Initialisation de la texture fleur
    SDL_Surface* fleurSurface = IMG_Load("textures/fleur.png");
    textureFleur = SDL_CreateTextureFromSurface(pRenderer, fleurSurface);
    SDL_FreeSurface(fleurSurface);

    //Initialisation de la texture arbre
    SDL_Surface* arbreSurface = IMG_Load("textures/arbre.png");
    textureArbre = SDL_CreateTextureFromSurface(pRenderer, arbreSurface);
    SDL_FreeSurface(arbreSurface);

    //Initialisation de la texture arbre
    SDL_Surface* arbreSurfaceBig = IMG_Load("textures/arbreBig.png");
    textureArbreBig = SDL_CreateTextureFromSurface(pRenderer, arbreSurfaceBig);
    SDL_FreeSurface(arbreSurfaceBig);

    //Initialisation de la texture arbre2
    SDL_Surface* arbreSurface2 = IMG_Load("textures/arbre2.png");
    textureArbre2 = SDL_CreateTextureFromSurface(pRenderer, arbreSurface2);
    SDL_FreeSurface(arbreSurface2);

    //Initialisation de la texture arbre3
    SDL_Surface* arbreSurface3 = IMG_Load("textures/arbre3.png");
    textureArbre3 = SDL_CreateTextureFromSurface(pRenderer, arbreSurface3);
    SDL_FreeSurface(arbreSurface3);

    //Initialisation de la texture hautesherbes
    SDL_Surface* hautesHerbesSurface = IMG_Load("textures/hautesHerbes.png");
    texturehautesHerbes = SDL_CreateTextureFromSurface(pRenderer, hautesHerbesSurface);
    SDL_FreeSurface(hautesHerbesSurface);

    //Initialisation de la texture porg
    SDL_Surface* porgSurface = IMG_Load("textures/dieuGlete.png");
    texturePorg = SDL_CreateTextureFromSurface(pRenderer, porgSurface);
    SDL_FreeSurface(porgSurface);

    //Initialisation de la texture poupinus
    SDL_Surface* poupinusSurface = IMG_Load("textures/poupinus.png");
    texturepoupinus = SDL_CreateTextureFromSurface(pRenderer, poupinusSurface);
    SDL_FreeSurface(poupinusSurface);

    //Initialisation de la texture nuageon
    SDL_Surface* nuageonSurface = IMG_Load("textures/nuageon.png");
    texturenuageon = SDL_CreateTextureFromSurface(pRenderer, nuageonSurface);
    SDL_FreeSurface(nuageonSurface);

    //Initialisation de la texture pingouinou
    SDL_Surface* pingouinouSurface = IMG_Load("textures/pingouinou.png");
    texturepingouinou = SDL_CreateTextureFromSurface(pRenderer, pingouinouSurface);
    SDL_FreeSurface(pingouinouSurface);

    //Initialisation de la texture centreSoin
    SDL_Surface* centreSoinSurface = IMG_Load("textures/centreSoin.png");
    texturecentreSoin = SDL_CreateTextureFromSurface(pRenderer, centreSoinSurface);
    SDL_FreeSurface(centreSoinSurface);


}
