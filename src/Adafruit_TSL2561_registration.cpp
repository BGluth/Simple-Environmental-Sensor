#include "EnvSnr_typedefs.hpp"
#include "Adafruit_TSL2561_registration.hpp"

#include "Adafruit_Sensor.h"
#include "Adafruit_TSL2561_U.h"

const char adafruit_TSL2561_sensor_name[17] = "Adafruit TSL2561";
static const char adafruit_TSL2561_fake_url_payload[16] = "TSL2561 Payload";

Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 1);
sensors_event_t event;

void Adafruit_TSL2561_init()
{
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
	return (char*)&adafruit_TSL2561_fake_url_payload;
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
