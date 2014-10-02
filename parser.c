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

void parseLignesMips(FILE * fichier, FILE * fichier_ecriture){
  int rd;
  int rs;
  int rt;
  int immediate;
  int opcode;
  int funct;
  int shamt;
  int ligne_binaire = 0;
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
     ligne_binaire = conversionEnBinaire(type_instruction, opcode, rs, rt, rd, immediate, funct, shamt);
     ecrireLigne(ligne_binaire, fichier_ecriture);
   }

  if(type_instruction == 'I'){
     int adresse_immediate = 0;
     int multi;

     if(dictionnaireValeurImmediate(mnemonic)) adresse_immediate = 1; 
     if(!adresse_immediate){
      char * inst = strtok(sline," ,");
      rt = dictionnaireRegistre(inst);
      inst = strtok(NULL, ",");
      rs = dictionnaireRegistre(inst); 
      inst = strtok(NULL, "\n");
      immediate = trouverValeurImmediate(inst, adresse_immediate, 0);
      opcode = dictionnaireOpCode(mnemonic); 
      ligne_binaire = conversionEnBinaire(type_instruction, opcode, rs, rt, rd, immediate, funct, shamt);
      ecrireLigne(ligne_binaire, fichier_ecriture);
     } else {
         char * inst = strtok(sline," ,");
         rt = dictionnaireRegistre(inst);
         inst = strtok(NULL, "\n");
          
         rs = trouverValeurImmediate(inst, adresse_immediate, &multi);
         opcode = dictionnaireOpCode(mnemonic); 
         immediate = multi;
         ligne_binaire = conversionEnBinaire(type_instruction, opcode, rs, rt, rd, immediate, funct, shamt);
         ecrireLigne(ligne_binaire, fichier_ecriture);
     }
   }
  
  if(type_instruction == 'J'){
    //non-implémenté
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

uint32_t conversionEnBinaire(char type, int opcode, int rs, int rt, int rd, int immediate, int funct, int shamt){
  uint32_t ligne_binaire = 0;
  int k;
  
  if(type == 'R'){
    //opcode sur 6 bits
    for(k = 6; k > 0; k--, opcode >>= 1){
     if(opcode & 1) ligne_binaire |= 1 << (32-k);
     else ligne_binaire |= 0 << (32-k);
    }
    
    //rs sur 5 bits
    for(k = 5; k > 0; k--, rs >>= 1){
     if(rs & 1) ligne_binaire |= 1 << (26-k);
     else ligne_binaire |= 0 << (26-k);
    }    

    //rt sur 5 bits
    for(k = 5; k > 0; k--, rt >>= 1){
     if(rt & 1) ligne_binaire |= 1 << (21-k);
     else ligne_binaire |= 0 << (21-k);
    } 

    //rd sur 5 bits
    for(k = 5; k > 0; k--, rd >>= 1){
     if(rd & 1) ligne_binaire |= 1 << (16-k);
     else ligne_binaire |= 0 << (16-k);
    }   

    //shamt sur 5 bits
    for(k = 5; k > 0; k--, shamt >>= 1){
     if(shamt & 1) ligne_binaire |= 1 << (11-k);
     else ligne_binaire |= 0 << (11-k);
    }   

    //funct sur 6 bits
    for(k = 6; k > 0; k--, funct >>= 1){
     if(funct & 1) ligne_binaire |= 1 << (6-k);
     else ligne_binaire |= 0 << (6-k);
    }
    return ligne_binaire; 
  }
  
  else if(type == 'I'){
    //opcode sur 6 bits
    for(k = 6; k > 0; k--, opcode >>= 1){
     if(opcode & 1) ligne_binaire |= 1 << (32-k);
     else ligne_binaire |= 0 << (32-k);
    }
    //rs sur 5 bits
    for(k = 5; k > 0; k--, rs >>= 1){
     if(rs & 1) ligne_binaire |= 1 << (26-k);
     else ligne_binaire |= 0 << (26-k);
    }
    //rt sur 5 bits
    for(k = 5; k > 0; k--, rt >>= 1){
     if(rt & 1) ligne_binaire |= 1 << (21-k);
     else ligne_binaire |= 0 << (21-k);
    }
    //immediate sur 6 bits
    for(k = 16; k > 0; k--, immediate >>= 1){
     if(immediate & 1) ligne_binaire |= 1 << (16-k);
     else ligne_binaire |= 0 << (16-k);
    }
    return ligne_binaire; 
  }
  
  else if(type == 'J'){ 
    //non implémenté
    return ligne_binaire; 
  }
  
  return -1;
}