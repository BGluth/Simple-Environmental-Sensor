#include "device_registration.hpp"
#include "device_registration_local.hpp"

#include "registration_api.h"

#include "non_sensor_specific_functions.hpp"
#include "Adafruit_TSL2561_registration.hpp"
#include "Adafruit_MCP9808_registration.hpp"

void register_all_functions()
{
	_register_non_sensor_specific_functions();
	_register_sensor_specific_functions();
	IoTLib_sensor_registration_init();
}

static void _register_non_sensor_specific_functions()
{
	IoTLib_register_upload_function(upload_function);
	IoTLib_register_debug_function(debug_function);
	IoTLib_register_store_last_upload_time_function(store_last_upload_time);
	IoTLib_register_retrieve_last_upload_time_function(retrieve_last_upload_time);
	IoTLib_register_retrieve_all_stored_unsent_sensor_data_function(retrieve_all_unsent_data);
	IoTLib_register_get_stored_unsent_data_count_function(get_stored_unsent_data_count);
	IoTLib_register_get_current_time_function(get_current_time);
	IoTLib_register_convert_time_type_to_seconds_func(convert_time_type_to_seconds);

	IoTLib_register_temp_sensorid_and_raw_to_temp_function(0, _fake_raw_to_temp_func); // Hack until I get the actual temperature sensor going.
}

static void _register_sensor_specific_functions()
{
	_register_Adafruit_TSL2561();
	_register_Adafruit_MCP9808();
}

static void _register_Adafruit_TSL2561()
{
	IoTLib_SensorID sensorID = IoTLib_register_sensor(adafruit_TSL2561_sensor_name);

	IoTLib_register_sensor_init_function(sensorID, Adafruit_TSL2561_init);
	IoTLib_register_sensor_poll_function(sensorID, Adafruit_TSL2561_poll);
	IoTLib_register_sensor_store_unsent_data_function(sensorID, Adafruit_TSL2561_store_unsent_data);
	IoTLib_register_sensor_generate_upload_payload_function(sensorID, Adafruit_TSL2561_generate_upload_payload);
	IoTLib_register_sensor_retrieve_last_polled_time_function(sensorID, Adafruit_TSL2561_retrieve_last_polled_time);
	IoTLib_register_sensor_store_last_polled_time_function(sensorID, Adafruit_TSL2561_store_last_polled_time);

	IoTLib_register_sensor_max_operating_temp(sensorID, 80);
	IoTLib_register_sensor_min_operating_temp(sensorID, -30);
	IoTLib_register_sensor_poll_frequency(sensorID, 1);
}

static void _register_Adafruit_MCP9808()
{
	IoTLib_SensorID sensorID = IoTLib_register_sensor(adafruit_MCP9808_sensor_name);

	IoTLib_register_sensor_init_function(sensorID, Adafruit_MCP9808_init);
	IoTLib_register_sensor_poll_function(sensorID, Adafruit_MCP9808_poll);
	IoTLib_register_sensor_store_unsent_data_function(sensorID, Adafruit_MCP9808_store_unsent_data);
	IoTLib_register_sensor_generate_upload_payload_function(sensorID, Adafruit_MCP9808_generate_upload_payload);
	IoTLib_register_sensor_retrieve_last_polled_time_function(sensorID, Adafruit_MCP9808_retrieve_last_polled_time);
	IoTLib_register_sensor_store_last_polled_time_function(sensorID, Adafruit_MCP9808_store_last_polled_time);

	IoTLib_register_sensor_max_operating_temp(sensorID, 125);
	IoTLib_register_sensor_min_operating_temp(sensorID, -40);
	IoTLib_register_sensor_poll_frequency(sensorID, 1);
}

static float _fake_raw_to_temp_func(void* data)
{
	return 25;
}
