#include "biblio.h"

int main()
{
    fullscreen();
    int i=0;
    int choix = 0, choixjeu=0, taille=0, choixtour=0, tour=0; ///Variable de menu
    int **tab1, **tab2, **tab3, **tab4; ///Differents tableau de jeu
    ///Declaration des structures de bateau
    t_bateau *cuirasse1;
    t_bateau *cuirasse2;
    t_bateau *croiseur1;
    t_bateau *croiseur2;
    t_bateau *destroyer1;
    t_bateau *destroyer2;
    t_bateau *sousm1;
    t_bateau *sousm2;
    int nbcu=0, nbcr=0, nbde=0, nbsm=0; ///Nombre des differents bateaux
    int x=0,y=0; ///Coordonn�es
    int victoire1=0, victoire2=0; ///Booleen de victoire
    int cuty=25, crty=15, dety=12, smty=10; ///Nombres qui servent a savoir le max de chaque bateau
    int touche=0; ///Presser entr�e pour passer de joueur
    int choixsave=0; ///Menu de la sauvegarde
    int testsave=0; ///Savoir si une partie a �t� sauvegard�e
    ///Declaration des valeurs pour compter le temps
    clock_t start1, end1,start2,end2;
    double Ttour1=0, Ttour2=0;
    double Ttotal1=0, Ttotal2=0;
    ///Initialisation du srand
    srand(time(NULL));
    color(15,0);
    while(choix != 4)
    {
        while(choix < 1 || choix > 4) ///Menu Principal
        {
            system("cls");
            printf("Bienvenue dans la bataille navale\n1. Jouer une partie : joueur 1 vs joueur 2 ou joueur vs ordinateur\n2. Regles\n3. Charger une partie \n4. Quitter\n");
            choix=saisie();
            fflush(stdin);
            printf("%d",choix);
        }
        switch(choix)
        {
        case 1:
        {
            do ///2eme menu
            {
                system("cls");
                printf("Vous souhaitez jouer:\n1. 2 joueurs\n2. 1 joueur vs l'IA\n");
                choixjeu=saisie();
                fflush(stdin);
            }
            while(choixjeu > 2 || choixjeu < 1);
            switch(choixjeu)
            {
            case 1: ///Jeu a 2 joueurs
            {
                system("cls");
                printf("Vous avez choisi de jouer a 2 joueurs\n");
                if(testsave == 0)
                {
                    do
                    {
                        printf("Saississez la taille du plateau de jeu comprise entre 10 et 40\n");
                        taille=saisie();
                        fflush(stdin);
                        system("cls");
                    }
                    while(taille < 10 || taille > 50);
                    ///Declaration des tableaux
                    tab1 = calloc(taille, sizeof(int*));
                    tab2 = calloc(taille, sizeof(int*));
                    tab3 = calloc(taille, sizeof(int*));
                    tab4 = calloc(taille, sizeof(int*));
                    for (i = 0 ; i < taille ; i++)
                    {
                        tab1[i] = calloc(taille, sizeof(int));
                        tab2[i] = calloc(taille, sizeof(int));
                        tab3[i] = calloc(taille, sizeof(int));
                        tab4[i] = calloc(taille, sizeof(int));
                    }
                    system("cls");
                    do
                    {
                        ///Recuperation du nombre de bateau
                        printf("Donnez le nombre de cuirasse\n");
                        nbcu=nbbateau(taille,cuty);
                        system("cls");
                        printf("Donnez le nombre de croiseur\n");
                        nbcr=nbbateau(taille,crty);
                        system("cls");
                        printf("Donnez le nombre de destroyer\n");
                        nbde=nbbateau(taille,dety);
                        system("cls");
                        printf("Donnez le nombre de sous-marin\n");
                        nbsm=nbbateau(taille,smty);
                    }
                    while(nbcu+nbcr+nbde+nbsm == 0);
                    ///Declaration des structures ded bateaux
                    cuirasse1 = malloc(nbcu * sizeof(t_bateau));
                    cuirasse2 = malloc(nbcu * sizeof(t_bateau));
                    croiseur1 = malloc(nbcr * sizeof(t_bateau));
                    croiseur2 = malloc(nbcr * sizeof(t_bateau));
                    destroyer1 = malloc(nbde * sizeof(t_bateau));
                    destroyer2 = malloc(nbde * sizeof(t_bateau));
                    sousm1 = malloc(nbsm * sizeof(t_bateau));
                    sousm2 = malloc(nbsm * sizeof(t_bateau));
                    Initdonneb(nbcu, nbcr, nbde,nbsm, cuirasse1, croiseur1, destroyer1, sousm1);
                    Initdonneb(nbcu, nbcr, nbde,nbsm, cuirasse2, croiseur2, destroyer2, sousm2);
                    ///Placement des bateaux du joueur 1
                    InitBateaux(taille,tab1,nbcu,cuirasse1);
                    InitBateaux(taille,tab1,nbcr,croiseur1);
                    InitBateaux(taille,tab1,nbde,destroyer1);
                    InitBateaux(taille,tab1,nbsm,sousm1);
                    ///Placement des bateaux du joueur 2
                    InitBateaux(taille,tab3,nbcu,cuirasse2);
                    InitBateaux(taille,tab3,nbcr,croiseur2);
                    InitBateaux(taille,tab3,nbde,destroyer2);
                    InitBateaux(taille,tab3,nbsm,sousm2);
                }
                while(victoire1 ==  0 && victoire2 == 0) ///Boucle de jeu � 2 joueurs humains
                {
                    start1 = clock();
                    while(tour%2==0)
                    {
                        ///Tour du joueur 1
                        do
                        {
                            Affichage(taille,tab1,tab2);
                            printf("J1: Que souhaitez vous faire ?\n 1.Tirer \n 2.Deplacer un bateau\n 3.Aide\n 4.Sauvegarder la partie\n");
                            choixtour=saisie();
                            fflush(stdin);
                        }
                        while(choixtour < 1 || choixtour > 5);
                        switch(choixtour)
                        {
                        case 1: ///Tirer
                        {
                            tour++;
                            Tir(taille, tab1,tab2,tab3,nbcu,nbcr,nbde,nbsm,destroyer1,&tour);
                            couler(taille,tab3,cuirasse2,nbcu);
                            couler(taille,tab3,croiseur2,nbcr);
                            couler(taille,tab3,destroyer2,nbde);
                            couler(taille,tab3,sousm2,nbsm);
                            victoire1 = victoire(taille, tab3);
                            break;
                        }
                        case 2: ///Deplacement
                        {
                            do
                            {
                                Affichage(taille,tab1,tab2);
                                printf("Saisissez les coordonnees du bateau a deplacer\n");
                                x=saisie();
                                y=saisie();
                                x--;
                                y--;

                            }
                            while(x < 0 || x > taille || y < 0 || y > taille);

                            if(tab1[x][y]==1)
                                Deplacement(taille,tab1,tab2,nbcu,cuirasse1,x,y,&tour);
                            if(tab1[x][y]==2)
                                Deplacement(taille,tab1,tab2,nbcr,croiseur1,x,y,&tour);
                            if(tab1[x][y]==3)
                                Deplacement(taille,tab1,tab2,nbde,destroyer1,x,y,&tour);
                            if(tab1[x][y]==4)
                                Deplacementsm(taille,tab1,tab2,nbsm,sousm1,x,y, &tour);
                            break;
                        }
                        case 3: ///Aide
                        {
                            Aide(taille,tab1,tab2);
                            Sleep(5000);
                            Affichage(taille,tab1,tab2);
                            break;
                        }
                        case 4: ///Sauvegarde de partie
                        {
                            system("cls");
                            Affichage(taille,tab1,tab2);
                            printf("\n Votre partie a ete sauvegarde\n Souhaitez-vous quitter le programme ?\n 1. Oui\n 2. Non\n");
                            Save(nbcr,nbcu,nbde,nbsm,taille,tour,cuirasse1,croiseur1,destroyer1,sousm1,cuirasse2,croiseur2,destroyer2,sousm2, tab1,tab2,tab3,tab4);
                            do
                            {
                                choixsave=saisie();
                                fflush(stdin);
                            }
                            while(choixsave < 1 || choixsave > 2);
                            if(choixsave==1)
                                exit(0);
                            break;
                        }
                        }
                    }
                    end1=clock();
                    Ttour1 = ((double)end1 - start1) / CLOCKS_PER_SEC;
                    Ttotal1 += Ttour1;
                    ///Passage au tour du 2nd joueur
                    do
                    {
                        system("cls");
                        printf("Vous avez prit %.2f secondes pour votre tour\n",Ttour1);
                        printf("Appuyer sur espace pour passer au deuxieme joueur !\n");
                        touche=getch();
                    }
                    while(touche != ' ');
                    start2 = clock();
                    fflush(stdin);
                    while(tour%2==1 && victoire1 == 0)
                    {
                        ///Tour du joueur 2
                        printf("Au tour du joueur 2\n");
                        do
                        {
                            Affichage(taille,tab3,tab4);
                            printf("J2: Que souhaitez vous faire ?\n 1.Tirer \n 2.Deplacer un bateau\n 3.Aide\n 4.Sauvegarder la partie\n");
                            choixtour=saisie();
                            fflush(stdin);
                        }
                        while(choixtour < 1 || choixtour > 4);
                        switch(choixtour)
                        {
                        case 1: ///Tir 2 eme joueur
                        {
                            tour++;
                            Tir(taille, tab3,tab4,tab1,nbcu,nbcr,nbde,nbsm,destroyer2,&tour);
                            couler(taille,tab1,cuirasse1,nbcu);
                            couler(taille,tab1,croiseur1,nbcr);
                            couler(taille,tab1,destroyer1,nbde);
                            couler(taille,tab1,sousm1,nbsm);
                            victoire2 = victoire(taille, tab1);
                            break;
                        }
                        case 2: ///Deplacement 2eme joueur
                        {
                            do
                            {
                                Affichage(taille,tab3,tab4);
                                printf("Saisissez les coordonnees du bateau a deplacer\n");
                                x=saisie();
                                fflush(stdin);
                                y=saisie();
                                fflush(stdin);
                                x--;
                                y--;
                            }
                            while(x < 0 || x > taille || y < 0 || y > taille);

                            if(tab3[x][y]==1)
                                Deplacement(taille,tab3,tab4,nbcu,cuirasse2,x,y,&tour);
                            if(tab3[x][y]==2)
                                Deplacement(taille,tab3,tab4,nbcr,croiseur2,x,y,&tour);
                            if(tab3[x][y]==3)
                                Deplacement(taille,tab3,tab4,nbde,destroyer2,x,y,&tour);
                            if(tab3[x][y]==4)
                                Deplacementsm(taille,tab3,tab4,nbsm,sousm2,x,y,&tour);
                            break;
                        }
                        case 3: /// Aide 2eme joueur
                        {
                            Aide(taille,tab3,tab4);
                            Sleep(5000);
                            break;
                        }
                        case 4: /// Sauvegarde au tour du 2eme joueur
                        {
                            system("cls");
                            printf("\n Votre partie a ete sauvegarde\n Souhaitez-vous quitter le programme ?\n 1. Oui\n 2. Non\n");
                            Save(nbcr,nbcu,nbde,nbsm,taille,tour,cuirasse1,croiseur1,destroyer1,sousm1,cuirasse2,croiseur2,destroyer2,sousm2, tab1,tab2,tab3,tab4);
                            do
                            {
                                choixsave=saisie();
                                fflush(stdin);
                            }
                            while(choixsave < 1 || choixsave > 2);
                            if(choixsave==1)
                                exit(0);
                            break;
                        }
                        }
                    }
                    /// Calcul du temps d'un tour
                    end2=clock();
                    Ttour2 = ((double)end2 - start2) / CLOCKS_PER_SEC;
                    Ttotal2 += Ttour2;
                    do
                    {
                        system("cls");
                        printf("Vous avez prit %.2f secondes pour votre tour\n",Ttour2);
                        printf("Appuyer sur espace pour passer au premier joueur !\n");
                        touche=getch();
                    }
                    while(touche != ' ');

                }
                ///Liberation des emplacements memoire si un joueur gagne
                if(victoire1 !=0 || victoire2 !=0)
                {
                    free(tab1);
                    free(tab2);
                    free(tab3);
                    free(tab4);
                    free(cuirasse1);
                    free(cuirasse2);
                    free(croiseur1);
                    free(croiseur2);
                    free(destroyer1);
                    free(destroyer2);
                    free(sousm1);
                    free(sousm2);
                    testsave=0;
                    choix=0;
                    ///Message de victoire
                    if(victoire1 != 0)
                    {
                        color(12,0);
                        printf("Le joueur 1 a gagner en %.2f secondes!!\n",Ttotal1);
                        color(15,0);
                        Sleep(5000);
                    }
                    if(victoire2 != 0)
                    {
                        color(12,0);
                        printf("Le joueur 2 a gagner en %.2f secondes !!\n",Ttotal2);
                        color(15,0);
                        Sleep(5000);
                    }
                    victoire1=0;
                    victoire2=0;
                }
                break;
            }
            case 2: ///Jeu a 1 joueur
            {

                system("cls");
                printf("Vous avez choisi de jouer avec l'ordinateur\n");
                if (testsave == 0)
                {
                    do
                    {
                        printf("Saississez la taille du plateau de jeu comprise entre 10 et 40\n");
                        taille=saisie();
                        fflush(stdin);
                        system("cls");
                    }
                    while(taille < 10 || taille > 40);
                    tab1 = calloc(taille, sizeof(int*));
                    tab2 = calloc(taille, sizeof(int*));
                    tab3 = calloc(taille, sizeof(int*));
                    tab4 = calloc(taille, sizeof(int*));
                    for (i = 0 ; i < taille ; i++)
                    {
                        tab1[i] = calloc(taille, sizeof(int));
                        tab2[i] = calloc(taille, sizeof(int));
                        tab3[i] = calloc(taille, sizeof(int));
                        tab4[i] = calloc(taille, sizeof(int));
                    }
                    do
                    {
                        system("cls");
                        printf("Donnez le nombre de cuirasse\n");
                        nbcu=nbbateau(taille, cuty);
                        system("cls");
                        printf("Donnez le nombre de croiseur\n");
                        nbcr=nbbateau(taille, crty);
                        system("cls");
                        printf("Donnez le nombre de destroyer\n");
                        nbde=nbbateau(taille, dety);
                        system("cls");
                        printf("Donnez le nombre de sous-marin\n");
                        nbsm=nbbateau(taille,smty);
                    }
                    while(nbcu+nbcr+nbde+nbsm == 0);
                    cuirasse1 = malloc(nbcu * sizeof(t_bateau));
                    cuirasse2 = malloc(nbcu * sizeof(t_bateau));
                    croiseur1 = malloc(nbcr * sizeof(t_bateau));
                    croiseur2 = malloc(nbcr * sizeof(t_bateau));
                    destroyer1 = malloc(nbde * sizeof(t_bateau));
                    destroyer2 = malloc(nbde * sizeof(t_bateau));
                    sousm1 = malloc(nbsm * sizeof(t_bateau));
                    sousm2 = malloc(nbsm * sizeof(t_bateau));
                    Initdonneb(nbcu, nbcr, nbde,nbsm, cuirasse1, croiseur1, destroyer1, sousm1);
                    Initdonneb(nbcu, nbcr, nbde,nbsm, cuirasse2, croiseur2, destroyer2, sousm2);
                    ///Placement des bateaux du joueur 1
                    InitBateaux(taille,tab1,nbcu,cuirasse1);
                    InitBateaux(taille,tab1,nbcr,croiseur1);
                    InitBateaux(taille,tab1,nbde,destroyer1);
                    InitBateaux(taille,tab1,nbsm,sousm1);
                    ///Placement des bateaux du joueur 2
                    InitBateaux(taille,tab3,nbcu,cuirasse2);
                    InitBateaux(taille,tab3,nbcr,croiseur2);
                    InitBateaux(taille,tab3,nbde,destroyer2);
                    InitBateaux(taille,tab3,nbsm,sousm2);
                }
                while(victoire1 ==  0 && victoire2 == 0) ///Boucle de jeu � 1 joueur + IA
                {
                    Affichage(taille,tab1,tab2);
                    while(tour%2==0)
                    {
                        ///Tour du joueur 1

                        printf("Au tour du joueur 1\n");
                        fflush(stdin);
                        do
                        {
                            Affichage(taille,tab1,tab2);
                            printf("Que souhaitez vous faire ?\n 1.Tirer \n 2.Deplacer un bateau\n 3.Aide\n 4.Sauvegarder la partie\n");
                            choixtour=saisie();
                            fflush(stdin);
                        }
                        while(choixtour < 1 || choixtour > 4);
                        switch(choixtour)
                        {
                        case 1: ///Tir
                        {
                            tour++;
                            Tir(taille, tab1,tab2,tab3,nbcu,nbcr,nbde,nbsm,destroyer1,&tour);
                            couler(taille,tab3,cuirasse2,nbcu);
                            couler(taille,tab3,croiseur2,nbcr);
                            couler(taille,tab3,destroyer2,nbde);
                            couler(taille,tab3,sousm2,nbsm);
                            victoire1 = victoire(taille, tab3);
                            break;
                        }
                        case 2: ///Deplacement
                        {
                            do
                            {
                                Affichage(taille,tab1,tab2);
                                printf("Saisissez les coordonnees du bateau a deplacer\n");
                                x=saisie();
                                fflush(stdin);
                                y=saisie();
                                fflush(stdin);
                                x--;
                                y--;

                            }
                            while(x < 0 || x > taille || y < 0 || y > taille);

                            if(tab1[x][y]==1)
                                Deplacement(taille,tab1,tab2,nbcu,cuirasse1,x,y,&tour);
                            if(tab1[x][y]==2)
                                Deplacement(taille,tab1,tab2,nbcr,croiseur1,x,y,&tour);
                            if(tab1[x][y]==3)
                                Deplacement(taille,tab1,tab2,nbde,destroyer1,x,y,&tour);
                            if(tab1[x][y]==4)
                                Deplacementsm(taille,tab1,tab2,nbsm,sousm1,x,y, &tour);
                            break;
                        }

                        case 3: ///Aide
                        {
                            Aide(taille,tab1,tab2);
                            Sleep(5000);
                            Affichage(taille,tab1,tab2);
                            break;
                        }
                        case 4: ///Sauvegarde
                        {
                            system("cls");
                            Affichage(taille,tab1,tab2);
                            printf("\n Votre partie a ete sauvegarde\n Souhaitez-vous quitter le programme ?\n 1. Oui\n 2. Non\n");
                            Save(nbcr,nbcu,nbde,nbsm,taille,tour,cuirasse1,croiseur1,destroyer1,sousm1,cuirasse2,croiseur2,destroyer2,sousm2, tab1,tab2,tab3,tab4);
                            do
                            {
                                choixsave=saisie();
                                fflush(stdin);
                            }
                            while(choixsave < 1 || choixsave > 2);
                            if(choixsave==1)
                                exit(0);
                            break;
                        }
                        }
                    }
                    Affichage(taille,tab3,tab4);
                    while(tour%2==1 && victoire1 == 0)
                    {
                        ///Tour de l'IA
                        tour++;
                        TirIA(taille, tab3,tab4,tab1,nbcu,nbcr,nbde,nbsm,cuirasse1);
                        couler(taille,tab1,cuirasse1,nbcu);
                        couler(taille,tab1,croiseur1,nbcr);
                        couler(taille,tab1,destroyer1,nbde);
                        couler(taille,tab1,sousm1,nbsm);
                        victoire2 = victoire(taille, tab1);
                    }
                }
                if(victoire1 !=0 || victoire2 !=0) ///Liberation de la m�moire � la fin du programme
                {
                    free(tab1);
                    free(tab2);
                    free(tab3);
                    free(tab4);
                    free(cuirasse1);
                    free(cuirasse2);
                    free(croiseur1);
                    free(croiseur2);
                    free(destroyer1);
                    free(destroyer2);
                    free(sousm1);
                    free(sousm2);
                    testsave=0;
                    choix=0;
                    ///Message de victoire
                    if(victoire1 != 0)
                    {
                        color(12,0);
                        printf("Le joueur 1 a gagner !!\n");
                        color(15,0);
                        Sleep(5000);
                    }
                    if(victoire2 != 0)
                    {
                        color(12,0);
                        printf("Le joueur 2 a gagner !!\n");
                        color(15,0);
                        Sleep(5000);
                    }
                    victoire1=0;
                    victoire2=0;
                }

                break;

            }

            }
            break;
        }
        case 2: ///Regles
        {
            do
            {
                system("cls");
                printf("L'objectif est de detruire tous les bateaux adverses\n");
                printf("A chaque tour vous avez le choix entre :\n 1.Tirer sur les bateaux adverses a l'aide de l'un de vos bateaux\n 2.Deplacer un bateau de votre choix horizontalement ou verticalement\n\n");
                printf("Un bateau touche ne peut pas se deplacer\n");
                printf("Les sous-marins ne peuvent etre touche que par les sous-marins\n");
                printf("La taille du plateau et le nombre de bateau sont reglables\n");
                printf("La partie peut-etre sauvegardee pour etre jouee plus tard\n");
                tp(1,80);
                printf("Puissance de tir des navires\n");
                tp(2,82);
                printf("Cuirasse : carre de 3*3");
                tp(3,82);
                printf("Croiseur : croix de 3*3");
                tp(4,82);
                printf("Destroyer : Premier tir de ce bateau est une fusee eclairante qui devoile une zone de 4*4");
                tp(5,94);
                printf("de la grille adverse pendant un court instant");
                tp(6,94);
                printf("Les tirs suivant ne font des degats que sur une seule case");
                tp(7,82);
                printf("Sous-marin : Les tirs n'ont qu'une seule case de degat");
                tp(8,95);
                printf("Mais seul un sous-marin peut toucher un sous-marin");
                tp(20,0);
                printf("Appuyez sur espace pour revenir au menu");
                touche=getch();
            }
            while(touche != ' ');
            choix=0;
            break;
        }
        case 3: ///Chargement d'une partie
        {
            system("cls");
            printf("Vous chargez une partie sauvegardee precedement\n");
            testsave=LoadInit(&nbcu,&nbcr,&nbde,&nbsm,&taille,&tour);
            if (testsave == 0)
            {
                printf("Aucune partie n'est sauvegardee...\n");
                Sleep(3000);
                break;
            }
            Sleep(3000);
            tab1 = calloc(taille, sizeof(int*));
            tab2 = calloc(taille, sizeof(int*));
            tab3 = calloc(taille, sizeof(int*));
            tab4 = calloc(taille, sizeof(int*));
            i=0;
            for (i = 0 ; i < taille ; i++)
            {
                tab1[i] = calloc(taille, sizeof(int));
                tab2[i] = calloc(taille, sizeof(int));
                tab3[i] = calloc(taille, sizeof(int));
                tab4[i] = calloc(taille, sizeof(int));
            }
            cuirasse1 = malloc(nbcu * sizeof(t_bateau));
            cuirasse2 = malloc(nbcu * sizeof(t_bateau));
            croiseur1 = malloc(nbcr * sizeof(t_bateau));
            croiseur2 = malloc(nbcr * sizeof(t_bateau));
            destroyer1 = malloc(nbde * sizeof(t_bateau));
            destroyer2 = malloc(nbde * sizeof(t_bateau));
            sousm1 = malloc(nbsm * sizeof(t_bateau));
            sousm2 = malloc(nbsm * sizeof(t_bateau));
            LoadAll(nbcu,nbcr,nbde,nbsm,taille,&tour,cuirasse1,croiseur1,destroyer1,sousm1,cuirasse2,croiseur2,destroyer2,sousm2,tab1,tab2,tab3,tab4);
            choix=1;
            testsave=1;
            break;

        }
        case 4: ///Quitter le jeu
        {
            printf("Vous avez choisi de quitter\n");
            break;
        }
        }
    }
    return 0;
}
