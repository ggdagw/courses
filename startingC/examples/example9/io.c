/*
 * system header files (note <>s)
 */
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

/*
 * our own header (note ""s)
 */
#include "main.h"
#include "io.h"

#ifndef MAXSTR
#define MAXSTR 255
#endif

/*
 * function to load radii data
 */
int load(const char* filename, planet *planets, const int iNumPlanets)
{
  /* locals */
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
   * We assume 3 columns:
   * name plus two columns of floating point values
   * separated by a TABS. We must convert radii from ascii
   * to binary floating point format, which is a bit
   * of a chore!
   */

  /* we're expecting iNumPlanets entries in the data file */
  for(ii=0; ii<iNumPlanets; ii++) {
    fgets(line,MAXSTR,fp);                      /* get line as character string */
    cPtr = strtok(line," \t\n");                /* ist column - name */
    if(cPtr == NULL) {
      die("could not parse input file");
    }
    strcpy(planets[ii].name,cPtr);              /* copy string to data struct */

    /* note the NULL arg to strtok for all subsequent calls */
    cPtr = strtok(NULL," \t\n");                /* 2nd column - equi_rad */
    if(cPtr == NULL) {
      die("could not parse input file");
    }
    planets[ii].equitorial_radius = atof(cPtr); /* convert chars to double */

    cPtr = strtok(NULL," \t\n");                /* 3rd column - pol_rad */
    if(cPtr == NULL) {
      die("could not parse input file");
    }
    planets[ii].polar_radius = atof(cPtr);
  }
  
  return EXIT_SUCCESS;
}

/*
 * function to print out calculated volumes
 */
int pretty_print(const planet plnt)
{
  printf("the volume of %s\tis:\t%f\tkms cubed\n", plnt.name, plnt.volume);

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
