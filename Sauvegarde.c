#include "biblio.h"

void Save(int nb1, int nb2,int nb3,int nb4,int taille,int tour,t_bateau* cuirasse1, t_bateau* croiseur1, t_bateau* destroyer1, t_bateau* sousm1,t_bateau* cuirasse2, t_bateau* croiseur2, t_bateau* destroyer2, t_bateau* sousm2, int **tab1, int **tab2, int **tab3, int **tab4)
{
    int i=0, j=0;
    FILE* fichier = NULL;
    fichier = fopen("SaveInit.txt", "w+");

    if (fichier != NULL)
    {
        fprintf(fichier, "%d %d %d %d %d %d ", nb1,nb2,nb3,nb4,taille,tour);
        fclose(fichier);
    }

    fichier = fopen("SaveAll.txt", "w+");
    if (fichier != NULL)
    {
        i=0;
        j=0;
        for (i=0; i<taille; i++)
        {
            for(j=0; j<taille; j++)
            {
                fprintf(fichier,"%d ",tab1[i][j]);
            }
        }
        i=0;
        j=0;
        for (i=0; i<taille; i++)
        {
            for(j=0; j<taille; j++)
            {
                fprintf(fichier,"%d ",tab2[i][j]);
            }
        }
        i=0;
        j=0;
        for (i=0; i<taille; i++)
        {
            for(j=0; j<taille; j++)
            {
                fprintf(fichier,"%d ",tab3[i][j]);
            }
        }
        i=0;
        j=0;
        for (i=0; i<taille; i++)
        {
            for(j=0; j<taille; j++)
            {
                fprintf(fichier,"%d ",tab4[i][j]);
            }
        }
        i=0;
        j=0;

        for (i=0; i<nb1; i++)
        {
            fprintf(fichier,"%d %d %d %d %d %d %d ",cuirasse1[i].taille,cuirasse1[i].touche,cuirasse1[i].x,cuirasse1[i].y,cuirasse1[i].sens, cuirasse1[i].typenb,cuirasse1[i].tir);
        }
        i=0;
        for (i=0; i<nb2; i++)
        {
            fprintf(fichier,"%d %d %d %d %d %d %d ",croiseur1[i].taille,croiseur1[i].touche,croiseur1[i].x,croiseur1[i].y,croiseur1[i].sens, croiseur1[i].typenb,croiseur1[i].tir);
        }
        i=0;
        for (i=0; i<nb3; i++)
        {
            fprintf(fichier,"%d %d %d %d %d %d %d ",destroyer1[i].taille,destroyer1[i].touche,destroyer1[i].x,destroyer1[i].y,destroyer1[i].sens, destroyer1[i].typenb,destroyer1[i].tir);
        }
        i=0;
        for (i=0; i<nb4; i++)
        {
            fprintf(fichier,"%d %d %d %d %d %d %d ",sousm1[i].taille,sousm1[i].touche,sousm1[i].x,sousm1[i].y,sousm1[i].sens, sousm1[i].typenb,sousm1[i].tir);
        }
        i=0;
        for (i=0; i<nb1; i++)
        {
            fprintf(fichier,"%d %d %d %d %d %d %d ",cuirasse2[i].taille,cuirasse2[i].touche,cuirasse2[i].x,cuirasse2[i].y,cuirasse2[i].sens, cuirasse2[i].typenb,cuirasse2[i].tir);
        }
        i=0;
        for (i=0; i<nb2; i++)
        {
            fprintf(fichier,"%d %d %d %d %d %d %d ",croiseur2[i].taille,croiseur2[i].touche, croiseur2[i].x,croiseur2[i].y,croiseur2[i].sens, croiseur2[i].typenb,croiseur2[i].tir);
        }
        i=0;
        for (i=0; i<nb3; i++)
        {
            fprintf(fichier,"%d %d %d %d %d %d %d ",destroyer2[i].taille,destroyer2[i].touche, destroyer2[i].x,destroyer2[i].y,destroyer2[i].sens, destroyer2[i].typenb,destroyer2[i].tir);
        }
        i=0;
        for (i=0; i<nb4; i++)
        {
            fprintf(fichier,"%d %d %d %d %d %d %d ",sousm2[i].taille,sousm2[i].touche, sousm2[i].x,sousm2[i].y,sousm2[i].sens, sousm2[i].typenb,sousm2[i].tir);
        }
        fclose(fichier);
    }
}

