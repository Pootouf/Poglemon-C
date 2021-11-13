#include <SDL.h>
#include <string>
#include <map>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <cstring>

#include "Poglemon.h"

using namespace std;

//Stats des poglemon
map <string, int> statsPog =
{

    //Stats de Nuageon

    {string{"pog"} + "hp" + "1", 40},
    {string{"pog"} + "atk" + "1", 45},
    {string{"pog"} + "spatk" + "1", 70},
    {string{"pog"} + "def" + "1", 45},
    {string{"pog"} + "spdef" + "1", 65},
    {string{"pog"} + "vit" + "1", 45},
    {string{"pog"} + "type1" + "1", 3},
    {string{"pog"} + "type2" + "1", 10},
    {string{"pog"} + "progressionxp" + "1", 3},
    {string{"pog"} + "basexp" + "1", 65},

    //Stats de Poupinus

    {string{"pog"} + "hp" + "4", 55},
    {string{"pog"} + "atk" + "4", 70},
    {string{"pog"} + "spatk" + "4", 45},
    {string{"pog"} + "def" + "4", 65},
    {string{"pog"} + "spdef" + "4", 50},
    {string{"pog"} + "vit" + "4", 40},
    {string{"pog"} + "type1" + "4", 4},
    {string{"pog"} + "type2" + "4", 0},
    {string{"pog"} + "progressionxp" + "4", 3},
    {string{"pog"} + "basexp" + "4", 65},

    //Stats de Pingouinou

    {string{"pog"} + "hp" + "7", 55},
    {string{"pog"} + "atk" + "7", 50},
    {string{"pog"} + "spatk" + "7", 55},
    {string{"pog"} + "def" + "7", 50},
    {string{"pog"} + "spdef" + "7", 60},
    {string{"pog"} + "vit" + "7", 40},
    {string{"pog"} + "type1" + "7", 2},
    {string{"pog"} + "type2" + "7", 0},
    {string{"pog"} + "progressionxp" + "7", 3},
    {string{"pog"} + "basexp" + "7", 65},

    //Stats de Doof

    {string{"pog"} + "hp" + "10", 65},
    {string{"pog"} + "atk" + "10", 60},
    {string{"pog"} + "spatk" + "10", 45},
    {string{"pog"} + "def" + "10", 45},
    {string{"pog"} + "spdef" + "10", 45},
    {string{"pog"} + "vit" + "10", 40},
    {string{"pog"} + "type1" + "10", 1},
    {string{"pog"} + "type2" + "10", 0},
    {string{"pog"} + "progressionxp" + "10", 1},
    {string{"pog"} + "basexp" + "10", 58},

    //Stats de MultiDoof

    {string{"pog"} + "hp" + "11", 90},
    {string{"pog"} + "atk" + "11", 85},
    {string{"pog"} + "spatk" + "11", 55},
    {string{"pog"} + "def" + "11", 65},
    {string{"pog"} + "spdef" + "11", 45},
    {string{"pog"} + "vit" + "11", 75},
    {string{"pog"} + "type1" + "11", 1},
    {string{"pog"} + "type2" + "11", 0},
    {string{"pog"} + "progressionxp" + "11", 1},
    {string{"pog"} + "basexp" + "11", 116},

    //Stats de dieuGlete

    {string{"pog"} + "hp" + "999", 90},
    {string{"pog"} + "atk" + "999", 130},
    {string{"pog"} + "spatk" + "999", 175},
    {string{"pog"} + "def" + "999", 90},
    {string{"pog"} + "spdef" + "999", 120},
    {string{"pog"} + "vit" + "999", 135},
    {string{"pog"} + "type1" + "999", 1},
    {string{"pog"} + "type2" + "999", 10},
    {string{"pog"} + "progressionxp" + "999", 4},
    {string{"pog"} + "basexp" + "999", 300}



};

map <string, string> statsPogName =
{
    {string{"pog"} + "name" + "0", string{""}},
    {string{"pog"} + "name" + "1", string{"Nuageon"}},
    {string{"pog"} + "name" + "4", string{"Poupinus"}},
    {string{"pog"} + "name" + "7", string{"Pingouinou"}},
    {string{"pog"} + "name" + "10", string{"Doof"}},
    {string{"pog"} + "name" + "11", string{"MultiDoof"}},
    {string{"pog"} + "name" + "999", string{"Dieu Glete"}}
};


