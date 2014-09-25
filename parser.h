/*
 *
 * @author : Maxime Girard 
 * @CodePermanent : GIRM30058500
 *
 */

#ifndef PARSER_H
#define PARSER_H

void parseLignesMips(FILE * fichier, FILE * fichier_ecriture);
char trouverTypeInstruction(char * ligne);
uint32_t conversionInstruction(char * ligne, const char TYPE);

#endif
