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

void parseLignesMips(FILE * fichier, FILE * fichier_ecriture){
  uint32_t ligne_binaire = 0;
  char line[256];
  while(fgets(line, sizeof(line), fichier)){ 	
   char type = trouverTypeInstruction(line);
   ligne_binaire = conversionInstruction(line, type);
   
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
	if(type == 'R'){
       
	}
	if(type == 'I'){

	}
	if(type == 'J'){	

	}
	return 0;
}



//
//for (Line line : fichier) 
//- binaryLine = parseToBinary(line);
//- writeLineInFile(binaryLine);
//  


 // Type d'instructions
 //
 // R-Type:
 // add
 // addu
 // and
 // jr
 // nor
 // or
 // sll
 // slt
 // sltu
 // srl
 // sub
 // subu
 //
 // I-Type:
 // addi
 // addiu
 // andi
 // beq
 // bne
 // lb
 // lbu
 // lh
 // lhu
 // lui
 // lw
 // ori
 // sb
 // sh
 // slti
 // sltiu
 // sw
 //
 // J-Type:
 // j
 // jal
 //


