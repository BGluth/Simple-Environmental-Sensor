#include "Adafruit_MCP9808_registration.hpp"

#include "application.h"
#include <stdio.h>
#include "Adafruit_MCP9808.h"

const char adafruit_MCP9808_sensor_name[17] = "Adafruit MCP9808";
static const char adafruit_MCP9808_fake_url_payload_template[34] = "FAKE MAC9808 Payload -> value: %f";
static char MCP9808_url_payload_buffer[40]; // Hacky, but it's for testing.

static Adafruit_MCP9808 mcp = Adafruit_MCP9808();
static float polled_temperature;

void Adafruit_MCP9808_init()
{
	if(!mcp.begin())
	{
		Serial.print("WARNING: No MCP9808 detected ... Check your wiring!");
	}
}

void* Adafruit_MCP9808_poll()
{
	mcp.shutdown_wake(0);

	// Hack. Needs a short warmup time before it can get an accurate reading.
	// Will remove once warmup functionality has been added to the IoT_Library.
	delay(250);

	polled_temperature = mcp.readTempC();
	mcp.shutdown_wake(1); // Sleep

	return (void*) &polled_temperature;
}

void Adafruit_MCP9808_store_unsent_data(void* rawSensorData)
{
	// TODO
}

char* Adafruit_MCP9808_generate_upload_payload(void* rawSensorData)
{
	// TODO
	float* current_temperautre = (float*)rawSensorData;
	sprintf(MCP9808_url_payload_buffer, adafruit_MCP9808_fake_url_payload_template, *current_temperautre);

	return MCP9808_url_payload_buffer;
}

EnvSnr_TIME_TYPE Adafruit_MCP9808_retrieve_last_polled_time()
{
	// TODO
	return 0;
}

void Adafruit_MCP9808_store_last_polled_time(EnvSnr_TIME_TYPE rawTime)
{
	// TODO
}

float Adafruit_MCP9808_raw_to_temp(void* rawSensorData)
{
	return *((float*) rawSensorData);
}
