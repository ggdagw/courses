/* 
 * In this program, we look at some of the  basic 
 * operations which we can use in C.
 */

#include<stdio.h> 
#include<stdlib.h> 
#include<limits.h>
#include<math.h>

int main(void)
{

  /* 
   * We can declare variables of a few basic types in C.
   */
  const double pi         = 3.14159265;  /* speaks for itself */
  char         nucleotide = 'A';         /* A, C, G or T for our DNA */
  int          numPlanets = 010;         /* using octal this time.. */
  double       equi_rad   = 6378.14e3;   /* SI units; an equitoral radius of Earth (m) */ 
  double       pol_rad    = 6356.75e3;   /* SI units; a polar radius of Earth (m) */ 
  double       val;                      /* a general purpose value.. */

  printf("\n== Welcome to the doing things program! ==\n\n");

  /*
   * =Arithmetic=
   *
   * The volume of a sphere (the planet) is:
   * Note that we use 4.0/3.0, rather than 4/3; and also x/1000.0.  Why? 
   *
   * 'pow' in one of the built in maths functions in <math.h>.
   * You can find 'sin', 'sqrt', 'log', 'exp', 'floor', 'fabs' etc. in there.
   *
   * Note that you need the linker flag '-lm' when employing functions
   * from the math libarary.
   */
  val = (4.0/3.0) * pi * pow(equi_rad,2) * pol_rad;
  printf("the volume of the Earth is:\t%f metres cubed\n", val);
  val = (4.0/3.0) * pi * pow((equi_rad/1000.0),2) * (pol_rad/1000.0);
  printf("or perhaps better as:\t\t%e km cubed\n", val);
  printf("\n");

  /*
   * You'll see the increment and decrement operators a fair bit..
   */
  printf("numPlanets is:\t%d\n", numPlanets);
  --numPlanets;
  printf("numPlanets is:\t%d\n", numPlanets);
  --numPlanets;
  printf("uh oh, we're losing 'em!\n");
  ++numPlanets;
  printf("numPlanets is:\t%d\n", numPlanets);
  ++numPlanets;
  printf("numPlanets is:\t%d\n", numPlanets);
  printf("phew!\n");
  printf("\n");

  /*
   * =Logic= 
   *
   * Testing for equivelance:
   */
  if ( nucleotide == 'A' ) {
    printf("nucleotide is Adenine! \n");
  }
  else if ( nucleotide == 'G' ) {
    printf("nucleotide is Guanine! \n");
  }

  /*
   * Logical AND and NOT EQUAL:
   */
  if ( (nucleotide != 'A') && (nucleotide != 'C') && 
       (nucleotide != 'T') && (nucleotide != 'G') ) {
    printf("nucleotide: %c is not one of the 4 used in DNA\n", nucleotide);
  }

  /*
   * Greater,  less than, and OR:
   */
  if ( (numPlanets < 8) || (numPlanets > 8) ) {
    printf("%d planets! We have a new discovery or something is amok!\n", numPlanets);
  }
  printf("\n");

  /*
   * Converting types, or 'casting'.
   * We can make temporary type conversions of variables, on-th-fly.
   * For example, we can convert a double to a (short) integer
   */
  printf("(short int) pi =\t%d\n", (short int) pi);
  printf("Watch out for that truncation though!\n");
  printf("going the other way..\n");
  printf("(float) 42 =\t%f\n", (float) 42 );
  printf("\n");

  /*
   * C also supports bitwise operations, should you so desire.
   *
   * =Leftshift=
   * The number 1 in binary is '00000001'
   * The number 8 in binary is '00001000'
   * '<<N' shifts all the bits leftwards by N places.
   * This is equivalent to multiplying by 2 to the power N.
   *
   * =Bitwise AND=
   * (72)  01001000 & 
   * (184) 10111000 = 
   *       --------
   * (8)   00001000
   * 
   * The is also a bitwise OR ('|') and XOR ('^'), if you need them.
   */

  numPlanets = 1;
  printf("number of planets before our leftshift is:\t%d\n",numPlanets);
  numPlanets = numPlanets << 3;
  printf("number of planets after our leftshift is:\t%d\n",numPlanets);
  printf("phew, saved again!\n");
  numPlanets = 72  & 184;
  printf("number of planets after our bitwise AND:\n");
  printf("\t01001000 & 10111000 is:\t\t\t%d\n",numPlanets);
  printf("\n");

  return EXIT_SUCCESS;
} 
