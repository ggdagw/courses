/*
 * System header files
 */
#include <stdlib.h>
#include <math.h>

/*
 * Our own header files
 */
#include "main.h"
#include "calcs.h"

/*
 * function to compute volume of an oblate spereoid
 */
int volume(planet *plnt)
{
  /* local variables */
  const double pi = 3.14159265;  

  /* 
   * The calcs.
   * Note that we must use '->' to access members of a structure
   * that we access via a pointer to that struct.
   */
  plnt->volume = (4.0/3.0) * pi * pow(plnt->equitorial_radius,2) * plnt->polar_radius;

  /* return just success or failure this time */
  return EXIT_SUCCESS;
}
