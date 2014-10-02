#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

char * toBinary(uint32_t n){
  size_t bits = sizeof(uint32_t) * 8;
  char * str = malloc(bits + 1);
  if(!str) return NULL;
  str[bits] = 0;
  for(; bits--; n >>= 1)
    str[bits] = n & 1 ? '1' : '0';
  return str;
}

void bob(int * ass){
	*ass += 3;
}

int main(){

 //little endian
 
 uint32_t n = 0;
 uint32_t a = 2	;
 
 //printf("%s\n", toBinary(n));
 
 int i;
 for(i = 0; i < 6; i++){
   n |= (1 << 31-5-i);
 //printf("%s\n", toBinary(n));
 }

 FILE * fichier = fopen("hello.txt", "ab+");
 rewind(fichier);
 fwrite( &n, sizeof(uint32_t), 1, fichier );
 int ass = 2;

 bob(&ass);
 printf("%d\n",ass);

 

 return 0;


}


