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
  int immediate;
  int opcode;
  int funct;
  int shamt;
  uint32_t ligne_binaire = 0;
  char line[256];

  while(fgets(line, sizeof(line), fichier)){
   char * mnemonic = trouverMnemonic(line);
   char * sline = strcpy(malloc(sizeof(line)), line+strlen(mnemonic));
   char type_instruction = dictionnaireType(mnemonic);
   
   if(type_instruction == 'R'){
     char * inst = strtok(sline," ,");
     rd = dictionnaireRegistre(inst);

     inst = strtok(NULL, ",");
     rs = dictionnaireRegistre(inst);

     inst = strtok(NULL, "\n");
     rt = dictionnaireRegistre(inst); 

     funct = dictionnaireFunction(mnemonic);
     opcode = 0;
     shamt = 0;
     printf("opcode %d | rs %d | rt %d | rd %d | shamt | funct %d \n", opcode, rs, rt, rd, funct); 
   }

  if(type_instruction == 'I'){

     int adresse_immediate = 0;
     int * multi;

     if(dictionnaireValeurImmediate(mnemonic)) adresse_immediate = 1; 
     if(!adresse_immediate){
      char * inst = strtok(sline," ,");
      rt = dictionnaireRegistre(inst);
      inst = strtok(NULL, ",");
      rs = dictionnaireRegistre(inst); 
      inst = strtok(NULL, "\n");
      immediate = trouverValeurImmediate(inst, adresse_immediate, 0);
      opcode = dictionnaireOpCode(mnemonic); 
      printf("opcode %d | rs %d | rt %d | immediate %d\n", opcode, rt, rt, immediate);
     } else {
         char * inst = strtok(sline," ,");
         rt = dictionnaireRegistre(inst);
         inst = strtok(NULL, "\n");
         int *multa = &multi; 
         rs = trouverValeurImmediate(inst, adresse_immediate, multa);
         opcode = dictionnaireOpCode(mnemonic); 
         immediate = *multa;
         printf("opcode %d | rs %d | rt %d | immediate %d\n", opcode, rs, rt, immediate);
     }
   }
  if(type_instruction == 'J'){
     printf("type j\n");
   }
   free(sline);
 }
}

int trouverValeurImmediate(char * mot, int adresse_immediate, int * multi ){
  if(adresse_immediate == 1){
    char * multiplicante = strtok(mot, "(");
    *multi = atoi(multiplicante);
    char * reste = strtok(NULL, ")");
    return dictionnaireRegistre(reste);
  } else {
    int valeur_immediate = atoi(mot);
    return valeur_immediate;
  }
}

char * trouverMnemonic(char * ligne){
   char * ligneCopie = strcpy(malloc(sizeof(ligne)), ligne);
   char * mnemonic = strcpy(malloc(5),strtok(ligneCopie, " "));
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
