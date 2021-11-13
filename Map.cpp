#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <math.h>

#define TAILLE_MAP 3600

int initialisationMap(int map[TAILLE_MAP][TAILLE_MAP]){

    int position = 1;

    srand (time(NULL));

    for(int x = 0; x<=9; x++){
        for(int y = 10; y<=35; y++){
            if(floor((float)x/2) == (float)x/2){
                if(position == 1){
                    int randA = rand() % 300;
                    if(randA <=100){
                        map[x][y] = 3;
                    }
                    if(randA >100 && randA <= 200){
                        map[x][y] = 5;
                    }
                    if(randA >200){
                        map[x][y] = 6;
                    }
                    randA = rand() % 300;
                    if(randA <=100){
                        map[x + 26][y] = 3;
                    }
                    if(randA >100 && randA <= 200){
                        map[x + 26][y] = 5;
                    }
                    if(randA >200){
                        map[x + 26][y] = 6;
                    }
                    position = 0;
                }else{
                    map[x][y] = 2;
                    map[x + 26][y] = 2;
                    position = 1;
                }
            }else{
                map[x][y] = 2;
                map[x + 26][y] = 2;
            }
        }
        position = 1;
    }

    position = 1;

    for(int y = 0; y<=9; y++){
        for(int x = 0; x<=35; x++){
            if(floor((float)y/2) == (float)y/2){
                if(position == 1){
                    int randA = rand() % 300;
                    if(randA <=100){
                        map[x][y] = 3;
                    }
                    if(randA >100 && randA <= 200){
                        map[x][y] = 5;
                    }
                    if(randA >200){
                        map[x][y] = 6;
                    }
                    randA = rand() % 300;
                    if(randA <=100){
                        map[x][y+ 26] = 3;
                    }
                    if(randA >100 && randA <= 200){
                        map[x][y+ 26] = 5;
                    }
                    if(randA >200){
                        map[x][y+ 26] = 6;
                    }
                    position = 0;
                }else{
                    map[x][y] = 2;
                    map[x][y+ 26] = 2;
                    position = 1;
                }
            }else{
                map[x][y] = 2;
                map[x][y+ 26] = 2;
            }
        }
        position = 1;
    }

    position = 1;

    for(int y = 36; y<=45; y++){
        for(int x = 0; x<=15; x++){
            if(floor((float)y/2) == (float)y/2){
                if(position == 1){
                    int randA = rand() % 300;
                    if(randA <=100){
                        map[x][y] = 3;
                    }
                    if(randA >100 && randA <= 200){
                        map[x][y] = 5;
                    }
                    if(randA >200){
                        map[x][y] = 6;
                    }
                    position = 0;
                }else{
                    map[x][y] = 2;
                    position = 1;
                }
            }else{
                map[x][y] = 2;
            }
        }
        position = 1;
    }

    position = 1;

    for(int y = 40; y<=45; y++){
        for(int x = 16; x<=63; x++){
            if(floor((float)y/2) == (float)y/2){
                if(position == 1){
                    int randA = rand() % 300;
                    if(randA <=100){
                        map[x][y] = 3;
                    }
                    if(randA >100 && randA <= 200){
                        map[x][y] = 5;
                    }
                    if(randA >200){
                        map[x][y] = 6;
                    }
                    position = 0;
                }else{
                    map[x][y] = 2;
                    position = 1;
                }
            }else{
                map[x][y] = 2;
            }
        }
        position = 1;
    }

    position = 1;

    for(int y = 40; y<=45; y++){
        for(int x = 16; x<=33; x++){
            if(floor((float)y/2) == (float)y/2){
                if(position == 1){
                    int randA = rand() % 300;
                    if(randA <=100){
                        map[x][y] = 3;
                    }
                    if(randA >100 && randA <= 200){
                        map[x][y] = 5;
                    }
                    if(randA >200){
                        map[x][y] = 6;
                    }
                    position = 0;
                }else{
                    map[x][y] = 2;
                    position = 1;
                }
            }else{
                map[x][y] = 2;
            }
        }
        position = 1;
    }

    position = 1;

    for(int y = 10; y<=25; y++){
        for(int x = 36; x<=53; x++){
            if(floor((float)y/2) == (float)y/2){
                if(position == 1){
                    int randA = rand() % 300;
                    if(randA <=100){
                        map[x][y] = 3;
                    }
                    if(randA >100 && randA <= 200){
                        map[x][y] = 5;
                    }
                    if(randA >200){
                        map[x][y] = 6;
                    }
                    position = 0;
                }else{
                    map[x][y] = 2;
                    position = 1;
                }
            }else{
                map[x][y] = 2;
            }
        }
        position = 1;
    }

    position = 1;

    for(int y = 10; y<=45; y++){
        for(int x = 54; x<=65; x++){
            if(floor((float)y/2) == (float)y/2){
                if(position == 1){
                    int randA = rand() % 300;
                    if(randA <=100){
                        map[x][y] = 3;
                    }
                    if(randA >100 && randA <= 200){
                        map[x][y] = 5;
                    }
                    if(randA >200){
                        map[x][y] = 6;
                    }
                    position = 0;
                }else{
                    map[x][y] = 2;
                    position = 1;
                }
            }else{
                map[x][y] = 2;
            }
        }
        position = 1;
    }

    for(int x = 36; x<=53; x++){
        for(int y = 26; y<=35; y++){
                map[x][y] = 4;
        }
    }


    for(int x = 10; x<=25; x++){
        for(int y = 10; y<=25; y++){
            int random = rand() % 11;

            if(random == 1){
                map[x][y] = 1;
            }else{
                map[x][y] = 0;
            }
        }
    }

    for(int x = 16; x<=53; x++){
        for(int y = 36; y<=39; y++){
            int random = rand() % 11;

            if(random == 1){
                map[x][y] = 1;
            }else{
                map[x][y] = 0;
            }
        }
    }

    //Soin
    map[53][39] = 7;

    //Chemin dieu Glete
    map[17][18] = 102;
    map[16][18] = 104;
    map[16][17] = 107;
    map[16][16] = 113;
    map[17][16] = 102;
    map[18][16] = 115;
    map[18][17] = 107;
    map[18][18] = 106;

    //chemin foret
    map[18][38] = 104;
    map[18][37] = 113;
    map[53][38] = 106;
    map[53][37] = 115;
    for(int x = 19; x<=52; x++){
        map[x][38] = 105;
        map[x][37] = 114;
    }

    //Poglemon
    map[17][17] = 15;
    map[44][30] = 16;
    map[42][30] = 17;
    map[46][30] = 18;
    return 0;
}
