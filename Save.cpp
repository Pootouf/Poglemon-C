#include "Poglemon.h"
#include <string>
#include <cstdio>
#include "Save.h"

using namespace std;

#define TAILLE_MAP 3600


void save(int map[TAILLE_MAP][TAILLE_MAP], Poglemon poglemon1, Poglemon poglemon2, Poglemon poglemon3, Poglemon poglemon4, Poglemon poglemon5, Poglemon poglemon6, int positionx, int positiony, Poglemon *pc[960]){

    FILE* fichier = fopen("MAP.bin", "wb" );

    for(int x = 0; x<TAILLE_MAP; x++){
        for(int y = 0; y<TAILLE_MAP; y++){
            fwrite(&map[x][y], 4, 1, fichier);
        }
    }

    fclose(fichier);

    fichier = fopen("save.bin", "wb" );

    fwrite(&positionx, 4, 1, fichier);
    fwrite(&positiony, 4, 1, fichier);

    fwrite(&poglemon1, sizeof(Poglemon), 1, fichier);
    char n;
    int x = poglemon1.name.size();
    fwrite(&x, sizeof(int), 1, fichier);
    for(int k = 0; k< x; k++){
        n = poglemon1.name[k];
        fwrite(&n, sizeof(char), 1, fichier);
    }

    fwrite(&poglemon2, sizeof(Poglemon), 1, fichier);
    x = poglemon2.name.size();
    fwrite(&x, sizeof(int), 1, fichier);
    for(int k = 0; k< x; k++){
        n = poglemon2.name[k];
        fwrite(&n, sizeof(char), 1, fichier);
    }

    fwrite(&poglemon3, sizeof(Poglemon), 1, fichier);
    x = poglemon3.name.size();
    fwrite(&x, sizeof(int), 1, fichier);
    for(int k = 0; k< x; k++){
        n = poglemon3.name[k];
        fwrite(&n, sizeof(char), 1, fichier);
    }

    fwrite(&poglemon4, sizeof(Poglemon), 1, fichier);
    x = poglemon4.name.size();
    fwrite(&x, sizeof(int), 1, fichier);
    for(int k = 0; k< x; k++){
        n = poglemon4.name[k];
        fwrite(&n, sizeof(char), 1, fichier);
    }

    fwrite(&poglemon5, sizeof(Poglemon), 1, fichier);
    x = poglemon5.name.size();
    fwrite(&x, sizeof(int), 1, fichier);
    for(int k = 0; k< x; k++){
        n = poglemon5.name[k];
        fwrite(&n, sizeof(char), 1, fichier);
    }

    fwrite(&poglemon6, sizeof(Poglemon), 1, fichier);
    x = poglemon6.name.size();
    fwrite(&x, sizeof(int), 1, fichier);
    for(int k = 0; k< x; k++){
        n = poglemon6.name[k];
        fwrite(&n, sizeof(char), 1, fichier);
    }

    fclose(fichier);

    savePC(pc);
}

void chargement(Poglemon* poglemon1, Poglemon* poglemon2, Poglemon* poglemon3, Poglemon* poglemon4, Poglemon* poglemon5, Poglemon* poglemon6, SDL_Renderer* pRenderer, int* positionx, int* positiony, int map[3600][3600], Poglemon *pc[960]){

    FILE* fichier = fopen("MAP.bin", "rb");

    int z[3600];

    for(int x = 0; x<TAILLE_MAP; x++){
        fread(&z[0], 4, TAILLE_MAP, fichier);
        for(int k = 0; k<= TAILLE_MAP; k++){
            map[x][k] = z[k];
        }
    }
    fclose(fichier);


    fichier = fopen("save.bin", "rb");
    fread(positionx, 4, 1, fichier);
    fread(positiony, 4, 1, fichier);

    char n[99];
    int x;

    fread(poglemon1, sizeof(Poglemon), 1, fichier);
    (*poglemon1).Reset(pRenderer);
    for(int k = 0; k<99; k++){n[k] = 0;}
    fread(&x, sizeof(int), 1, fichier);
    fread(&n[0], sizeof(char), x, fichier);
    (*poglemon1).name = n;

    fread(poglemon2, sizeof(Poglemon), 1, fichier);
    (*poglemon2).Reset(pRenderer);
    for(int k = 0; k<99; k++){n[k] = 0;}
    fread(&x, sizeof(int), 1, fichier);
    fread(&n[0], sizeof(char), x, fichier);
    (*poglemon2).name = n;

    fread(poglemon3, sizeof(Poglemon), 1, fichier);
    (*poglemon3).Reset(pRenderer);
    for(int k = 0; k<99; k++){n[k] = 0;}
    fread(&x, sizeof(int), 1, fichier);
    fread(&n[0], sizeof(char), x, fichier);
    (*poglemon3).name = n;

    fread(poglemon4, sizeof(Poglemon), 1, fichier);
    (*poglemon4).Reset(pRenderer);
    for(int k = 0; k<99; k++){n[k] = 0;}
    fread(&x, sizeof(int), 1, fichier);
    fread(&n[0], sizeof(char), x, fichier);
    (*poglemon4).name = n;

    fread(poglemon5, sizeof(Poglemon), 1, fichier);
    (*poglemon5).Reset(pRenderer);
    for(int k = 0; k<99; k++){n[k] = 0;}
    fread(&x, sizeof(int), 1, fichier);
    fread(&n[0], sizeof(char), x, fichier);
    (*poglemon5).name = n;

    fread(poglemon6, sizeof(Poglemon), 1, fichier);
    (*poglemon6).Reset(pRenderer);
    for(int k = 0; k<99; k++){n[k] = 0;}
    fread(&x, sizeof(int), 1, fichier);
    fread(&n[0], sizeof(char), x, fichier);
    (*poglemon6).name = n;

    fclose(fichier);

    chargementPC(pc, pRenderer);

}


void savePC(Poglemon *pc[960]){

    FILE* fichier = fopen("pc.bin", "wb");

    for(int y = 0; y<960; y++){
        pc[y] ->save(fichier);
    }

    fclose(fichier);
}

void chargementPC(Poglemon *pc[960], SDL_Renderer* pRenderer){

    FILE* fichier = fopen("pc.bin", "rb");


    for(int y = 0; y<960; ++y){
        pc[y] ->chargement(pRenderer, fichier);
    }

    fclose(fichier);

}



