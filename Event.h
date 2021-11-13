#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include "Poglemon.h"

//Realise l'event spécifié dans idEvent en affichant une serie de dialogue avec un id. Certains event ont des choix a faire avec des boutons confirmer et annuler.
int Event(int idEvent, int resolutionecranx, int resolutionecrany, SDL_Renderer* pRenderer, string valeurTouche[322],  int map[TAILLE_MAP][TAILLE_MAP], int positionx, int positiony, Sol sol, Personnage porg, Bouton iconeMenu);

void FinEvent(int idEvent, Poglemon* poglemon1, Poglemon* poglemon2, Poglemon* poglemon3, Poglemon* poglemon4, Poglemon* poglemon5, Poglemon* poglemon6, Poglemon *pc[960], SDL_Renderer* pRenderer, int map[3600][3600]);

#endif // EVENT_H_INCLUDED
