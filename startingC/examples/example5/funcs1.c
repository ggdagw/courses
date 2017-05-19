#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>

/*
 * function prototypes go here
 */
double volume(double equitorial_rad, double polar_rad);

/*
 * main program
 */ 
int main(void)
{
  const unsigned int NumPlanets = 8;
  double       equi_rad[NumPlanets]; /* equitoral radii of planets */
  double       pol_rad[NumPlanets];  /* polar radii of planets */
  unsigned int ii;
  double       val;                  /* notice same name used in function */

  printf("\n== Welcome to the first functions program! ==\n\n");

  /*
   * we need to set the values for the planetary radii
   * all values in kms
   */
  equi_rad[0] = pol_rad[0] = 2439.7;  /* Mercury: +/- 1km, no flattening */
  equi_rad[1] = pol_rad[1] = 6051.8;  /* Venus:   +/- 1km, no flattening */
  /* Earth */  
  equi_rad[2]              = 6378.14; 
  pol_rad[2]               = 6356.75;
  /* Mars */
  equi_rad[3]              = 3396.2;  /* +/- 0.1km */ 
  pol_rad[3]               = 3376.2;  /* +/- 0.1km */ 
  /* Jupiter */
  equi_rad[4]              = 71492.0;  /* +/- 4km */ 
  pol_rad[4]               = 66854.0;  /* +/- 10km */ 
  /* Saturn */
  equi_rad[5]              = 60268.0;  /* +/- 4km */ 
  pol_rad[5]               = 54364.0;  /* +/- 10km */ 
  /* Uranus - every schoolchild's favourite!  */
  equi_rad[6]              = 25559.0;  /* +/- 4km */ 
  pol_rad[6]               = 24973.0;  /* +/- 20km */ 
  /* Neptune */
  equi_rad[7]              = 24764.0;  /* +/- 15km */ 
  pol_rad[7]               = 24341.0;  /* +/- 30km */ 

  /*
   * loop over planets, calling function to calculate volume
   * each time
   */
  for(ii=0; ii<NumPlanets; ii++) {
    val = volume(equi_rad[ii], pol_rad[ii]);
    printf("the volume of the planet is:\t%f\tkms cubed\n", val);
  }
  printf("\n");

  return EXIT_SUCCESS;
} 

/*
 * function definitions go here
 */
double volume(double equitorial_rad, double polar_rad)
{
  /* local variables */
  const double pi = 3.14159265;  
  double       val;

  /* the calcs */
  val = (4.0/3.0) * pi * pow(equitorial_rad,2) * polar_rad;
  
  /* functions typically return a value */
  return val;
}
