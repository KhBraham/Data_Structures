#include "head.h"

int main()
{
    int n;
    noeud *A=NULL;

    printf("donnez une sequence de nombres non nuls et sans reputution\n");
    do
    {
        scanf("%d", &n);
        ajout_val(&A, n);
        affiche_arb(A);
    }while(n != 0);
    printf("\n");
    affiche_arb(A);
    //printf("\n");
    //printf("la taille de l'arbre est: %d la hauteur est: %d", taille_arbre(A),hauteur_arbre(A));

    return 0;
}
