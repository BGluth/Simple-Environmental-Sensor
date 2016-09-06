#ifndef ADAFRUIT_MCP9808_H
#define ADAFRUIT_MCP9808_H

#include "EnvSnr_typedefs.hpp"

extern const char adafruit_MCP9808_sensor_name[17];
void Adafruit_MCP9808_init();
void* Adafruit_MCP9808_poll();
void Adafruit_MCP9808_store_unsent_data(void* rawSensorData);
char* Adafruit_MCP9808_generate_upload_payload(void* rawSensorData);
EnvSnr_TIME_TYPE Adafruit_MCP9808_retrieve_last_polled_time();
void Adafruit_MCP9808_store_last_polled_time(EnvSnr_TIME_TYPE rawTime);
float Adafruit_MCP9808_raw_to_temp(void* rawSensorData);

#endif