//Listes des apprentissages d'attaque
map <string, int> poglemonAttaqueNiv =
{
    //Attaque de Nuageon

    {string{"pog"} + "1" + "attaqueniv" + "4", 1},
    {string{"pog"} + "1" + "attaqueniv" + "6", 4},
    {string{"pog"} + "1" + "attaqueniv" + "2", 4},


    //Attaque de Poupinus

    {string{"pog"} + "4" + "attaqueniv" + "1", 1},
    {string{"pog"} + "4" + "attaqueniv" + "2", 4},
    {string{"pog"} + "4" + "attaqueniv" + "3", 4},

    //Attaque de Pingouinou

    {string{"pog"} + "7" + "attaqueniv" + "1", 1},
    {string{"pog"} + "7" + "attaqueniv" + "2", 4},
    {string{"pog"} + "7" + "attaqueniv" + "3", 4},

    //Attaque de Doof

    {string{"pog"} + "10" + "attaqueniv" + "1", 1},
    {string{"pog"} + "10" + "attaqueniv" + "2", 4},
    {string{"pog"} + "10" + "attaqueniv" + "3", 4},
    {string{"pog"} + "10" + "attaqueniv" + "4", 5},

    //Attaque de MultiDoof

    {string{"pog"} + "11" + "attaqueniv" + "1", 1},
    {string{"pog"} + "11" + "attaqueniv" + "2", 4},
    {string{"pog"} + "11" + "attaqueniv" + "3", 4},
    {string{"pog"} + "11" + "attaqueniv" + "4", 5},

    //Attaque de DieuGlete

    {string{"pog"} + "999" + "attaqueniv" + "1", 1},
    {string{"pog"} + "999" + "attaqueniv" + "2", 2},
    {string{"pog"} + "999" + "attaqueniv" + "3", 2},
    {string{"pog"} + "999" + "attaqueniv" + "4", 3},
    {string{"pog"} + "999" + "attaqueniv" + "5", 4},
    {string{"pog"} + "999" + "attaqueniv" + "6", 7}

};



//Liste des attaques
map <string, int> attaqueStats =
{

    {string{"degat"} + "1", 40},
    {string{"pp"} + "1", 35},
    {string{"precision"} + "1", 100},

    {string{"degat"} + "2", 90},
    {string{"pp"} + "2", 25},
    {string{"precision"} + "2", 90},

    {string{"degat"} + "3", 250},
    {string{"pp"} + "3", 5},
    {string{"precision"} + "3", 45},

    {string{"degat"} + "4", 999},
    {string{"pp"} + "4", 1},
    {string{"precision"} + "4", 1},

    {string{"degat"} + "5", 1},
    {string{"pp"} + "5", 50},
    {string{"precision"} + "5", 100},

    {string{"degat"} + "6", 60},
    {string{"pp"} + "6", 15},
    {string{"precision"} + "6", 95}

};

map <string, string> attaqueName =
{

    {string{"nom"} + "1", "Charge"},
    {string{"categorie"} + "1", "physique"},

    {string{"nom"} + "2", "Cochon"},
    {string{"categorie"} + "2", "special"},

    {string{"nom"} + "3", "Dinde"},
    {string{"categorie"} + "3", "special"},

    {string{"nom"} + "4", "Glete"},
    {string{"categorie"} + "4", "special"},

    {string{"nom"} + "5", "Pelote"},
    {string{"categorie"} + "5", "physique"},

    {string{"nom"} + "6", "Bourguignon"},
    {string{"categorie"} + "6", "physique"}

};





//Nom des types
string typeTab[19] = {"", "Normal", "Feu", "Eau", "Plante", "Electrique", "Glace", "Combat", "Poison", "Sol", "Vol", "Psy", "Insecte", "Roche", "Spectre", "Dragon", "Ténèbre", "Acier", "Fée"};


Poglemon::Poglemon(SDL_Renderer* pRenderer, int ID_pog, string namePog, int niveauPog, bool newPog){

    isInit = newPog;
    if(namePog == string{""}){
        name = statsPogName[string{"pog"} + "name" + to_string(ID_pog)];
    }else{
        name = namePog;
    }
    hpTotal = 0;
    atk = 0;
    speatk = 0;
    def = 0;
    spedef = 0;
    vitesse = 0;
    progressionXP = 0;
    type1 = 0;
    type2 = 0;
    xpNiveau = 0;
    xpactuel = 0;
    hp = 0;
    niveau = 1;

    for(int k = 0; k<4;k++){
        attaqueid[k] = 0;
        attaquepprestant[k] = 0;
    }

    if(newPog == true){

        Init(pRenderer, ID_pog, namePog, niveauPog);
    }
}




