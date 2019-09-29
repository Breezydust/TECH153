//function prototypes for all sensor getter/setters

#ifndef SENSOR_H

#define SENSOR_H

#include "display.h"

// Constants

// Function Prototypes

void GhControllerInit();
void GhGetReadings(double readings[SENSORS]);
void GhSetControls(int*header, int*humidifier, int*light, double readings[SENSORS]);
void GhGetControls(void);
void GhGetSetpoints(void);
void GhSetSetpoints(void);
double GhGetTemperature(void);
double GhGetHumidity(void);
double GhGetPressure(void);
double GhGetLight(void);

#endif
