/*
 *
 * @author : Maxime Girard 
 * @CodePermanent : GIRM30058500
 *
 */

#include <stdlib.h>
#include <stdio.h>
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

int valider_ouverture_fichier(char * nom_fichier){
 if(fopen(nom_fichier, "r") == NULL) 
 {
  printf("Erreur : fichier non valide\n");
  return 0;
 }
 return 1;
}


