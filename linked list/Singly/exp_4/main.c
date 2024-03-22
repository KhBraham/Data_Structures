#include"head.h"
int main()
{
    file L;
    L.debut=NULL;
    L.fin=NULL;
    L.nbr=0;
    cell*nouveau;
    int i;
    for (i=0; i<10; i++)
    {
        nouveau=init2(i);
        ajout_file(&L,nouveau);
    }
    print_file(L);
    for (i=0; i<15; i++)
    {
        supprime_tail(&L);
        print_file(L);
    }
    return 0;
}
