#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

char * toBinary(uint32_t n){
  size_t bits = sizeof(uint32_t) * 8;
  char * str = malloc(bits + 1);
  if(!str) return NULL;
  str[bits] = 0;
  for(; bits--; n >>= 1)
    str[bits] = n & 1 ? '1' : '0';
  return str;
}

int main()
{

 uint32_t n = 0;
 uint32_t x = 0;
 uint32_t k;
 
 for(k = 6; k > 0; k--,n >>= 1){
    if(n & 1) x |= 1 << 32-k;
    else x |= 0 << n;
 }

int m = 19 ;
 for(k = 5; k > 0; k--,	m >>= 1){
    if(m & 1) x |= 1 << 26-k;
    else x |= 0<< 26-k;
 }
 
int g = 21 ;
 for(k = 5; k > 0; k--,g >>= 1){
    if(g & 1) x |= 1 << 21-k;
    else x |= 0<< 21-k;
 }
 
 int q = 11;
 for(k = 5; k > 0; k--,q >>= 1){
    if(q & 1) x |= 1 << 16-k;
    else x |= 0<< 16-k;
 }

 int z = 0;
 for(k = 5; k > 0; k--,z >>= 1){
    if(z & 1) x |= 1 << 11-k;
    else x |= 0<< 11-k;
 }

 int w = 32;
 for(k = 6; k > 0; k--,w >>= 1){
    if(w & 1) x |= 1 << 6-k;
    else x |= 0 << 6-k;
 }



 printf("%d\n", x);


 FILE * fichier = fopen("helloop.txt", "wb+");
 rewind(fichier);
 fwrite( &x, sizeof(uint32_t), 1, fichier);
 fclose(fichier);
 printf("%s\n", toBinary(x));
 return 0;
}
