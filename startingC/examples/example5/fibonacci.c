#include<stdio.h> 
#include<stdlib.h> 

/*
 * function prototypes go here
 */
int fib(int iNum);

/*
 * main program
 */ 
int main(void)
{
  const unsigned int iMaxNum = 10;
  unsigned int ii;

  printf("\n== Welcome to the Fibonacci program! ==\n\n");  

  for(ii=0;ii<iMaxNum;ii++) {
    printf("Fibonacci number %d:\t%d\n", ii, fib(ii));
  }
  printf("\n");

  return EXIT_SUCCESS;
} 

/*
 * function definitions go here
 */
int fib(int iNum)
/* Fibonacci value of a number */
{
  switch(iNum) {
  case 0:
    return(0);
    break;
  case 1:
    return(1);
    break;
  default:  /* Including recursive calls */
    return(fib(iNum - 1) + fib(iNum - 2));
    break;
  }
}
