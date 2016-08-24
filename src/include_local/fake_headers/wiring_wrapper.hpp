#ifndef WIRING_WRAPPER_H
#define WIRING_WRAPPER_H

#ifndef Wire
	#define Wire wiring_wrapper
#endif

class WiringWrapper
{
	public:
		static void begin();
		static void beginTransmission(uint8_t);
		static size_t send(uint8_t);
		static size_t write(uint8_t);
		static int receive();
		static int read();
		static uint8_t endTransmission();
		static uint8_t requestFrom(uint8_t, uint8_t);
};

extern WiringWrapper wiring_wrapper;

#endif
