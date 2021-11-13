#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <SDL.h>

#include "Sol.h"

class Personnage
{
    private:

    int velocity;
    int frame;
    int status;
    SDL_Texture* tabJoueurBas[4];
    SDL_Texture* tabJoueurHaut[4];
    SDL_Texture* tabJoueurGauche;
    SDL_Texture* tabJoueurDroite;

    public:
    int zone;

    //Initialisation des valeurs
    Personnage(SDL_Renderer* pRenderer);

    //Affiche le joueur
    void AffichageJoueur(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany);

    //Detecte une collision
    bool DetectionCollision(int positionx, int positiony, int map[3600][3600], int movement, bool collision);

    //Bouge le joueur en fonction de la touche pressée
    void PressionToucheMouvement(int Movement, int *positionx, int *positiony, SDL_Renderer* pRenderer, int map[3600][3600], int resolutionecranx, int resolutionecrany, Personnage porg, Sol sol, Bouton iconeMenu);

    //Augmente de 1 le compteur de l'index, remet à 0 si valeur max dépassé
    void augmentIndex();

    //Detection de si un event peut etre déclenché en face du joueur, si oui renvoie l'id de l'event
    int DetectionEvent(int positionx, int positiony, int map[3600][3600]);

    //Destructeur du personnage
    void DestroyPersonnage();

    //Reset du personnage
    void Reset(SDL_Renderer* pRenderer);

    //Permet de calculer la zone où se trouve le joueur, ce qui définit quels sont les poglemons de la zone
    void CalculZone(int positionx, int positiony);

    //Detecte si le joueur se trouve sur une case d'herbe
    bool DetectionHerbe(int x, int y, int map[TAILLE_MAP][TAILLE_MAP]);

};

#endif // PERSONNAGE_H_INCLUDED
