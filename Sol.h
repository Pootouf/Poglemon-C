#ifndef SOL_H_INCLUDED
#define SOL_H_INCLUDED

#include <SDL.h>

#define TAILLE_MAP 3600

class Sol
{

    private:


    SDL_Texture* textureHerbe;
    SDL_Texture* textureFleur;
    SDL_Texture* textureArbre;
    SDL_Texture* textureArbre2;
    SDL_Texture* textureArbre3;
    SDL_Texture* textureArbreBig;
    SDL_Texture* texturehautesHerbes;
    SDL_Texture* texturecentreSoin;
    SDL_Texture* textureChemin[16];

    SDL_Texture* texturePorg;
    SDL_Texture* texturepoupinus;
    SDL_Texture* texturenuageon;
    SDL_Texture* texturepingouinou;


    public:

    //Initialisation du sol
    Sol(SDL_Renderer* pRenderer);

    //Affichage du sol
    void AffichageSol(SDL_Renderer* pRenderer, int map[TAILLE_MAP][TAILLE_MAP], int positionjoueurx, int positionjoueury, int resolutionecranx, int resolutionecrany, int deplacementX, int deplacementY);

    //Destructeur du sol
    void DestroySol();

    //Reset du sol
    void Reset(SDL_Renderer* pRenderer);

};

#endif // SOL_H_INCLUDED
