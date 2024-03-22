#include"head.h"
void ajout_file(file*L,cell*M)
{
    if(L->fin==NULL)
    {
        L->debut=M;
    }
    else
    {
        L->fin->suivant=M;
    }
    L->fin=M;
    L->nbr++;
}
cell* init2(int val)
{
    cell *e=malloc(sizeof(cell));
    e->val = val;
    e->suivant=NULL;
    return e;
}
void print_file(file L)
{
    cell *p=NULL;
    printf("La liste contient %d element\n",L.nbr);
    if(L.fin==NULL)
    {
        printf("La liste est VIDE!\n");
    }
    else
    {
        for(p=L.debut;p!=NULL;p=p->suivant)
        {
            printf("%d\n",p->val);
        }
    }
}
void supprime_tail(file*L)
{
    cell*p,*q;
    if(L->fin==NULL)//nbr=0 ou debut=0
    {
        printf("La liste est vide\n");
    }
    else
    {
        if(L->debut==L->fin)//L->nbr==1
        {
            p=L->debut;//ou L->fin
            L->debut=NULL;
            L->fin=NULL;
            L->nbr=0;
            free(p);
        }
        else
        {
            p=L->debut;
            /*while(p->suivant!=L->fin)
            {
                p=p->suivant;
            }*/
            for(p=L->debut;p->suivant!=L->fin;p=p->suivant);//ou la condition L->fin->suivant!=NULL
            q=L->fin;
            p->suivant=NULL;
            L->fin=p;
            free(q);
            L->nbr--;
        }
    }
}
