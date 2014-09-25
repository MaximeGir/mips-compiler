/*
 *
 * @author : Maxime Girard 
 * @CodePermanent : GIRM30058500
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "argument.h"
#include "parser.h"
#include "writer.h"

int main(int argc, char * args[]){

//Validation ouverture fichier
 FILE *fichier = fopen(args[1], "r");
 if(fichier == NULL) {
	 printf("Fichier inexistant, réessayé avec un fichier valide.\n");
	 return EXIT_FAILURE;
 }
 //Validation arguments
 if(!valider_nom_fichier(args[1]) && !valider_nombre_argument(argc)) return EXIT_FAILURE;

 char * nom_fichier_ecriture = genererNomFichier(args[1]);
 FILE * fichier_ecriture = ouvrirFichierEcriture(nom_fichier_ecriture);
 parseLignesMips(fichier, fichier_ecriture);
 
 fclose(fichier);
 fclose(fichier_ecriture);

 return EXIT_SUCCESS;
}
