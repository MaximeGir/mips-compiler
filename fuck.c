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

int main(){
 uint32_t n = 0;
 printf("%s\n", toBinary(n));
 int i;
 for(i = 0; i < 5; i++){
   n |= (1 << 31-i);
   printf("%s\n", toBinary(n));
 }
 return 0;
}

