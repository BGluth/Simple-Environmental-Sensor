##### Current status:

(5/9/2016)
- Project is not yet complete and is currently more of a proof of concept.
- This repo page is currently pretty minimal. Once the project gets further along it will become more complete. 

## What?

Firmware for an IoT device with seven attached sensors which takes frequent different environmental measurements. Uses a C library called the [IoT Library](https://github.com/BGluth/IoT-Library) that provides general functionality for IoT devices.

#### Hardware:

- **Sensors:**
    - [Luminosity](https://www.adafruit.com/product/439)
    - [Temperature](https://www.adafruit.com/product/1782)
    - [Noise](https://www.adafruit.com/products/2716)
    - [PM 2.5](http://breathe.indiaspend.org/wp-content/uploads/2015/11/nova_laser_sensor.pdf)
    - [Ozone](https://www.controleverything.com/content/Gas?sku=ADC121C_I2CGAS_MQ131)
    - [Wind speed and direction](http://store.switchdoc.com/weatherrack-anemometer-wind-rain-for-weatherpiarduino-weatherplus-raspberry-pi-arduino/)

- **Other:**
    - [Particle Photon](https://docs.particle.io/datasheets/photon-datasheet/)
	- [LoRa transceiver](https://www.adafruit.com/products/3072)
	- [Solar panel](https://www.adafruit.com/products/200) - May change...
	- [MPPT solar charging circuit](http://www.ebay.com/itm/BQ24650-5A-MPPT-Solar-Panel-Lithium-Lead-acid-Battery-Charging-Controller-Board-/171753976645) - Heavy Chinglish warning!
	- [900mm MHZ antenna](https://www.digikey.ca/product-detail/en/abracon-llc/APAMS-118/535-12911-ND/5226432)
	- [SMA connector for antenna](https://www.digikey.ca/product-detail/en/taoglas-limited/EMPCB.SMAFSTJ.B.HT/931-1175-ND/3522337)
	- 3X [Cyclon battery (2V 2.5Ah)](https://www.digikey.ca/product-detail/en/enersys/0810-0004/842-1000-ND/2003832)
	- [Linear voltage regulator (3.3V out)](https://www.digikey.ca/product-detail/en/stmicroelectronics/LD1117V33C/497-1492-5-ND/586013)
	- [Enclosure](http://www.homedepot.com/p/Carlon-6-in-x-6-in-x-4-in-PVC-Junction-Box-3-per-Case-E987RR/202206112) - Potentially may not be the exact one that I'm using, but it's close.
 
##### Features:
- Periodically uploads data to a server backend using a [LoRa](https://www.lora-alliance.org/) transceiver
- Stores sensor data locally if no upload connection can be made or if not enough time has passed to perform an upload
- Only runs sensors if the current outdoor temperature is within their operating range
- Sensors are polled at different rates
- Low-ish power consumption

### Schematic of current hardware setup
In progress...

## Why?
TODO

## Building
There are two available options that you can choose to build this project and flash it onto a Particle device.

You can either:

1. Use either the Atom IDE setup that particle provides (either [locally downloaded](https://www.particle.io/products/development-tools/particle-local-ide) or  [cloud based](https://docs.particle.io/guide/getting-started/build/photon/#logging-in))
    - This is by far the simplest option to get going quick, but the downside is that you will be using an IDE that is pretty simple ATM (very limited auto-completion, etc.)
2. Setup the toolchain for building firmware for Particle devices on your local machine. This will allow you to use whatever IDE you want that can be customized to run other programs.
    - This is the route that I went. For me I spent many frustrating hours trying to get the build system off the ground.
    - If you go this route, you can either:
        - Use a [premade installer](https://community.particle.io/t/toolchain-for-windows-installer/13217)
        - Manually [install the toolchain yourself](https://github.com/spark/firmware/blob/develop/docs/gettingstarted.md)
            - If you decide to build locally, please beware that if you are working in Windows, you are very likely going to run into some major "fun" with GNU Make. In particular:
                - If you have file paths in your PATH variable that contain brackets "()", make will crash and give you a very cryptic and unhelpful error.
                    - If you're on Windows, you have normal paths that contain brackets (ie. "Program Files (x86)") which you can't change.
                    - So to get around this, since make reads PATH in order from beginning to end, make sure you put what it needs to find ahead of any path that contains brackets.
                - Make also strongly dislikes spaces. While it won't crash from simply reading a path that contains a space, if it's working with a path that contains a space, it will give you errors related to not being able to a path not existing. This is because whenever it sees a space, it thinks the path ends there. Solution is simple; replace the space with an "_" or similar.
            - There is also an automatic installer [here](https://community.particle.io/t/toolchain-for-windows-installer/13217)

## Development
If you're interested in contributing to this project, issues and pull requests are totally welcome!