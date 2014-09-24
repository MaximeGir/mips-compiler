/*
 *
 * @author : Maxime Girard 
 * @CodePermanent : GIRM30058500
 *
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
#include "writer.h"

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


