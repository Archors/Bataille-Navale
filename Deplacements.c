#include "biblio.h"

void Deplacement(int taille, int **tab,int **tab1, int nbb, t_bateau* bateau,int x,int y, int *tour)
{
    int bouger=0;
    int i=0, j=0, sens=0;
    int test= (*tour);
    for(i=0; i<nbb; i++)
    {
        if(bateau[i].sens == 0)
        {
            for(j=0; j<bateau[i].taille; j++)
            {
                if (tab[bateau[i].x+j][bateau[i].y] == 11)
                    bateau[i].touche = 1;
            }
            j=0;
            for(j=0; j<bateau[i].taille; j++)
            {

                if (bateau[i].x+j == x && bateau[i].y == y && bouger==0 && bateau[i].touche == 0)
                {
                    bouger=1;
                    x=bateau[i].x;
                    y=bateau[i].y;
                    do
                    {
                        Affichage(taille, tab,tab1);
                        printf("Donnez le sens de deplacement du bateau\n1.Vers le haut\n2.Vers le bas\n");
                        sens=saisie();
                    }
                    while(sens < 1 || sens > 2);

                    ///Monte

                    if(sens == 1 && bateau[i].sens == 0 && x > 0)
                    {
                        if(tab[x-1][y] == 0)
                        {
                            (*tour)++;
                            tab[x-1][y]=bateau[i].typenb;
                            tab[x+bateau[i].taille-1][y]=0;
                            bateau[i].x--;
                            Affichage(taille,tab,tab1);
                            Sleep(3000);
                        }
                    }
                    ///Descend

                    if(sens == 2 && bateau[i].sens==0 && x+bateau[i].taille <= taille)
                    {
                        if(tab[x+bateau[i].taille][y]==0)
                        {
                            (*tour)++;
                            tab[x+bateau[i].taille][y]=bateau[i].typenb;
                            tab[x][y]=0;
                            bateau[i].x++;
                            Affichage(taille,tab,tab1);
                            Sleep(3000);
                        }
                    }


                }
            }
        }
        if(bateau[i].sens == 1)
        {
            for(j=0; j<bateau[i].taille; j++)
            {

                if (tab[bateau[i].x][bateau[i].y+j] == 11)
                    bateau[i].touche = 1;
            }
            j=0;
            for(j=0; j<bateau[i].taille; j++)
            {
                if (bateau[i].x == x && bateau[i].y+j == y && bouger==0 && bateau[i].touche == 0)
                {
                    bouger=1;
                    x=bateau[i].x;
                    y=bateau[i].y;
                    do
                    {
                        Affichage(taille, tab,tab1);
                        printf("Donnez le sens de deplacement du bateau\n1.Vers la gauche\n2.Vers la droite\n");
                        sens=saisie();
                    }
                    while(sens < 1 && sens > 2);
                    ///Gauche

                    if(sens == 1 && bateau[i].sens==1 && y > 0)
                    {
                        if(tab[x][y-1]==0)
                        {
                            (*tour)++;
                            tab[x][y-1]=bateau[i].typenb;
                            tab[x][y+bateau[i].taille-1]=0;
                            bateau[i].y--;
                            Affichage(taille,tab,tab1);
                            Sleep(3000);
                        }
                    }
                    ///Droite

                    if(sens == 2 && bateau[i].sens==1 && y+bateau[i].taille <= taille)
                    {
                        if(tab[x][y+bateau[i].taille]== 0)
                        {
                            (*tour)++;
                            tab[x][y+bateau[i].taille]=bateau[i].typenb;
                            tab[x][y]=0;
                            bateau[i].y++;
                            Affichage(taille,tab,tab1);
                            Sleep(3000);
                        }
                    }

                }
            }
        }
    }
    if (test == (*tour))
    {
        color(12,0);
        printf("Deplacement impossible\n");
        Sleep(2000);
        color(15,0);
    }
}

void Deplacementsm(int taille, int **tab, int **tab1, int nbb, t_bateau* bateau,int x,int y, int *tour)
{
    int i=0,choix=0;
    int test = (*tour);
    for(i=0; i<nbb; i++)
    {
        if(bateau[i].x == x && bateau[i].y == y)
        {
            do
            {
                printf("Dans quelle direction souhaitez vous deplacer le sous marin ?\n1.Vers la gauche\n2.Vers la droite\n3.Vers le haut\n4.Vers le bas\n");
                choix=saisie();
            }
            while(choix < 1 && choix < 4); ///Gauche
            if (choix == 1 && y > 0)
            {
                if(tab[x][y-1] == 0)
                {
                    (*tour)++;
                    bateau[i].y--;
                    tab[x][y]=0;
                    tab[x][y-1]=4;
                }
            }
            if (choix == 2 && y < taille-1) ///Droite
            {
                if(tab[x][y+1] == 0)
                {
                    (*tour)++;
                    bateau[i].y++;
                    tab[x][y]=0;
                    tab[x][y+1]=4;
                }
            }
            if (choix == 3 && x > 0) ///Haut
            {
                if(tab[x-1][y] == 0)
                {
                    (*tour)++;
                    bateau[i].x--;
                    tab[x][y]=0;
                    tab[x-1][y]=4;
                }
            }
            if (choix == 4 && x < taille-1) ///Bas
            {
                if(tab[x+1][y] == 0)
                {
                    (*tour)++;
                    bateau[i].x++;
                    tab[x][y]=0;
                    tab[x+1][y]=4;
                }
            }
        }
    }
    if (test == (*tour))
    {
        color(12,0);
        printf("Deplacement impossible\n");
        Sleep(2000);
        color(15,0);
    }
    else
    {
        Affichage(taille,tab,tab1);
        Sleep(3000);
    }
}
