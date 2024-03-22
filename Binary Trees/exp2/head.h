#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
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
int Menu(void);
void CreerValeur2(Arbre **, int );
void CreerValeur3(Arbre **,int );
void ChargerArbre2(Arbre ** ,char * );
void SuppValeur2(Arbre **, int);
void SuppValeur3(Arbre **, int );
int estPhilophorme(Arbre *);
int estFiliforme(Arbre *);
int estPeigne(Arbre *);
int EstPeigneDroit(Arbre *);
int EstPeigne(Arbre *);
Arbre* Peigne(int );
bool est_peigne(Arbre* );
bool est_peigne2(Arbre* );
int compareArbres(Arbre* , Arbre* );

#endif // HEAD_H_INCLUDED
