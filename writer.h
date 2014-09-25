/*
 *
 * @author : Maxime Girard 
 * @CodePermanent : GIRM30058500
 *
 */

#ifndef WRITER_H
#define WRITER_H

char * genererNomFichier(char * nom_fichier);
FILE * ouvrirFichierEcriture(char * nom_fichier);
int ecrireLigne(uint32_t ligne, FILE * fichier);
#endif
