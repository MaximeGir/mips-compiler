/*
 *
 * @author : Maxime Girard 
 * @CodePermanent : GIRM30058500
 *
 */

#include <stdlib.h>
#include <stdio.h>

#include "argument.h"
#include "parser.h"
#include "writer.h"

int main(int argc, char * args[]){
 FILE *fichier = fopen(args[1], "r");
 
 //Validation 
 if(fichier == NULL) {
	 printf("Fichier inexistant, réessayé avec un fichier valide.\n");
	 return EXIT_FAILURE;
 }

 if(!valider_nom_fichier(args[1])){
  	 printf("Fichier invalide, l'extension devrait être '.mips'\n");
	 return EXIT_FAILURE;
 }

 if(!valider_nombre_argument(argc)) return EXIT_FAILURE;
  
  //Debug printf
  printf("working so far!\n");
  return EXIT_SUCCESS;
}