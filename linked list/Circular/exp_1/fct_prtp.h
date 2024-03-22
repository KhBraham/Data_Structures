#ifndef FCT_PRTP_H_INCLUDED
#define FCT_PRTP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cel
{
    // 1 : le data pour nos tests
    int val;
    // 2 : le pointeur pour l'élément suivant
    struct cel* next;
}cell;

cell* init(int );
void ajouter(cell **,cell *);
void print_liste(cell *);



#endif // FCT_PRTP_H_INCLUDED
