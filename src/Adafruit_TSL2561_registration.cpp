#include "Adafruit_TSL2561_registration.hpp"

#include <stdio.h>
#include "EnvSnr_typedefs.hpp"

#include "Adafruit_Sensor.h"
#include "Adafruit_TSL2561_U.h"

#include "application.h"

const char adafruit_TSL2561_sensor_name[17] = "Adafruit TSL2561";
static const char adafruit_TSL2561_fake_url_payload_template[34] = "FAKE TSL2561 Payload -> value: %f";
static char TSL2561_url_payload_buffer[40]; // Hacky, but it's for testing.

Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 1);
sensors_event_t event;

void Adafruit_TSL2561_init()
{
	if(!tsl.begin())
	{
		Serial.print("No TSL2561 detected ... Check your wiring! Halting!");
		while(1);
	}
	tsl.enableAutoRange(true);
}

void* Adafruit_TSL2561_poll()
{
	tsl.getEvent(&event);
	return (void*) &event;
}

void Adafruit_TSL2561_store_unsent_data(void* rawSensorData)
{
	// TODO
}

char* Adafruit_TSL2561_generate_upload_payload(void* rawSensorData)
{
	// TODO
	// Need to temporarily cast away const for testing.
	sensors_event_t* event = (sensors_event_t*)rawSensorData;
	sprintf(TSL2561_url_payload_buffer, adafruit_TSL2561_fake_url_payload_template, event->light);

	return TSL2561_url_payload_buffer;
}

EnvSnr_TIME_TYPE Adafruit_TSL2561_retrieve_last_polled_time()
{
	// TODO
	return 0;
}

void Adafruit_TSL2561_store_last_polled_time(EnvSnr_TIME_TYPE rawTime)
{
	// TODO
}
