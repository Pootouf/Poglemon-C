#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED

//Sauvegarde la map dans le fichier MAP.bin ansi que les poglemon de l'equipe dans save.bin puis appelle la fonction savepc
void save(int map[3600][3600], Poglemon poglemon1, Poglemon poglemon2, Poglemon poglemon3, Poglemon poglemon4, Poglemon poglemon5, Poglemon poglemon6, int positionx, int positiony, Poglemon *pc[960]);

//charge la map depuis MAP.bin puis les poglemons de l'equipe depuis save.bin puis appelle chargementpc
void chargement(Poglemon* poglemon1, Poglemon* poglemon2, Poglemon* poglemon3, Poglemon* poglemon4, Poglemon* poglemon5, Poglemon* poglemon6, SDL_Renderer* pRenderer, int* positionx, int* positiony, int map[3600][3600], Poglemon *pc[960]);

//Sauvegarde le pc dans le fichier pc.bin
void savePC(Poglemon *pc[960]);

//Charge les poglemons du pc du fichier pc.bin
void chargementPC(Poglemon *pc[960], SDL_Renderer* pRenderer);

#endif // SAVE_H_INCLUDED
