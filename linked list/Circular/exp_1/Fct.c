#include "fct_prtp.h"

cell* init(int i)
{
    cell *e=malloc(sizeof(cell));
    e->val=i;
    e->next=NULL;
    return e;
}

void ajouter(cell **L,cell *nouv)
{
    if (*L == NULL)
    {
        *L = nouv;
        (*L)->next = *L;
    }
    else
    {
        cell *p=*L;
        while (p->next != *L) {
            p = p->next;
        }
        p->next = nouv;
        nouv->next = *L;
    }
}
void print_liste(cell *L)
{
    cell *p=NULL;
    if(L==NULL)
    {
        printf("La liste est VIDE!\n");
    }
    else
    {
        for(p=L;p->next!=L;p=p->next)
        {
            printf("%d\n",p->val);
        }
        printf("%d\n",p->val);
    }
}
cell *supprime_x(cell**L,int x)
{
    cell *prec=NULL,*p=NULL,*suiv=NULL;
    int ind=0;
    p=*L;
    prec=*L;
    if(*L==NULL)
    {
       printf("la liste est vide!\n");
    }
    else
    {
        do
        {
            if(p->val!=x*2+1)
            {
                prec=p;
                p=p->next;
            }
            else
            {
                prec->next=prec->next->next;
                suiv=prec->next;
                free(p);
                ind=1;
                break;
            }
        }while(p->next!=*L);

     }
     return suiv;
}