bool Poglemon::exist(){
    return isInit;
}




void Poglemon::Init(SDL_Renderer* pRenderer, int ID_pog, string namePog, int niveauPog){

    isInit = true;


    IDPog = ID_pog;
    if(namePog == string{""}){
        name = statsPogName[string{"pog"} + "name" + to_string(ID_pog)];
    }else{
        name = namePog;
    }

    MonteeNiveau(niveauPog);

    progressionXP = statsPog[string{"pog"} + "progressionxp" + to_string(IDPog)];

    type1 = statsPog[string{"pog"} + "type1" + to_string(IDPog)];
    type2 = statsPog[string{"pog"} + "type2" + to_string(IDPog)];

    if (progressionXP == 1){
        xpNiveau = 0.8*(niveau + 1)*(niveau+1)*(niveau+1) - 0.8*(niveau)*(niveau)*(niveau);
    }

    if (progressionXP == 2){
        xpNiveau = (niveau + 1)*(niveau+1)*(niveau+1) - (niveau)*(niveau)*(niveau);
    }

    if (progressionXP == 3){
        xpNiveau = (1.2*(niveau + 1)*(niveau+1)*(niveau+1) - 15*(niveau + 1)*(niveau + 1) + 100*(niveau+1) -140) - (1.2*(niveau)*(niveau)*(niveau) - 15*(niveau)*(niveau) + 100*(niveau) -140);
    }

    if (progressionXP == 4){
        xpNiveau = 1.25*(niveau + 1)*(niveau+1)*(niveau+1) - 1.25*(niveau)*(niveau)*(niveau);
    }

    xpactuel = 0;
    hp = hpTotal;

    string localisationTexture = "";

    if(IDPog == 1){
        localisationTexture = "textures/nuageon.png";
    }
    if(IDPog == 4){
        localisationTexture = "textures/poupinus.png";
    }
    if(IDPog == 7){
        localisationTexture = "textures/pingouinou.png";
    }
    if(IDPog == 10){
        localisationTexture = "textures/Doof.png";
    }
    if(IDPog == 11){
        localisationTexture = "textures/Multidoof.png";
    }
    if(IDPog == 999){
        localisationTexture = "textures/dieuGlete.png";
    }

    SDL_Surface* poglemonSurface = IMG_Load(localisationTexture.c_str());
    texturePog = SDL_CreateTextureFromSurface(pRenderer, poglemonSurface);
    SDL_FreeSurface(poglemonSurface);

}


void Poglemon::MonteeNiveau(int niveauPog){

    for(int k = niveau; k<=niveauPog; k++){
        for(int y = 1; y<=6; y++){
            if(poglemonAttaqueNiv[string{"pog"} + to_string(IDPog) + "attaqueniv" + to_string(y)] == k){
                for(int x = 0; x<4; x++){
                    if(attaqueid[x] ==0){
                        attaqueid[x] = y;
                        attaquepprestant[x] = attaqueStats[string{"pp"} + to_string(y)];
                        x = 5;
                    }
                }
            }

        }
    }

    if (progressionXP == 1){
        xpNiveau = 0.8*(niveau + 1)*(niveau+1)*(niveau+1) - 0.8*(niveau)*(niveau)*(niveau);
    }

    if (progressionXP == 2){
        xpNiveau = (niveau + 1)*(niveau+1)*(niveau+1) - (niveau)*(niveau)*(niveau);
    }

    if (progressionXP == 3){
        xpNiveau = (1.2*(niveau + 1)*(niveau+1)*(niveau+1) - 15*(niveau + 1)*(niveau + 1) + 100*(niveau+1) -140) - (1.2*(niveau)*(niveau)*(niveau) - 15*(niveau)*(niveau) + 100*(niveau) -140);
    }

    if (progressionXP == 4){
        xpNiveau = 1.25*(niveau + 1)*(niveau+1)*(niveau+1) - 1.25*(niveau)*(niveau)*(niveau);
    }

    niveau = niveauPog;

    hpTotal = (int)((((statsPog[string{"pog"} + "hp" + to_string(IDPog)]*2)*niveau)/100) + niveau + 10);
    atk = (int)((((statsPog[string{"pog"} + "atk" + to_string(IDPog)]*2)*niveau)/100) + 5);
    speatk = (int)((((statsPog[string{"pog"} + "spatk" + to_string(IDPog)]*2)*niveau)/100) + 5);
    def = (int)((((statsPog[string{"pog"} + "def" + to_string(IDPog)]*2)*niveau)/100) + 5);
    spedef = (int)((((statsPog[string{"pog"} + "spdef" + to_string(IDPog)]*2)*niveau)/100) + 5);
    vitesse = (int)((((statsPog[string{"pog"} + "vit" + to_string(IDPog)]*2)*niveau)/100) + 5);

}


