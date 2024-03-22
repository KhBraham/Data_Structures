#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel
{
    int val;
    char s[80];
    struct cel *next;
}cell;

cell* init()
{
    char *n[]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    cell *e=(cell *)malloc(sizeof(cell));
    e->val=(rand()%26);
    strcpy(e->s,n[rand()%26]);
    e->next=NULL;
    return e;
}

cell *init2(int val, char *st)
{
    cell *e=(cell *)malloc(sizeof(cell));
    e->val=val;
    strcpy(e->s,st);
    e->next=NULL;
    return e;
}

cell* ajout_debut1(cell *prem, cell *e)
{
    e->next=prem;
    prem=e;
    return prem;
}

void ajout_debut2(cell **prem, cell *e)
{
    e->next=*prem;
    *prem=e;
}
cell *ajout_ord(cell *prem, cell *e)
{
    cell *prec=NULL ,*p=prem;
    if(prem==NULL || e->val<prem->val)
    {
        e->next=prem;
        return e;
    }
    while((p!=NULL) && (e->val>=p->val))
    {
        prec=p;
        p=p->next;
    }
    prec->next=e;
    e->next=p;

    return prem;
}

void print_liste(cell *L)
{
    cell *p=NULL;
    if (L==NULL)
    {
        printf("la liste est vide !");
    }
    else
    {
        for(p=L;p!=NULL;p=p->next)
        {
            printf("%d %s\n",p->val,p->s);
        }
    }
}

void suprimer_premier(cell **prem)
{
    cell *p = *prem;
    if (p==NULL)
    {
        printf("la liste est vide !");
    }
    else
    {
        *prem=(*prem)->next;
        free(p);
    }
}

cell *suprimer_val(cell *prem,int x)
{
    cell *prec=NULL, *p=prem;
    int i=0;
    prec=prem;
    if(prem==NULL)
    {
        printf("la liste est vide!");
        i=1;//return prem;
    }
    else
    {
        while(i==0 && p!=NULL)
        {
            if(prem->val==x)
            {
                p=prem;
                prem=prem->next;
                i=1;
            }
            else
            {
                if(p->val==x)
                {
                    prec->next=p->next;//prec->next=prec->next->next;
                    free(p);
                    i=1;
                }
                else
                {
                    prec=p;
                    p=p->next;
                }
            }
        }
    }
    if(i==0)
        printf("la valeur entrEe n'existe pas!\n");
    return prem;
}
/*
cell *supprimer_val(cell *prem, int x) {
    cell *prec = NULL, *p = prem;

    if (prem == NULL) {
        printf("la liste est vide!\n");
        return prem;
    }

    while (p != NULL) {
        if (p->val == x) {
            if (p == prem) {
                prem = prem->next; // If the first element needs to be removed
            } else {
                prec->next = p->next;
            }
            free(p);
            break;
        }
        prec = p;
        p = p->next;
    }

    if (p == NULL) {
        printf("la valeur entrée n'existe pas!\n");
    }

    return prem;
}
*/
void suprimer_liste(cell **L)
{
    cell *p=NULL;
    if(*L != NULL)
    {
        while(*L != NULL)
        {
            p=*L;
            *L=(*L)->next;
            free(p);
        }
    }
    else
    {
        printf("la liste est vide!");
    }

}
void inverst(cell **prem)
{
    cell *prev = NULL, *current = *prem, *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *prem = prev;  // Update the head of the list to point to the new first node (previously the last node)
}

/*void inverst(cell **prem)
{
    cell *p = NULL, *prec = NULL, *paus = NULL;
    if ((*prem)->next == NULL || *prem == NULL)
        return;
    else
    {
        paus = *prem;
        while (paus->next != NULL)
        {
            for (p = *prem; p->next != NULL; p = p->next);
            for (prec = *prem; prec->next != p; prec = prec->next);
            p->next = *prem;
            prec->next = NULL;
            *prem = p;
        }
    }
}*/



int main()
{
    cell *nouveau=NULL, *premier=NULL;
    int x,n;
    char st[100];
    for(int i=0;i<10;i++)
    {
        /*printf("donnez une valeur :");
        scanf("%d",&n);
        printf("donnez une chaine de caracter :");
        scanf("%s",st);
        nouveau=init2(n,st);*/
        nouveau=init();
        premier=ajout_ord(premier,nouveau);
        //ajout_debut2(&premier,nouveau);
    }
    printf("Afichage du liste chainee:\n");
    print_liste(premier);
    suprimer_premier(&premier);
    printf("Afichage du liste chainee:\n");
    print_liste(premier);
    printf("donnez une valeur pour supprimer: ");
    scanf("%d",&x);
    premier=suprimer_val(premier,x);
    printf("Afichage du liste chainee:\n");
    print_liste(premier);
    /*suprimer_liste(&premier);
    printf("Afichage du liste chainee:\n");
    print_liste(premier);*/
    inverst(&premier);
    printf("Afichage du liste chainee:\n");
    print_liste(premier);
    return 0;
}
