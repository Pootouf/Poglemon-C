#ifndef OPTIONSJEU_H_INCLUDED
#define OPTIONSJEU_H_INCLUDED

//Menu du jeu. Afficher plusieurs bouton et renvoie un entier différent en fonction de celui qui est pressé
int menuJeu(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany);

//Affichage du menu du jeu
void AfficheMenuJeu(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton equipe, Bouton sac, Bouton pc, Bouton options, Bouton quitter, Bouton revenir, Bouton sauvegarder, Bouton iconeMenu);

//Destructeur du menu du jeu
void destructeurMenuJeu(Bouton equipe, Bouton sac, Bouton pc, Bouton options, Bouton quitter, Bouton revenir, Bouton sauvegarde, Bouton iconeMenu);

#endif // OPTIONSJEU_H_INCLUDED
