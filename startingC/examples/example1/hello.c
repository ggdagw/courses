/* This is a comment */

/*
 *  As is this.
 *  We include some system 'header' files 
 *  so that we can make use of the printf function
 *  and also the 'macro' EXIT_SUCCESS
 */
 
#include <stdio.h>
#include <stdlib.h>

/* 
 * This is the main program function.
 */
int main(void)
{
  /* 
   * Print a message to the screen.
   */
  printf("hello, world!\n");
  
  /* 
   * Provide a return value to the outside world.
   * All good programs should do this.
   */
  return EXIT_SUCCESS;
}
