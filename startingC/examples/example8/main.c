/*
 * System header files
 */ 
#include<stdio.h> 
#include<stdlib.h> 

/*
 * Include our own header files here.
 * Note the use of the double quotes (")
 * rather than angle brackets (<>).  
 */
#include "main.h"
#include "calcs.h"
#include "io.h"

/*
 * an even neater main program
 */ 
int main(void)
{

  const unsigned int iNumPlanets = 8; /* Pluto doesn't count! */
  unsigned int ii;                    /* counter */
  planet planets[iNumPlanets];        /* our master array */

  printf("\n== Welcome to the structures program! ==\n\n");

  /*
   * Load the data
   */
  load("planets.dat", planets, iNumPlanets);

  /*
   * loop over planets, calling function to calculate volume
   * each time
   */
  for(ii=0; ii<iNumPlanets; ii++) {
    volume(&planets[ii]);
    pretty_print(planets[ii]);
  }
  printf("\n");

  return EXIT_SUCCESS;
} 
