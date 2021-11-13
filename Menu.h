#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

//Menu de départ, affiche des boutons et renvoie des entiers différents en fonction de celui qui est pressé
int menuStart(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany);

//Affichage du menu de départ
void AfficheMenu(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton titre, Bouton nPartie, Bouton cPartie, Bouton options, Bouton quitter);

//Destructeur du menu départ
void destructeur(Bouton titre, Bouton nPartie, Bouton cPartie, Bouton options, Bouton quitter);

#endif // MENU_H_INCLUDED
