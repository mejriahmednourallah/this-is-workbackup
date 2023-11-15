#ifndef ETS_H_INCLUDED
#define ETS_H_INCLUDED
#include <stdio.h>
typedef struct
{
    char nom_ets[20];
    char id_ets[20];
    char administrateur_ets[20];
    char region_ets[20];
    int capacite_ets;
} ets;
ets new_ets();
int ajouter_ets(ets Ets);
int modifier_ets(char *id ,ets Ets);
int supprimer_ets(char *id);
ets chercher_ets(char *id);

#endif
