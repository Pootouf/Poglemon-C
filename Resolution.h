#ifndef RESOLUTION_H_INCLUDED
#define RESOLUTION_H_INCLUDED

//Permet de recuperer toutes les résolutions possibles pour l'utilisateur (non utilisé)
int recupResolution();

//Permet d'initialiser la fenetre
void initialisationFenetre(int resolutionx, int resolutiony, Uint32 flag, SDL_Window **pWindow, SDL_Renderer **pRenderer, bool nouvelleFenetre, int *resolutionecranx, int *resolutionecrany);

#endif // RESOLUTION_H_INCLUDED
