#include "biblio.h"

///Source Openclassroom

void purger(void) ///Enleve le \n qui apparait � la fin de fgets
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {}
}

void clean (char *chaine)
{
    char *p = strchr(chaine, '\n');

    if (p)
    {
        *p = 0;
    }

    else
    {
        purger();
    }
}
int saisie()
{
    int nombre=0;
    char chaine[20];
    fgets(chaine, sizeof chaine, stdin);
    clean(chaine);
    sscanf(chaine, "%d", &nombre);
    return nombre;
}
