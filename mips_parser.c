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

int main(int argc, char ** args){
 if(!valider_nombre_argument(argc)) return EXIT_FAILURE;
 if(!valider_ouverture_fichier(args[1])) return EXIT_FAILURE;
 printf("working so far!\n");
  return EXIT_SUCCESS;
}
