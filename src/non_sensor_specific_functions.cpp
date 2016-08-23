#include "non_sensor_specific_functions.hpp"

#include "Application.h"

#include "user_settings.h"
#include "public_structs.h"


void upload_function(char* urlUploadString)
{
	// TODO: Implement
	Serial.print("Upload function called with: ");
	Serial.println(urlUploadString);
}

void debug_function(char* debugString)
{
	Serial.println(debugString);
}

void store_last_upload_time(EnvSnr_TIME_TYPE lastUploadTime)
{
	// TODO: Implement
}

EnvSnr_TIME_TYPE retrieve_last_upload_time()
{
	// TODO: Implement
	return 0;
}

struct IoTLib_RawSensorDataAndSensorID* retrieve_all_unsent_data()
{
	// TODO: Implement
	// Until implemented, get_stored_unsent_data_count() will return 0, so the library won't ever do anything with this returned value.
	return NULL;
}

size_t get_stored_unsent_data_count()
{
	// TODO: Implement
	return 0;
}

EnvSnr_TIME_TYPE get_current_time()
{
	// TODO: Implement
	// For simple testing, will always return a value that is large enough to trigger all sensors to poll and the upload function to fire.
	return IoTLib_MIN_SECONDS_BETWEEN_UPLOADS + 1;
}

double convert_time_type_to_seconds(EnvSnr_TIME_TYPE rawTime)
{
	// TODO: Implement
	return 0;
}
