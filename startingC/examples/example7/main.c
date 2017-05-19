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
#include "calcs.h"
#include "io.h"

/*
 * a much neater main program
 */ 
int main(void)
{
  const unsigned int iNumPlanets = 8; /* Pluto doesn't count! */
  double       equi_rad[iNumPlanets]; /* equitoral radii of planets */
  double       pol_rad[iNumPlanets];  /* polar radii of planets */
  unsigned int ii;                    /* counter */
  double       val;                   /* we'll record volume with this */

  printf("\n== Welcome to the header file program! ==\n\n");

  /*
   * Load the data
   */
  load("radii.dat", equi_rad, pol_rad, iNumPlanets);

  /*
   * loop over planets, calling function to calculate volume
   * each time
   */
  for(ii=0; ii<iNumPlanets; ii++) {
    val = volume(equi_rad[ii], pol_rad[ii]);
    pretty_print(val);
  }
  printf("\n");

  return EXIT_SUCCESS;
} 
