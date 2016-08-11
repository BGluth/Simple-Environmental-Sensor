#ifndef ADAFRUIT_TSL2561_H
#define ADAFRUIT_TSL2561_H

#include "EnvSnr_typedefs.h"

extern const char adafruit_TSL2561_sensor_name[17];
void Adafruit_TSL2561_init();
void* Adafruit_TSL2561_poll();
void Adafruit_TSL2561_store_unsent_data(void* rawSensorData);
char* Adafruit_TSL2561_generate_upload_payload(void* rawSensorData);
EnvSnr_TIME_TYPE Adafruit_TSL2561_retrieve_last_polled_time();
void Adafruit_TSL2561_store_last_polled_time(EnvSnr_TIME_TYPE rawTime);

#endif
