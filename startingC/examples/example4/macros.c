#include <stdio.h>
#include <stdlib.h>

#define MAXSTR 25

int main(void)
{
  int  ii;            /* a lowly, common or garden counter */
  char cStr[MAXSTR];  /* a character array with size set globally */

  printf("\n== Welcome to the C preprocessor program! ==\n\n");

  /*
   * Loop over the cells in the character array 
   * and set them to a value ('c')
   * Note the terminating '\0' character
   */
  for(ii=0;ii<MAXSTR-1;ii++) {
    cStr[ii] = 'c';
  }
  cStr[MAXSTR-1] = '\0';
  printf("%s\n", cStr);
  printf("\n");

  /*
   * This code will be 'conditionally compiled', depending
   * upon whether a macro called DEBUG is defined or not.
   * See the 'CFLAGS' variable in the Makfile.
   */
#ifdef DEBUG
  printf("DEBUG is ON\n");
  printf("I'm going to print out a lot more information\n");
  printf("Boy-oh-boy am I going to have a lot to say!\n");
#endif 
  
  return EXIT_SUCCESS;
}
