#include<stdio.h>
#include <string.h>
#include "ets.h"
ets new_ets()
{
   ets new_ets;
    printf("Enter the name of the establishment: ");
    scanf("%s", new_ets.nom_ets);
    printf("Enter the id of the establishment: ");
    scanf("%s", new_ets.id_ets);
    printf("Enter the administrator of the establishment: ");
    scanf("%s", new_ets.administrateur_ets);
    printf("Enter the region of the establishment: ");
    scanf("%s", new_ets.region_ets);
    printf("Enter the capacity of the establishment: ");
    scanf("%d", &new_ets.capacite_ets);
    return new_ets;
}
int ajouter_ets(ets e)
{
    FILE *f = fopen("etablissment.txt", "a");
    if (f != NULL)
    {
        fprintf(f, "%s %s %s %s %d\n", e.nom_ets, e.id_ets, e.administrateur_ets, e.region_ets, e.capacite_ets);
        fclose(f);
        return 1;
    }
    else
        return 0;
}
int modifier_ets( char *id, ets temp)
{
    int done = 0;
    ets e;
    FILE *f = fopen("etablissment.txt", "r");
    FILE *f2 = fopen("temp.txt", "w");
    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%s %s %s %s %d\n", e.nom_ets, e.id_ets, e.administrateur_ets, e.region_ets, &e.capacite_ets) != EOF)
        {
            if (strcmp(e.id_ets, id) == 0)
            {
                fprintf(f2, "%s %s %s %s %d\n", temp.nom_ets, temp.id_ets, temp.administrateur_ets, temp.region_ets, temp.capacite_ets);
                done = 1;
            }
            else
                fprintf(f2, "%s %s %s %s %d\n", e.nom_ets, e.id_ets, e.administrateur_ets, e.region_ets, e.capacite_ets);
        }
    }
    fclose(f);
    fclose(f2);
    remove("etablissment.txt");
    rename("temp.txt", "etablissment.txt");
    return done;
}

int supprimer_ets( char *id)
{
    int found = 0;
    ets e;
    FILE *f = fopen("etablissment.txt", "r");
    FILE *f2 = fopen("temp.txt", "w");
    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%s %s %s %s %d\n", e.nom_ets, e.id_ets, e.administrateur_ets, e.region_ets, &e.capacite_ets) != EOF)
        {
            if (strcmp(e.id_ets, id) == 0)
                found = 1;
            else
                fprintf(f2, "%s %s %s %s %d\n", e.nom_ets, e.id_ets, e.administrateur_ets, e.region_ets, e.capacite_ets);
        }
    }
    fclose(f);
    fclose(f2);
    remove("etablissment.txt");
    rename("temp.txt", "etablissment.txt");
    return found;
}

ets chercher_ets( char *id)
{
    ets e;
    int found = 0;
    FILE *f = fopen("etablissment.txt", "r");
    if (f != NULL)
    {
        while (found == 0 && fscanf(f, "%s %s %s %s %d\n", e.nom_ets, e.id_ets, e.administrateur_ets, e.region_ets, &e.capacite_ets) != EOF)
        {
            if (strcmp(e.id_ets, id) == 0)
                found = 1;
        }
    }
    fclose(f);
    if (found == 0)
        strcpy(e.id_ets, "-1");
    return e;
}

