#ifndef EnvSnr_NON_SENSOR_SPECIFIC_FUNCTIONS_H
#define EnvSnr_NON_SENSOR_SPECIFIC_FUNCTIONS_H

#include <stddef.h>
#include "EnvSnr_typedefs.hpp"

struct IoTLib_RawIoTLib_RawSensorDataAndSensorID;

void upload_function(char* urlUploadString);
void debug_function(char* debugString);
void store_last_upload_time(EnvSnr_TIME_TYPE lastUploadTime);
EnvSnr_TIME_TYPE retrieve_last_upload_time();
struct IoTLib_RawSensorDataAndSensorID* retrieve_all_unsent_data();
size_t get_stored_unsent_data_count();
EnvSnr_TIME_TYPE get_current_time();
double convert_time_type_to_seconds(EnvSnr_TIME_TYPE rawTime);

#endif
