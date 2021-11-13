#ifndef COMBAT_H_INCLUDED
#define COMBAT_H_INCLUDED

//Detecte si un combat doit avoir lieu. Si oui, renvoie un nombre différent de zero correspondant au type de poglemon de la zone. Sinon, renvoie zero.
int detectionCombat();

//Lance un combat contre un poglemon
int combat(SDL_Renderer* pRenderer, int zone, int rand, int resolutionecranx, int resolutionecrany, Poglemon* poglemon1, bool dresseur, Poglemon* poglemon2, Poglemon* poglemon3, Poglemon* poglemon4, Poglemon* poglemon5, Poglemon* poglemon6);

//Affiche le menu de combat
void AfficheMenuCombat(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton menu, Bouton sac, Bouton equipe, Bouton attaque, Bouton fuite, Bouton annuler, Bouton attaque1, Bouton attaque2, Bouton attaque3, Bouton attaque4, Poglemon joueur, Poglemon ennemy, bool menuattaqueouvert);

//Detruit le menu combat
void destructeurMenuCombat(Bouton menu, Bouton sac, Bouton equipe, Bouton attaque, Bouton fuite, Bouton annuler, Bouton attaque1, Bouton attaque2, Bouton attaque3, Bouton attaque4, Poglemon ennemy);

//Réalise un tour de combat en appliquant des dégats à chaque poglemon. Si le joueur a tenté de fuir, celui ci ne peut pas attaquer
int tourCombat(Poglemon* joueur, Poglemon* ennemy, int attaquenum, bool estenfuite, int resolutionecranx, int resolutionecrany, SDL_Renderer* pRenderer, Bouton menu, Bouton sac, Bouton equipe, Bouton attaque, Bouton fuite, Bouton annuler, Bouton attaque1, Bouton attaque2, Bouton attaque3, Bouton attaque4, bool menuattaqueouvert);

void attaquepoglemon(Poglemon* poglemonA, Poglemon* poglemonD, int attaqueNum, int resolutionecranx, int resolutionecrany, SDL_Renderer* pRenderer);

//Permet de sélectionner le poglemon a envoyer au combat
Poglemon* deplaceCombat(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Poglemon *poglemon1, Poglemon *poglemon2, Poglemon *poglemon3, Poglemon *poglemon4, Poglemon *poglemon5, Poglemon *poglemon6, Poglemon *joueur, bool ko);

#endif // COMBAT_H_INCLUDED
