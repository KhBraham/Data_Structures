#ifndef FCT_H_INCLUDED
#define FCT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
typedef struct Arbre
{
	int Valeur;
	struct Arbre * FG;
	struct Arbre * FD;
} Arbre;

void ajout_val(Arbre **, int );
void ajout_noeud(Arbre **, Arbre *);

void AfficherArbreCroissant(Arbre * );
void AfficherArbreDecroissant(Arbre * );
void AfficherArbre(Arbre * );
Arbre * CreerValeur(Arbre * ,int );
void EnregArbre(Arbre * ,char * );
Arbre * ChargerArbre(Arbre * ,char * );
int Somme(Arbre * );
int CompteValeur(Arbre * );
Arbre * RechercheValeur(Arbre * ,  int );
Arbre * SuppValeur(Arbre * , int );
int Menu();
void CreerValeur2(Arbre **, int );
void CreerValeur3(Arbre **,int );
void ChargerArbre2(Arbre ** ,char * );
void SuppValeur2(Arbre **, int);
void SuppValeur3(Arbre **, int );
int estFiliforme(Arbre *);
bool est_peigne(Arbre* root);
bool est_peigne2(Arbre* Racine);
int identique(Arbre* , Arbre* );

#endif // FCT_H_INCLUDED
