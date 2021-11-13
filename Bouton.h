#ifndef BOUTON_H_INCLUDED
#define BOUTON_H_INCLUDED

#include <SDL.h>
#include <SDL_mixer.h>
#include <string>

class Bouton
{

    private:

    int positionx;
    int positiony;
    int w;
    int h;
    int index;
    SDL_Texture* textureBouton;
    SDL_Texture* textureBoutonHover;
    SDL_Texture* bouton;
    int numeroTexture;

    public:

    //Initialisation Bouton
    Bouton(int positionboutonx, int positionboutony, int w, int h, SDL_Renderer* pRenderer, int numTexture);

    //Destructeur du bouton
    void DestroyBouton();

    //Affichage du bouton
    void AffichageBouton(SDL_Renderer* pRenderer);

    //Changement texture du bouton en mode hover
    void ChangeCouleurBouton(bool hover);

    //Affichage du texte du bouton
    void AffichageTexte(SDL_Renderer* pRenderer, const std::string texte, int taille, SDL_Color color);

    //Detection de si la souris touche le bouton
    bool hoverBouton(SDL_Event events);

    //Detection de si la souris touche le bouton meme si elle ne bouge pas
    bool hoverBoutonStatic(int x, int y);

    //Affichage du texte dans les boutons sous forme de dialogue. Permet de faire plusieurs lignes dans un seul bouton, ainsi que un affichage du texte qui évolue si le joueur appuie sur une touche
    void AffichageTexteDialogue(SDL_Renderer* pRenderer, const std::string texte, int taille, SDL_Color color, int resolutionecranx, int resolutionecrany);

    //Permet de reinitialiser les données du bouton, notamment sa texture
    void reset(int positionboutonx, int positionboutony, int largeur, int hauteur, SDL_Renderer* pRenderer);

    //change la texture du bouton
    void changeTexture(int nouveaunum, SDL_Renderer* pRenderer);

};



#endif // BOUTON_H_INCLUDED
