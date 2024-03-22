#include <stdio.h>
#include <stdlib.h>

typedef struct maillon
{
    float val;
    struct maillon *next;
}cel;
int main()
{
    cel *T,*nouv,*p;
    int choix=1;
    T=(cel *)malloc(sizeof(cel));
    printf("donnez une valeur:\n");
    scanf("%f",&T->val);
    T->next=NULL;
    p=T;
    while(choix!=0)
    {
        nouv=(cel *)malloc(sizeof(cel));
        printf("donnez une valeur:\n");
        scanf("%f",&nouv->val);
        nouv->next=NULL;
        p->next=nouv;
        p=p->next;
        printf("voulez vous intruduire une autre tapez une autre valeur different de 0 \n");
        scanf("%d",&choix);
    }
    for (p=T;p!=NULL;p=p->next)
    {
        printf("%f\n",p->val);
    }
    return 0;
}
9
