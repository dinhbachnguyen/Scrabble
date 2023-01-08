#include <stdio.h>
#include "Function.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NOMBRE_MAX 102
#define NOMBRE_COLONNE 61
#define NOMBRE_LIGNE 31




int main() {

    srand(time(NULL));


    // Initialisation de la partie
// Début de partie


    printf("\n");
    printf("Bonjour et bienvenue sur le jeu du Scrabble \n\n");

    int nombreJoueurs=0;
    printf("Veuillez rentrer le nombre de joueur pour cette partie (de 1 a 4 joueurs) :\n");
    scanf(" %d",&nombreJoueurs);

    Joueur* tabJoueur= (Joueur*) malloc(4*sizeof(Joueur));

    for (int i = 0; i < nombreJoueurs; i++) {

        printf("Veuillez rentrer le pseudo du joueur numero %d :\n", i + 1);
        fflush(stdin);
        fgets(tabJoueur[i].pseudo, 100, stdin);
    }


    // Création de la Pioche
    char chaine[104] = "AAAAAAAAABBCCDDDEEEEEEEEEEEEEEEFFGGHHIIIIIIIIJKLLLLLMMMNNNNNNOOOOOOPPQRRRRRRSSSSSSTTTTTTUUUUUUVVWXYZ??";

    // Mélange de la Pioche
    char *laPioche = pioche(chaine);
    printf("\n\n\n\n");



    for (int i = 0; i < nombreJoueurs; i++) {
        strcpy(tabJoueur[i].main, creationMain(laPioche));
    }



// Initialisation du plateau de jeu
    char **plateau = allouerPlateau();
    creationPlateau(plateau);

    // Déroulement de la partie
    char *mot;
    int colonne = 0;
    int ligne = 0;
    int sens = 0;
    int verification = 2;


    while (strlen(laPioche) > 2) {
        for ( int i = 0; i<nombreJoueurs; i++) {


            // Affichage du plateau de jeu
            printf("  A   B   C   D   E   F   G   H   I   J   K   L   M   N   O");
            affichagePlateau(plateau);
            printf("\n\n\n");

            printf("C'est le tour de %s ", tabJoueur[i].pseudo);
            printf("\n\n");
            printf("La main de %s  \n ", tabJoueur[i].pseudo);
            printf("%s", tabJoueur[i].main);
            printf("\n\n\n");

            // Demande Mot, la position et le sens

            colonne = colonneMot();
            if (colonne != 404) {
                ligne = ligneMot();
                if (ligne != 404) {
                    sens = sensMot();
                    if (sens != 404) {
                        mot = demandeMot();
                        verification = verifierMot(tabJoueur[i].main, mot, colonne, ligne, sens, plateau);
                        if (verification == 1){
                            // Placement du mot dans le plateau
                            placementMot(colonne, ligne, sens, mot, plateau);
                            // Calcul du score
                            tabJoueur[i].score = score(plateau, mot, colonne, ligne, sens);
                            printf("Vous venez de marquer %d point(s) \n\n", tabJoueur[i].score);
                            // Demande de jeton à la pioche
                            char *Jetonpiochee = demandeJeton(laPioche, tabJoueur[i].main, mot);
                            strcpy(tabJoueur[i].main, reunionJetons(Jetonpiochee, tabJoueur[i].main, mot));
                            laPioche = suppressionchaine(laPioche, Jetonpiochee);
                            printf("Votre nouvelle main est : %s \n", tabJoueur[i].main);
                            printf("\n");
                        }
                        else {
                            printf("ERREUR, Tour passe\n");
                        }
                    }
                    else {
                        printf("ERREUR, Tour passe \n");
                    }
                }
                else {
                    printf("ERREUR, Tour passe \n");
                }
            }
            else {
                printf("ERREUR, Tour passe \n");
            }
        }
    }
    int max = 0;
    int cmp = 0;
    for (int i = 0; i < nombreJoueurs - 1; i++) {
        if (tabJoueur[i].score > tabJoueur[i+1].score) {
            max = tabJoueur[i].score;
            cmp = i;
        }
        else {
            max = tabJoueur[i+1].score;
        }
    }
    printf("Bravo %s , tu as gagne avec %d points !!!", tabJoueur[cmp].pseudo, max);

    free(tabJoueur);
    free(chaine);
    free(laPioche);
    free(plateau);
    free(mot);

    return 0;
}
