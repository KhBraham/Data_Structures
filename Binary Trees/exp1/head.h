#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct arbre
{
    int val;
    struct arbre *FG, *FD;
}noeud;

void ajout_val(noeud **, int );
void ajout_noeud(noeud **, noeud *);
int taille_arbre(noeud *);
int max(int , int );
int taille_arbre(noeud *);
#endif // HEAD_H_INCLUDED
