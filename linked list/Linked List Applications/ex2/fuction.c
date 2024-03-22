#include "head.h"

//ex1
cell* init()
{
    cell *e = (cell *)malloc(sizeof(cell));
    printf("donner une valeur :");
    scanf("%d",&e->val);
    e->next = NULL;
    return e;
}

cell* init1(int x)
{
    cell *e = (cell *)malloc(sizeof(cell));
    e->val = x;
    e->next = NULL;
    return e;
}

void free_list(cell *prem)
{
    cell *current = prem;
    cell *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}


cell* add_head(cell *prem, cell *e)
{
    e->next = prem;
    return e;
}

void add_head1(cell **prem, cell *e)
{
    e->next = *prem;
    *prem = e;
}

void add_end(cell **prem, cell *e)
{
    cell *p = NULL;
    if(*prem == NULL)
    {
        e->next = *prem;
        *prem = e;
    }
    else
    {
        for(p = *prem; p->next!=NULL; p = p->next);
        p->next = e;
    }
}

void print_list(cell *prem)
{
    cell *p = NULL;
    if(prem == NULL)
    {
        printf("la liste est VIDE !!");
    }
    else
    {
        int i = 0;
        for(p=prem;p!=NULL;p=p->next)
        {
            i++;
            printf("le %d eme element dans la liste : %d \n",i,p->val);
        }
    }
}

void find_max_iter(cell *prem)
{
    cell *p = NULL;
    if(prem == NULL)
    {
        printf("la liste est vide!");
        return;
    }
    else
    {
        int max = prem->val;
        for(p = prem->next; p != NULL; p = p->next)
        {
            if(max < p->val)
                max = p->val;
        }
        printf("la valeur maximale ext : %d\n",max);
    }
}

int find_max_rec(cell *p, int max)
{
    if (p == NULL)
        return max;
    else
    {
        if(max < p->val)
            max = p->val;
        find_max_rec(p->next, max);
    }
}

int max_rec(cell *prem)
{
    if (prem == NULL) {
        return -1;
    }
    if (prem->next == NULL) {
        return prem->val;
    }
    int maxReste = max_rec(prem->next);
    return (prem->val > maxReste) ? prem->val : maxReste;
}
//ex2
void concatenate(cell **L1, cell **L2)
{
    if(*L1 == NULL)
    {
        *L1 = *L2;
        return;
    }
    else
    {
        cell *p;
        for(p = *L1; p->next != NULL; p=p->next);
        p->next = *L2;
        *L2 = *L1;
    }
}
//ex3

void sepaiet(cell *prem, cell **L1, cell **L2)
{
    if(prem == NULL)
    {
        printf("la liste est vide!");
    }
    else
    {
        cell *p = NULL;
        for(p = prem; p != NULL; p = p->next)
        {
            cell *nouv = init1(p->val);
            if(p->val >= 0)
                add_end(L1,nouv);
            else
                add_end(L2,nouv);
        }
    }
}
/*
void permuter(cell **prem, cell t, cell *v)
{
    cell *prect = t, *suiv_t = NULL, *precv = v, *siuv_v = NULL, *p = NULL;
    for(p = *prem; p->next != t; p = p->next);
    prect = p;
    suiv_t = t->next;
    for(p = *prem; p->next != v; p = p->next);
    precv = p;
    suiv_v = v->next;
    if(t == *prem || v == *prem)
    {
        if(t == *prem)
        {
            precv->next = t;
            t->next = suiv_v;
            v->next = suiv_t;
            *prem = v;
        }
        else
        {
            prect->next = v;
            v->next = suiv_t;
            t->next = suiv_v;
            *prem = t;
        }
    }
    else
    {
        prect->next = v;
        v->next = suiv_t;
        precv->next = t;
        t->next = suiv_v;
    }
}
void permuter(cell **prem, cell *t, cell *v)
{
    if (*prem == NULL || t == NULL || v == NULL)
    {
        fprintf(stderr, "Invalid pointers.\n");
        exit(EXIT_FAILURE);
    }

    if (t == v)
    {
        // No need to swap if t and v are the same
        return;
    }

    cell *prect = NULL, *suiv_t = NULL, *precv = NULL, *suiv_v = NULL, *p = NULL;

    // Find predecessor and successor for t
    for (p = *prem; p != NULL; p = p->next)
    {
        if (p->next == t)
        {
            prect = p;
            suiv_t = t->next;
            break;
        }
    }

    // Find predecessor and successor for v
    for (p = *prem; p != NULL; p = p->next)
    {
        if (p->next == v)
        {
            precv = p;
            suiv_v = v->next;
            break;
        }
    }

    // Check if t and v are adjacent nodes
    if (suiv_t == v || suiv_v == t)
    {
        if (t == *prem)
        {
            // Swap t and v directly
            precv->next = t;
            t->next = suiv_v;
            v->next = t;
            *prem = v;
        }
        else
        {
            if (v == *prem)
            {
                // Swap t and v directly
                prect->next = v;
                v->next = suiv_t;
                t->next = v;
                *prem = t;
            }
            else
            {
                // Swap t and v directly
                prect->next = v;
                v->next = suiv_t;
                precv->next = t;
                t->next = suiv_v;
            }
        }
    }
    else
    {
        // General case: t and v are not adjacent
        if (t == *prem)
        {
            // Update the head to v
            *prem = v;
            precv->next = t;
            t->next = suiv_v;
            prect->next = v;
            v->next = suiv_t;
        }
        else
        {
            if (v == *prem)
            {
                // Update the head to t
                *prem = t;
                prect->next = v;
                v->next = suiv_t;
                precv->next = t;
                t->next = suiv_v;
            }
            else
            {
                // Neither t nor v is the head
                prect->next = v;
                v->next = suiv_t;
                precv->next = t;
                t->next = suiv_v;
            }
        }
    }
}*/

