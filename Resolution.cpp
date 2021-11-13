#include <SDL.h>
#include <cstdlib>
#include <iostream>

int recupResolution(){

    int i;

    // On récupère le nombre de modes d'affichage pour l'écran 0
    int modeNumber = SDL_GetNumDisplayModes(0);

    if (modeNumber < 0)
    {
        fprintf(stdout,"Échec lors de la récupération du nombre de modes (%s)\n",SDL_GetError());
        return -2;
    }

    fprintf(stdout,"Vous avez %d mode(s) d'affichage\n", modeNumber);

    // Affichage des différents modes
    SDL_DisplayMode displayMode;

    for (i = 0 ; i < modeNumber ; i++)
    {
        int error = SDL_GetDisplayMode(0, i, &displayMode);
        if (error < 0)
        {
            fprintf(stdout, "Échec lors de la récupération du mode d'affichage (%s)\n", SDL_GetError());
            return -3;
        }

        fprintf(stdout, "Mode %d : %dx%dx%d\n", i, displayMode.w, displayMode.h, displayMode.refresh_rate);
    }

    return 0;
}

void initialisationFenetre(int resolutionx, int resolutiony, Uint32 flag, SDL_Window** pWindow, SDL_Renderer** pRenderer, bool nouvelleFenetre, int *resolutionecranx, int *resolutionecrany){

    if(nouvelleFenetre == true){
        SDL_DestroyWindow(*pWindow);
        SDL_DestroyRenderer(*pRenderer);
    }

    if (SDL_CreateWindowAndRenderer(resolutionx, resolutiony, flag, pWindow, pRenderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        SDL_Quit();
    }

    SDL_GetWindowSize(*pWindow, resolutionecranx, resolutionecrany);
}


