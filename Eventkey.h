#ifndef EVENTKEY_H_INCLUDED
#define EVENTKEY_H_INCLUDED

#include "Personnage.h"

#include <string>

//Recupere la touche pressée et regarde si celle ci correspond a une des valeurs par défaut ou définit par l'utilisateur dans les options. Si oui renvoir un entier différent de 0 correspondant à la touche pressée sinon renvoie 0.
int PressionTouche(SDL_Renderer** pRenderer, SDL_Window** pWindow, bool keys[322], int *resolutionx, int *resolutiony, std::string valeurTouche[322]);

//Transforme la valeur de la touche en int
void intTouche(std::string valeurTouche[322], int toucheTab[6]);

#endif // EVENTKEY_H_INCLUDED
