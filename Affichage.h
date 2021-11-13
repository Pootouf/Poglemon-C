#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

#include "Bouton.h"

//Permet d'afficher le sol, regarde chaque case de map et pour chaque valeur affiche une texture différente. Ne le fais que pour les cases proches du joueur, et les affiche avec un décalage si nécessaire lors d'un mouvement
void AffichageSol(SDL_Renderer* pRenderer, int map[3600][3600], int positionx, int positiony, int resolutionecranx, int resolutionecrany, int deplacementX, int deplacementY);


#endif // AFFICHAGE_H_INCLUDED
