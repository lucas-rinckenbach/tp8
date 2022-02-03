//
// Created by lucas rinckenbach on 02/02/2022.
//

#include "TP8.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int compterOccurs(char* str , char c){
    int compteur = 0;
    for ( int i = 0; str[i] != '\0' ; i++){
        if (str[i] == c ){
            compteur ++ ;
        }

    }
    return compteur ;
}
void tp7ex1() {
    char texte[100] = "Bonjour";
    char caract = 'o';
    printf("le mot \"%s\" contient %d fois la lettre %c\n", texte , compterOccurs(texte ,caract), caract);

}
int getRandomInteger ( int min , max){
    return rand() % (max + 1 - min ) + min ;
}
int tp7ex2 (){
    srand(time(NULL));
    printf("%d\n", getRandomInteger(0,10));
    return 0;
}
int tp7ex3 (){
    int min = 0;
    int max = 0 ;
    int choixutilisateur = 0;

    printf("Quel est le min ?");
    scanf("%d", &min);
    printf("Quel est le max ? ");
    scanf("%d", &max);
    int but = getRandomInteger(min , max);
    printf("qu'elle est la valeur de but ?\n");
    scanf(" %d", &choixutilisateur );
    while(choixutilisateur != but){
        if (choixutilisateur < but){
            printf("la valeur de but est plus grande que %d\n", choixutilisateur);
        }

        else {
            printf("la valeur de but est plus petite que %d\n", choixutilisateur);
        }
        printf("qu'elle est la valeur de but ?\n");
        scanf(" %d", &choixutilisateur );
    }
    printf("c'est bien le nombre %d\n", but);

    return 0 ;
}
void afficherRectangles(Rectangle** rectangles, int tailleLogique) {
    for (int i = 0; i < tailleLogique; i++) {
        printf("Rectangle de %d x %d.\n", rectangles[i]->largeur, rectangles[i]->longueur);
    }
}
Rectangle* creerRectangle() {
    Rectangle* rect = malloc(1 * sizeof(Rectangle));
    printf("Allocation d'un rectangle en 0x%p.\n", rect);
    printf("Largeur ?\n");
    //scanf("%d", &(*rect).largeur);
    scanf("%d", &rect->largeur);
    //scanf("%d", &rect[0].largeur);
    printf("Longueur ?\n");
    scanf("%d", &rect->longueur);
    return rect;
}
void ajouterRectangle(Rectangle*** pRectangles, int* pTaillePhysique, int* pTailleLogique, Rectangle** pRectangleFavori) {
    int estFavori = 0;
    if(*pRectangles == NULL) {
        *pTaillePhysique = 3;
        *pTailleLogique = 0;
        *pRectangles = calloc(*pTaillePhysique, sizeof(Rectangle *));
        printf("Allocation du tableau en 0x%p.\n", *pRectangles);
    }

    if(*pTailleLogique >= *pTaillePhysique) { // si le tableau est plein
        *pTaillePhysique += 3;
        *pRectangles = realloc(*pRectangles, *pTaillePhysique * sizeof(Rectangle*));
        printf("Reallocation du tableau en 0x%p.\n", *pRectangles);

    }

    (*pRectangles)[*pTailleLogique] = creerRectangle();
    printf("Est-ce votre nouveau rectangle favori ? (0 = non, 1 = oui)\n");
    scanf("%d", &estFavori);
    if(estFavori) {
        *pRectangleFavori = (*pRectangles)[*pTailleLogique];
    }
    (*pTailleLogique)++;
}
int tp8ex5() {
    Rectangle** rectangles = NULL;
    int taillePhysique = 0, tailleLogique = 0;
    int ajouterNouveau = 0;
    Rectangle* rectangleFavori = NULL;

    while(1) {
        printf("Voulez-vous ajouter un nouveau rectangle ? (0 = non, 1 = oui)\n");
        scanf("%d", &ajouterNouveau);
        if(ajouterNouveau == 0) {
            break;
        }
        ajouterRectangle(&rectangles, &taillePhysique, &tailleLogique, &rectangleFavori);
    }

    afficherRectangles(rectangles, tailleLogique);

    if(rectangleFavori != NULL) {
        printf("Votre rectangle favori est celui de %d x %d.\n", rectangleFavori->largeur, (*rectangleFavori).longueur);
    }


    for (int i = 0; i < tailleLogique; i++) {
        free(rectangles[i]);
        printf("Liberation d'un rectangle en 0x%p.\n", rectangles[i]);
        rectangles[i] = NULL;
    }
    if(rectangles != NULL) {
        free(rectangles);
        printf("Liberation du tableau en 0x%p.\n", rectangles);
        tailleLogique = taillePhysique = 0;
        rectangles = NULL;
    }

    return 0;
}
