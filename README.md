# nb-usitwisl-if
USI-based interrupt-free TWI (I2C) slave driver for ATtiny microcontrollers

This driver is for Microchip (ex Atmel) ATtiny devices that implement the I2C protocol by using the Universal Serial Interface (USI) peripheral, that is, microcontrollers that are not equipped with I2C-specific hardware.

This particular version is designed for applications that cannot use the microcontroller standard interrupt vectors. In fact, the application should disable interrupts at startup to implement this software. It is used almost exclusively in  [bootloaders](https://github.com/casanovg/timonel) and similar applications.

For standard I2C applications, it is recommended to use a driver [version that uses interrupts](https://github.com/casanovg/nb-usitwisl).
