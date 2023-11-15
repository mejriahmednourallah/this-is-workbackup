#include "ets.h"
#include <gtk/gtk.h>
enum
{
ID,
NOM,
ADMINISTRATEUR,
REGION,
CAPACITE,
COLUMNS
};


void ajouter_ets(ets e) {
    FILE *f = fopen("etablissement.txt", "a+");
    if (f != NULL) {
        fprintf(f, "%s %s %s %s %d\n", e.id_ets, e.nom_ets, e.administrateur_ets, e.region_ets, e.capacite_ets);
        fclose(f);
    }
}
void afficher_ets(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

    ets current_ets;
    store = NULL;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" ID", renderer, "text", ID, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" Name", renderer, "text", NOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" Administrator", renderer, "text", ADMINISTRATEUR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" Region", renderer, "text", REGION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" Capacity", renderer, "text", CAPACITE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    }
    store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);
    f = fopen("etablissement.txt", "a+");
    if (f == NULL)
    {
        return;
    }
    else
    {
        while (fscanf(f, "%s %s %s %s %d\n", current_ets.id_ets, current_ets.nom_ets, current_ets.administrateur_ets, current_ets.region_ets, &current_ets.capacite_ets) != EOF)
        {
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, ID , current_ets.id_ets, NOM, current_ets.nom_ets, ADMINISTRATEUR, current_ets.administrateur_ets, REGION, current_ets.region_ets, CAPACITE, current_ets.capacite_ets, -1);
        }
    }
    fclose(f);
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);
}
void supprimer_ets(ets e)
{
    char nom[30];
    char id[30];
    char administrateur[30];
    char region[30];
    int capacite;

    FILE *f, *g;
    f = fopen("etablissement.txt", "r");
    g = fopen("dump.txt", "a");

    if (f == NULL || g == NULL)
    {
        return;
    }
    else
    {
        while (fscanf(f, "%s %s %s %s %d\n", id, nom, administrateur, region, &capacite) != EOF)
        {
            if (strcmp(e.id_ets, id) != 0 || strcmp(e.nom_ets, nom) != 0 || strcmp(e.administrateur_ets, administrateur) != 0 || strcmp(e.region_ets, region) != 0 || e.capacite_ets != capacite)
            {
                fprintf(g, "%s %s %s %s %d\n", id, nom, administrateur, region, capacite);
            }
        }
        fclose(f);
        fclose(g);
        remove("etablissement.txt");
        rename("dump.txt", "etablissement.txt");
    }
}
int ETSparregion(char tempfiles[],char reg[]) {
    FILE *file, *tempFile;
    ets current_ets;

    int nbr = 0;

    file = fopen("etablissement.txt", "r");
    tempFile = fopen(tempfiles, "a");

    if (file == NULL || tempFile == NULL) 
	{

        printf("Error opening file!\n");
        return -1;
    }

    while (fscanf(file, "%s %s %s %s %d", current_ets.nom_ets, current_ets.id_ets,
                  current_ets.administrateur_ets, current_ets.region_ets, &current_ets.capacite_ets) == 5) {

        				if (strcmp(current_ets.region_ets, reg) == 0) {
            				fprintf(tempFile, "%s %s %s %s %d\n", current_ets.nom_ets, current_ets.id_ets,
                   		 	current_ets.administrateur_ets, current_ets.region_ets, current_ets.capacite_ets);
           				nbr++;
     }
    }

    fclose(file);
    fclose(tempFile);

    return nbr;
}

