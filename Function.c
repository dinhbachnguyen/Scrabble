

#include "Function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NOMBRE_MAX 102
#define NOMBRE_COLONNE 64
#define NOMBRE_LIGNE 31



char* pioche(char* chaine){
    for (int i = 0; i < strlen(chaine); i++) {
        int random = rand() % strlen(chaine);
        char temp = chaine[i];
        chaine[i] = chaine[random];
        chaine[random] = temp;
    }
    return chaine;
}

char* creationMain(char* chaine){
    int i = 0;
    char* mainJoueur = (char*) malloc(7 * sizeof(char));
    for (i = 0; i < 7; i++) {
        mainJoueur[i] = chaine[i];
    }
    mainJoueur[7] = '\0';
    for (i = 7; i < NOMBRE_MAX + 1; i++) {
        chaine[i-7] = chaine[i];
    }
    return mainJoueur;
}


char** allouerPlateau() {
    char** plateau;
    int i = 0;
    plateau = (char**) calloc(NOMBRE_LIGNE, sizeof(char*));
    for(i = 0; i < NOMBRE_LIGNE; i++) {
        plateau[i] = (char*) calloc(NOMBRE_COLONNE, sizeof(char));
    }
    return plateau;
}


char** creationPlateau(char** plateau) {
    int i = 0, j = 0;
    int n = 0, m = 0;
    while (i<=NOMBRE_LIGNE-1 && j<NOMBRE_COLONNE){
        if (i%2 ==0) {
            for (n=0; n<NOMBRE_COLONNE-4; n++){
                plateau[i][n] = '-';
            }
            i+=1;
        }
        else {
            for (m=0; m<NOMBRE_COLONNE; m++){
                if (m%4 == 0) {
                    plateau[i][m] = '|';

                }
                else {

                    if ((i==1 && m==2) || (i==29 && m==2) || (i==1 && m==58)  || (i==29 && m==58) || (i==15 && m==2) || (i==15 && m==58) ||
                        (i==1 && m==30) || (i==29 && m==30)) {

                        // Mot compte triple

                        plateau[i][m] = '!';

                    }
                    else if ((i==3 && m==6) || (i==5 && m==10) || (i==7 && m==14)  || (i==9 && m==18) ||
                             (i==3 && m==54) || (i==5 && m==50) || (i==7 && m==46)  || (i==9 && m==42) ||
                             (i==27 && m==54) || (i==25 && m==50) || (i==23 && m==46)  || (i==21 && m==42) ||
                             (i==27 && m==6) || (i==25 && m==10) || (i==23 && m==14)  || (i==21 && m==18)) {

                        // Mot compte double

                        plateau[i][m] = '@';

                    }
                    else if ((i==7 && m==2) || (i==1 && m==14) || (i==1 && m==46) || (i==7 && m==58) ||
                             (i==5 && m==26) || (i==13 && m==26) || (i==7 && m==30) || (i==23 && m==30) ||
                             (i==5 && m==34) || (i==13 && m==34) || (i==17 && m==26) || (i==25 && m==26) ||
                             (i==17 && m==34) || (i==25 && m==34) || (i==23 && m==2) || (i==29 && m==14) ||
                             (i==29 && m==46) || (i==23 && m==58) ||
                             (i==15 && m==46) || (i==13 && m==50) || (i==17 && m==50) ||
                             (i==15 && m==14) || (i==13 && m==10) || (i==17 && m==10)) {

                        // Lettre compte double

                        plateau[i][m] = '&';
                    }
                    else if ((i==11 && m==6) || (i==19 && m==6) || (i==11 && m==22) || (i==19 && m==22) ||
                             (i==11 && m==38) || (i==19 && m==38) || (i==11 && m==54) || (i==19 && m==54) ||
                             (i==3 && m==22) || (i==27 && m==22) || (i==3 && m==38) || (i==27 && m==38)) {

                        // Lettre compte triple

                        plateau[i][m] = '%';

                    }
                    else if (i==15 && m==30) {

                        // Milieu du plateau

                        plateau[i][m] = '#';

                    }
                    else if (i==1 && m==62){
                        plateau[i][m]='1';
                    }
                    else if (i==3 && m==62){
                        plateau[i][m]='2';
                    }
                    else if (i==5 && m==62){
                        plateau[i][m]='3';
                    }
                    else if (i==7 && m==62){
                        plateau[i][m]='4';
                    }
                    else if (i==9 && m==62){
                        plateau[i][m]='5';
                    }
                    else if (i==11 && m==62){
                        plateau[i][m]='6';
                    }
                    else if (i==13 && m==62){
                        plateau[i][m]='7';
                    }
                    else if (i==15 && m==62){
                        plateau[i][m]='8';
                    }
                    else if (i==17 && m==62){
                        plateau[i][m]='9';
                    }
                    else if (i==19 && m==62){
                        plateau[i][m]='1';
                    }
                    else if (i==19 && m==63){
                        plateau[i][m]='0';
                    }
                    else if (i==21 && m==62){
                        plateau[i][m]='1';
                    }
                    else if (i==21 && m==63){
                        plateau[i][m]='1';
                    }
                    else if (i==23 && m==62){
                        plateau[i][m]='1';
                    }
                    else if (i==23 && m==63){
                        plateau[i][m]='2';
                    }
                    else if (i==25 && m==62){
                        plateau[i][m]='1';
                    }
                    else if (i==25 && m==63){
                        plateau[i][m]='3';
                    }
                    else if (i==27 && m==62){
                        plateau[i][m]='1';
                    }
                    else if (i==27 && m==63){
                        plateau[i][m]='4';
                    }
                    else if (i==29 && m==62){
                        plateau[i][m]='1';
                    }
                    else if (i==29 && m==63){
                        plateau[i][m]='5';
                    }
                    else {
                        plateau[i][m] = ' ';
                    }
                }
            }
            i+=1;
        }
    }
    return plateau;
}


