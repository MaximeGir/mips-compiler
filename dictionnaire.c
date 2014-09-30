/*
 *
 * @author : Maxime Girard 
 * @CodePermanent : GIRM30058500
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionnaire.h"

char dictionnaireType(char * mot){
 if(!strcmp(mot, "addi") 
  	|| !strcmp(mot, "andi") 
    || !strcmp(mot, "lw") 
    || !strcmp(mot, "lb") 
    || !strcmp(mot, "lh") 
    || !strcmp(mot, "sw") 
    || !strcmp(mot, "sh") 
    || !strcmp(mot, "sb") 
    || !strcmp(mot, "ori")) 
 return 'I'; 

 if(!strcmp(mot, "add") 
  	|| !strcmp(mot, "sub") 
    || !strcmp(mot, "and") 
    || !strcmp(mot, "or" ) 
    || !strcmp(mot, "nor") ) 
 return 'R'; 
 else return 'J';
}

int dictionnaireOpCode(char * mot){
  if(!strcmp(mot, "addi")) return 0x08;
  if(!strcmp(mot, "andi")) return 0x0C;
  if(!strcmp(mot, "lw"))   return 0x23;
  if(!strcmp(mot, "lb"))   return 0x20;
  if(!strcmp(mot, "lh"))   return 0x21;
  if(!strcmp(mot, "sw"))   return 0x2B;
  if(!strcmp(mot, "sh"))   return 0x29;
  if(!strcmp(mot, "sb"))   return 0x28;
  if(!strcmp(mot, "ori"))  return 0x0D;
  if(!strcmp(mot,"j"))     return 0x02;
  else return 0;
}

int dictionnaireRegistre(char * mot){
  if(!strcmp(mot, "$zero")) return 0;
  if(!strcmp(mot, "$at")) return 1;
  if(!strcmp(mot, "$v0")) return 2;
  if(!strcmp(mot, "$v1")) return 3;
  if(!strcmp(mot, "$a0")) return 4;
  if(!strcmp(mot, "$a1")) return 5;
  if(!strcmp(mot, "$a2")) return 6;
  if(!strcmp(mot, "$a3")) return 7;
  if(!strcmp(mot, "$t0")) return 8;
  if(!strcmp(mot, "$t1")) return 9;
  if(!strcmp(mot, "$t2")) return 10;
  if(!strcmp(mot, "$t3")) return 11;
  if(!strcmp(mot, "$t4")) return 12;
  if(!strcmp(mot, "$t5")) return 13;
  if(!strcmp(mot, "$t6")) return 14;
  if(!strcmp(mot, "$t7")) return 15;
  if(!strcmp(mot, "$s0")) return 16;
  if(!strcmp(mot, "$s1")) return 17;
  if(!strcmp(mot, "$s2")) return 18;
  if(!strcmp(mot, "$s3")) return 19;
  if(!strcmp(mot, "$s4")) return 20;
  if(!strcmp(mot, "$s5")) return 21;
  if(!strcmp(mot, "$s6")) return 22;
  if(!strcmp(mot, "$s7")) return 23;
  if(!strcmp(mot, "$t8")) return 24;
  if(!strcmp(mot, "$t9")) return 25;
  if(!strcmp(mot, "$k0")) return 26;
  if(!strcmp(mot, "$k1")) return 27;
  if(!strcmp(mot, "$gp")) return 28;
  if(!strcmp(mot, "$sp")) return 29;
  if(!strcmp(mot, "$fp")) return 30;
  if(!strcmp(mot, "$ra")) return 31;
  return -1;
}

int dictionnaireFunction(char * mot){
 if(!strcmp(mot, "add")) return 0x21;
 if(!strcmp(mot, "sub")) return 0x22;
 if(!strcmp(mot, "and")) return 0x24;
 if(!strcmp(mot, "or" )) return 0x25;
 if(!strcmp(mot, "nor")) return 0x27;
 return -1;
}