#include <stdio.h>
#include <stdint.h>

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
 uint32_t n = 15;
 uint32_t x = 0;
 uint32_t k;
 
 for(k = 5; k > 0; k--, n >>= 1){
    if(n & 1) x |= 1 << 31-k;
    else x |= 0<<n;
 }
int m = 1;
 for(k = 5; k > 0; k--, m >>= 1){
    if(m & 1) x |= 1 << 25-k;
    else x |= 0<< 25-k;
 }

 FILE * fichier = fopen("hell.txt", "ab+");
 rewind(fichier);
 //fwrite( &x, sizeof(uint32_t), 1, fichier );
 printf("%s\n", toBinary(x));
 return 0;
}
