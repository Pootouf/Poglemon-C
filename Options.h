#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED

#include <string>

//Menu des options, affiche des boutons et renvoie des entiers diff�rents en fonction de celui qui est press�
int menuOptions(SDL_Renderer** pRenderer, SDL_Window** pWindow, int* resolutionecranx, int* resolutionecrany, std::string valeurTouche[322], std::string stringTouche[322]);

//Destructeur du menu options
void destructeurMenuOptions(Bouton touche, Bouton resolution, Bouton option, Bouton retour);

//Affichage du menu options
void AfficheOptions(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton touche, Bouton resolution, Bouton option, Bouton retour);

//Definit la resolution en fonction du bouton press� par l'utilisateur
int OptionsResolution(SDL_Renderer** pRenderer, SDL_Window** pWindow, int* resolutionecranx, int* resolutionecrany);

//Destructeur du menu optionsresolution
void destructeurMenuOptionsResolution(Bouton resolution, Bouton resolution1080, Bouton resolution720, Bouton resolution576, Bouton resolution1440, Bouton confirmer, Bouton retour);

//Affichage du menu options resolution
void AfficheOptionsResolution(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton resolution, Bouton resolution1080, Bouton resolution720, Bouton resolution576, Bouton resolution1440, Bouton confirmer, Bouton retour );

//Si une touche est press� quand la souris est au dessus d'un bouton de touche, remplace la touche affich� sur le bouton par celle press�.
int OptionsTouche(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, std::string valeurTouche[322], std::string stringTouche[322]);

//Destructeur du menu OptionsTouche
void destructeurMenuOptionsTouche(Bouton Touche, Bouton ToucheZ, Bouton ToucheQ, Bouton ToucheD, Bouton ToucheS, Bouton ToucheI, Bouton ToucheEspace, Bouton confirmer, Bouton defaut);

//Affichage du menu OptionsTouche
void AfficheOptionsTouche(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton Touche, Bouton ToucheZ, Bouton ToucheQ, Bouton ToucheD, Bouton ToucheS, Bouton ToucheI, Bouton ToucheEspace, Bouton confirmer, Bouton defaut, std::string valeurTouche[322], std::string stringTouche[322]);

//Recupere les valeurs press�s par l'utilisateur. Stocke ensuite la chaine correspondant � l'entier touche dans valeurTouche � la valeur donn�e par l'utilisateur et stocke dans stringTOuche
// � la valeur donn�e par l'utilisateur la chaine donn�e par l'utilisateur. Par exemple, si � la touche 1 l'utilisateur appuie sur E, la valeur E sera stock�e dans stringTouche � l'entier correpondant
// � l'�num�ration E, et la valeur Z sera stock�e dans valeurTouche � l'entier correpondant � l'�num�ration E. De plus, les anciens endroits ou le tableau contient la chaine Z, o� la chaine correpondant
// au caractere donn� par l'utilisateur sont transform�s en chaine nulle ("")
void recupTouche(SDL_Event events, std::string valeurTouche[322], std::string stringTouche[322], int touche);

#endif // OPTIONS_H_INCLUDED
