#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const MAX = 100, MIN = 10;
int nbMystere = 0, nbEntre = 0, compteur = 0;
int continuer = 1;
char rep = ' ';
int mode = -1;

void AfficherMode(){
    printf("*****MENU******\n");
    printf("Choisissez votre mode : \n");
    printf("1. Mode 1 joueur\n");
    printf("2. Mode 2 joueurs\n");
}
void DemandeNombre(){
       do {
            printf("\nQuel est le nombre : ");
            scanf("%d", &nbEntre);
            compteur++;

            if(nbEntre < nbMystere)
                printf("Ce nombre est inferieur !");
            else if(nbEntre > nbMystere)
                printf("Ce nombre est superieur !");
            else {
                printf("Felicitations, vous avez trouve le nombre mystere en %d tour(s)!\n",compteur);
            }
       } while(nbEntre != nbMystere); // End do while       continuer = 0;

         compteur = 0;
         printf("Voulez-vous continuer ? O/N : ");
         scanf("%s",&rep);

         if(rep == 'O' || rep == 'o')
            continuer = 1;
         else
            continuer = 0;
}
void ModeUnJoueur(){
    do{
        // Génération du nombre aléatoire
        srand(time(NULL));
        nbMystere = (rand()%(MAX - MIN + 1)) + MIN;
        DemandeNombre();

    }  while(continuer);
}

void ModeDeuxJoueurs(){
    do{
        printf("Joueur N° 1, donnez le nombre a chercher : ");
        scanf("%d",&nbMystere);
        printf("Joueur N° 2 a vous maintenant!\n");
        DemandeNombre();
    }  while(continuer);
}
int main()
{
    AfficherMode();
    printf("\nQuel est votre choix : ");
    scanf("%d",&mode);

    switch(mode){
        case 1 :
            ModeUnJoueur();
        case 2:
            ModeDeuxJoueurs();
        default:
            break;
    }
    return 0;
}
