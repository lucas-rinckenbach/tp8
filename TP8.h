//
// Created by lucas rinckenbach on 02/02/2022.
//

#ifndef TP8_TP8_H
#define TP8_TP8_H
int compterOccurs(char* str , char c);
void tp7ex1();
int getRandomInteger ( int min , max);
int tp7ex2 ();
int tp7ex3 ();
typedef struct{
    int longueur;
    int largeur;

}Rectangle;
void afficherRectangles(Rectangle** rectangles, int tailleLogique);
Rectangle* creerRectangle();
void ajouterRectangle(Rectangle*** pRectangles, int* pTaillePhysique, int* pTailleLogique, Rectangle** pRectangleFavori);
int tp8ex5();
int tp8ex2 ();
int tp8ex1 ();
void initialiser(int* pEntier, double* pReel);
#endif //TP8_TP8_H
