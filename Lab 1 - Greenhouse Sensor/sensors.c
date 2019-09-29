//this file is responsible for reading information off the sensors
#include "display.h"
#include "sensor.h"

void GhControllerInit(void)
{
	srand(time(NULL));
	GhSetSetpoints();
	GhDisplayHeader("Thomas Aziz n01166379");
}

void GhSetSetpoints(void)
{
}

void GhGetReadings(double readings[SENSORS])
{
	readings[TEMPERATURE] = GhGetTemperature();
	readings[HUMIDITY] = GhGetHumidity();
	readings[PRESSURE] = GhGetPressure();
	readings[LIGHT] = GhGetLight();
}

void GhGetControls(void)
{
}

void GhGetSetpoints(void)
{
}

double GhGetTemperature(void)
{
	#if SIMULATE
		return GhGetRandom(USTEMP-LSTEMP)+LSTEMP;
	#else
		return STEMP;
	#endif
}	

double GhGetHumidity(void)
{
	#if SIMULATE
		return GhGetRandom(USHUMID-LSHUMID)+LSHUMID;
	#else
		return SHUMID;
	#endif
}

double GhGetPressure(void)
{
	#if SIMULATE
		return GhGetRandom(USPRESS-LSPRESS)+LSPRESS;
	#else
		return SPRESSURE;
	#endif
}

double GhGetLight()
{
	#if SIMULATE
		return GhGetRandom(USLIGHT-LSLIGHT)+LSLIGHT;
	#else
		return SLIGHT;
	#endif
}

void GhSetControls(int *heater, int *humidifier, int *light, double readings[SENSORS])
{
	if (readings[TEMPERATURE]<STEMP)
	{
		*heater = ON;
	}
	else
	{
		*heater = OFF;
	}
	if (readings[HUMIDITY]<SHUMID)
	{
		*humidifier = ON;
	}
	else
	{
		*humidifier = OFF;
	}
	*light = readings[LIGHT];
}
	
