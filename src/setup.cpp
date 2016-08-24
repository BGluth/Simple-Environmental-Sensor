#include "setup_local.hpp"
#include "setup.hpp"
#include "device_registration.hpp"
#include "application.h"

void run_setup()
{
	setup_pins();
	register_all_functions();
}

static void setup_pins()
{
	pinMode(D0, OUTPUT); // I2C SCL
	pinMode(D1, OUTPUT); // I2C SDA

	pinMode(D7, OUTPUT); // Debug LED
}
