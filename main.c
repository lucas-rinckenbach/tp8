#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TP8.h"

int main (){
    int n = 0;
    int demanderentier= 0;
    printf("quel est l'entier \n");
    scanf(" %d",&n);
    int* tab = malloc(n *sizeof (int));
    for (int i = 0; i < n ; ++i) {
        printf("quel valeur sera dans votre case\n");
        scanf("%d",&demanderentier);
        tab[i]= demanderentier;
    }
    free(tab);
    return 0;
}