#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED


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
void supprime_tail(file*L);
void copie_file(file L,file *C);
void concat_file(file *L1,file *L2);

#endif // FONCTION_H_INCLUDED
