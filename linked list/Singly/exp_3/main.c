#include "FCT.h"


int main()
{
	int valeur;
	int Choix;
	char * NomFic="Fic.txt";
	Arbre * Racine;
	Arbre *Racine2 = NULL;
	Arbre * RepRecherche;
	Racine = NULL;
	Choix = Menu();
	while (Choix!=14)
	{
		if (Racine==NULL && Choix>1 && Choix <13)
		{
			printf("Vous devez d'abord saisir un arbre");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
			getch();
		}
		else
		{
			switch (Choix)
			{
				case 1 :	printf("Saisir un entier (0 pour finir la saisie) : ");
							scanf("%d",&valeur);
							while (valeur != 0)
							{
								ajout_val(&Racine, valeur);//Racine=CreerValeur(Racine,valeur);
								printf("Saisir un entier (0 pour finir la saisie) : ");
								scanf("%d",&valeur);
							}
							break;
				case 2 :	AfficherArbre(Racine);
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
							getch();
							break;
				case 3 :	AfficherArbreCroissant(Racine);
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
							getch();
							break;
				case 4 :	AfficherArbreDecroissant(Racine);
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
							getch();
							break;
				case 5 :	AfficherArbreCroissant(Racine);
							printf("\nTotal : %d",Somme(Racine));
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
							getch();
							break;
				case 6 :	AfficherArbreCroissant(Racine);
							printf("\nTotal : %d",CompteValeur(Racine));
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
							getch();
							break;
				case 7 :	printf("Saisir la valeur \205 rechercher : ");
							scanf("%d", &valeur);
							RepRecherche = RechercheValeur(Racine,valeur);
							if(RepRecherche!=NULL)
                            {
                                if (RepRecherche->Valeur==valeur)
                                {
                                    printf("%d", RepRecherche->Valeur);
                                }
                                else
                                {
                                    printf("Impossible de trouver la valeur recherch\202e");
                                }
                            }
                            else
                                printf("Impossible de trouver la valeur recherch\202e");
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
							getch();
							break;
				case 8 :	printf("Saisir la valeur du Valeur \205 supprimer : \n");
							scanf("%d",&valeur);
							SuppValeur2(&Racine,valeur);//Racine=SuppValeur(Racine,valeur);
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
							getch();
							break;
				case 9 :	system("del Fic.txt");
							system("cls");
							EnregArbre(Racine,NomFic);
							printf("Arbre enregistr\202\n");
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
							getch();
							break;
				case 10 :	ChargerArbre2(&Racine,NomFic);//Racine=ChargerArbre(Racine,NomFic);
							printf("Arbre charg\202\n");
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
							getch();
							break;
                case 11 :   if(estFiliforme(Racine) == 1)
                            {
                                printf("l'arbre est filforme !\n");
                            }
                            else
                            {
                                printf("l'arbre n'est pas filiforme !\n");
                            }
                            break;
                case 12:    if (est_peigne(Racine)||est_peigne2(Racine))
                                printf("L'arbre est un peigne .\n");
                            else
                                printf("L'arbre n'est pas un peigne .\n");

                            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAppuyez sur une touche pour retourner au menu principal");
                            getch();
                            break;
                case 13 :	printf("Saisir un entier (0 pour finir la saisie) : ");
                            scanf("%d", &valeur);
                            while (valeur != 0) {
                                ajout_val(&Racine2, valeur);
                                printf("Saisir un entier (0 pour finir la saisie) : ");
                                scanf("%d", &valeur);
                            }
                            if (identique(Racine, Racine2) == 1) {
                                printf("Les arbres sont egaux.\n");
                            } else {
                                printf("Les arbres ne sont pas egaux.\n");
                            }
                            break;
			}
		}
		system("pause");
        system("cls");
		Choix=Menu();
	}
	 return 0;
}
