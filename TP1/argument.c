/*
 *
 * @author : Maxime Girard 
 * @CodePermanent : GIRM30058500
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "argument.h"

int valider_nombre_argument(int nombre_argument){
 if(nombre_argument > 2)
 {
  printf("Erreur : Ce programme fonctionne avec qu'un (1) seul fichier d'entré.\n");
  return 0; 
 }

 if(nombre_argument < 2) 
 {
  printf("Erreur : fichier manquant.\n");
  return 0;
 }
 return 1; 
}

int valider_nom_fichier(char *nom_fichier){
  char *extension = strrchr(nom_fichier, '.');
  if(extension != NULL && !strcmp(extension, ".mips")){
	return 1;
  }
  else {
      printf("Fichier invalide, l'extension devrait être '.mips'\n");
      return 0;
  }
  
}
