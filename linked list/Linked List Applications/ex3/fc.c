#include "hd.h"

void add_arbre(Arb **Ar, Arb *nouv)
{
    if(*Ar == NULL)
    {
        *Ar = nouv;
    }
    else
    {
        if(nouv->val == (*Ar)->val)
        {
            printf("la valeur deja existante!\n");
            return;
        }
        else
        {
            if(nouv->val < (*Ar)->val)
            {
                if((*Ar)->FG == NULL)
                    (*Ar)->FG = nouv;
                else
                    add_arbre(&(*Ar)->FG, nouv);
            }
            else
            {
                if((*Ar)->FD == NULL)
                    (*Ar)->FD = nouv;
                else
                    add_arbre(&(*Ar)->FD, nouv);
            }
        }
    }
}

void add_valeur(Arb **Ar, int x)
{
    Arb *nouv = (Arb *) malloc(sizeof(Arb));
    if(nouv == NULL)
    {
        printf("Erreur d'allocation de memoire\n");
        exit(4);
    }
    nouv->val = x;
    nouv->FD = NULL;
    nouv->FG = NULL;
    add_arbre(Ar, nouv);
}

void print_tree_prefixe(Arb *Ar)
{
    if(Ar != NULL)
    {
        printf("%d  ",Ar->val);
        print_tree_prefixe(Ar->FG);
        print_tree_prefixe(Ar->FD);
    }
}

void print_tree_infixe(Arb *Ar)
{
    if(Ar != NULL)
    {
        print_tree_infixe(Ar->FG);
        printf("%d  ",Ar->val);
        print_tree_infixe(Ar->FD);
    }
}

void print_tree_suffixe(Arb *Ar)
{
    if(Ar != NULL)
    {
        print_tree_suffixe(Ar->FG);
        print_tree_suffixe(Ar->FD);
        printf("%d  ",Ar->val);
    }
}

int somme(Arb *Ar)
{
    if(Ar == NULL)
    {
        return 0;
    }
    else
    {
        return somme(Ar->FD) + somme(Ar->FG) + Ar->val;
    }
}

int taille_tree(Arb *Ar)
{
    if(Ar == NULL)
    {
        return 0;
    }
    else
    {
        return taille_tree(Ar->FD) + taille_tree(Ar->FG) + 1;
    }
}

Arb* find_value(Arb *Ar, int x)
{
    if(Ar == NULL || Ar->val == x)
        return Ar;
    else
    {
        if(x > Ar->val)
            return find_value(Ar->FD, x);
        else
            return find_value(Ar->FG, x);
    }
}

void delete_val(Arb **Ar, int x)
{
    Arb *delval = NULL, *p = NULL;
    if (*Ar == NULL)
    {
        printf("the value dosent exist!.\n");
        return;
    }
    if((*Ar)->val == x)
    {
        delval = *Ar;
        if((*Ar)->FG == NULL)
        {
            *Ar = delval->FD;
        }
        else
        {
            *Ar = (*Ar)->FG;
            while((*Ar)->FD != NULL)
            {
                p = *Ar;
                *Ar = (*Ar)->FD;
            }
            if(p != NULL)
            {
                p->FD = NULL;
            }
            (*Ar)->FD = delval->FD;
            (*Ar)->FG = delval->FG;
        }
        free(delval);
    }
    else
    {
        if(x < (*Ar)->val)
        {
            delete_val(&(*Ar)->FG, x);
        }
        else
        {
            delete_val(&(*Ar)->FD, x);
        }
    }
}
Arb * SuppValeur(Arb * Racine, int valeur)
{
	Arb * ValeurASupprimer;
	if (Racine->val == valeur) // on a trouvé l'élément à supprimer
	{
		ValeurASupprimer = Racine;
		if (ValeurASupprimer->FG == NULL) //si ya pa de FG, on retourne FD
			return ValeurASupprimer->FD;
		else
		{
			Racine = ValeurASupprimer->FG; //sinon on recherche dans FG l'endroit pour insérer le FD
				while (Racine->FD != NULL)
				{
					Racine = Racine->FD;
				}
				Racine->FD = ValeurASupprimer->FD;
				Racine->FG = ValeurASupprimer->FG;
			return Racine;
		}
		free(ValeurASupprimer);
	}
	else
	{
		if (Racine->val > valeur)
		{
			Racine->FG = SuppValeur(Racine->FG,valeur);
		}
		else
		{
			Racine->FD = SuppValeur(Racine->FD,valeur);
		}
	}
	return Racine;
}

/* Given a binary search tree and a key, this function
   deletes the key and returns the new root */
Arb* deleteNode(Arb* root, int k)
{
    // Base case
    if (root == NULL)
        return root;

    // Recursive calls for ancestors of
    // node to be deleted
    if (root->val > k) {
        root->FG = deleteNode(root->FG, k);
        return root;
    } else if (root->val < k) {
        root->FD = deleteNode(root->FD, k);
        return root;
    }

    // We reach here when root is the node
    // to be deleted.

    // If one of the children is empty
    if (root->FG == NULL) {
        Arb* temp = root->FD;
        free(root);
        return temp;
    } else if (root->FD == NULL) {
        Arb* temp = root->FG;
        free(root);
        return temp;
    }

    // If both children exist
    else {
        Arb* succParent = root;

        // Find successor
        Arb* succ = root->FD;
        while (succ->FG != NULL) {
            succParent = succ;
            succ = succ->FG;
        }

        // Delete successor. Since the successor
        // is always the left child of its parent,
        // we can safely make the successor's right
        // child the left child of its parent.
        // If there is no successor, then assign
        // succ->FD to succParent->FD
        if (succParent != root)
            succParent->FG = succ->FD;
        else
            succParent->FD = succ->FD;

        // Copy Successor Data to root
        root->val = succ->val;

        // Delete Successor and return root
        free(succ);
        return root;
    }
}
