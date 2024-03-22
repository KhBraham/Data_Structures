#include "head.h"

int main()
{
    //ex1

    cell *premier = NULL, *nouv = NULL;
    //cell *L1 = NULL, *L2 = NULL;

    /*
    for(int i=0;i<6;i++)
    {
        nouv = init();
        add_end(&premier, nouv);
    }
    printf("l'affichage de la liste : \n");
    print_list(premier);
    //find_max_iter(premier);
    if(premier == NULL)
        printf("la liste est vide!");
    else
    {
        int max = premier->val;
        max = find_max_rec(premier, max);
        printf("la valeur maximale ext : %d\n",max);
    }
    return 0;
    //max_rec(premier)*/

    //ex2
    /*for(int i=0;i<5;i++)
    {
        nouv = init();
        add_end(&L1, nouv);
    }
    printf("l'affichage de la liste avec L1: \n");
    print_list(L1);
    for(int i=0;i<5;i++)
    {
        nouv = init();
        add_end(&L2, nouv);
    }
    printf("l'affichage de la liste avec L2: \n");
    print_list(L2);
    concatenate(&L1,&L2);
    //EX3
    sepaiet(premier,&L1,&L2);
    printf("l'affichage de la liste avec L1: \n");
    print_list(L1);
    printf("l'affichage de la liste avec L2: \n");
    print_list(L2);
    //EX4
    int x1, x2;
    printf("donnez deux valeur :");
    scanf("%d %d",&x1,x2);
    cell *t = find_x(premier,x1), *v = find_x(premier,x2);
    permuter(&premier,t,v);
    print_list(premier);*/
    //EX5
    int x;
    /*
    printf("donnez une valeur :");
    scanf("%d",&x);
    printf("combien des fois pour ingnorer le %d :",x);
    int i=0;
    scanf("%d",&i);
    delete_xkeme(&premier,x,i);
    not_repeted(&premier);
    printf("l'affichage de la liste apres la supprission : \n");
    print_list(premier);
    //EX6
    reverse_itr(&premier);
    printf("l'affichage de la liste : \n");
    print_list(premier);
    //EX7
    transf(&premier);
    printf("l'affichage de la liste : \n");
    print_cecle_list(premier);
    //EX8
    printf("la construction du polynome : \n");
    int n = poly_init(&premier);
    printf("le degree du polynome est : %d\n",n);
    printf("l'affichage de la liste : \n");
    print_list(premier);
    printf("donnez une valeur :");
    scanf("%d",&x);
    printf("P(%d) = %d",x,poly_evaluer(premier,x));*/
    //EX9
    int T[10] = {12, 2, 35, 14, 55, 16, 87, 48, 9, 110};
    cercle_ordonnee(&premier,10);
    printf("l'affichage de la liste : \n");
    print_cecle_list(premier);*


    free_list(premier);
    //free_list(L1);
    //free_list(L2);

    return 0;
}
