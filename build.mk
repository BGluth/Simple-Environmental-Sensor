CPPSRC += $(call target_files,src/,*.cpp)

CSRC += $(call target_files,lib/IoT_Library/source/src,*.c)
CPPSRC += $(call target_files,lib/Sensor_Libraries/Adafruit/Adafruit_TSL2561,*.cpp)

INCLUDE_DIRS += $(APPDIR)/src/include
INCLUDE_DIRS += $(APPDIR)/src/include_local
INCLUDE_DIRS += $(APPDIR)/src/include_local/fake_headers

INCLUDE_DIRS += $(APPDIR)/lib/IoT_Library/source/include
INCLUDE_DIRS += $(APPDIR)/lib/IoT_Library/source/include_local
INCLUDE_DIRS += $(APPDIR)/lib/Sensor_Libraries/Adafruit/Adafruit_Sensor
INCLUDE_DIRS += $(APPDIR)/lib/Sensor_Libraries/Adafruit/Adafruit_TSL2561

all: 