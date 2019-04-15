#include "biblio.h"

void TirIA(int taille, int **tab1, int **tab2, int **tab3, int nbcu, int nbcr, int nbde, int nbsm,t_bateau* bateau1)
{
    int i=0,j=0;
    int x=0, y=0, tirx=-1, tiry=-1;
    do
    {
        x=rand()%taille;
        y=rand()%taille;
    }
    while(tab1[x][y] == 0 || tab1[x][y]==11);
    ///Affichage du bateau selectionne
    if(tab1[x][y] == 1)
    {
        x++;
        y++;
        printf("L'ordinateur a selectionne un cuirasse en %d %d\n",x,y);
        x--;
        y--;
    }
    if(tab1[x][y] == 2)
    {
        x++;
        y++;
        printf("L'ordinateur a selectionne un croiseur en %d %d\n",x,y);
        x--;
        y--;
    }
    if(tab1[x][y] == 3)
    {
        x++;
        y++;
        printf("L'ordinateur a selectionne un destroyer en %d %d\n",x,y);
        x--;
        y--;
    }
    if(tab1[x][y] == 4)
    {
        x++;
        y++;
        printf("L'ordinateur a selectionne un sous-marin en %d %d\n",x,y);
        x--;
        y--;
    }
    //Sleep(2500);
    if(tab1[x][y] !=0)
    {
        ///Tir de l'IA avec le cuirassé
        if(tab1[x][y] == 1)
        {
            ///IA Intelligente du cuirassé
            i=0;
            j=0;
            for(i=0; i<taille; i++)
            {
                for(j=0; j<taille; j++)
                {
                    if (tab2[i][j] == 6 && (tab3[i][j-1] == 1 || tab3[i][j-1] == 2 || tab3[i][j-1] == 3))
                    {
                        if(i==0)
                            i++;
                        if(j==0)
                            j++;
                        if(i==taille)
                            i--;
                        if(j==taille)
                            j--;
                        tirx = i+1;
                        tiry = j;
                        i=taille;
                        j=taille;
                    }
                    if(j != taille)
                    {
                        if (tab2[i][j] == 6 && (tab3[i][j+1] == 1 || tab3[i][j+1] == 2 || tab3[i][j+1] == 3))
                        {
                            if(i==0)
                                i++;
                            if(j==0)
                                j++;
                            if(i==taille)
                                i--;
                            if(j==taille)
                                j--;
                            tirx = i+1;
                            tiry = j+2;
                            i=taille;
                            j=taille;
                        }
                    }
                    if(i != taille)
                    {
                        if (tab2[i][j] == 6 && (tab3[i+1][j] == 1 || tab3[i+1][j] == 2 || tab3[i+1][j] == 3))
                        {
                            if(i==0)
                                i++;
                            if(j==0)
                                j++;
                            if(i==taille)
                                i--;
                            if(j==taille)
                                j--;
                            tirx = i+2;
                            tiry = j+1;
                            i=taille;
                            j=taille;
                        }
                    }
                    if(i != taille)
                    {
                        if (tab2[i][j] == 6 && (tab3[i-1][j] == 1 || tab3[i-1][j] == 2 || tab3[i-1][j] == 3))
                        {
                            if(i==0)
                                i++;
                            if(j==0)
                                j++;
                            if(i==taille)
                                i--;
                            if(j==taille)
                                j--;
                            tirx = i;
                            tiry = j+1;
                            i=taille;
                            j=taille;
                        }
                    }


                }
            }
            i=0;
            j=0;
            if(tirx == -1 && tiry == -1)
            {
                tirx=rand()%(taille-2) + 2;
                tiry=rand()%(taille-2) + 2;
            }
            printf("L'ordinateur tire en %d %d", tirx, tiry);
            tirx--;
            tiry--;
            Sleep(2000);
            ///Application des degats dans la zone de tir
            if(tab3[tirx-1][tiry-1]== 1 || tab3[tirx-1][tiry-1]== 2 || tab3[tirx-1][tiry-1]== 3)
            {
                tab2[tirx-1][tiry-1]=6;
                tab3[tirx-1][tiry-1]=11;
            }
            if(tab3[tirx-1][tiry-1] == 0)
                tab2[tirx-1][tiry-1]=5;

            if(tab3[tirx][tiry-1]== 1 || tab3[tirx][tiry-1]== 2 || tab3[tirx][tiry-1]== 3)
            {
                tab2[tirx][tiry-1]=6;
                tab3[tirx][tiry-1]=11;
            }
            if(tab3[tirx][tiry-1] == 0)
                tab2[tirx][tiry-1]=5;
            if(tab3[tirx+1][tiry-1]== 1 || tab3[tirx+1][tiry-1]== 2 || tab3[tirx+1][tiry-1]== 3)
            {
                tab2[tirx+1][tiry-1]=6;
                tab3[tirx+1][tiry-1]=11;
            }
            if(tab3[tirx+1][tiry-1] == 0)
                tab2[tirx+1][tiry-1]=5;


            if(tab3[tirx-1][tiry]== 1 || tab3[tirx-1][tiry]== 2 || tab3[tirx-1][tiry]== 3)
            {
                tab2[tirx-1][tiry]=6;
                tab3[tirx-1][tiry]=11;
            }
            if(tab3[tirx-1][tiry] == 0)
                tab2[tirx-1][tiry]=5;
            if(tab3[tirx][tiry]== 1 || tab3[tirx][tiry]== 2 || tab3[tirx][tiry]== 3)
            {
                tab2[tirx][tiry]=6;
                tab3[tirx][tiry]=11;
            }
            if(tab3[tirx][tiry] == 0)
                tab2[tirx][tiry]=5;
            if(tab3[tirx+1][tiry]== 1 || tab3[tirx+1][tiry]== 2 || tab3[tirx+1][tiry]== 3)
            {
                tab2[tirx+1][tiry]=6;
                tab3[tirx+1][tiry]=11;
            }
            if(tab3[tirx+1][tiry] == 0)
                tab2[tirx+1][tiry]=5;

            if(tab3[tirx-1][tiry+1]== 1 || tab3[tirx-1][tiry+1]== 2 || tab3[tirx-1][tiry+1]== 3)
            {
                tab2[tirx-1][tiry+1]=6;
                tab3[tirx-1][tiry+1]=11;
            }
            if(tab3[tirx-1][tiry+1] == 0)
                tab2[tirx-1][tiry+1]=5;
            if(tab3[tirx][tiry+1]== 1 || tab3[tirx][tiry+1]== 2 || tab3[tirx][tiry+1]== 3)
            {
                tab2[tirx][tiry+1]=6;
                tab3[tirx][tiry+1]=11;
            }
            if(tab3[tirx][tiry+1] == 0)
                tab2[tirx][tiry+1]=5;
            if(tab3[tirx+1][tiry+1]== 1 || tab3[tirx+1][tiry+1]== 2 || tab3[tirx+1][tiry+1]== 3)
            {
                tab2[tirx+1][tiry+1]=6;
                tab3[tirx+1][tiry+1]=11;
            }
            if(tab3[tirx+1][tiry+1] == 0)
                tab2[tirx+1][tiry+1]=5;
        }
        ///Tir de l'IA avec le croiseur
        if(tab1[x][y] == 2)
        {
            ///IA Intelligente du croiseur
            i=0;
            j=0;
            for(i=0; i<taille; i++)
            {
                for(j=0; j<taille; j++)
                {
                    if (tab2[i][j] == 6 && (tab3[i][j-1] == 1 || tab3[i][j-1] == 2 || tab3[i][j-1] == 3))
                    {
                        if(i==0)
                            i++;
                        if(j==0)
                            j++;
                        if(i==taille)
                            i--;
                        if(j==taille)
                            j--;
                        tirx = i+1;
                        tiry = j;
                        i=taille;
                        j=taille;
                    }
                    if(j != taille)
                    {
                        if (tab2[i][j] == 6 && (tab3[i][j+1] == 1 || tab3[i][j+1] == 2 || tab3[i][j+1] == 3))
                        {
                            if(i==0)
                                i++;
                            if(j==0)
                                j++;
                            if(i==taille)
                                i--;
                            if(j==taille)
                                j--;
                            tirx = i+1;
                            tiry = j+2;
                            i=taille;
                            j=taille;
                        }
                    }
                    if(i != taille)
                    {
                        if (tab2[i][j] == 6 && (tab3[i+1][j] == 1 || tab3[i+1][j] == 2 || tab3[i+1][j] == 3))
                        {
                            if(i==0)
                                i++;
                            if(j==0)
                                j++;
                            if(i==taille)
                                i--;
                            if(j==taille)
                                j--;
                            tirx = i+2;
                            tiry = j+1;
                            i=taille;
                            j=taille;
                        }
                    }
                    if(i != taille)
                    {
                        if (tab2[i][j] == 6 && (tab3[i-1][j] == 1 || tab3[i-1][j] == 2 || tab3[i-1][j] == 3))
                        {
                            if(i==0)
                                i++;
                            if(j==0)
                                j++;
                            if(i==taille)
                                i--;
                            if(j==taille)
                                j--;
                            tirx = i;
                            tiry = j+1;
                            i=taille;
                            j=taille;
                        }
                    }
                }
            }
            i=0;
            j=0;
            if(tirx == -1 && tiry == -1)
            {
                tirx=rand()%(taille-2) + 2;
                tiry=rand()%(taille-2) + 2;
            }
            printf("L'ordinateur tire en %d %d\n", tirx, tiry);
            tirx--;
            tiry--;
            Sleep(5000);
            ///Application des degats dans la zone de tir
            if(tab3[tirx][tiry-1]== 1 || tab3[tirx][tiry-1]== 2 || tab3[tirx][tiry-1]== 3)
            {
                tab2[tirx][tiry-1]=6;
                tab3[tirx][tiry-1]=11;
            }
            if(tab3[tirx][tiry-1] == 0)
                tab2[tirx][tiry-1]=5;
            if(tab3[tirx-1][tiry]== 1 || tab3[tirx-1][tiry]== 2 || tab3[tirx-1][tiry]== 3)
            {
                tab2[tirx-1][tiry]=6;
                tab3[tirx-1][tiry]=11;
            }
            if(tab3[tirx-1][tiry] == 0)
                tab2[tirx-1][tiry]=5;
            if(tab3[tirx][tiry]== 1 || tab3[tirx][tiry]== 2 || tab3[tirx][tiry]== 3)
            {
                tab2[tirx][tiry]=6;
                tab3[tirx][tiry]=11;
            }
            if(tab3[tirx][tiry] == 0)
                tab2[tirx][tiry]=5;
            if(tab3[tirx+1][tiry]== 1 || tab3[tirx+1][tiry]== 2 || tab3[tirx+1][tiry]== 3)
            {
                tab2[tirx+1][tiry]=6;
                tab3[tirx+1][tiry]=11;
            }
            if(tab3[tirx+1][tiry] == 0)
                tab2[tirx+1][tiry]=5;
            if(tab3[tirx][tiry+1]== 1 || tab3[tirx][tiry+1]== 2 || tab3[tirx][tiry+1]== 3)
            {
                tab2[tirx][tiry+1]=6;
                tab3[tirx][tiry+1]=11;
            }
            if(tab3[tirx][tiry+1] == 0)
                tab2[tirx][tiry+1]=5;

        }
        ///Tir de l'IA avec le destroyer
        if(tab1[x][y] == 3)
        {
            ///IA Intelligente du destroyer
            i=0;
            j=0;
            for(i=1; i<taille; i++)
            {
                for(j=1; j<taille; j++)
                {
                    if (tab2[i][j] == 6 && (tab3[i][j-1] == 1 || tab3[i][j-1] == 2 || tab3[i][j-1] == 3))
                    {
                        tirx = i+1;
                        tiry = j;
                        i=taille;
                        j=taille;
                    }
                    if(j != taille)
                    {
                        if (tab2[i][j] == 6 && (tab3[i][j+1] == 1 || tab3[i][j+1] == 2 || tab3[i][j+1] == 3))
                        {
                            tirx = i+1;
                            tiry = j+2;
                            i=taille;
                            j=taille;
                        }
                    }
                    if(i != taille)
                    {
                        if (tab2[i][j] == 6 && (tab3[i+1][j] == 1 || tab3[i+1][j] == 2 || tab3[i+1][j] == 3))
                        {
                            tirx = i+2;
                            tiry = j+1;
                            i=taille;
                            j=taille;
                        }
                    }
                    if(i != taille)
                    {
                        if (tab2[i][j] == 6 && (tab3[i-1][j] == 1 || tab3[i-1][j] == 2 || tab3[i-1][j] == 3))
                        {
                            tirx = i;
                            tiry = j+1;
                            i=taille;
                            j=taille;
                        }
                    }
                }
            }
            i=0;
            j=0;
            if (tirx == -1 && tiry == -1)
            {
                printf("Aleatoire !\n");
                tirx=rand()%(taille-2) + 2;
                tiry=rand()%(taille-2) + 2;
            }
            printf("L'ordinateur tire en %d %d", tirx, tiry);
            tirx--;
            tiry--;
            Sleep(4000);
            ///Application des degats dans la zone de tir
            if(tab3[tirx][tiry]== 1 || tab3[tirx][tiry]== 2 || tab3[tirx][tiry]== 3)
            {
                tab2[tirx][tiry]=6;
                tab3[tirx][tiry]=11;
            }
            if(tab3[tirx][tiry] == 0)
                tab2[tirx][tiry]=5;
        }
        if(tab1[x][y] == 4)
        {
            ///IA Intelligente du sous-marin
            i=0;
            j=0;
            for(i=1; i<taille; i++)
            {
                for(j=1; j<taille; j++)
                {
                    if (tab2[i][j] == 6 && (tab3[i][j-1] == 1 || tab3[i][j-1] == 2 || tab3[i][j-1] == 3 || tab3[i][j-1] == 4))
                    {
                        tirx = i+1;
                        tiry = j;
                        i=taille;
                        j=taille;
                    }
                    if(j != taille)
                    {
                        if (tab2[i][j] == 6 && (tab3[i][j+1] == 1 || tab3[i][j+1] == 2 || tab3[i][j+1] == 3 || tab3[i][j+1] == 4))
                        {
                            tirx = i+1;
                            tiry = j+2;
                            i=taille;
                            j=taille;
                        }
                    }
                    if(i != taille)
                    {
                        if (tab2[i][j] == 6 && (tab3[i+1][j] == 1 || tab3[i+1][j] == 2 || tab3[i+1][j] == 3 || tab3[i+1][j] == 4))
                        {
                            tirx = i+2;
                            tiry = j+1;
                            i=taille;
                            j=taille;
                        }
                    }
                    if(i != taille)
                    {
                        if (tab2[i][j] == 6 && (tab3[i-1][j] == 1 || tab3[i-1][j] == 2 || tab3[i-1][j] == 3 || tab3[i-1][j] == 4))
                        {
                            tirx = i;
                            tiry = j+1;
                            i=taille;
                            j=taille;
                        }
                    }
                }
            }
            i=0;
            j=0;
            if (tirx == -1 && tiry == -1)
            {
                tirx=rand()%(taille-2) + 2;
                tiry=rand()%(taille-2) + 2;
            }
            printf("L'ordinateur tire en %d %d", tirx, tiry);
            tirx--;
            tiry--;
            Sleep(4000);
            if(tab3[tirx][tiry]== 1 || tab3[tirx][tiry]== 2 || tab3[tirx][tiry]== 3 || tab3[tirx][tiry] == 4)
            {
                tab2[tirx][tiry]=6;
                tab3[tirx][tiry]=11;
            }
            if(tab3[tirx][tiry] == 0)
                tab2[tirx][tiry]=5;
        }
    }
}
