#ifndef HD_H_INCLUDED
#define HD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

typedef struct Arb
{
    int val;
    struct Arb *FD, *FG;
}Arb;

void add_arbre(Arb **, Arb *);
void add_valeur(Arb **, int );
void print_tree_prefixe(Arb *);
void print_tree_infixe(Arb *);
void print_tree_suffixe(Arb *);
int somme(Arb *);
int taille_tree(Arb *);
Arb* find_value(Arb *, int );
void delete_val(Arb **, int );
Arb * SuppValeur(Arb *, int );
Arb* deleteNode(Arb* , int );




#endif // HD_H_INCLUDED