void permuter(cell **prem, cell *t, cell *v)
{
    // Check if the pointers are valid
    if (*prem == NULL || t == NULL || v == NULL) {
        fprintf(stderr, "Invalid pointers.\n");
        exit(EXIT_FAILURE);
    }

    // Special case: if t and v are the same, no need to swap
    if (t == v) {
        return;
    }

    // Variables to track the predecessor and successor of t and v
    cell *prect = NULL, *suiv_t = NULL, *precv = NULL, *suiv_v = NULL, *p = NULL;

    // Find predecessor and successor for t
    for (p = *prem; p != NULL; p = p->next) {
        if (p->next == t) {
            prect = p;
            suiv_t = t->next;
            break;
        }
    }

    // Find predecessor and successor for v
    for (p = *prem; p != NULL; p = p->next) {
        if (p->next == v) {
            precv = p;
            suiv_v = v->next;
            break;
        }
    }

    // Check if t and v are adjacent nodes
    if (suiv_t == v || suiv_v == t) {
        if (t == *prem) {
            // Swap t and v directly
            precv->next = t;
            t->next = suiv_v;
            v->next = t;
            *prem = v;
        } else if (v == *prem) {
            // Swap t and v directly
            prect->next = v;
            v->next = suiv_t;
            t->next = v;
            *prem = t;
        } else {
            // Swap t and v directly
            prect->next = v;
            v->next = suiv_t;
            precv->next = t;
            t->next = suiv_v;
        }
    } else {
        // General case: t and v are not adjacent
        prect->next = v;
        v->next = suiv_t;
        precv->next = t;
        t->next = suiv_v;
    }
}


cell *find_x(cell *prem, int x)
{
    // Traverse the list until a node with the desired value is found
    while (prem != NULL)
    {
        if (prem->val == x)
        {
            // Node with the desired value found, return the pointer to this node
            return prem;
        }
        prem = prem->next; // Move to the next node
    }

    // If the value is not found, return NULL
    return NULL;
}
//ex5
void delete_x(cell **prem, int x)
{
    if(*prem == NULL)
    {
        printf("la liste est vide");
        return;
    }
    cell *p = *prem, *prec = NULL, *q = NULL;
    while(p != NULL)
    {
        if((*prem)->val == x)
        {
            q = *prem;
            *prem = (*prem)->next;
            prec = *prem;
            p = *prem;
            free(q);
        }
        else
        {
            if(p->val == x)
            {
                prec->next = p->next;
                q = p;
                p = p->next;
                free(q);
            }
            else
            {
                prec = p;
                p = p->next;
            }
        }
    }
}
/*
void delete_x(cell **prem, int x) {
    if (*prem == NULL) {
        printf("la liste est vide");
        return;
    }

    cell *p = *prem;  // Initialize p to the head of the list
    cell *prec = NULL; // Initialize prec to NULL

    // Traverse the list
    while (p != NULL) {
        if (p->val == x) {
            // Node with value x found

            // If the node is the head of the list
            if (prec == NULL) {
                *prem = p->next; // Update the head
                free(p);        // Free the node
                p = *prem;      // Move to the next node
            } else {
                // If the node is not the head
                prec->next = p->next; // Update the previous node's next pointer
                free(p);              // Free the node
                p = prec->next;       // Move to the next node
            }
        } else {
            // Node does not have the value x
            prec = p; // Move prec to the current node
            p = p->next; // Move to the next node
        }
    }
}
*/

