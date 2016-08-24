#ifndef EnvSnr_REGISTRATION_LOCAL_H
#define EnvSnr_REGISTRATION_LOCAL_H

static void _register_non_sensor_specific_functions();
static void _register_sensor_specific_functions();
static void _register_Adafruit_TSL2561();
static float _fake_raw_to_temp_func(void* data);

#endif
