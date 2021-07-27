# nb-usitwisl-if
USI-based interrupt-free TWI (I2C) slave driver for ATTiny microcontrollers

This driver is designed to be used in I2C applications that require to operate without using the microcontroller standard interrupts. In fact the application must disable the interrupts at start. It is used almost exclusively in  [bootloaders](https://github.com/casanovg/timonel) and similar applications.

For standard user applications, it is recommended to use a driver [version that uses interrupts](https://github.com/casanovg/nb-usitwisl).
