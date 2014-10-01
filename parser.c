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
#include <string.h>
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
  int rd;
  int rs;
  int rt;
  int opcode;
  int funct;
  int shamt;
  uint32_t ligne_binaire = 0;
  char line[256];

  while(fgets(line, sizeof(line), fichier)){
   //printf("Ligne entre dans parseLignesMips %sx \n",line);
   
   char * mnemonic = trouverMnemonic(line);

   //printf("mnemonic revenu de trouverMnemonic : %s\n", mnemonic);
   //printf("Ligne apres avoir trovuer mnemonic %s\n", line);
   char * sline = strcpy(malloc(sizeof(line)), line+strlen(mnemonic));

   char type_instruction = dictionnaireType(mnemonic);
   
   //printf("sline apres avooir ete copier de ligne : %s\n", sline);
   
   if(type_instruction == 'R'){
     char * inst = strtok(sline," ,");
     rd = dictionnaireRegistre(inst);
     //printf("premier token %s\n",inst);

     inst = strtok(NULL, ",");
     rs = dictionnaireRegistre(inst);
     //printf("deuxieme token %s\n",inst);

     inst = strtok(NULL, "\n");
     rt = dictionnaireRegistre(inst); 
     //printf("dernier token %s\n",inst);

     funct = dictionnaireFunction(mnemonic);
     opcode = 0;
     shamt = 0;

     printf("opcode %d | rs %d | rt %d | rd %d | shamt | funct %d \n", opcode, rs, rt, rd, funct);
    
   }

  if(type_instruction == 'I'){
     printf("type i\n");
   }

  if(type_instruction == 'J'){
     printf("type j\n");
   }
   free(sline);

 }
}

char * trouverMnemonic(char * ligne){
   char * ligneCopie = strcpy(malloc(sizeof(ligne)), ligne);
   char * mnemonic = strcpy(malloc(5),strtok(ligneCopie, " "));
   //printf("ligne trouverMnemonic : %s, mnemonic : %s\n", ligne, mnemonic);
   return mnemonic;
}

uint32_t conversionInstruction(char * ligne, char type){
	uint32_t ligne_binaire = 0;
  setOpCodeBit(ligne, type, &ligne_binaire);
  setOtherBit(ligne, &ligne_binaire);  
  return ligne_binaire; 
}



















void setOpCodeBit(char * ligne, char type, uint32_t *ligne_binaire){
	if(type == 'R'){
	  int i;
      for(i = 0; i < 5; i++){
        *ligne_binaire |= (0 << (31-5-i));
	    }
    }
  if(type == 'I'){
     
  }

  if(type == 'J'){

  }
}

void setOtherBit(char * ligne, uint32_t * ligne_binaire){
  printf("%d :: %s \n", *ligne_binaire, ligne);
}
