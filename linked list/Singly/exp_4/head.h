#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
typedef struct cellule
{
    int val;
    struct cellule* suivant;
}cell;

typedef struct fi
{
    cell* debut;
    cell* fin;
    int nbr;
}file;
void ajout_file(file*L,cell*M);
cell* init2(int val);
void print_file(file L);
void supprime_tail(file *L);
#endif // HEAD_H_INCLUDED
