#include "setup.hpp"
#include "application.h"

#include "registration_api.h"

SYSTEM_MODE(MANUAL);

void setup()
{
	delay(6000); // Hack so that I have time to connect with a PC.

	Serial.begin(9600);
	Serial.println("STARTING!!");
	WiFi.off();

	run_setup();
}

void loop()
{
	delay(1000);
	digitalWrite(D7, HIGH);

	IoTLib_run();

	digitalWrite(D7, LOW);
}
