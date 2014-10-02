/*
 *
 * @author : Maxime Girard 
 * @CodePermanent : GIRM30058500
 *
 */

#ifndef PARSER_H
#define PARSER_H

char * toBinary(uint32_t n);
char * trouverNextMot(char * ligne);
void parseLignesMips(FILE * fichier, FILE * fichier_ecriture);
int trouverValeurImmediate(char * mot, int adresse_immediate, int * valeur);
char * trouverMnemonic(char * ligne);
uint32_t conversionEnBinaire(char type, int opcode, int rs, int rt, int rd, int immediate, int funct, int shamt);
#endif