void delete_xkeme(cell **prem, int x, int i)
{
    if(*prem == NULL)
    {
        printf("la liste est vide");
        return;
    }
    cell *p = *prem, *prec = NULL, *q = NULL;
    while(p != NULL)
    {
        if(p->val == x)
        {
            if(i == 0)
            {
                prec->next = p->next;
                q = p;
                p = p->next;
                free(q);
            }
            else
            {
                i--;
                prec = p;
                p = p->next;
            }
        }
        else
        {
            prec =p;
            p = p->next;
        }
    }
}

void not_repeted(cell **prem)
{
    if(*prem == NULL)
    {
        printf("la liste est vide!");
        return;
    }
    cell *p = NULL;
    for(p = *prem; p != NULL; p = p->next)
    {
        delete_xkeme(prem,p->val,1);
    }
}
//ex6
void reverse_itr(cell **prem)
{
    cell *p = *prem, *q = NULL;
    while(p != NULL)
    {
        *prem = p->next;
        p->next = q;
        q = p;
        p = *prem;
    }
    *prem = q;
}
//ex7
void transf(cell **prem)
{
    if(prem == NULL)
    {
        printf("la liste est vide");
        return;
    }
    cell *p = NULL;
    for(p = *prem; p->next != NULL; p = p->next);
    p->next = *prem;
}

void print_cecle_list(cell *prem)
{
    if(prem == NULL)
    {
        printf("la liste est vide");
        return;
    }
    cell *p = NULL;
    int i = 1;
    for(p = prem; p->next != prem; p = p->next)
    {
        printf("le %d eme element dans la liste : %d \n",i,p->val);
        i++;
    }
    printf("le %d eme element dans la liste : %d \n",i,p->val);
}
//ex8
int poly_init(cell **prem)
{
    int i, j, n;
    cell *nouv;
    printf("donnez le degree du polynome:");
    scanf("%d",&n);
    for(i = 0; i <= n; i++)
    {
        printf("donnez le coeficient a%d :",i);
        scanf("%d",&j);
        nouv = init1(j);
        add_head1(prem, nouv);
    }
    return n;
}

int poly_evaluer(cell *prem, int x)
{
    cell *p = NULL;
    int s = 0;
    for(p = prem; p != NULL; p = p->next)
    {
        s = s * x + p->val;
    }
    return s;
}
//ex9
void cercle_ordonnee(cell **prem, int n)
{
    cell *nouv = NULL, *p = NULL, *prec = NULL, *last = NULL;
    int i,j;
    for(i = 0; i < n; i++)
    {
        printf("donnez le %d nombre :",i);
        scanf("%d",&j);
        nouv = init1(j);
        if(*prem == NULL)
        {
            *prem = nouv;
            (*prem)->next = *prem;
            last = *prem;
        }
        else
        {
            for(p = *prem; p->next != *prem; p = p->next)
            {
                if(nouv->val < p->val)
                {
                    if(p == *prem)
                    {
                        last->next = nouv;
                        nouv->next = *prem;
                        *prem = nouv;
                        prec = *prem;
                        break;
                    }
                    else
                    {
                        prec->next = nouv;
                        nouv->next = p;
                        break;
                    }
                }
                else
                {
                    if(p->next == NULL)
                    {
                        p->next = nouv;
                        last = nouv;
                        nouv->next = *prem;
                        last->next = *prem;
                        prec = *prem;
                        break;
                    }
                    else
                    {
                        prec = p;
                    }
                }
            }
        }
    }
}



















