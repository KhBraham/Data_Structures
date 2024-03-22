#include "fct_prtp.h"

int main()
{
    cell *L=NULL,*nouv;
    int i;
    for(i=1;i<57;i++)
    {
        nouv=init(i);
        ajouter(&L,nouv);

    }
    print_liste(L);
    return 0;
}
