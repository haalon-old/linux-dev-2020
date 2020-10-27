#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


#define BUF_SIZE 42

int main () {
   char *str;
   int n;

   str = (char *) malloc(BUF_SIZE);
   n = read(1, str, BUF_SIZE-1);


   for(int i = n-2; i>=0; i--)
      putchar(str[i]);

   putchar('\n');
   free(str);
   free(str);
   
   return(0);
}