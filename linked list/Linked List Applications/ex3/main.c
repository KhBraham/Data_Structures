#include "hd.h"

int main()
{
    Arb *A = NULL, *R_val = NULL;
    int n, i, j;
    printf("Gave a number not null:");
    scanf("%d",&n);
    while(n != 0)
    {
        add_valeur(&A, n);
        printf("Gave a number not null:");
        scanf("%d",&n);
    }
    if(A == NULL)
    {
        printf("the tree is empty !\n");
    }
    else
    {
        print_tree_prefixe(A);
        printf("\n La somme des valeurs d'arbre :%d\n",somme(A));
        printf("\n la taille d'arbre :%d\n",taille_tree(A));
    }
    for(i = 0; i < 3; i++)
    {
        printf("gave us a value to find :");
        scanf("%d",&j);
        R_val = find_value(A, j);
        if(R_val != NULL)
        {
            printf("la valeu existe et sa valeur : %d\n",R_val->val);
        }
        else
            printf("Impossible de trouver la valeur recherch\n");

    }
    for(i = 0; i < taille_tree(A); i++)
    {
        printf("\ndonnez une valeur pour supprimer :");
        scanf("%d",&j);
        //delete_val(&A, j);
        A = deleteNode(A, j);
        //SuppValeur(A, j);
        if(A == NULL)
        {
            printf("the tree is empty !\n");
        }
        else
        {
            print_tree_prefixe(A);
        }
    }

    return 0;
}
