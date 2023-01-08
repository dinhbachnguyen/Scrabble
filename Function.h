

#ifndef UNTITLED_FUNCTION_H
#define UNTITLED_FUNCTION_H



typedef struct {
    char pseudo[100];
    char main[30];
    int score;
} Joueur;




char* pioche(char* chaine);


char* creationMain(char* chaine);


char** allouerPlateau();
char** creationPlateau(char** plateau);
void affichagePlateau(char** plateau);


int colonneMot();
int ligneMot();
int sensMot();
char* demandeMot();


int verifierMot(char* mainJoueur, char* mot, int codeColonne, int ligne, int sens, char** plateau);


void placementMot(int codeColonne, int ligne, int sens, char* mot, char** plateau);


int score(char** plateau, char* mot, int codeColonne, int ligne, int sens);


char* demandeJeton(char* chaine, char* mainJoueur, char* mot);


char* reunionJetons(char* JetonPioches, char* mainJoueur, char* mot);
char* suppressionchaine(char* chaine,char* JetonPioches);


#endif //UNTITLED_FUNCTION_H
