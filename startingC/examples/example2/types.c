/* 
 * In this program, we look at the basic types of things
 * which we can use in C.  These are the 'intrinsic' types.
 */

#include<stdio.h> 
#include<stdlib.h> 
#include<limits.h>
#include<string.h>

int main(void)
{

  /* 
   * We can declare variables of a few basic types in C.
   */
  char   nucleotide;        /* A, C, G or T for our DNA */
  int    numPlanets;        /* eight in our solar system - poor old Pluto! */
  float  length;            /* e.g.  1.8288m, for a 6' snooker table */
  double accum;             /* an accumulator */

  /*
   * And arrays of those types.
   */
  char cStr[20];            /* a character array/string of 20 chars */
  int  iMat2d[3][3];        /* a 2-dimensional matrix of integers - 3x3 */ 

  /* 
   * Qualifiers can also be added, such as:
   */
  short int mini;           /* typically two bytes */ 
  long  int maxi;           /* typically eight bytes */ 

  /*
   * and
   */
  signed char cSigned;      /* one byte, values in the range [-128:127] */
  unsigned char cUsigned;   /* values in the range [0:255] */
  
  /*
   * Declarations can also carry initial values, for example:
   */
  long int c = 299792458;   /* speed of light (m/s) */

  /*
   * and can be declared constant, if we don't want them to be changed..
   */
  const float pi = 3.14159265;

  /*
   * You are also likely to encounter enumerated types,
   * which map symbolic names to constant values, e.g.
   */
  enum boolean { NO, YES }; /* NO = 0, YES = 1 */
  enum months { JAN = 1, FEB , MAR , APR , MAY , JUN ,
		JUL , AUG , SEP , OCT , NOV , DEC }; /* FEB = 2, etc. */

  /* 
   * Now we have some variables, let's do something with 'em!
   * Note what the intrinsic function 'sizeof()' does..
   * We've seen that '/n' gives a newline before.  '/t' gives a tab.
   * %lu expects a 'long, unsigned interger'
   */
  printf("\n== Welcome to the size-of-things program! ==\n\n");
  printf("sizeof int:\t%lu\tbytes\n",   sizeof(numPlanets));
  printf("sizeof short:\t%lu\tbytes\n", sizeof(mini));
  printf("sizeof long:\t%lu\tbytes\n",  sizeof(maxi));
  printf("\n");

  /*
   * Note, we get SCHAR_MAX, amongst other things, 
   * from <limits.h>
   */
  cSigned = SCHAR_MAX;
  printf("the maximum signed char values is:\t%d\n", cSigned);
  cSigned += 1;
  printf("add one and cSigned becomes:\t\t%d\twatch out for overflow!..\n", cSigned);
  printf("\n");
  
  /* 
   * Let's convert metric to imperial units..
   */ 
  length = 1.8288 * 3.2808;
  printf("1.8288 (length) * 3.2808 (conversion factor) is:\t%f\t(feet)\n", length);
  printf("Note that we'be not quite recovered our 6 feet, here.\n");
  printf("\n");
  
  /*
   * Here's just a quick print out of the value
   * of one of our enumerated types
   */
  printf("the symbol FEB has the value:\t%d\n", FEB );

  /*
   * Set a character to a value:
   */
  nucleotide = 'T';
  printf("nucleotide is:\t\t\t%c\n", nucleotide);

  /*
   * and you can set an integer using hexadecimal, if you like:
   */
  numPlanets = 0x8;
  printf("numPlanets is:\t\t\t%d\n", numPlanets);
  printf("\n");

  /*
   * Let's set the elements of the character array.
   * Note that array indices start at zero.
   */
  cStr[0] = 'h';  /* first elememt set to ascii char code for 'h' */
  cStr[1] = 'e';
  cStr[2] = 'l';
  cStr[3] = 'l';
  cStr[4] = 'o';
  cStr[5] = '!';
  cStr[6] = '\0'; /* this is the null character, used as a terminator */
  printf("the character array is:\t\t%s\n", cStr);

  /*
   * An easier way to set a string, however, to use a function
   * from the string library, accessed through the inclusion of <string.h>.
   * We'll see more of strings in later exercises.
   */
  strcpy(cStr,"hey, good looking!");
  printf("now the array is:\t\t%s\n", cStr);
  printf("\n");

  /*
   * ps, you'll get a compiler error if you try to change
   * a 'const' variable..
   */
  /* pi = pi * 2.0; */

  return EXIT_SUCCESS;
} 