int LoadInit(int* nb1, int* nb2,int* nb3,int* nb4,int* taille,int* tour)
{
    int test=1;
    FILE* fichier = NULL;
    fichier = fopen("SaveInit.txt", "r");
    if (fichier != NULL)
    {
        fscanf(fichier,"%d %d %d %d %d %d",nb1,nb2,nb3,nb4,taille,tour);
        fclose(fichier);
    }
    else
        test=0;
    return test;
}

void LoadAll(int nb1, int nb2,int nb3,int nb4,int taille,int* tour,t_bateau* cuirasse1, t_bateau* croiseur1, t_bateau* destroyer1, t_bateau* sousm1,t_bateau* cuirasse2, t_bateau* croiseur2, t_bateau* destroyer2, t_bateau* sousm2, int **tab1, int **tab2, int **tab3, int **tab4)
{
    int i=0,j=0;
    FILE* fichier = NULL;
    fichier = fopen("SaveAll.txt", "r");
    if (fichier != NULL)
    {
        for(i=0; i<taille; i++)
        {
            for(j=0; j<taille; j++)
                fscanf(fichier,"%d",&tab1[i][j]);
        }
        i=0;
        j=0;
        for(i=0; i<taille; i++)
        {
            for(j=0; j<taille; j++)
                fscanf(fichier,"%d",&tab2[i][j]);
        }
        i=0;
        j=0;
        for(i=0; i<taille; i++)
        {
            for(j=0; j<taille; j++)
                fscanf(fichier,"%d",&tab3[i][j]);
        }
        i=0;
        j=0;
        for(i=0; i<taille; i++)
        {
            for(j=0; j<taille; j++)
                fscanf(fichier,"%d",&tab4[i][j]);
        }
        for(i=0; i<nb1; i++)
        {
            fscanf(fichier,"%d %d %d %d %d %d %d",&cuirasse1[i].taille,&cuirasse1[i].touche,&cuirasse1[i].x,&cuirasse1[i].y,&cuirasse1[i].sens,&cuirasse1[i].typenb,&cuirasse1[i].tir);
        }
        i=0;
        for(i=0; i<nb2; i++)
        {
            fscanf(fichier,"%d %d %d %d %d %d %d",&croiseur1[i].taille,&croiseur1[i].touche,&croiseur1[i].x,&croiseur1[i].y,&croiseur1[i].sens,&croiseur1[i].typenb,&croiseur1[i].tir);
        }
        i=0;
        for(i=0; i<nb3; i++)
        {
            fscanf(fichier,"%d %d %d %d %d %d %d",&destroyer1[i].taille,&destroyer1[i].touche,&destroyer1[i].x,&destroyer1[i].y,&destroyer1[i].sens,&destroyer1[i].typenb,&destroyer1[i].tir);
        }
        i=0;
        for(i=0; i<nb4; i++)
        {
            fscanf(fichier,"%d %d %d %d %d %d %d",&sousm1[i].taille,&sousm1[i].touche,&sousm1[i].x,&sousm1[i].y,&sousm1[i].sens,&sousm1[i].typenb,&sousm1[i].tir);
        }
        i=0;
        for(i=0; i<nb1; i++)
        {
            fscanf(fichier,"%d %d %d %d %d %d %d",&cuirasse2[i].taille,&cuirasse2[i].touche,&cuirasse2[i].x,&cuirasse2[i].y,&cuirasse2[i].sens,&cuirasse2[i].typenb,&cuirasse2[i].tir);
        }
        i=0;
        for(i=0; i<nb2; i++)
        {
            fscanf(fichier,"%d %d %d %d %d %d %d",&croiseur2[i].taille,&croiseur2[i].touche,&croiseur2[i].x,&croiseur2[i].y,&croiseur2[i].sens,&croiseur2[i].typenb,&croiseur2[i].tir);
        }
        i=0;
        for(i=0; i<nb3; i++)
        {
            fscanf(fichier,"%d %d %d %d %d %d %d",&destroyer2[i].taille,&destroyer2[i].touche,&destroyer2[i].x,&destroyer2[i].y,&destroyer2[i].sens,&destroyer2[i].typenb,&destroyer2[i].tir);
        }
        i=0;
        for(i=0; i<nb4; i++)
        {
            fscanf(fichier,"%d %d %d %d %d %d %d",&sousm2[i].taille,&sousm2[i].touche,&sousm2[i].x,&sousm2[i].y,&sousm2[i].sens,&sousm2[i].typenb,&sousm2[i].tir);
        }
        i=0;
        fclose(fichier);
    }
}
