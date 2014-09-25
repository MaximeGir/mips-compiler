/*
 *
 * @author : Maxime Girard 
 * @CodePermanent : GIRM30058500
 *
 */

#ifndef PARSER_H
#define PARSER_H

char * toBinary(uint32_t n);
void parseLignesMips(FILE * fichier, FILE * fichier_ecriture);
char trouverTypeInstruction(char * ligne);
uint32_t conversionInstruction(char * ligne, const char TYPE);
void setOpCodeBit(char type, uint32_t *ligne_binaire);
void setOtherBit(char * ligne, uint32_t * ligne_binaire);  

#endif
