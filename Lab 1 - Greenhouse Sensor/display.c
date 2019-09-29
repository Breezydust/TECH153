//This file is responsible for initializing the display

#include "display.h"
#include "sensor.h"

void GhDisplayHeader(const char*sname)
{
	printf("Tech153 Greenhouse Controller");
}

void GhDisplayReadings(time_t rtime, double dreads[SENSORS])
{
	printf("Current time:\t%s", ctime(&rtime));
	static int j;
	j++;
	printf("Counter value is: %d\n",j);
	printf("Readings:\tT: %3.1lfC\tH: %3.0lf%\tP: %5.1lfmb\tL: %3.0lflux\t\n",dreads[0],dreads[1],dreads[2],dreads[3]);
}
int GhDisplaySetpoints(void)
{
	printf("Setpoints:\tsT: %gC\t\tsH: %g%\tsP: %dmb\tsL: %glux\n",STEMP,SHUMID,SPRESSURE,SLIGHT);
}
void GhDisplayControls(int *heater, int *humidifier, int *light)
{
	printf("Controls:\tHeater: %1d\tHumidifier: %1d\t\tLights: %3d\n\n",*heater,*humidifier,*light);
}

void GhDelay(int milliseconds)
{  
	int i=0,j=0;
    	for(i=0;i<milliseconds;i++){for(j=0;j<200000;j++){}};	
}

int GhGetRandom(int range)
{
	return rand() % range;
}