void affichagePlateau(char** plateau) {
    for(int i=0; i<NOMBRE_LIGNE; i++) {
        printf("\n");
        for (int j=0; j<NOMBRE_COLONNE; j++) {
            printf("%c", plateau[i][j]);
        }
    }
}

char* demandeMot() {
    char* mot = (char*) malloc(25 * sizeof(char));
    printf("Veuillez saisir votre mot (mettre ? a la place de la lettre voulu si vous avez un Joker)\n");
    scanf(" %s", mot);
    return mot;
}


int colonneMot() {
    char colonne = 'a';
    int codeColonne = 0;
    printf("En quelle colonne voulez vous placer votre mot ? (exemple : G) \t\n");
    scanf(" %c", &colonne);
    codeColonne = colonne - 64;
    if (codeColonne>15) {
        return 404;
    }
    else {
        return codeColonne;
    }
}

int ligneMot() {
    int ligne = 0;
    printf("En quelle ligne voulez vous placer votre mot ? (exemple : 12) \t\n");
    scanf(" %d", &ligne);
    if (ligne > 15) {
        return 404;
    }
    else {
        return ligne;
    }
}

int sensMot() {
    int sens = 0;
    printf("Dans quel sens voulez vous placer votre mot ? (1 pour Horizontal et 0 pour Vertical) \t\n");
    scanf(" %d", &sens);
    if (sens == 0  || sens == 1 ) {
        return sens;
    }
    else {
        return 404;
    }
}

void placementMot(int codeColonne, int ligne, int sens, char* mot, char** plateau) {
    int i = 0;
    if (sens == 1) {
        for (i=0; i < strlen(mot)+1; i++) {
            plateau[(ligne*2)-1][(codeColonne*4)-2] = mot[i];
            codeColonne = codeColonne + 1;
        }
    }
    else if (sens == 0) {
        for (i=0; i < strlen(mot)+1; i++) {
            plateau[(ligne*2)-1][(codeColonne*4)-2] = mot[i];
            ligne = ligne + 1;
        }
    }
    else {
        plateau[(ligne*2)-1][(codeColonne*4)-2] = ' ';
    }
}

int verifierMot(char* mainJoueur, char* mot, int codeColonne, int ligne, int sens, char** plateau ) {
    int i = 0;
    for (i=0; i<strlen(mot); i++) {
        if (mot[i] == mainJoueur[0]) {
            continue;
        }
        else if (mot[i] == mainJoueur[1]) {
            continue;
        }
        else if (mot[i] == mainJoueur[2]) {
            continue;
        }
        else if (mot[i] == mainJoueur[3]) {
            continue;
        }
        else if (mot[i] == mainJoueur[4]) {
            continue;
        }
        else if (mot[i] == mainJoueur[5]) {
            continue;
        }
        else if (mot[i] == mainJoueur[6]) {
            continue;
        }
        else if (mot[i] == plateau[(ligne*2)-1][(codeColonne*4)-2]) {
            continue;
        }
        else {
            return 0;
        }
    }
    return 1;
}



