/*
 * This is the I/O functions header file
 */

int load(const char* filename, double *equitoral_radii, double *polar_radii, const int iNumPlanets);
int pretty_print(const double volume);
void die(const char* msg);
