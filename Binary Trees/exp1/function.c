#include "head.h"

void ajout_val(noeud **Ar, int x)
{
    noeud *nouv=(noeud *)malloc(sizeof(noeud));
    if(nouv==NULL)
    {
        printf("Erreur d'allocation de memoire\n");
        exit(4);
    }
    nouv->val=x;
    nouv->FG=NULL;
    nouv->FD=NULL;
    ajout_noeud(Ar,nouv);

}

void ajout_noeud(noeud **Ar, noeud *nouv)
{
    if(*Ar==NULL)
    {
        *Ar=nouv;
    }
    else
    {
        if(nouv->val==(*Ar)->val)
        {
            printf("la valeur deja existante!\n");
            return;
        }
        else
        {
            if(nouv->val<(*Ar)->val)
            {
               if((*Ar)->FG==NULL)
                {
                    (*Ar)->FG=nouv;
                }
                else
                    ajout_noeud(&(*Ar)->FG,nouv);
            }

            else
            {
                if((*Ar)->FD==NULL)
                {
                    (*Ar)->FD=nouv;
                }
                else
                    ajout_noeud(&(*Ar)->FD,nouv);
            }
        }
    }
}


void affiche_arb(noeud *Ar)
{
    if(Ar==NULL)
    {
        return;
    }
    else
    {
        affiche_arb(Ar->FG);
        affiche_arb(Ar->FD);
        printf("%d -> ",Ar->val);
    }
}

int taille_arbre(noeud *Ar)
{
    if(Ar==NULL)
    {
        return 0;
    }
    else
    {
        return taille_arbre(Ar->FD)+taille_arbre(Ar->FG)+1;
    }
}

int max(int v1, int v2)
{
    return v1>v2?v1:v2;
}

int hauteur_arbre(noeud *Ar)
{
    if(Ar==NULL)
    {
        return 0;
    }
    else
    {
        return max(hauteur_arbre(Ar->FD),hauteur_arbre(Ar->FG))+1;
    }
}
/*
int est_H_equilibre(noeud *Ar)
{
    fabs(hauteur_arbre(Ar->FD)-hauteur_arbre(Ar->))
}
*/

noeud* recherche_min(noeud* node) {
    while (node->FG != NULL) {
        node = node->FG;
    }
    return node;
}

noeud* supprime_noeud(noeud* Ar, int x) {
    if (Ar == NULL) {
        printf("La valeur n'existe pas dans l'arbre!\n");
        return Ar;
    }

    if (x < Ar->val) {
        Ar->FG = supprime_noeud(Ar->FG, x);
    } else if (x > Ar->val) {
        Ar->FD = supprime_noeud(Ar->FD, x);
    } else {
        // Node with only one child or no child
        if (Ar->FG == NULL) {
            noeud* temp = Ar->FD;
            free(Ar);
            return temp;
        } else if (Ar->FD == NULL) {
            noeud* temp = Ar->FG;
            free(Ar);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        noeud* temp = recherche_min(Ar->FD);

        // Copy the inorder successor's content to this node
        Ar->val = temp->val;

        // Delete the inorder successor
        Ar->FD = supprime_noeud(Ar->FD, temp->val);
    }

    return Ar;
}
