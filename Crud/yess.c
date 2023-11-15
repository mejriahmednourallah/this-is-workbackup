#include <stdio.h>
#include <string.h>
#include "ets.h"
int main()
{
	int test;
	ets ETS1,temp;
	char id[20],id2[20],id3[20];	
	ETS1=create_ets();
	test=ajouter_ets(ETS1);
	if(test == 1) {
    		printf("\nadeed");}
	else{
    		printf("\nerreur");
	test=0;
	scanf("%s",id);	
	test=modifier_ets(id,temp);}
	if (test == 1){
    		printf("\nmodified");}
	else{
    		printf("\nerreur");
	test=0;
	scanf("%s",id2);	
	temp=chercher_ets(id2);}
	if (strcmp(temp.id_ets, "-1") != 0){
    		printf("\nfound");
		printf("%s %s %s %s %d\n", temp.nom_ets, temp.id_ets, temp.administrateur_ets, temp.region_ets, temp.capacite_ets);}
	else{
    	printf("\nerreur");
	scanf("%s",id3);	
	test=supprimer_ets(id3);}
	if (test == 1){
    		printf("\ndeleted");}
	else{
    		printf("\nerreur");}
	return 0;
}
	
	
