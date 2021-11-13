#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

//Menu de d�part, affiche des boutons et renvoie des entiers diff�rents en fonction de celui qui est press�
int menuStart(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany);

//Affichage du menu de d�part
void AfficheMenu(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton titre, Bouton nPartie, Bouton cPartie, Bouton options, Bouton quitter);

//Destructeur du menu d�part
void destructeur(Bouton titre, Bouton nPartie, Bouton cPartie, Bouton options, Bouton quitter);

#endif // MENU_H_INCLUDED
