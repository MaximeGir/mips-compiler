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