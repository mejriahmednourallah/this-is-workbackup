#ifndef ETS_H_INCLUDED
#define ETS_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>
typedef struct
{
    char nom_ets[20];
    char id_ets[20];
    char administrateur_ets[20];
    char region_ets[20];
    int capacite_ets;
}ets;
void supprimer_ets(ets e);
void ajouter_ets(ets e);
void afficher_ets(GtkWidget *liste);
int ETSparregion(char tempfiles[], char reg[]);
#endif
