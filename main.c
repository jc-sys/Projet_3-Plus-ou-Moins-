#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu ()
{
    int choix;
    printf("\n******MENU******\n");
    printf("1- JOUER\n");
    printf("2- REGLES DU JEU\n");
    printf("3- MEILLEUR SCORE\n");
    printf("0- QUITTER\n\n");
    scanf("%d", &choix);
    if(choix==1)
    {
    printf("COMMENCER LE JEU\n");
    jouer();
    }
    else if(choix==2)
    {
    printf("VOICI LE PRINCIPE DU JEU\n");
    regleJeu();
    }
    else if(choix==3)
    {
     printf("VOICI LE MELLEUIR SCORE\n");
    }
    else if(choix==0)
    {
    printf("MERCI! AU REVOIR\n");
    }

}
int jouer()
{
    int nombreMystere = 0, nombreEntre = 0,nbrjoueur1 = 0,nbrjoueur2 = 0;
    int MAX, MIN ;
    int contiparti=1;
    int mode;
    int niveau;
    int compteur;

    srand(time(NULL));// génère les nombres aléatoires
    do
    {
    printf("Choisissez votre niveau de difficulte\n");//Choix du niveau
    printf("1 pour entre 1 et 100\n");
    printf("2 pour entre 1 et 1000\n");
    printf("3 pour entre 1 et  10000\n");
    scanf("%d",&niveau);
    if(niveau==1)
    {
    MAX=100;
    MIN=1;
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
    }
    else if(niveau==2)
    {
	MAX=1000;
	MIN=1;
	nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
    }
    else
    {
	MAX=10000;
	MIN=1;
	nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
    }
    printf("1- Mode 1 joueur\n");//Choix du mode par le joueur
    printf("2- Mode 2 joueurs\n");
    printf("Choisissez un mode\n");
    scanf("%d",&mode);
    switch(mode)
    {
	case 1:
	compteur=0;
    do
    {
    // On demande le nombre
    printf("Quel est le nombre ? ");
    scanf("%d", &nombreEntre);
    // On compare le nombre entré avec le nombre mystère
    if (nombreMystere > nombreEntre)
    printf("C'est plus !\n\n");
    else if (nombreMystere < nombreEntre)
    printf("C'est moins !\n\n");
    else
    printf ("Bravo, vous avez trouve le nombre mystere\n");
    compteur++;
    printf("coup= %d\n",compteur);
    } while (nombreEntre != nombreMystere);
    break;
    case 2:
    compteur=0;
    do{
    printf("Joueur1 choisissez votre nombre\n");
    scanf("%d",&nbrjoueur1);
    if(nombreMystere < nbrjoueur1)
    {
    printf("C'est moins\n");
    }
    else if(nombreMystere> nbrjoueur1)
    {
    printf("C'est plus\n");
    }
    else
    {
    printf("Bravo joueur1, vous avez trouve le nombre mystere\n");
    compteur++;
    printf("coup= %d\n",compteur);
    break;
    }
    printf("Joueur2 choisissez votre nombre\n");
    scanf("%d",&nbrjoueur2);
    if(  nombreMystere < nbrjoueur2)
    {
    printf("C'est moins\n");
    }
    else if(nombreMystere > nbrjoueur2)
    {
    printf("C'est plus\n");
    }
    else
    {
    printf("Bravo joueur2, vous avez trouve le nombre mystere\n");
    compteur++;
    printf("coup= %d\n",compteur);
    break;
    }
    compteur++;
    printf("coup= %d\n",compteur);
    }while(nombreMystere != nbrjoueur1 && nombreMystere != nbrjoueur2);
    break;
    }
    printf("Tapez 1 continuer\n");
    scanf("%d",&contiparti);
    } while(contiparti==1);
    return nombreMystere;
}
void regleJeu()
{
    printf("Le but du jeu sera de faire deviner a l’utilisateur un nombre compris dans un intervalle\n");
    printf("correspondant au niveau de difficulte du jeu. Le jeu aura trois niveaux de difficulte:\n- Facile:   1 - 100\n- Moyen:    1 - 1000\n- Difficile:1 - 10000\n");
    printf("L'ordinateur tire au sort un nombre compris dans l’intervalle. L'ordinateur compare le nombre entre\npar le joueur avec le nombre « mystere » qu'il a tire au sort et vous dit si le nombre mystere est\n");
    printf("superieur ou inferieur a celui que vous avez entre. Dans ce cas, le joueur devra entrer un autre\nnombre jusqu’a ce qu’il trouve le nombre « mystere ».\n");
    printf("Le but du jeu, bien sur, est de trouver le nombre mystere en un minimum de coups.\n\n");
    printf("\nBONNE CHANCE\n");
    retourMenu();
}
void retourMenu()
{
    int a;
    printf("Taper:\n");
    printf("1- pour commencer le jeu\n");
    printf("2- pour retouner au MENU\n");
    scanf("%d",&a);
    if(a==1)
    {
    jouer();
    }
    else if(a==2)
    {
     menu();
    }
    else
    printf("Merci! Au revoir\n");
}
void score(int v)
{
FILE* fichier = NULL;
fichier = fopen("test.txt", "w");
if (fichier != NULL)
{
fprintf(fichier,"%d ",v);
printf("\n");
fclose(fichier);
}
}
int main ()
{
    printf("=========================PLUS OU MOINS==========================\n");
    menu();
    return 0;
}

