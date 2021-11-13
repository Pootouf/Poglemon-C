#ifndef MENUEQUIPE_H_INCLUDED
#define MENUEQUIPE_H_INCLUDED

#include "Poglemon.h"

//Menu equipe (dans menu jeu), affiche les différents membres de l'equipe sous forme de bouton qui peuvent etre pressés pour avoir un deuxieme menu
void menuEquipe(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Poglemon* poglemon1, Poglemon* poglemon2, Poglemon* poglemon3, Poglemon* poglemon4, Poglemon* poglemon5, Poglemon* poglemon6, Poglemon *pc[960]);

//Affichage du menu equipe
void AfficheMenuEquipe(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton menu, Bouton boutonpoglemon1, Bouton boutonpoglemon2, Bouton boutonpoglemon3, Bouton boutonpoglemon4, Bouton boutonpoglemon5, Bouton boutonpoglemon6, Bouton quitter, Poglemon poglemon1, Poglemon poglemon2, Poglemon poglemon3, Poglemon poglemon4, Poglemon poglemon5, Poglemon poglemon6);

//Destructeur du menu equipe
void destructeurMenuEquipe(Bouton menu, Bouton boutonpoglemon1, Bouton boutonpoglemon2, Bouton boutonpoglemon3, Bouton boutonpoglemon4, Bouton boutonpoglemon5, Bouton boutonpoglemon6, Bouton quitter);

//Permet d'avoir un menu propre à chaque poglemon de l'equipe.
int menuPoglemon(int x, int y, Poglemon* pog, SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Poglemon *poglemon1, Poglemon *poglemon2, Poglemon *poglemon3, Poglemon *poglemon4, Poglemon *poglemon5, Poglemon *poglemon6, Poglemon *pc[960]);

//Affichage du menu Poglemon
void AfficheMenuPoglemon(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton resume, Bouton deplacer, Bouton pc, Bouton revenir);

//Destructeur du menu Poglemon
void destructeurMenuPoglemon(Bouton resume, Bouton deplacer, Bouton pc, Bouton revenir);

//Permet d'afficher un menu similaire au menu Equipe afin de selectionner le poglemon à échanger
void choixDeplacement(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Poglemon *poglemon1, Poglemon *poglemon2, Poglemon *poglemon3, Poglemon *poglemon4, Poglemon *poglemon5, Poglemon *poglemon6, Poglemon *pog);

//Permet d'echanger les places de deux poglemon entre eux
void EchangePogle(Poglemon* poglemon1, Poglemon* poglemon2, SDL_Renderer* pRenderer);

//Permet de faire en sorte qu'il n'y ait pas de vide au début où entre les poglemons. Si c'est le cas, déplace les poglemons en gardant leurs ordre jusqu'a combler tous les trous
void OrdreEquipe(Poglemon *poglemon1, Poglemon *poglemon2, Poglemon *poglemon3, Poglemon *poglemon4, Poglemon *poglemon5, Poglemon *poglemon6, SDL_Renderer* pRenderer);

#endif // MENUEQUIPE_H_INCLUDED
