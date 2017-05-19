#include <stdio.h>
#include <stdlib.h>

#define MAXCOUNT 10 

int main(void)
{
  unsigned int ii;
  int iNum;             /* just a plain old integer */
  int* iAddr = NULL;    /* a 'pointer' to an integer - intriguing! */
  int data[MAXCOUNT] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };  /* 1st N Fib no.s */ 

  printf("\n== Welcome to the pointers program! ==\n\n");

  iNum = 3;       /* first, we'll set the value of iNum */
  iAddr = &iNum;  /* now we set iAddr to the 'address' of iNum */

  /* print value of iNum */
  printf("iNum has the value:\t\t\t%d\n", iNum);

  /* 'derefernce' pointer and print value */
  printf("*iAdrr (dereference) has the value:\t%d\n", *iAddr);
  printf("\n");

  /*
   * now change the value of iNum and print what
   * we get when we 'dereference' our pointer again
   */
  iNum = 7;
  printf("iNum reset to the value:\t\t%d\n", iNum);
  printf("and *iAdrr has the corresponding value:\t%d\n", *iAddr);
  printf("\n");

  /*
   * change the value that iAddr is pointing to
   * and print out the value of iNum
   */
  *iAddr = 17;
  printf("set *iAdrr to:\t\t\t\t%d\n", *iAddr);
  printf("and sure enough iNum has the value:\t%d\n", iNum);
  printf("\n");  

  /*
   * (perhaps accidentally) changing the value of iAddr,
   * without dereferencing it will not cause iNum to change,
   * of course...
   */
  iAddr = 18;
  printf("set iAdrr to:\t\t\t\t%d\t(NB no *, so no dereference)\n", iAddr);
  printf("and iNum will NOT change value:\t\t%d\n", iNum);
  printf("\n");  

  printf("-- on to arrays...\n\n");

  /*
   * The address of an array is that of it's first element.
   * We can perform 'pointer arithmetic' to access other cells.
   */
  printf("pointer arithmetic:\n");
  iAddr = &data[0];
  for (ii=0; ii<MAXCOUNT; ii++) {
    printf("data[%d]\tor equivalently *(iAddr+%d)\tis:\t%d\n", ii, ii,*(iAddr+ii));
  }
  printf("\n");  

  /*
   * Lastly, we could allocate some memory and
   * arrange for iAddr to point to that memory.
   * Notice the cast to int* in the call to malloc.
   *
   * We can refer to this new container as if it
   * were an array (well, that's exactly what it is).
   * and set the values in the new array to
   * whatever we like.
   */
  printf("dynamic memory allocation:\n");
  iAddr = (int *)malloc(sizeof(int)*MAXCOUNT);
  /* After requesting space it is good practice to check
     whether the request was successful */
  if (iAddr == NULL) {
    fprintf(stderr,"ERROR: could not allocate memory\n");
    exit(EXIT_FAILURE);
  }
  for (ii=0; ii<MAXCOUNT; ii++) {
    /* lets add on offet of 1 to all our lovely */
    /* Fibonacci numbers.. */
    iAddr[ii] = data[ii] + 1;
  }
  /* and print both arrays, side-by-side */
  for (ii=0; ii<MAXCOUNT; ii++) {
    printf("data[%d] is:\t%d\tiAddr[%d] is:\t%d\n", ii,data[ii], ii, iAddr[ii]);
  }
  printf("\n");  

  /*
   * Good practice: always cleanup memory you've allocated.
   * Use NULL as a safeguard where you can to ensure that
   * you don't free memory you haven't allocated.  That would
   * cause your program to crash.
   */
  if(iAddr != NULL) {
    free(iAddr);
  }

  return EXIT_SUCCESS;
}