int score(char** plateau, char* mot, int codeColonne, int ligne, int sens){
    int scoreTotal = 0;
    for (int i = 0; i < strlen(mot); i++) {
        if (mot[i] == 'A') {
            scoreTotal = scoreTotal + 1;
        }
        else if (mot[i] == 'B') {
            scoreTotal = scoreTotal + 3;
        }
        else if (mot[i] == 'C') {
            scoreTotal = scoreTotal + 3;
        }
        else if (mot[i] == 'D') {
            scoreTotal = scoreTotal + 2;
        }
        else if (mot[i] == 'E') {
            scoreTotal = scoreTotal + 1;
        }
        else if (mot[i] == 'F') {
            scoreTotal = scoreTotal + 4;
        }
        else if (mot[i] == 'G') {
            scoreTotal = scoreTotal + 2;
        }
        else if (mot[i] == 'H') {
            scoreTotal = scoreTotal + 4;
        }
        else if (mot[i] == 'I') {
            scoreTotal = scoreTotal + 1;
        }
        else if (mot[i] == 'J') {
            scoreTotal = scoreTotal + 8;
        }
        else if (mot[i] == 'K') {
            scoreTotal = scoreTotal + 10;
        }
        else if (mot[i] == 'L') {
            scoreTotal = scoreTotal + 1;
        }
        else if (mot[i] == 'M') {
            scoreTotal = scoreTotal + 2;
        }
        else if (mot[i] == 'N') {
            scoreTotal = scoreTotal + 1;
        }
        else if (mot[i] == 'O') {
            scoreTotal = scoreTotal + 1;
        }
        else if (mot[i] == 'P') {
            scoreTotal = scoreTotal + 3;
        }
        else if (mot[i] == 'Q') {
            scoreTotal = scoreTotal + 8;
        }
        else if (mot[i] == 'R') {
            scoreTotal = scoreTotal + 1;
        }
        else if (mot[i] == 'S') {
            scoreTotal = scoreTotal + 1;
        }
        else if (mot[i] == 'T') {
            scoreTotal = scoreTotal + 1;
        }
        else if (mot[i] == 'U') {
            scoreTotal = scoreTotal + 1;
        }
        else if (mot[i] == 'V') {
            scoreTotal = scoreTotal + 4;
        }
        else if (mot[i] == 'W') {
            scoreTotal = scoreTotal + 10;
        }
        else if (mot[i] == 'X') {
            scoreTotal = scoreTotal + 10;
        }
        else if (mot[i] == 'Y') {
            scoreTotal = scoreTotal + 10;
        }
        else if (mot[i] == 'Z') {
            scoreTotal = scoreTotal + 10;
        }
        else if (mot[i] == '?') {
            scoreTotal = scoreTotal + 0;
        }
    }
    return scoreTotal;
}

char* demandeJeton(char* chaine, char* mainJoueur, char* mot) {
    int nbJeton = 0; int i = 0;
    char* JetonPioches = (char*) calloc(7, sizeof(char));
    do {
        printf("Combien de jeton voulez-vous piocher ? \n ");
        scanf(" %d", &nbJeton);
        if ((strlen(mainJoueur) - strlen(mot)) + nbJeton < 8) {
            for (i = 0; i < nbJeton; i++) {
                JetonPioches[i] = chaine[i];
            }
            JetonPioches[nbJeton] = '\0';
        }
        else {
            for (i = nbJeton; i < NOMBRE_MAX + 1; i++) {
                chaine[i-nbJeton] = chaine[i];
            }
            printf("Vous demandez trop de jeton, reessayer \n");
        }
    }
    while ((strlen(mainJoueur) - strlen(mot)) + nbJeton > 7);
    return JetonPioches;
}

char* suppressionchaine(char* chaine,char* JetonPioches){
    int i = 0;
    for (i = 0; i < strlen(chaine); i++) {
        chaine[i] = chaine[i+strlen(JetonPioches)];
    }
    return chaine;
}

char* reunionJetons(char* JetonPioches, char* mainJoueur, char* mot) {

    for (int i = 0; i < 7; i++) {
        if (mainJoueur[0] == mot[i]) {
            mainJoueur[0] = JetonPioches[i];
        } else if (mainJoueur[1] == mot[i]) {
            mainJoueur[1] = JetonPioches[i];
        } else if (mainJoueur[2] == mot[i]) {
            mainJoueur[2] = JetonPioches[i];
        } else if (mainJoueur[3] == mot[i]) {
            mainJoueur[3] = JetonPioches[i];
        } else if (mainJoueur[4] == mot[i]) {
            mainJoueur[4] = JetonPioches[i];
        } else if (mainJoueur[5] == mot[i]) {
            mainJoueur[5] = JetonPioches[i];
        } else if (mainJoueur[6] == mot[i]) {
            mainJoueur[6] = JetonPioches[i];
        } else if (mainJoueur[7] == mot[i]) {
            mainJoueur[7] = JetonPioches[i];
        }
    }
    return mainJoueur;
}