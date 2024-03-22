#include "fcth.h"

int main()
{
    cell *nouveau=NULL,*premier=NULL;
    int i;
    for (i=0;i<10;i++)
    {
        nouveau=init();
        premier=ajout_debut1(premier,nouveau);
    }
    printf("Affichage de la liste\n");
    print_liste(premier);
    supprimer_debut(&premier);
    printf("Affichage de la liste\n");
    print_liste(premier);
    int x;
    printf("donnez la valeur a supprimer:");
    scanf("%d",&x);
    supprimer_x(x,&premier);
    print_liste(premier);

    printf("sauvgarder la liste et vider la liste");
    sauvgarde_txt(&premier);
    print_liste(premier);

    return 0;
}
