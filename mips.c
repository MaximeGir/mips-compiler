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
 if(fichier == NULL) {
	 printf("Fichier inexistant, réessayé avec un fichier valide.\n");
	 return EXIT_FAILURE;
 }
 if(!valider_nom_fichier(args[1]) && !valider_nombre_argument(argc)) return EXIT_FAILURE;  
 
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

 printf("VALIDATION PASSED\n");
 return EXIT_SUCCESS;
}