void Poglemon::AffichePogEquipe(int numPog, int resolutionecranx, int resolutionecrany, SDL_Renderer* pRenderer){

    int x, y;

    if(isInit == true){

        if(numPog == 1){
            x = resolutionecranx/14.77 ;
            y = resolutionecrany/15.43 ;
        }
        if(numPog == 2){
            x = resolutionecranx/1.75 ;
            y = resolutionecrany/15.43 ;
        }
        if(numPog == 3){
            x = resolutionecranx/14.77 ;
            y = resolutionecrany/2.96;
        }
        if(numPog == 4){
            x = resolutionecranx/1.75 ;
            y = resolutionecrany/2.96 ;
        }
        if(numPog == 5){
            x = resolutionecranx/14.77 ;
            y = resolutionecrany/1.64 ;
        }
        if(numPog == 6){
            x = resolutionecranx/1.75 ;
            y = resolutionecrany/1.64 ;
        }

        //Affichage Texture pog
        SDL_Rect src{0,0,96,90};
        SDL_Rect dest{x , y, resolutionecranx/8.35, resolutionecrany/5.02};
        SDL_RenderCopy(pRenderer, texturePog, &src, &dest);


        TTF_Font* fontMinecraft = TTF_OpenFont("Minecraft.TTF", resolutionecranx/38.4); //Chargement police

        //Affichage nom pog
        affichageTexte(fontMinecraft, name, pRenderer, x + resolutionecranx/6.4, y);


        //Affichage Barre de vie pog
        affichageBarre(string{"textures/BarreDeVieVide.png"}, string{"textures/BarreDeVie.png"}, pRenderer, x + resolutionecranx/7.68, y + resolutionecrany/10.8, hpTotal, hp, resolutionecranx, resolutionecrany);


        //Affichage Barre d'xp
        affichageBarre(string{"textures/BarreDeVieVide.png"}, string{"textures/BarreDeXP.png"}, pRenderer, x + resolutionecranx/7.68, y + resolutionecrany/10.8 + resolutionecrany/36, xpNiveau, xpactuel, resolutionecranx, resolutionecrany);


        //Affichage niveau
        affichageTexte(fontMinecraft, (string("Niveau:") + to_string(niveau)), pRenderer, x + resolutionecranx/6.4, y + resolutionecrany/6.35);

        TTF_CloseFont(fontMinecraft);


    }

}

void Poglemon::Reset(SDL_Renderer* pRenderer){

    if(isInit == true){

        string localisationTexture = "";

        if(IDPog == 1){
            localisationTexture = "textures/nuageon.png";
        }
        if(IDPog == 4){
            localisationTexture = "textures/poupinus.png";
        }
        if(IDPog == 7){
            localisationTexture = "textures/pingouinou.png";
        }
        if(IDPog == 10){
            localisationTexture = "textures/Doof.png";
        }
        if(IDPog == 11){
            localisationTexture = "textures/Multidoof.png";
        }
        if(IDPog == 999){
            localisationTexture = "textures/dieuGlete.png";
        }

        SDL_Surface* poglemonSurface = IMG_Load(localisationTexture.c_str());
        texturePog = SDL_CreateTextureFromSurface(pRenderer, poglemonSurface);
        SDL_FreeSurface(poglemonSurface);
    }


}


void Poglemon::PoglemonStats(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany){

    bool isOpen = true;
    SDL_Event events;

    while(isOpen){
        AffichePoglemonStats(pRenderer, resolutionecranx, resolutionecrany);
        while (SDL_PollEvent(&events)) {
            switch(events.type){
                case SDL_MOUSEBUTTONDOWN:
                    isOpen = false;
                    break;

                case SDL_KEYDOWN:
                    isOpen = false;
                    break;
            }
        }

    }

}

