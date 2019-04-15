#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <conio.h>

typedef struct bateau
{
    int taille;
    int touche;
    int x;
    int y;
    int sens;
    int typenb;
    int tir;
    char nom [15];
} t_bateau;

void color(int t,int f);
void fullscreen();
void ResetTab(int taille, int **tab);
void Affichage(int taille, int **tab, int **tab1);
void Initdonneb(int nb1, int nb2, int nb3, int nb4, t_bateau* bateau1, t_bateau* bateau2, t_bateau* bateau3, t_bateau* bateau4);
void InitBateaux(int taille, int **tab,int nbb, t_bateau typeb[]);
void Tir(int taille, int **tab1, int **tab2, int **tab3, int nbcu, int nbcr, int nbde, int nbsm,t_bateau* bateau1, int *tour);
void TirIA(int taille, int **tab1, int **tab2, int **tab3, int nbcu, int nbcr, int nbde, int nbsm,t_bateau* bateau1);
void Deplacement(int taille, int **tab,int **tab2, int nbb, t_bateau* bateau, int x, int y,int *tour);
void Deplacementsm(int taille, int **tab, int **tab1, int nbb, t_bateau* bateau,int x,int y,int *tour);
int victoire(int taille, int **tab);
void couler(int taille, int **tab, t_bateau* bateau, int nbb);
int nbbateau(int taille, int type);
void Aide(int taille, int **tab1, int **tab2);
void purger(void);
void clean (char *chaine);
int saisie();
void tp( int lig, int col );
void Save(int nb1, int nb2,int nb3,int nb4,int taille,int tour,t_bateau* cuirasse1, t_bateau* croiseur1, t_bateau* destroyer1, t_bateau* sousm1,t_bateau* cuirasse2, t_bateau* croiseur2, t_bateau* destroyer2, t_bateau* sousm2, int **tab1, int **tab2, int **tab3, int **tab4);
int LoadInit(int* nb1, int* nb2,int* nb3,int* nb4,int* taille,int* tour);
void LoadAll(int nb1, int nb2,int nb3,int nb4,int taille,int* tour,t_bateau* cuirasse1, t_bateau* croiseur1, t_bateau* destroyer1, t_bateau* sousm1,t_bateau* cuirasse2, t_bateau* croiseur2, t_bateau* destroyer2, t_bateau* sousm2, int **tab1, int **tab2, int **tab3, int **tab4);
