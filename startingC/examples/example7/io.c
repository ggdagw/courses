/*
 * system header files (note <>s)
 */
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

/*
 * our own header (note ""s)
 */
#include "io.h"

#define MAXSTR 250

/*
 * function to load radii data
 */
int load(const char* filename, double *equitorial_radii, double *polar_radii, const int iNumPlanets)
{
  unsigned int ii;   /* counter */
  FILE *fp = NULL;   /* file pointer */
  char line[MAXSTR]; /* char array to hold a line read from file */
  char *cPtr = NULL; /* pointer to a character */

  /* open the file */
  fp = fopen(filename,"r");

  /* check whether we were sucessful */
  if (fp == NULL) {
    die("could not open file");
  }

  /*
   * Load the data into given arrays.
   *
   * Note that we are getting addresses for
   * the arrays as args and so changes will stick.
   *
   * We assume two columns of floating point values
   * separated by a TAB. We must convert from ascii
   * to binary floating point format, which is a bit
   * of a chore!
   */

  /* we're expecting iNumPlanets entries in the data file */
  for(ii=0; ii<iNumPlanets; ii++) {
    fgets(line,MAXSTR,fp);              /* get line as character string */
    cPtr = strtok(line," \t\n");        /* get 1st column */
    if(cPtr == NULL) {
      die("could not parse input file");
    }
    equitorial_radii[ii] = atof(cPtr);  /* convert chars to double */

    /* note the NULL arg to strtok this time around */
    cPtr = strtok(NULL," \t\n");        /* get 2nd column */
    if(cPtr == NULL) {
      die("could not parse input file");
    }
    polar_radii[ii] = atof(cPtr);       /* convert chars to double */
  }
  
  return EXIT_SUCCESS;
}

/*
 * function to print out calculated volumes
 */
int pretty_print(const double volume)
{
  printf("the volume of the planet is:\t%f\tkms cubed\n", volume);

  return EXIT_SUCCESS;
}

/*
 * Error handler
 */
void die(const char* msg)
{
  fprintf(stderr,"Error: %s\n", msg);
  exit(EXIT_FAILURE);
}
