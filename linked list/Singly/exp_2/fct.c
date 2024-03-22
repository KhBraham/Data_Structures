#include "fcth.h"

cell *init()
{
    char *n[]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    cell *e=(cell*)malloc(sizeof(cell));
    e->val=rand()%26;
    strcpy(e->s,n[rand()%26]);
    e->next=NULL;
    return e;
}
cell *init2(char st,int val)
{
    cell *e=(cell*)malloc(sizeof(cell));
    e->val=val;
    strcpy(e->s,st);
    e->next=NULL;
    return e;
}
cell* ajout_debut1(cell *prem,cell *e)
{
    e->next=prem;
    prem=e;
    return prem;
}

void print_liste(cell *L)
{
    cell *p=NULL;
    if (L==NULL)
    {
        printf("La liste est vide !\n");
    }
    else
    {
        for (p=L;p!=NULL;p=p->next)
        {
            printf("%s %d\n",p->s,p->val);
        }
    }
}

void supprimer_debut(cell **prem)
{
    cell *p=NULL;
    if (*prem!=NULL)
    {
        p=*prem;
        *prem=(*prem)->next;
        free(p);
    }
}

void supprimer_x(int x,cell **prem)
{
    cell *p=NULL,*prec=NULL;
    int ind=0;
    p=*prem;
    prec=*prem;
    if (*prem==NULL)
    {
        printf("la liste est vide!\n");
    }
    else
    {
        if (p->val==x)
        {
            supprimer_debut(prem);

        }
        else
        {
            while(p!=NULL)
            {
                if(p->val!=x)
                {
                    prec=p;
                    p=p->next;
                }
                else
                {
                    prec->next=prec->next->next;
                    free(p);
                    ind=1;
                    break;
                }
            }
            if(ind==0)
            {
                printf("la valeur %d n'existe pas \n");
            }
        }
    }
}

void supprime_liste(cell **L)
{
    cell *p=NULL;
    while(*L!=NULL)
    {
        p=*L;
        *L=(*L)->next;
        free(p);
    }
}

void sauvgarde_txt(cell **L)
{
    FILE *f=fopen("sauv.txt","w");
    cell *p=*L;
    while(p!=NULL)
    {
        fprintf(f,"%d %s\n",p->val,p->s);
        p=p->next;

    }
    supprime_liste(L);
    fclose(f);
}

cell *restorer_txt(void)
{
    FILE *f=fopen("sauv.txt","r");
    cell *L=NULL;
    do
    {
        fscanf(f,"sauv.txt","r");


    }while(feof(f)==0);

    fclose(f);
}
