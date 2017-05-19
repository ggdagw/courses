/*
 * System header files
 */
#include<math.h>

/*
 * Our own header files
 */
#include "calcs.h"

/*
 * function to compute volume of an oblate spereoid
 * Note we declare everything we don't need to change
 * as const.  This protects us from bugs.
 */
double volume(const double equitorial_rad, const double polar_rad)
{
  /* local variables */
  const double pi = 3.14159265;  
  double       retval;

  /* the calcs */
  retval = (4.0/3.0) * pi * pow(equitorial_rad,2) * polar_rad;
  
  /* functions typically return a value */
  return retval;
}
