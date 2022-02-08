#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TP8.h"

void initialiser(int* pEntier, double* pReel) {
    *pEntier = 0;
    *pReel = 0.0;
}
int tp6ex1 (){
    int entier;
    double reel;
    printf("%d %f\n", entier, reel);
    initialiser(&entier, &reel);
    printf("%d %f\n", entier, reel);
    return 0;
}
