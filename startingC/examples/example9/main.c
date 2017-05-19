/*
 * System header files
 */ 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

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
int main(int argc, char** argv)
{

  unsigned int iNumPlanets;           /* A different solar system? */
  unsigned int ii;                    /* counter */
  planet *planets = NULL;             /* our master array - as yet unallocated */
  char progname[MAXSTR];              /* the program name */
  char filename[MAXSTR];              /* the data file name */

  printf("\n== Welcome to the command line program! ==\n\n");

  /*
   * Parse the command line.
   * 'argc' is a count of the number of command line arguments.
   * 'argv' is a 2d character array of those args, given as strings.
   * NB we'll have to convert any strings which we wish to interpret
   * as numerical values.
   */

  /* record the name of the executable, just because we can */
  strcpy(progname,argv[0]);

  if(argc != 3) {
    die("usage: command.exe <data file name> <num planets>");
  }

  strcpy(filename,argv[1]);   /* capture the name of the data file */
  iNumPlanets = atof(argv[2]);  /* could we check that this is sensible? */

  /*
   * allocate planet storage space:)
   */
  planets = (planet *)malloc(sizeof(planet)*iNumPlanets);
  if (planets == NULL) {
    die("could not allocate planet storage space!");
  }

  /*
   * Load the data
   */
  load(filename, planets, iNumPlanets);

  /*
   * loop over planets, calling function to calculate volume
   * each time
   */
  for(ii=0; ii<iNumPlanets; ii++) {
    volume(&planets[ii]);
    pretty_print(planets[ii]);
  }
  printf("\n");

  /*
   * Always clean up after yourself
   */
  if(planets != NULL) {
    free(planets);
  }

  return EXIT_SUCCESS;
} 
