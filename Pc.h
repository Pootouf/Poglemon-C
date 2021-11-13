#ifndef PC_H_INCLUDED
#define PC_H_INCLUDED

void PC(Poglemon *pc[960], SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Poglemon *poglemon1, Poglemon *poglemon2, Poglemon *poglemon3, Poglemon *poglemon4, Poglemon *poglemon5, Poglemon *poglemon6);

void AffichePC(Poglemon *pc[960], SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton *poglemon[30], Bouton fond, Bouton boite, int numeroBoite, Bouton flecheGauche, Bouton flecheDroite, Bouton quitter);

void destructeurMenuPC(Bouton *poglemon[30], Bouton fond, Bouton boite, Bouton flecheGauche, Bouton flecheDroite, Bouton quitter);

int menuPoglemonPC(Poglemon *pc[960], int x, int y, Poglemon* pog, SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, int numBoite, Poglemon *poglemon1, Poglemon *poglemon2, Poglemon *poglemon3, Poglemon *poglemon4, Poglemon *poglemon5, Poglemon *poglemon6);

void AfficheMenuPoglemonPC(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton resume, Bouton deplacer, Bouton pc, Bouton revenir);

void destructeurMenuPoglemonPC(Bouton resume, Bouton deplacer, Bouton pc, Bouton revenir);

int deplacePC(Poglemon *pc[960], SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Poglemon* pog, int numBoite);



#endif // PC_H_INCLUDED