void Poglemon::AffichePoglemonStats(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany){

    //Chargement Back
    SDL_Surface* statsSurface = IMG_Load("textures/StatsPoke.png");
    SDL_Texture* statsTexture = SDL_CreateTextureFromSurface(pRenderer, statsSurface);
    SDL_FreeSurface(statsSurface);
    SDL_Rect src = {0,0,1920, 1080};
    SDL_Rect dest = {0, 0, resolutionecranx, resolutionecrany};
    SDL_RenderCopy(pRenderer, statsTexture, &src, &dest);
    SDL_DestroyTexture(statsTexture);


    //Chargement Sprite
    src = {0,0,96, 90};
    dest = {resolutionecranx/13.71 , resolutionecrany/4.91, resolutionecranx/4.8, resolutionecrany/2.7};
    SDL_RenderCopy(pRenderer, texturePog, &src, &dest);


    //Chargement Texte

    TTF_Font* fontMinecraft = TTF_OpenFont("Minecraft.TTF", resolutionecranx/24); //Chargement police
    SDL_Rect position;



    affichageTexte(fontMinecraft, name, pRenderer, resolutionecranx/17.45, resolutionecrany/16.62);
    affichageTexte(fontMinecraft, (to_string(hp) + "/" + to_string(hpTotal)), pRenderer, resolutionecranx/2.02, resolutionecrany/5.68);
    affichageTexte(fontMinecraft, to_string(atk), pRenderer, resolutionecranx/2.02, resolutionecrany/4);
    affichageTexte(fontMinecraft, to_string(speatk), pRenderer, resolutionecranx/2.02, resolutionecrany/3.18);
    affichageTexte(fontMinecraft, to_string(def), pRenderer, resolutionecranx/2.02, resolutionecrany/2.63);
    affichageTexte(fontMinecraft, to_string(spedef), pRenderer, resolutionecranx/2.02, resolutionecrany/2.23);
    affichageTexte(fontMinecraft, to_string(vitesse), pRenderer, resolutionecranx/2.02, resolutionecrany/1.93);
    affichageTexte(fontMinecraft, (typeTab[type1] + "   " + typeTab[type2]), pRenderer, resolutionecranx/5.82, resolutionecrany/1.61);
    affichageTexte(fontMinecraft, to_string(IDPog), pRenderer, resolutionecranx/2.7, resolutionecrany/1.44);
    affichageTexte(fontMinecraft, to_string(niveau), pRenderer, resolutionecranx/1.1, resolutionecrany/15.43);



    //Affichage Attaque

    string pp;

    fontMinecraft = TTF_OpenFont("Minecraft.TTF", resolutionecranx/50);

    int positionx[] = {resolutionecranx/2.07, resolutionecranx/1.375, resolutionecranx/2.07, resolutionecranx/1.375};
    int positiony[] = {resolutionecrany/1.51, resolutionecrany/1.51, resolutionecrany/1.23, resolutionecrany/1.23};

    for(int k = 0; k<4; k++){

        if(attaqueid[k] != 0){

            pp = to_string(attaquepprestant[k]) + "/" + to_string(attaqueStats[string{"pp"} + to_string(attaqueid[k])]);

            affichageTexte(fontMinecraft, attaqueName[string{"nom"} + to_string(attaqueid[k])], pRenderer, positionx[k], positiony[k]);
            affichageTexte(fontMinecraft, pp, pRenderer, positionx[k], positiony[k] + resolutionecrany/20);
            affichageTexte(fontMinecraft, "Deg:" + to_string(attaqueStats[string{"degat"} + to_string(attaqueid[k])]), pRenderer, positionx[k] + resolutionecranx/7.68, positiony[k]);
            affichageTexte(fontMinecraft, "Pre:" + to_string(attaqueStats[string{"precision"} + to_string(attaqueid[k])]), pRenderer, positionx[k] + resolutionecranx/7.68, positiony[k] + resolutionecrany/20);


        }
    }


    affichageBarre(string{"textures/BarreDeVieVide.png"}, string{"textures/BarreDeXP.png"}, pRenderer, resolutionecranx/1.34, resolutionecrany/3.86, xpNiveau, xpactuel, resolutionecranx, resolutionecrany);



    TTF_CloseFont(fontMinecraft);
    SDL_RenderPresent(pRenderer);

    SDL_Delay(50);

}



void Poglemon::destructeurPoglemon(){
    if(isInit == true){
        SDL_DestroyTexture(texturePog);
    }
}

