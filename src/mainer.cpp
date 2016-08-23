#include "application.h"


SYSTEM_MODE(MANUAL);

void setup()
{

	WiFi.off();
	pinMode(D7, OUTPUT);
}

void loop()
{
	delay(1000);
	delay(1000);
	digitalWrite(D7, HIGH);
	digitalWrite(D7, LOW);
}
