/*
Jeu du pendu

Ces fonctions piochent au hasard un mot dans un fichier dictionnaire pour le jeu du pendu
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

#include "../include/pendu.h"

int niveau;
int piocherMot(char *motPioche)
{
    FILE* pendu = NULL;
    int nombreMots = 0, numMotChoisi = 0, i = 0;
    int caractereLu = 0;
re:while(niveau){
if (niveau==1){
    pendu = fopen("../ressource/facile.txt","r");
goto next;
    }
else if (niveau==2){
    pendu = fopen("../ressource/moyen.txt","r");
goto next;
    }
else if (niveau==3){
    pendu = fopen("../ressource/difficile.txt","r");
goto next;
    }
else{
      printf("Choice does not exist! Please reinput choice: ");
      scanf("%d",&niveau);
      goto re;
    }
}

next:   if (pendu == NULL)
    {
        printf("\nCannot load file of words");
goto next2;
    }

next2:  do
    {
    caractereLu = fgetc(pendu);
    if (caractereLu == '\n')
        nombreMots++;
    } while (caractereLu != EOF);

    numMotChoisi = nombreAleatoire(nombreMots);

    rewind(pendu);
    while (numMotChoisi > 0)
    {
        caractereLu = fgetc(pendu);
        if (caractereLu == '\n')
            numMotChoisi--;
    }

    fgets(motPioche, 100, pendu);

    motPioche[strlen(motPioche) -1] = '\0';
    fclose(pendu);
    
    return 1;
}

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}

