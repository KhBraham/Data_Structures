#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cel
{
    // 1 : les datas pour nos tests
    int val;
    char s[80];
    // 2 : le pointeur pour l'élément suivant
    struct cel* next;
}cell;

cell* init()
{
    char* n[]={"A","B","C","D","E","F","G","H","I","J","K",
    "L","M","N","O","P","Q","R","S","T","U","V","X","Y","Z"};
    cell *e=malloc(sizeof(cell));
    e->val=rand()%26;
    strcpy(e->s,n[rand()%26]);
    e->next=NULL;
    return e;
}
cell* init2(int val, char *st)
{
    cell *e=malloc(sizeof(cell));
    strcpy(e->s,st);
    e->val = val;
    e->next=NULL;
    return e;
}
cell* ajout_debut1(cell*prem,cell*e)
{
    e->next=prem;
    prem=e;
    return prem;
}
void ajout_debut2(cell **prem,cell*e)
{
    e->next=*prem;
    *prem=e;
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
        for(p=L;p!=NULL;p=p->next)
        {
            printf("%s %d\n",p->s,p->val);
        }
    }
}

void rotation(cell **prem)
{
    if(*prem == NULL)
    {
        printf("la liste est vide !");
        return;
    }
    cell *p = *prem, *q = NULL;
    if((*prem)->next == NULL)
        return;
    else{
        while(p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        p->next = *prem;
        *prem = p;
    }
}

void concat(cell **l, cell **m)
{
    if (*l == NULL)
    {
        *l = *m;  // If the first list is empty, simply point it to the second list
    }
    else if (*m != NULL)
    {
        cell *p = *l;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = *m;  // Concatenate the second list to the end of the first list
        *m = NULL;     // Set the second list pointer to NULL to avoid dangling pointers
    }
}

void rotation_n(cell** prem, int n) {
    int i;

    // Vérifier si la liste est vide
    if (*prem == NULL) {
        printf("La liste est vide !");
        return;
    }

    // Vérifier si la liste a un seul élément ou est déjà vide après la rotation
    if ((*prem)->next == NULL || n <= 0) {
        return;
    }

    // Effectuer la rotation n fois
    for (i = 0; i < n; i++) {
        cell* prec = NULL;
        cell* p = *prem;

        // Parcourir la liste jusqu'à la fin
        while (p->next != NULL) {
            prec = p;
            p = p->next;
        }

        // Déplacer le dernier élément au début
        prec->next = NULL;
        p->next = *prem;
        *prem = p;
    }
}

void substr(cell** L, cell* M) {
    if (*L == NULL || M == NULL) {
        return;
    }

    cell *p = *L, *prec = NULL, *q = NULL, *u = NULL;

    while (p != NULL) {
        int i = 0;
        prec = p;

        for (u = M; u != NULL; u = u->next) {
            if (p->val == u->val) {
                if (p == *L) {
                    q = *L;
                    *L = (*L)->next;
                    p = *L;
                    free(q);
                    break;
                } else {
                    q = p;
                    prec->next = p->next;
                    p = p->next;
                    free(q);
                    break;
                }
                i = 1;
            }
        }

        if (i == 0) {
            p = p->next;
        }
    }
}

int main()
{
    cell* premier=NULL;
    cell*nouveau;
    int i,x;
    rotation(&premier);
    for (i=0; i<10; i++)
    {
        nouveau=init();
        ajout_debut2(&premier,nouveau);
    }
    printf("Affichage de la liste\n");
    print_liste(premier);
    rotation(&premier);
    printf("Affichage de la liste\n");
    print_liste(premier);
    rotation_n(&premier,3);
    printf("Affichage de la liste\n");
    print_liste(premier);

    return 0;
}
