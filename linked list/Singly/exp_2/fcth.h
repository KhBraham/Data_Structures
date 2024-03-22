#ifndef FCTH_H_INCLUDED
#define FCTH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct cel
{
    int val;
    char s[80];
    struct cel* next;
}cell;

cell * init();
cell * ajout_debut1(cell *,cell *);
void print_liste(cell *);
void supprimer_debut(cell **);
void supprimer_x(int ,cell **);
void supprime_liste(cell **);
void sauvgarde_txt(cell **);

#endif // FCTH_H_INCLUDED
