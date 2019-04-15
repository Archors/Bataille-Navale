#include "biblio.h"

void Fusee(int **tab, int x, int y, int taille)
{
    int i=x, j=y;
    for(i=x; i<(x+4); i++)
    {
        tp(i+2,(taille*2)+(y*2)+7);
        for(j=y; j<(y+4); j++)
        {
            if (tab[i][j] == 0)
                color(0,9);
            if (tab[i][j] == 1 || tab[i][j]== 5)
                color(0,2);
            if (tab[i][j] == 2)
                color(0,11);
            if (tab[i][j] == 3)
                color(0,14);
            if (tab[i][j] == 4)
                color(0,8);
            if (tab[i][j] == 11 || tab[i][j]== 6)
                color(0,12);
            printf("  ");
        }
    }
    color(15,0);
    Sleep(5000);
    system("cls");
}

void Tir(int taille, int **tab1, int **tab2, int **tab3, int nbcu, int nbcr, int nbde, int nbsm,t_bateau* bateau3, int *tour)
{
    int i=0,j=0;
    int x=0, y=0, tirx=0, tiry=0;
    int cuira=0;

    do
    {
        Affichage(taille, tab1,tab2);
        printf("Saississez les coordonnees du bateau qui va tirer\n");
        x=saisie();
        y=saisie();
        fflush(stdin);
    }
    while(x>taille || y>taille || x < 1 || y < 1);
    x -= 1;
    y -= 1;
    if(tab1[x][y] !=0 && tab1[x][y] != 11)
    {
        if(tab1[x][y] == 1)
        {
            do
            {
                Affichage(taille,tab1, tab2);
                printf("Vous avez selectionner un cuirasse, saississez les coordonnes du tir\n");
                tirx=saisie();
                tiry=saisie();
                tirx--;
                tiry--;
            }
            while(tirx < 1 || tirx > taille-2 || tiry < 1 || tiry > taille-2);
            if(tab3[tirx-1][tiry-1]== 1 || tab3[tirx-1][tiry-1]== 2 || tab3[tirx-1][tiry-1]== 3)
            {
                tab2[tirx-1][tiry-1]=6;
                tab3[tirx-1][tiry-1]=11;
            }
            if(tab3[tirx-1][tiry-1] == 0 || tab3[tirx-1][tiry-1] == 4)
                tab2[tirx-1][tiry-1]=5;

            if(tab3[tirx][tiry-1]== 1 || tab3[tirx][tiry-1]== 2 || tab3[tirx][tiry-1]== 3)
            {
                tab2[tirx][tiry-1]=6;
                tab3[tirx][tiry-1]=11;
            }
            if(tab3[tirx][tiry-1] == 0 || tab3[tirx][tiry-1] == 4)
                tab2[tirx][tiry-1]=5;
            if(tab3[tirx+1][tiry-1]== 1 || tab3[tirx+1][tiry-1]== 2 || tab3[tirx+1][tiry-1]== 3)
            {
                tab2[tirx+1][tiry-1]=6;
                tab3[tirx+1][tiry-1]=11;
            }
            if(tab3[tirx+1][tiry-1] == 0 || tab3[tirx+1][tiry-1] == 4)
                tab2[tirx+1][tiry-1]=5;


            if(tab3[tirx-1][tiry]== 1 || tab3[tirx-1][tiry]== 2 || tab3[tirx-1][tiry]== 3)
            {
                tab2[tirx-1][tiry]=6;
                tab3[tirx-1][tiry]=11;
            }
            if(tab3[tirx-1][tiry] == 0 || tab3[tirx-1][tiry] == 4)
                tab2[tirx-1][tiry]=5;
            if(tab3[tirx][tiry]== 1 || tab3[tirx][tiry]== 2 || tab3[tirx][tiry]== 3)
            {
                tab2[tirx][tiry]=6;
                tab3[tirx][tiry]=11;
            }
            if(tab3[tirx][tiry] == 0 || tab3[tirx][tiry] == 4)
                tab2[tirx][tiry]=5;
            if(tab3[tirx+1][tiry]== 1 || tab3[tirx+1][tiry]== 2 || tab3[tirx+1][tiry]== 3)
            {
                tab2[tirx+1][tiry]=6;
                tab3[tirx+1][tiry]=11;
            }
            if(tab3[tirx+1][tiry] == 0 || tab3[tirx+1][tiry] == 4)
                tab2[tirx+1][tiry]=5;

            if(tab3[tirx-1][tiry+1]== 1 || tab3[tirx-1][tiry+1]== 2 || tab3[tirx-1][tiry+1]== 3)
            {
                tab2[tirx-1][tiry+1]=6;
                tab3[tirx-1][tiry+1]=11;
            }
            if(tab3[tirx-1][tiry+1] == 0 || tab3[tirx-1][tiry+1] == 4)
                tab2[tirx-1][tiry+1]=5;
            if(tab3[tirx][tiry+1]== 1 || tab3[tirx][tiry+1]== 2 || tab3[tirx][tiry+1]== 3)
            {
                tab2[tirx][tiry+1]=6;
                tab3[tirx][tiry+1]=11;
            }
            if(tab3[tirx][tiry+1] == 0 || tab3[tirx][tiry+1] == 4)
                tab2[tirx][tiry+1]=5;
            if(tab3[tirx+1][tiry+1]== 1 || tab3[tirx+1][tiry+1]== 2 || tab3[tirx+1][tiry+1]== 3)
            {
                tab2[tirx+1][tiry+1]=6;
                tab3[tirx+1][tiry+1]=11;
            }
            if(tab3[tirx+1][tiry+1] == 0 || tab3[tirx+1][tiry+1] == 4)
                tab2[tirx+1][tiry+1]=5;
            Affichage(taille,tab1,tab2);
            Sleep(3000);
        }
        if(tab1[x][y] == 2)
        {
            do
            {
                Affichage(taille,tab1, tab2);
                printf("Vous avez selectionner un croiseur, selectionner les coordonnes du tir\n");
                tirx=saisie();
                tiry=saisie();
                tirx --;
                tiry --;
            }
            while(tirx < 0 || tirx > taille-2 || tiry < 0 || tiry > taille-2);
            if(tiry!=0)
            {
                if(tab3[tirx][tiry-1]== 1 || tab3[tirx][tiry-1]== 2 || tab3[tirx][tiry-1]== 3)
                {
                    tab2[tirx][tiry-1]=6;
                    tab3[tirx][tiry-1]=11;
                }
                if(tab3[tirx][tiry-1] == 0 || tab3[tirx][tiry-1] == 4)
                    tab2[tirx][tiry-1]=5;
            }
            if(tirx!=0)
            {
                if(tab3[tirx-1][tiry]== 1 || tab3[tirx-1][tiry]== 2 || tab3[tirx-1][tiry]== 3)
                {
                    tab2[tirx-1][tiry]=6;
                    tab3[tirx-1][tiry]=11;
                }
                if(tab3[tirx-1][tiry] == 0 || tab3[tirx-1][tiry] == 4)
                    tab2[tirx-1][tiry]=5;
            }
            if(tab3[tirx][tiry]== 1 || tab3[tirx][tiry]== 2 || tab3[tirx][tiry]== 3)
            {
                tab2[tirx][tiry]=6;
                tab3[tirx][tiry]=11;
            }
            if(tab3[tirx][tiry] == 0 || tab3[tirx][tiry] == 4)
                tab2[tirx][tiry]=5;
            if(tab3[tirx+1][tiry]== 1 || tab3[tirx+1][tiry]== 2 || tab3[tirx+1][tiry]== 3)
            {
                tab2[tirx+1][tiry]=6;
                tab3[tirx+1][tiry]=11;
            }
            if(tab3[tirx+1][tiry] == 0 || tab3[tirx+1][tiry] == 4)
                tab2[tirx+1][tiry]=5;
            if(tab3[tirx][tiry+1]== 1 || tab3[tirx][tiry+1]== 2 || tab3[tirx][tiry+1]== 3)
            {
                tab2[tirx][tiry+1]=6;
                tab3[tirx][tiry+1]=11;
            }
            if(tab3[tirx][tiry+1] == 0 || tab3[tirx][tiry+1] == 4)
                tab2[tirx][tiry+1]=5;
            Affichage(taille,tab1,tab2);
            Sleep(3000);
        }
        if(tab1[x][y] == 3)
        {

            for(i=0; i<nbde; i++)
            {
                if(bateau3[i].sens == 0)
                {
                    for(j=0; j<3; j++)
                    {
                        if (bateau3[i].x + j == x && bateau3[i].y == y && bateau3[i].tir==0)
                        {
                            do
                            {
                                Affichage(taille, tab1,tab2);
                                printf("Saisissez la zone pour lancer une fusee eclairante\n");
                                tirx=saisie(),
                                tiry=saisie(),
                                tirx -=1;
                                tiry -=1;
                            }
                            while(tirx < 0 || tirx > taille-4 || tiry < 0 || tiry > taille-4);
                            Fusee(tab3,tirx,tiry,taille);
                            bateau3[i].tir=1;
                            cuira=1;

                        }
                    }
                }
                if(bateau3[i].sens == 1)
                {
                    for(j=0; j<7; j++)
                    {
                        if (bateau3[i].x  == x && bateau3[i].y + j == y && bateau3[i].tir==0)
                        {
                            do
                            {
                                Affichage(taille,tab1, tab2);
                                printf("Saisissez la zone pour lancer une fusee eclairante\n");
                                tirx=saisie();
                                tiry=saisie();
                                tirx --;
                                tiry --;
                            }
                            while(tirx < 0 || tirx > taille-4 || tiry < 0 || tiry > taille-4);
                            Fusee(tab3,tirx,tiry,taille);
                            bateau3[i].tir=1;
                            cuira=1;

                        }
                    }
                }

            }
            if(cuira==0)
            {
                do
                {
                    Affichage(taille,tab1, tab2);
                    printf("Vous avez selectionner un destroyer, saississez les coordonnes du tir\n");
                    tirx=saisie();
                    tiry=saisie();
                    tirx--;
                    tiry--;
                }
                while(tirx < 0 || tirx > taille-1 || tiry < 0 || tiry > taille-1);
                if(tab3[tirx][tiry]== 1 || tab3[tirx][tiry]== 2 || tab3[tirx][tiry]== 3)
                {
                    tab2[tirx][tiry]=6;
                    tab3[tirx][tiry]=11;
                }
                if(tab3[tirx][tiry] == 0 || tab3[tirx][tiry] == 4)
                    tab2[tirx][tiry]=5;
                Affichage(taille,tab1,tab2);
                Sleep(3000);
            }
            cuira=0;
            Affichage(taille,tab1,tab2);
            Sleep(3000);
        }
        if(tab1[x][y] == 4)
        {
            do
            {
                Affichage(taille,tab1, tab2);
                printf("Vous avez selectionner un sous-marin, selectionner les coordonnes du tir\n");
                tirx=saisie();
                tiry=saisie();
                tirx --;
                tiry --;
            }
            while(tirx < 0 || tirx > taille-1 || tiry < 0 || tiry > taille-1);
            if(tab3[tirx][tiry]== 1 || tab3[tirx][tiry]== 2 || tab3[tirx][tiry]== 3 || tab3[tirx][tiry] == 4)
            {
                tab2[tirx][tiry]=6;
                tab3[tirx][tiry]=11;
            }
            if(tab3[tirx][tiry] == 0)
                tab2[tirx][tiry]=5;
            Affichage(taille,tab1,tab2);
            Sleep(3000);
        }
    }
    else
    {
        Affichage(taille, tab1,tab2);
        printf("Coordonnes invalides\n");
        (*tour)--;
        Sleep(3000);
    }
}