void Poglemon::save(FILE* fichier){

    fwrite(&IDPog, sizeof(int), 1, fichier);
    fwrite(&hp, sizeof(int), 1, fichier);
    fwrite(&hpTotal, sizeof(int), 1, fichier);
    fwrite(&atk, sizeof(int), 1, fichier);
    fwrite(&speatk, sizeof(int), 1, fichier);
    fwrite(&def, sizeof(int), 1, fichier);
    fwrite(&spedef, sizeof(int), 1, fichier);
    fwrite(&vitesse, sizeof(int), 1, fichier);
    fwrite(&niveau, sizeof(int), 1, fichier);
    fwrite(&xpNiveau, sizeof(int), 1, fichier);
    fwrite(&xpactuel, sizeof(int), 1, fichier);
    fwrite(&type1, sizeof(int), 1, fichier);
    fwrite(&type2, sizeof(int), 1, fichier);
    fwrite(&numeroPog, sizeof(int), 1, fichier);
    fwrite(&progressionXP, sizeof(int), 1, fichier);
    for(int k = 0; k<4; k++){
        fwrite(&attaqueid[k], sizeof(int), 1, fichier);
        fwrite(&attaquepprestant[k], sizeof(int), 1, fichier);
    }
    fwrite(&isInit, sizeof(bool), 1, fichier);

    char n;
    int x = name.size();
    fwrite(&x, sizeof(int), 1, fichier);
    for(int k = 0; k<x; k++){
        n = name[k];
        fwrite(&n, sizeof(char), 1, fichier);
    }
}


void Poglemon::chargement(SDL_Renderer* pRenderer, FILE* fichier){

    int tab[23];
    bool i;
    fread(&tab[0], sizeof(int), 23, fichier);
    fread(&i, sizeof(bool), 1, fichier);

    IDPog = tab[0];
    hp = tab[1];
    hpTotal = tab[2];
    atk = tab[3];
    speatk = tab[4];
    def = tab[5];
    spedef = tab[6];
    vitesse = tab[7];
    niveau = tab[8];
    xpNiveau = tab[9];
    xpactuel = tab[10];
    type1 = tab[11];
    type2 = tab[12];
    numeroPog = tab[13];
    progressionXP = tab[14];
    for(int k = 0; k<4; k++){
        attaqueid[k] = tab[15 + 2*k];
        attaquepprestant[k] = tab[16 + 2*k];
    }
    isInit = i;

    Reset(pRenderer);

    int x;
    fread(&x, sizeof(int), 1, fichier);
    char n[x];
    for(int k = 0; k<x; k++){
        fread(&n[k], sizeof(char), 1, fichier);
    }
    n[x] = 0;
    changementNom(n);
}

void Poglemon::changementNom(char newName[]){
    name = newName;
}

void Poglemon::AffichePoglePC(SDL_Renderer* pRenderer, int positionx, int positiony, int resolutionecranx, int resolutionecrany){

    if(isInit == true){
        SDL_Rect src = {0,0,96, 90};
        SDL_Rect position;
        SDL_Rect dest = {positionx - resolutionecranx/25.6, positiony - resolutionecrany/14.4, resolutionecranx/12.8 , resolutionecrany/7.2};
        SDL_RenderCopy(pRenderer, texturePog, &src, &dest);
    }

}

void Poglemon::AffichePogCombat(bool joueur, int resolutionecranx, int resolutionecrany, SDL_Renderer* pRenderer){

    if(isInit){
        SDL_Rect src = {0,0,96, 90};
        SDL_Rect dest;
        SDL_Rect position;
        if(joueur){
            dest = {resolutionecranx/7.38, resolutionecrany/3.6, resolutionecranx/12.8 , resolutionecrany/7.2};
        }else{
            dest = {resolutionecranx/1.32, resolutionecrany/5.68, resolutionecranx/12.8 , resolutionecrany/7.2};
        }
        SDL_RenderCopy(pRenderer, texturePog, &src, &dest);
    }

}

void Poglemon::AfficheAttaqueCombat(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany){

    TTF_Font* fontMinecraft = TTF_OpenFont("Minecraft.TTF", resolutionecranx/50);

    int positionx[] = {resolutionecranx/18.29, resolutionecranx/1.44, resolutionecranx/18.29, resolutionecranx/1.44};
    int positiony[] = {resolutionecrany/1.54, resolutionecrany/1.54, resolutionecrany/1.27, resolutionecrany/1.27};

    string pp;

    for(int k = 0; k<4; k++){

        if(attaqueid[k] != 0){

            pp = to_string(attaquepprestant[k]) + "/" + to_string(attaqueStats[string{"pp"} + to_string(attaqueid[k])]);

            affichageTexte(fontMinecraft, attaqueName[string{"nom"} + to_string(attaqueid[k])], pRenderer, positionx[k], positiony[k]);
            affichageTexte(fontMinecraft, pp, pRenderer, positionx[k], positiony[k] + resolutionecrany/20);
            affichageTexte(fontMinecraft, "Deg:" + to_string(attaqueStats[string{"degat"} + to_string(attaqueid[k])]), pRenderer, positionx[k] + resolutionecranx/7.68, positiony[k]);
            affichageTexte(fontMinecraft, "Pre:" + to_string(attaqueStats[string{"precision"} + to_string(attaqueid[k])]), pRenderer, positionx[k] + resolutionecranx/7.68, positiony[k] + resolutionecrany/20);


        }
    }

    TTF_CloseFont(fontMinecraft);

}

