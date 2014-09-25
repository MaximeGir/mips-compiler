/*
 *
 * @author : Maxime Girard 
 * @CodePermanent : GIRM30058500
 *
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "writer.h"

char * genererNomFichier(char * nom_fichier){
  return strcat(nom_fichier, ".asm");
}

FILE * ouvrirFichierEcriture(char * nom_fichier){
  FILE * fichier = fopen(nom_fichier, "ab+");
  rewind(fichier);
  return fichier;
}

int ecrireLigne(uint32_t ligne, FILE * fichier){
  fwrite( &ligne, sizeof(uint32_t), 1, fichier);
  return 0;
}
