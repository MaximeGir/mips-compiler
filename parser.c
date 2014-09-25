/*
 *
 * @author : Maxime Girard 
 * @CodePermanent : GIRM30058500
 *
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include "parser.h"
#include "writer.h"
#include "dictionnaire.h"

char * toBinary(uint32_t n){
  size_t bits = sizeof(uint32_t) * 8;
  char * str = malloc(bits + 1);
  if(!str) return NULL;
  str[bits] = 0;
  for(; bits--; n >>= 1)
    str[bits] = n & 1 ? '1' : '0';
  return str;
}

void parseLignesMips(FILE * fichier, FILE * fichier_ecriture){
  uint32_t ligne_binaire = 0;
  char line[256];
  while(fgets(line, sizeof(line), fichier)){ 	
   char type = trouverTypeInstruction(line);
   ligne_binaire = conversionInstruction(line, type);
   printf("%s\n", toBinary(ligne_binaire));
  }
}

char trouverTypeInstruction(char * ligne){
	char * iterator = ligne;
	char * mot = malloc(256);
	char * depart_mot = mot;
	while(isspace(*iterator)) iterator++;
    while(!isspace(*iterator)){
     *mot = *(iterator++);
     mot++;
    }
    char type_instruction = dictionnaireType(depart_mot);
    return type_instruction;
}

uint32_t conversionInstruction(char * ligne, char type){
	uint32_t ligne_binaire = 0;
	if(type == 'R'){
       setOpCodeBit('R', &ligne_binaire);
       setOtherBit(ligne, &ligne_binaire);  
       return ligne_binaire; 
	}

	if(type == 'I'){

	}
	if(type == 'J'){	

	}
	return 0;
}

void setOpCodeBit(char type, uint32_t *ligne_binaire){
	if(type == 'R'){
	  int i;
      for(i = 0; i < 5; i++){
        *ligne_binaire |= (0 << (31-5-i));
	  }
    }
}

void setOtherBit(char * ligne, uint32_t * ligne_binaire){
  printf("%d :: %s \n", *ligne_binaire, ligne);
}