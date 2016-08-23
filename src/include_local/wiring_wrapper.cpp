#include "application.h"
#include "wiring_wrapper.hpp"

void WiringWrapper::begin()
{
	Wire.begin();
}

void WiringWrapper::beginTransmission(uint8_t address)
{
	Wire.beginTransmission(address);
}

size_t WiringWrapper::send(uint8_t value)
{
	return Wire.write(value);
}

int WiringWrapper::receive()
{
	return Wire.read();
}

uint8_t WiringWrapper::endTransmission()
{
	return Wire.endTransmission();
}

uint8_t WiringWrapper::requestFrom(uint8_t address, uint8_t quantity)
{
	return Wire.requestFrom(address, quantity);
}

WiringWrapper wiring_wrapper;
