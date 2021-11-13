#ifndef CHAINE_H_INCLUDED
#define CHAINE_H_INCLUDED

#include <string>
#include <vector>

//Permet de diviser une chaine en plusieurs chaines qui sont délimités par le caractere delimiteur
void split( std::string *chaine, char delimiteur, std::vector<std::string> *elements);

#endif // CHAINE_H_INCLUDED
