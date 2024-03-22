#include "FCT.h"


void ajout_val(Arbre **Ar, int x)
{
    Arbre *nouv=(Arbre *)malloc(sizeof(Arbre));
    if(nouv==NULL)
    {
        printf("Erreur d'allocation de memoire\n");
        exit(4);
    }
    nouv->Valeur=x;
    nouv->FG=NULL;
    nouv->FD=NULL;
    ajout_noeud(Ar,nouv);

}

void ajout_noeud(Arbre **Ar, Arbre *nouv)
{
    if(*Ar==NULL)
    {
        *Ar=nouv;
    }
    else
    {
        if(nouv->Valeur==(*Ar)->Valeur)
        {
            printf("la valeur deja existante!\n");
            return;
        }
        else
        {
            if(nouv->Valeur<(*Ar)->Valeur)
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
void AfficherArbreCroissant(Arbre * Racine)
{
	if (Racine!=NULL)
	{
		AfficherArbreCroissant(Racine->FG);
		printf("%d ",Racine->Valeur);
		AfficherArbreCroissant(Racine->FD);
	}
}
void AfficherArbreDecroissant(Arbre * Racine)
{
	if (Racine!=NULL)
	{
		AfficherArbreDecroissant(Racine->FD);
		printf("%d ",Racine->Valeur);
		AfficherArbreDecroissant(Racine->FG);
	}
}

void AfficherArbre(Arbre * Racine)
{
	if (Racine!=NULL)
	{
		printf("%d ",Racine->Valeur);
		if (Racine->FD!=NULL || Racine->FG!=NULL)
		{
			AfficherArbre(Racine->FG);
			AfficherArbre(Racine->FD);
		}
	}
}
Arbre * CreerValeur(Arbre * Racine,int valeur)
{
	if (Racine!=NULL)
	{
		if (Racine->Valeur>valeur)
		{
			Racine->FG=CreerValeur(Racine->FG,valeur);
		}
		else
		{
			Racine->FD=CreerValeur(Racine->FD,valeur);
		}
	}
	else
	{
		Racine=(Arbre *)malloc(sizeof(Arbre));
		Racine->Valeur=valeur;
		Racine->FD=NULL;
		Racine->FG=NULL;
	}
return Racine;
}

void CreerValeur3(Arbre **Racine, int valeur) {
    if (*Racine != NULL) {
        if ((*Racine)->Valeur > valeur) {
            CreerValeur3(&(*Racine)->FG, valeur);
        } else {
            CreerValeur3(&(*Racine)->FD, valeur);
        }
    } else {
        *Racine = (Arbre *)malloc(sizeof(Arbre));
        if (*Racine == NULL) {
            printf("Erreur d'allocation de memoire\n");
            exit(4);
        }

        (*Racine)->Valeur = valeur;
        (*Racine)->FD = NULL;
        (*Racine)->FG = NULL;
    }
}


void CreerValeur2(Arbre **pRacine, int valeur)
{
    if (*pRacine != NULL) {
        if ((*pRacine)->Valeur > valeur) {
            CreerValeur(&(*pRacine)->FG, valeur);
        } else {
            CreerValeur(&(*pRacine)->FD, valeur);
        }
    } else {
        *pRacine = (Arbre *)malloc(sizeof(Arbre));
        if (*pRacine == NULL) {
            printf("Erreur d'allocation de memoire\n");
            exit(4);
        }

        (*pRacine)->Valeur = valeur;
        (*pRacine)->FD = NULL;
        (*pRacine)->FG = NULL;
    }
}

void EnregArbre(Arbre * Racine,char * NomFic)
{
	int nb;
	FILE * fic;
	fic=fopen(NomFic,"at");
	if (Racine!=NULL)
	{
		nb=Racine->Valeur;
		fwrite(&nb,sizeof(int),1,fic);
		fclose(fic);
		if (Racine->FD!=NULL || Racine->FG!=NULL)
		{
			EnregArbre(Racine->FG,NomFic);
			EnregArbre(Racine->FD,NomFic);
		}
	}
}

void ChargerArbre2(Arbre ** Racine,char * NomFic)
{
	int nb;
	FILE * fic;
	fic=fopen(NomFic,"rt");
	fread(&nb,sizeof(int),1,fic);
	while (!feof(fic))
	{
		*Racine = CreerValeur(*Racine,nb);
		fread(&nb,sizeof(int),1,fic);
	}
	fclose(fic);
}

Arbre * ChargerArbre(Arbre * Racine,char * NomFic)
{
	int nb;
	FILE * fic;
	fic=fopen(NomFic,"rt");
	fread(&nb,sizeof(int),1,fic);
	while (!feof(fic))
	{
		Racine = CreerValeur(Racine,nb);
		fread(&nb,sizeof(int),1,fic);
	}
	fclose(fic);
	return Racine;
}

int Somme(Arbre * Racine)
{
	int total=0;
	if (Racine!=NULL)
	{
		total=Somme(Racine->FG);
		total+=Racine->Valeur;
		total+=Somme(Racine->FD);
	}
	return total;
}

int CompteValeur(Arbre * Racine)
{
	int total=0;
	if (Racine!=NULL)
	{
		total=CompteValeur(Racine->FG);
		total++;
		total+=CompteValeur(Racine->FD);
	}
	return total;
}

Arbre * RechercheValeur(Arbre * Racine,  int valeur)
{
	if (Racine!=NULL)
	{
		if (Racine->Valeur>valeur)
		{
			Racine=RechercheValeur(Racine->FG,valeur);
		}
		else
		{
			if (Racine->Valeur<valeur)
			{
				Racine=RechercheValeur(Racine->FD,valeur);
			}
		}
		return Racine;
	}
	return Racine;
}


Arbre * SuppValeur(Arbre * Racine, int valeur)
{
	Arbre * ValeurASupprimer;
	if (Racine->Valeur==valeur) // on a trouv้ l'้l้ment เ supprimer
	{
		ValeurASupprimer=Racine;
		if (ValeurASupprimer->FG==NULL) //si ya pa de FG, on retourne FD
			return ValeurASupprimer->FD;
		else
		{
			Racine=ValeurASupprimer->FG; //sinon on recherche dans FG l'endroit pour ins้rer le FD
				while (Racine->FD!=NULL)
				{
					Racine=Racine->FD;
				}
				Racine->FD=ValeurASupprimer->FD;
			return ValeurASupprimer->FG;
		}
		free(ValeurASupprimer);
	}
	else
	{
		if (Racine->Valeur>valeur)
		{
			Racine->FG=SuppValeur(Racine->FG,valeur);
		}
		else
		{
			Racine->FD=SuppValeur(Racine->FD,valeur);
		}
	}
	return Racine;
}

void SuppValeur2(Arbre **Racine, int valeur) {
    if (*Racine == NULL) {
        return;
    }

    if ((*Racine)->Valeur == valeur) {
        Arbre *ValeurASupprimer = *Racine;

        if (ValeurASupprimer->FG == NULL) {
            *Racine = ValeurASupprimer->FD;
        } else {
            *Racine = ValeurASupprimer->FG;

            Arbre *temp = *Racine;
            while (temp->FD != NULL) {
                temp = temp->FD;
            }
            temp->FD = ValeurASupprimer->FD;
        }

        free(ValeurASupprimer);
    } else {
        if ((*Racine)->Valeur > valeur) {
            SuppValeur2(&(*Racine)->FG, valeur);
        } else {
            SuppValeur2(&(*Racine)->FD, valeur);
        }
    }
}


void SuppValeur3(Arbre **pRacine, int valeur) {
    if (*pRacine == NULL) {
        return;
    }

    if (valeur < (*pRacine)->Valeur) {
        SuppValeur(&((*pRacine)->FG), valeur);
    } else if (valeur > (*pRacine)->Valeur) {
        SuppValeur(&((*pRacine)->FD), valeur);
    } else {
        Arbre *ValeurASupprimer = *pRacine;

        if (ValeurASupprimer->FG == NULL) {
            *pRacine = ValeurASupprimer->FD;
        } else {
            *pRacine = ValeurASupprimer->FG;

            Arbre *temp = ValeurASupprimer->FG;
            while (temp->FD != NULL) {
                temp = temp->FD;
            }
            temp->FD = ValeurASupprimer->FD;
        }

        free(ValeurASupprimer);
    }
}

int Menu()
{
	int Choix;
	do
	{
		system("cls"); //efface l'้cran
		printf("             ษออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
		printf("             บ                                                      บ\n");
		printf("             บ                    Menu Principal                    บ\n");
		printf("             บ                                                      บ\n");
		printf("             ศออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
		printf("\n                 1- Ajouter un Valeur(s)");
		printf("\n                 2- Afficher l'arbre");
		printf("\n                 3- Afficher l'arbre dans l'ordre croissant");
		printf("\n                 4- Afficher l'arbre dans l'ordre decroissant");
		printf("\n                 5- Somme des Valeurs");
		printf("\n                 6- Nombre de Valeurs");
		printf("\n                 7- Rechercher un Valeur");
		printf("\n                 8- Enlever un Valeur");
		printf("\n                 9- Enregister l'arbre dans un fichier");
		printf("\n                10- Charger l'arbre \205 partir d'un fichier");
		printf("\n                11- La filoformite");
		printf("\n                12- Peigne");
		printf("\n                13- creer et comparer les arbres");

		printf("\n                14- Quitter\n");

		printf("\n\n\n\n\n\n\nChoix :");
		scanf("%d",&Choix);
	} while (Choix <1 || Choix >14);
	system("cls");
	return Choix;
}


bool est_peigne(Arbre* Racine) {

    if (Racine == NULL || (Racine->FG == NULL && Racine->FD == NULL)) {
        return true;
    }


    if (Racine->FG != NULL && Racine->FD == NULL) {
        return est_peigne(Racine->FG);
    }


    if (Racine->FG == NULL && Racine->FD != NULL) {
        return false;
    }


    if (Racine->FG != NULL && Racine->FD != NULL) {
        return est_peigne(Racine->FG) && est_peigne(Racine->FD);
    }
   return false;
}
bool est_peigne2(Arbre* Racine) {

    if (Racine == NULL || (Racine->FD == NULL && Racine->FG == NULL)) {
        return true;
    }


    if (Racine->FD != NULL && Racine->FG == NULL) {
        return est_peigne2(Racine->FD);
    }


    if (Racine->FD== NULL && Racine->FG != NULL) {
        return false;
    }


    if (Racine->FD != NULL && Racine->FG != NULL) {
        return est_peigne2(Racine->FD) && est_peigne2(Racine->FG);
    }
   return false;
}

int estFiliforme(Arbre *Racine) {
    if (Racine == NULL) {
        return 1;
    }

    while (Racine->FG != NULL || Racine->FD != NULL) {
        if (Racine->FG != NULL && Racine->FD != NULL) {
            return 0;
        }
        if (Racine->FG != NULL) {
            Racine = Racine->FG;
        } else {
            Racine = Racine->FD;
        }
    }
    return true;
}

int identique(Arbre* Racine1, Arbre* Racine2) {
    if (Racine1 == NULL && Racine2 == NULL) {
        return 1;
    }

    if (Racine1 == NULL || Racine2 == NULL) {
        return 0;
    }

    if (Racine1->Valeur != Racine2->Valeur) {
        return 0;
    }

    return identique(Racine1->FG, Racine2->FG) && identique(Racine1->FD, Racine2->FD);
}
