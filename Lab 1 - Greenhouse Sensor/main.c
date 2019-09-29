//main execution file
#include "display.h"
#include "sensor.h"

int main()
{
	time_t now;
	double creadings[4]={0};
	int tempc,humidc,lightc;
	GhControllerInit();

	for(;;)
	{
		now=time(NULL);
		
		GhGetSetpoints();
		GhGetReadings(creadings);
		GhSetControls(&tempc,&humidc,&lightc,creadings);
		GhDisplayReadings(now,creadings);
		GhDisplaySetpoints();
		GhDisplayControls(&tempc,&humidc,&lightc);
		GhDelay(GHUPDATE);
	}
}
