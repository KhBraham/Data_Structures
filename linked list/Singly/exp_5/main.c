
#include"fonction.h"
int main()
{
    file CP;
    file L;
    file CT;

    cell*nouveau;
    int i;
    CT.debut=NULL;
    CT.fin=NULL;
    CT.nbr=0;
    CP.debut=NULL;
    CP.fin=NULL;
    CP.nbr=0;
    L.debut=NULL;
    L.fin=NULL;
    L.nbr=0;
    for (i=0; i<10; i++)
    {
        nouveau=init2(i);
        ajout_file(&L,nouveau);
    }
    print_file(L);
    copie_file(L,&CP);
    for (i=0; i<15; i++)
    {
        supprime_tail(&L);
        print_file(L);
    }
    print_file(CP);
     for (i=10; i<20; i++)
    {
        nouveau=init2(i);
        ajout_file(&CT,nouveau);
    }
     printf("la file CT\n");
     print_file(CT);
     concat_file(&CP,&CT);
     printf("concatenation\n");
     print_file(CP);
     printf("la file CT\n");
     print_file(CT);
     printf("la suppression \n");
     supprime_tail(&CT);
     printf("la file CT\n");
     print_file(CT);
     printf("la file CP\n");
     print_file(CP);
    nouveau=init2(100);
    ajout_file(&CP,nouveau);
    print_file(CP);

    return 0;
}

