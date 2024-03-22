#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int val;
    struct cell *next;
}cell;

cell* init();
cell* init1(int );
cell* add_head(cell *, cell *);
void add_head1(cell **, cell *);
void add_end(cell **, cell *);
void print_list(cell *);
void find_max_iter(cell *);
int find_max_rec(cell *, int );
int max_rec(cell *);
void concatenate(cell **, cell **);
void sepaiet(cell *, cell **, cell **);
void free_list(cell *);
void permuter(cell **, cell *, cell *);
cell *find_x(cell *, int );
void delete_x(cell **, int );
void delete_xkeme(cell **, int , int );
void not_repeted(cell **);
void reverse_itr(cell **);
void transf(cell **);
void print_cecle_list(cell *);
int poly_init(cell **);
int poly_evaluer(cell *, int );
void cercle_ordonnee(cell **, int );





#endif // HEAD_H_INCLUDED
