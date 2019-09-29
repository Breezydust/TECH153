//header file containing values for display initialization, as well as function prototypes

#ifndef DISPLAY_H

#define DISPLAY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants

#define SIMULATE 1
#define SENSORS 4
#define TEMPERATURE 0
#define HUMIDITY 1
#define PRESSURE 2
#define LIGHT 3
#define USTEMP 50
#define LSTEMP -10
#define USHUMID 100
#define LSHUMID 0
#define USPRESS 1016
#define LSPRESS 985
#define USLIGHT 255
#define LSLIGHT 0
#define STEMP 25.0
#define SHUMID 55.0
#define SPRESSURE 1000
#define SLIGHT 255.0
#define ON 1
#define OFF 0
#define GHUPDATE 5000
	
// Function Prototypes
void GhDisplayHeader(const char*sname);
void GhDisplayReadings(time_t rtime,double dreads[SENSORS]);
int GhDisplaySetpoints(void);
void GhDisplayControls(int*heater, int*humidifier, int*light);
int GhGetRandom(int range);

#endif
