#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED

#include <string>

//Menu des options, affiche des boutons et renvoie des entiers différents en fonction de celui qui est pressé
int menuOptions(SDL_Renderer** pRenderer, SDL_Window** pWindow, int* resolutionecranx, int* resolutionecrany, std::string valeurTouche[322], std::string stringTouche[322]);

//Destructeur du menu options
void destructeurMenuOptions(Bouton touche, Bouton resolution, Bouton option, Bouton retour);

//Affichage du menu options
void AfficheOptions(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton touche, Bouton resolution, Bouton option, Bouton retour);

//Definit la resolution en fonction du bouton pressé par l'utilisateur
int OptionsResolution(SDL_Renderer** pRenderer, SDL_Window** pWindow, int* resolutionecranx, int* resolutionecrany);

//Destructeur du menu optionsresolution
void destructeurMenuOptionsResolution(Bouton resolution, Bouton resolution1080, Bouton resolution720, Bouton resolution576, Bouton resolution1440, Bouton confirmer, Bouton retour);

//Affichage du menu options resolution
void AfficheOptionsResolution(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton resolution, Bouton resolution1080, Bouton resolution720, Bouton resolution576, Bouton resolution1440, Bouton confirmer, Bouton retour );

//Si une touche est pressé quand la souris est au dessus d'un bouton de touche, remplace la touche affiché sur le bouton par celle pressé.
int OptionsTouche(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, std::string valeurTouche[322], std::string stringTouche[322]);

//Destructeur du menu OptionsTouche
void destructeurMenuOptionsTouche(Bouton Touche, Bouton ToucheZ, Bouton ToucheQ, Bouton ToucheD, Bouton ToucheS, Bouton ToucheI, Bouton ToucheEspace, Bouton confirmer, Bouton defaut);

//Affichage du menu OptionsTouche
void AfficheOptionsTouche(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, Bouton Touche, Bouton ToucheZ, Bouton ToucheQ, Bouton ToucheD, Bouton ToucheS, Bouton ToucheI, Bouton ToucheEspace, Bouton confirmer, Bouton defaut, std::string valeurTouche[322], std::string stringTouche[322]);

//Recupere les valeurs pressés par l'utilisateur. Stocke ensuite la chaine correspondant à l'entier touche dans valeurTouche à la valeur donnée par l'utilisateur et stocke dans stringTOuche
// à la valeur donnée par l'utilisateur la chaine donnée par l'utilisateur. Par exemple, si à la touche 1 l'utilisateur appuie sur E, la valeur E sera stockée dans stringTouche à l'entier correpondant
// à l'énumération E, et la valeur Z sera stockée dans valeurTouche à l'entier correpondant à l'énumération E. De plus, les anciens endroits ou le tableau contient la chaine Z, où la chaine correpondant
// au caractere donné par l'utilisateur sont transformés en chaine nulle ("")
void recupTouche(SDL_Event events, std::string valeurTouche[322], std::string stringTouche[322], int touche);

#endif // OPTIONS_H_INCLUDED