void Poglemon::AfficheNomCombat(SDL_Renderer* pRenderer, int resolutionecranx, int resolutionecrany, bool joueur){

    TTF_Font* fontMinecraft = TTF_OpenFont("Minecraft.TTF", resolutionecranx/50);

    if(joueur){
        affichageTexte(fontMinecraft, name, pRenderer, resolutionecranx/13.71, resolutionecrany/6.97);
        affichageTexte(fontMinecraft, "Niv:" + to_string(niveau), pRenderer, resolutionecranx/4.27, resolutionecrany/6.97);
        affichageBarre(string{"textures/BarreDeVieVide.png"}, string{"textures/BarreDeVie.png"}, pRenderer, resolutionecranx/14.77, resolutionecrany/5.54, hpTotal, hp, resolutionecranx, resolutionecrany);
        affichageBarre(string{"textures/BarreDeVieVide.png"}, string{"textures/BarreDeXP.png"}, pRenderer, resolutionecranx/14.77, resolutionecrany/4.9, xpNiveau, xpactuel, resolutionecranx, resolutionecrany);
    }else{
        affichageTexte(fontMinecraft, name, pRenderer, resolutionecranx/1.43, resolutionecrany/2.45);
        affichageTexte(fontMinecraft, "Niv:" + to_string(niveau), pRenderer, resolutionecranx/1.16, resolutionecrany/2.45);
        affichageBarre(string{"textures/BarreDeVieVide.png"}, string{"textures/BarreDeVie.png"}, pRenderer, resolutionecranx/1.43, resolutionecrany/2.23, hpTotal, hp, resolutionecranx, resolutionecrany);
    }

    TTF_CloseFont(fontMinecraft);
}

int Poglemon::vitesseCombat(){return vitesse;}

void Poglemon::degat(int attaqueE, int puissance, int niveauE, bool physique){
    int defense;
    if(physique){
        defense = def;
    }else{
        defense = spedef;
    }

    int degat = (((niveauE*0.4 + 2)*attaqueE*puissance)/(defense*50))+2;
    hp = hp - degat;
    if(hp<0){
        hp = 0;
    }
}

int Poglemon::attaqueCombat(){return atk;}

int Poglemon::attaquespeCombat(){return speatk;}

int Poglemon::niveauCombat(){return niveau;}

int Poglemon::puissanceAttaque(int attaqueNum){
    return attaqueStats[string{"degat"} + to_string(attaqueid[attaqueNum - 1])];
}

int Poglemon::precisionAttaque(int attaqueNum){
    return attaqueStats[string{"precision"} + to_string(attaqueid[attaqueNum - 1])];
}

void Poglemon::enlevepp(int attaqueNum){
    attaquepprestant[attaqueNum - 1] -= 1;
}

void Poglemon::rajoutepp(int attaqueNum){
    attaquepprestant[attaqueNum - 1] += 1;
}

int Poglemon::renvoiepp(int attaquenum){
    return attaquepprestant[attaquenum - 1];
}

int Poglemon::renvoieid(int attaquenum){
    return attaqueid[attaquenum - 1];
}

bool Poglemon::estphysique(int attaquenum){
    if(attaqueName[string{"categorie"} + to_string(attaqueid[attaquenum - 1])] == "physique"){
        return true;
    }else{
        return false;
    }
}

bool Poglemon::estko(){
    if(hp <= 0){
        return true;
    }
    return false;
}

