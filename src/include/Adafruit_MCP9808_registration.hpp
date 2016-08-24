#ifndef ADAFRUIT_TSL2561_H
#define ADAFRUIT_TSL2561_H

#include "EnvSnr_typedefs.hpp"

void Adafruit_MCP9808_init();
void* Adafruit_MCP9808_poll();
void Adafruit_MCP9808_store_unsent_data(void* rawSensorData);
char* Adafruit_MCP9808_generate_upload_payload(void* rawSensorData);
EnvSnr_TIME_TYPE Adafruit_MCP9808_retrieve_last_polled_time();
void Adafruit_MCP9808_store_last_polled_time(EnvSnr_TIME_TYPE rawTime);

#endif
