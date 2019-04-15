#include "biblio.h"

void tp( int lig, int col )
{
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}

///Affiche les tableaux envoyés en paramètre
void Affichage(int taille, int **tab, int **tab1)
{
    int i=0, j=0;
    system("cls");
    ///Affiche le premier tableau (position des bateaux)
    tp(0,taille-10);
    printf("Vos bateaux\n  ");
    for(i=1; i<taille+1; i++)
    {
        if(i%2 == 0)
            color(11,0);
        else
            color(14,0);

        printf("%2d",i);
    }
    printf("\n");
    i=0;
    for(i=0 ; i < taille ; i++)
    {
        if(i%2 == 0)
            color(11,0);
        else
            color(14,0);
        printf("%2d",i+1);
        for(j=0 ; j < taille ; j++)
        {
            if (tab[i][j] == 0)
                color(0,1);
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
        printf("\n");
        color(15,0);
    }
    ///Affichage du deuxieme tableau (tir)
    i=1;
    tp(0,2*taille+taille-5);
    printf("Vos tirs");
    tp(1,2*taille+7);
    for(i=1; i<taille+1; i++)
    {
        if(i%2 == 0)
            color(11,0);
        else
            color(14,0);
        printf("%2d",i);
    }
    tp(2,2*taille+5);
    i=0;
    j=0;
    for(i=0 ; i < taille ; i++)
    {
        if(i%2 == 0)
            color(11,0);
        else
            color(14,0);
        if(i<9)
            printf(" %d",i+1);
        else
            printf("%d",i+1);
        for(j=0 ; j < taille ; j++)
        {
            if (tab1[i][j] == 0)
                color(0,1);
            if (tab1[i][j] == 1 || tab1[i][j]== 5)
                color(0,2);
            if (tab1[i][j] == 2)
                color(0,11);
            if (tab1[i][j] == 3)
                color(0,14);
            if (tab1[i][j] == 4)
                color(0,8);
            if (tab1[i][j] == 11 || tab1[i][j]== 6)
                color(0,12);
            printf("  ");
        }
        tp(i+3,2*taille+5);
        color(15,0);
    }
    tp(taille+2,0);
}


void Initdonneb(int nb1, int nb2, int nb3, int nb4, t_bateau* bateau1, t_bateau* bateau2, t_bateau* bateau3, t_bateau* bateau4)
{
    int i=0;
    for (i=0; i<nb1; i++)
    {
        bateau1[i].typenb = 1;
        bateau1[i].taille = 7;
        bateau1[i].touche = 0;
        bateau1[i].nom[0] = 'c';
        bateau1[i].nom[1] = 'u';
        bateau1[i].nom[2] = 'i';
        bateau1[i].nom[3] = 'r';
        bateau1[i].nom[4] = 'a';
        bateau1[i].nom[5] = 's';
        bateau1[i].nom[6] = 's';
        bateau1[i].nom[7] = 'e';
        bateau1[i].nom[8] = '\0';
    }
    i=0;
    for (i=0; i<nb2; i++)
    {
        bateau2[i].typenb = 2;
        bateau2[i].taille = 5;
        bateau2[i].touche = 0;
        bateau2[i].nom[0] = 'c';
        bateau2[i].nom[1] = 'r';
        bateau2[i].nom[2] = 'o';
        bateau2[i].nom[3] = 'i';
        bateau2[i].nom[4] = 's';
        bateau2[i].nom[5] = 'e';
        bateau2[i].nom[6] = 'u';
        bateau2[i].nom[7] = 'r';
        bateau2[i].nom[8] = '\0';
    }
    i=0;
    for (i=0; i<nb3; i++)
    {
        bateau3[i].typenb = 3;
        bateau3[i].taille = 3;
        bateau3[i].tir = 0;
        bateau3[i].touche = 0;
        bateau3[i].nom[0] = 'd';
        bateau3[i].nom[1] = 'e';
        bateau3[i].nom[2] = 's';
        bateau3[i].nom[3] = 't';
        bateau3[i].nom[4] = 'r';
        bateau3[i].nom[5] = 'o';
        bateau3[i].nom[6] = 'y';
        bateau3[i].nom[7] = 'e';
        bateau3[i].nom[8] = 'r';
        bateau3[i].nom[9] = '\0';
    }
    i=0;
    for (i=0; i<nb4; i++)
    {
        bateau4[i].typenb = 4;
        bateau4[i].taille = 1;
        bateau4[i].sens = 0;
        bateau4[i].touche = 0;
        bateau4[i].nom[0] = 's';
        bateau4[i].nom[1] = 'o';
        bateau4[i].nom[2] = 'u';
        bateau4[i].nom[3] = 's';
        bateau4[i].nom[4] = '-';
        bateau4[i].nom[5] = 'm';
        bateau4[i].nom[6] = 'a';
        bateau4[i].nom[7] = 'r';
        bateau4[i].nom[8] = 'i';
        bateau4[i].nom[9] = 'n';
        bateau4[i].nom[10] = '\0';
    }
}
///Initialise la position aléatoire de chaque bateau pour le joueur 1
void InitBateaux(int taille, int **tab,int nbb, t_bateau* bateau)
{
    int i=0, j=0, aleax=0, aleay=0, test=1;
    ///Initialisation bateaux
    for(j=0; j<nbb; j++)
    {
        bateau[j].sens = rand()%2;
        do
        {
            if (bateau[j].sens == 0)
            {
                aleax = rand()%(taille - bateau[0].taille);
                aleay = rand()%taille;
                i=0;
                test=1;
                for(i=0; i<bateau[0].taille; i++)
                {
                    if (tab[aleax+i][aleay] != 0)
                        test = 0;
                }
            }
            if (bateau[j].sens == 1)
            {
                aleax = rand()%taille;
                aleay = rand()%(taille - bateau[0].taille);
                i=0;
                test=1;
                for(i=0; i<bateau[0].taille; i++)
                {
                    if (tab[aleax][aleay+i] != 0)
                        test = 0;
                }
            }
        }
        while(test == 0);
        bateau[j].x = aleax;
        bateau[j].y = aleay;
        if (bateau[j].sens == 0)
        {
            for(i=0; i<bateau[0].taille; i++)

                tab[aleax+i][aleay] = bateau[0].typenb;

        }
        if (bateau[j].sens == 1)
        {
            for(i=0; i<bateau[0].taille; i++)
                tab[aleax][aleay+i] = bateau[0].typenb;
        }

    }

}

///Demande le nombre de bateau de chaque type à l'utilisateur
int nbbateau(int taille, int nb)
{
    int nombredubateau=0;
    do
    {
        nombredubateau=saisie();
        fflush(stdin);
    }
    while(nombredubateau < 0 || nombredubateau > ((taille*taille)/nb));
    return nombredubateau;
}


void couler(int taille, int **tab, t_bateau* bateau, int nbb)
{
    int i=0, j=0, compteur=0;
    for(i=0; i<nbb; i++)
    {
        if (tab[bateau[i].x][bateau[i].y]==11)
        {
            if (bateau[i].sens == 0)
            {
                for (j=0; j<bateau[i].taille; j++)
                {
                    if(tab[bateau[i].x +j][bateau[i].y]==11)
                        compteur++;
                }
            }
            if (bateau[i].sens == 1)
            {
                for (j=0; j<bateau[i].taille; j++)
                {
                    if(tab[bateau[i].x][bateau[i].y+j]==11)
                        compteur++;
                }
            }
        }
        if (compteur == bateau[i].taille)
        {
            color(12,0);
            printf("Un %s a ete coule !\n",bateau[i].nom);
            Sleep(2500);
            color(15,0);
            if (bateau[i].sens == 0)
            {

                j=0;
                for(j=0; j<bateau[i].taille; j++)
                {
                    tab[bateau[i].x+j][bateau[i].y]=0;
                }
            }
            if (bateau[i].sens == 1)
            {

                j=0;
                for(j=0; j<bateau[i].taille; j++)
                {
                    tab[bateau[i].x][bateau[i].y+j]=0;
                }
            }

        }
        compteur=0;
    }
}

int victoire(int taille, int **tab)
{
    int i=0, j=0, vic=1;
    for (i=0; i<taille; i++)
    {
        for(j=0; j<taille; j++)
        {
            if (tab[i][j] != 0)
                vic = 0;
        }
    }
    return vic;
}

void Aide(int taille, int **tab1, int **tab2)
{
    int i=0, j=0,compteur=0;
    for (i=0; i<taille; i++)
    {
        for(j=0; j<taille; j++)
        {
            if(tab2[i][j] == 6)
            {
                i++;
                j++;
                printf("Vous avez touche un bateau en %d %d et il n'est pas encore coulee vous devriez tirer aux environs pour le couler\n",i,j);
                j=taille;
                i=taille;
            }
            else
                compteur++;
        }
    }
    if (compteur==taille*taille)
    {
        printf("Il n'y a aucun bateau qui est touche, vous pouvez tirer n'importe ou...\n Selectionner un cuirasse (bateau vert) pour avoir une zone d'impact de tir plus importante");
    }
}
///Mettre la console en pleine ecran simule un alt + entrée
void fullscreen()
{
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}