void Poglemon::gainXp(int basexpE, int niveauE, int resolutionecranx, int resolutionecrany, SDL_Renderer* pRenderer, int divPog){
    int newxp = ((basexpE * niveauE)/(7*divPog))*1;
    SDL_Log("DivPog: %d", divPog);
    TTF_Font* fontMinecraft = TTF_OpenFont("Minecraft.TTF", resolutionecranx/50); //Chargement police
    xpactuel += newxp;
    while(xpactuel >= xpNiveau){
        newxp = xpactuel - xpNiveau;
        xpactuel = 0;
        niveau += 1;
        MonteeNiveau(niveau);
        affichageTexte(fontMinecraft, name + " monte de niveau!", pRenderer, resolutionecranx/3.2, resolutionecrany/2.02);
        SDL_RenderPresent(pRenderer);
        SDL_Delay(1000);
        xpactuel += newxp;
    }
    TTF_CloseFont(fontMinecraft);
}

int Poglemon::renvoiebasexp(){
    return statsPog[string{"pog"} + "basexp" + to_string(IDPog)];
}

string Poglemon::renvoienompog(){
    return name;
}

string Poglemon::renvoienomattaque(int attaquenum){
    return attaqueName[string{"nom"} + to_string(attaqueid[attaquenum - 1])];
}

void Poglemon::soin(){
    hp = hpTotal;
    for(int k = 0; k<4; k++){
        attaquepprestant[k] = attaqueStats[string{"pp"} + to_string(attaqueid[k])];
    }
}

void newPoglemon(Poglemon* poglemon1, Poglemon* poglemon2, Poglemon* poglemon3, Poglemon* poglemon4, Poglemon* poglemon5, Poglemon* poglemon6, Poglemon *pc[960], SDL_Renderer* pRenderer, int IDPog, string name, int niv){

    if((*poglemon1).exist() == false){(*poglemon1).Init(pRenderer, IDPog, name, niv);}else
    if((*poglemon2).exist() == false){(*poglemon2).Init(pRenderer, IDPog, name, niv);}else
    if((*poglemon3).exist() == false){(*poglemon3).Init(pRenderer, IDPog, name, niv);}else
    if((*poglemon4).exist() == false){(*poglemon4).Init(pRenderer, IDPog, name, niv);}else
    if((*poglemon5).exist() == false){(*poglemon5).Init(pRenderer, IDPog, name, niv);}else
    if((*poglemon6).exist() == false){(*poglemon6).Init(pRenderer, IDPog, name, niv);
    }else{

        for(int k = 0; k<960; k++){
            if((*pc[k]).exist() == false){
                (*pc[k]).Init(pRenderer, IDPog, name, niv);
                break;
            }
        }
    }


}


void affichageTexte(TTF_Font* font, string texture, SDL_Renderer* pRenderer, int positionx, int positiony){

    SDL_Rect position;

    SDL_Surface* textAffiche = TTF_RenderText_Blended(font, texture.c_str(), SDL_Color{0,0,0,255});
    SDL_Texture* textureAffiche = SDL_CreateTextureFromSurface(pRenderer, textAffiche);
    SDL_QueryTexture(textureAffiche, nullptr, nullptr, &position.w, &position.h);

    position.x = positionx;
    position.y = positiony;

    SDL_RenderCopy(pRenderer, textureAffiche, nullptr, &position);

    SDL_DestroyTexture(textureAffiche);
    SDL_FreeSurface(textAffiche);

}


void affichageBarre(string nomBarreVide, string nomBarrePleine, SDL_Renderer* pRenderer, int positionx, int positiony, int valeurMax, int valeurActuelle, int resolutionecranx, int resolutionecrany){

    SDL_Surface* barrevideSurface = IMG_Load(nomBarreVide.c_str());
    SDL_Texture* textureBarreVide = SDL_CreateTextureFromSurface(pRenderer, barrevideSurface);
    SDL_FreeSurface(barrevideSurface);

    SDL_Surface* barrepleineSurface = IMG_Load(nomBarrePleine.c_str());
    SDL_Texture*textureBarrepleine = SDL_CreateTextureFromSurface(pRenderer, barrepleineSurface);
    SDL_FreeSurface(barrepleineSurface);

    SDL_Rect src = {0,0,440,30};
    SDL_Rect dest = {positionx , positiony , resolutionecranx/4.36, resolutionecrany/36};
    SDL_RenderCopy(pRenderer, textureBarreVide, &src, &dest);
    src = {0,0,400,10};
    double tailleBarre = (double)valeurMax/valeurActuelle;
    dest = {positionx + resolutionecranx/96, positiony + resolutionecrany/108, resolutionecranx/(4.8 * tailleBarre), resolutionecrany/108};
    SDL_RenderCopy(pRenderer, textureBarrepleine, &src, &dest);

    SDL_DestroyTexture(textureBarrepleine);
    SDL_DestroyTexture(textureBarreVide);

}
