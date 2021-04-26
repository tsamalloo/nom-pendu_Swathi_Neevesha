/*

Jeu du pendu

Fonctions principales de gestion du jeu

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

#include "../include/pendu.h"

int gagne(int lettreTrouvee[], long tailleMot);
int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[]);
char lireCaractere();
int niveau;
char hint;
int h;

int main(int argc, char* argv[])
{
    char lettre = 0;
    char motSecret[100]= {0};
    int *lettreTrouvee = NULL;
    long coupsRestants = 8;
    long i = 0;
    long tailleMot = 0;

    printf("Welcome to the Hangman's Game!\n\n");
    printf("Choose the level of difficulty you want by entering one of the numbers below: \n");
    printf("1: Easy \n");
    printf("2: Medium \n");
    printf("3: Difficult \n");
    printf("Your choice: \n");
    scanf("%d",&niveau);
	
    if (!piocherMot(motSecret))
	exit(0);

    tailleMot = strlen(motSecret);
  
    lettreTrouvee = malloc(tailleMot * sizeof(int));
    if (lettreTrouvee == NULL)
	exit(0);

    for (i = 0; i < tailleMot; i++)
	lettreTrouvee[i] = 0;

    printf("\nDo you want a hint? \nChoose a number below: \n");
    printf("\n1: Yes");
    printf("\n2: No \n");
    printf("Your choice: ");
    scanf("%d",&h);
    if (h==1){
    srand(time(NULL));
    hint = hint+motSecret[rand()% tailleMot];
    printf("Here is a hint: %c",hint);
    goto nxt;}

    else if (h==2){
    goto nxt;}
	
    nxt:while (coupsRestants > 0 && !gagne(lettreTrouvee, tailleMot))
        {
	printf("\n\nYou still have %ld moves to play!", coupsRestants);
	printf("\nWhat is the secret word? ");

        for (i = 0; i < tailleMot; i++)
        {
	    if (lettreTrouvee[i]){
	        printf("%c",motSecret[i]);
				 }
	    else{
	        printf("_");
		}
        }

        printf("\nPlease guess a letter: ");
        lettre = lireCaractere();

        if (!rechercheLettre(lettre, motSecret, lettreTrouvee))
        {
	    coupsRestants--;
	    printf("This letter is unfortunately not in the word! Sorry!\n");
	    if (coupsRestants==7)
	    {
		printf("		---------- \n");
		printf("		|	 | \n");
		printf("		| \n");
		printf("		| \n");
		printf("		| \n");
		printf("		| \n");
	    }

	    if (coupsRestants==6)
	    {
		printf("		---------- \n");
		printf("		|	 | \n");
		printf("		|        0  \n");
		printf("		| \n");
		printf("		| \n");
		printf("		| \n");
	    }

	    if (coupsRestants==5)
	    {
		printf("		---------- \n");
		printf("		|	 | \n");
		printf("		|        0 \n");
		printf("		|        | \n");
		printf("		| \n");
		printf("		| \n");
	    }

	    if (coupsRestants==4)
	    {
		printf("		---------- \n");
		printf("		|	 | \n");
		printf("		|        0 \n");
		printf("		|      --| \n");
		printf("		| \n");
		printf("		| \n");
	    }

	    if (coupsRestants==3)
	    {
		printf("		---------- \n");
		printf("		|	 | \n");
		printf("		|        0 \n");
		printf("		|      --|-- \n");
		printf("		| \n");
		printf("		| \n");
	    }

	    if (coupsRestants==2)
	    {
		printf("		---------- \n");
		printf("		|	 | \n");
		printf("		|        0 \n");
		printf("		|      --|-- \n");
		printf("		|        | \n");
		printf("		| \n");
	    }

	    if (coupsRestants==1)
	    {
		printf("		---------- \n");
		printf("		|	 | \n");
		printf("		|        0 \n");
		printf("		|      --|-- \n");
		printf("		|        | \n");
		printf("		|       | \n");
	    }

	    if (coupsRestants==0)
	    {
		printf("		---------- \n");
		printf("		|	 | \n");
		printf("		|        0 \n");
		printf("		|      --|-- \n");
		printf("		|        | \n");
		printf("		|       | | \n");
	    }
        }
    }

    if (gagne(lettreTrouvee, tailleMot))
	printf("\n\nGood job! The secret word was indeed %s!\n", motSecret);
    else
	printf("\n\nSorry,you ran out of tries! \nThe word was %s. \nMaybe next time! \n", motSecret);

    free(lettreTrouvee);

    return 0;
}

char lireCaractere()
{
    char caractere = 0;

    caractere = getchar();
    caractere = toupper(caractere);

    while (getchar() != '\n');
    return caractere;
}

int gagne(int lettreTrouvee[], long tailleMot)
{
    long i = 0;
    int joueurGagne = 1;
    for (i = 0; i < tailleMot; i++)
    {
	if (lettreTrouvee[i] == 0)
	    joueurGagne = 0;
    }

    return joueurGagne;
}

int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[])
{
    long i = 0;
    int bonneLettre = 0;

    for (i = 0; motSecret[i] != '\0'; i++)
    {
	if (lettre == motSecret[i])
	{
	    bonneLettre = 1;
	    lettreTrouvee[i] = 1;
	}
    }

    return bonneLettre;
}

