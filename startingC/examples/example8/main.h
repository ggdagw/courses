#ifndef MAXSTR
#define MAXSTR 255
#endif

/* 
 * we can create our own parcel to store related
 * values together
 */ 
typedef struct {
  char   name[MAXSTR];       /* planet's name */
  double equitorial_radius;  /* center to equator */
  double polar_radius;       /* center to pole */
  double volume;             /* we can store computed volume here */
} planet;
