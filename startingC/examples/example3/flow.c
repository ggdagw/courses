/*
 * Loops and conditionals
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  
  const unsigned int iMax = 5;  /* we'll count up to this */
  double temperature      = 45; /* degrees Celcius */
  unsigned int iCount     = 4;  /* can't be negative, right? */
  unsigned int ii;              /* a plain old counter */
  unsigned int threshold;       /* we'll use this in our while loop */ 

  printf("\n== Welcome to the ifs and loops program! ==\n\n");

  /*
   * The essential 'if..then..else' syntax in C is:
   */
  printf("if..then..else example:\n");
  if ( temperature < 0.0 ) {
    printf("Water would normally freeze at:\t%f\tdegrees C\n", temperature);
  }
  else if (temperature > 100.0 ) {
    printf("Water would normally boil at:\t%f\tdegrees C\n", temperature);
  }
  else {
    printf("The temperature must be in the range [0.0,100.0]\n");
  }
  printf("\n");

  /*
   * If we have more conditions, 'switch' is more concise:
   */
  printf("'switch' example:\n");
  switch (iCount) {
  case 0:
    printf("case 0: nada, zip, nowt.\n");
    break;
  case 1:
    printf("case 1: uno, sole, unitary.\n");
    break;
  case 2:
    printf("case 2: a pair, a brace, company.\n");
    break;
  case 3:
    printf("case 3: trio, triplet, a crowd?\n");
    break;
  case 4:
    printf("case 4: several, quatro, seasons.\n");
    break;
  case 5:
  default:  /* a default protects against 'fall through' bugs */
    printf("default: mucho, many, lashings.\n");
    break;
  }
  printf("\n");

  /*
   * The 'for' loop is most common..
   * and is the obvious choice if we know how many
   * iterations we want to run through.
   */
  printf("for loop example:\n");
  for(ii=0; ii<iMax; ii++) {
    if (ii == 3) {
      printf("Surprise!\n");
      continue;  /* jumps to the start of the next iteration */
    }  
    printf("Yup, I'm in a for loop, whizz-oh.  Counter is:\t%d\n", ii);
  }
  printf("\nNote, the value of the counter after the loop:\t%d\n\n", ii);
  
  /*
   * If we can't know the number of iterations ahead of time,
   * the 'while' loop comes to our aid: 
   */
  
  threshold = RAND_MAX/4;           /* a random number will be less than  */
				    /* this value 1/4 of the time, right? */
  srand((unsigned int)time(NULL));  /* seed new random series with current time */
  ii = rand();                      /* assign ii a new random number */

  printf("while loop example:\n");
  printf("The loop will continue until the random value\nis less than the thresold..\n");
  printf("threshold is:\t\t%d\n\n", threshold);
  printf("1st random value is:\t%d\n", ii);

  while (ii > threshold) {
    printf("%d\t> threshold, continuing..\n",ii);
    ii = rand();                    /* get next random number */
    printf("next random value:\t%d\n", ii);
  }
  printf("Finish loop because: %d < %d\n", ii, threshold);
  printf("\n");

  
  return EXIT_SUCCESS;
}
