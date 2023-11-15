#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ets.h"

void
on_ets_list_afficher_row_activated (GtkTreeView *treeview, GtkTreePath *path, GtkTreeViewColumn *column, gpointer
user_data){
GtkTreeIter iter;
gchar* nom;
gchar* id ; 
gchar* administrateur;
gchar* region;
gint*  capacite;
ets e;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter, path)) 
{
//obtention des valeurs de la ligne selectionnée
gtk_tree_model_get (GTK_LIST_STORE (model), &iter, 0, &id, 1, &nom,2,&administrateur, 3, &region,4,&capacite,-1);
strcpy(e.id_ets,id);
strcpy(e.nom_ets,nom);
strcpy(e.administrateur_ets,administrateur);
strcpy(e.region_ets,region);
e.capacite_ets=capacite;
supprimer_ets(e);
afficher_ets(treeview);
}

}


void
on_button_ajout_ets_clicked     (GtkWidget  *objet , gpointer
user_data)
{
ets e;
GtkWidget *input1, *input2, *input3, *input4, *input5; 
GtkWidget *Administrateur;
Administrateur=lookup_widget(objet, "Administrateur");
input1=lookup_widget(objet, "entry_ets_ajouter_id");
input2=lookup_widget(objet, "entry_ets_ajouter_name");
input3=lookup_widget(objet, "entry_ets_ajouter_admis");
input4=lookup_widget(objet, "comboboxentry_ajout_ets"); 
input5=lookup_widget(objet, "spinbutton_ajout_ets");
strcpy(e.nom_ets, gtk_entry_get_text(GTK_ENTRY (input1))); 
strcpy(e.id_ets, gtk_entry_get_text(GTK_ENTRY (input2))); 
strcpy(e.administrateur_ets, gtk_entry_get_text(GTK_ENTRY (input3))); 
strcpy(e.region_ets, gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
e.capacite_ets=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
ajouter_ets (e);
}


void
on_button_afficher_ets_clicked         (GtkWidget
*objet,
gpointer
user_data){

GtkWidget *Administrateur;
GtkWidget *ets_list_afficher;
Administrateur=lookup_widget(objet, "Administrateur"); 
ets_list_afficher=lookup_widget(Administrateur, "ets_list_afficher");
afficher_ets(ets_list_afficher);
}

void
on_button_afficher_ets_region_clicked  (GtkWidget
*objet,
gpointer
user_data){
GtkWidget *Administrateur;
GtkWidget *treeview_par_region;
GtkWidget *input;
GtkWidget *output;
int nbr;
char *tempfile;
gchar nbr_region[30];
char *reg[20];
Administrateur=lookup_widget(objet, "Administrateur");
treeview_par_region=lookup_widget(Administrateur, "treeview_par_region");
input=lookup_widget(objet, "comboboxentry6"); 
output=lookup_widget(objet, "label_ets_region_nbr");
strcpy(reg, gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));
tempfile="temporaryregion.txt";
nbr=ETSparregion(tempfile,reg);
afficher_ets(treeview_par_region);
sprintf(nbr_region,"%d",nbr);
gtk_label_set(GTK_LABEL(output),nbr_region);
}

