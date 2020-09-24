/*
  hw-mapping.h
  =================================
  Library hardware mapping
  ---------------------------------
  Version: 1.0.2 / 2020-09-19
  ---------------------------------
*/

#ifndef HARDWARE_MAPPING_H
#define HARDWARE_MAPPING_H

// ATtinyX5
#if defined(__AVR_ATtiny25__) | \
    defined(__AVR_ATtiny45__) | \
    defined(__AVR_ATtiny85__)
#define DDR_USI DDRB
#define PORT_USI PORTB
#define PIN_USI PINB
#define PORT_USI_SDA PB0
#define PORT_USI_SCL PB2
#define PIN_USI_SDA PINB0
#define PIN_USI_SCL PINB2
#define TWI_START_COND_FLAG USISIF  // Status register flag: indicates an I2C START condition on the bus (can trigger an interrupt)
#define USI_OVERFLOW_FLAG USIOIF    // Status register flag: indicates a complete bit reception/transmission (can trigger an interrupt)
#define TWI_STOP_COND_FLAG USIPF    // Status register flag: indicates an I2C STOP condition on the bus
#define TWI_COLLISION_FLAG USIDC    // Status register flag: indicates a data output collision on the bus
#define TWI_START_COND_INT USISIE   // Control register bit: defines whether an I2C START condition triggers an interrupt
#define USI_OVERFLOW_INT USIOIE     // Control register bit: defines whether a USI 4-bit counter overflow triggers an interrupt
#endif

// ATtinyX4
#if defined(__AVR_ATtiny24__) | \
    defined(__AVR_ATtiny44__) | \
    defined(__AVR_ATtiny84__)
#define DDR_USI DDRA
#define PORT_USI PORTA
#define PIN_USI PINA
#define PORT_USI_SDA PORTA6
#define PORT_USI_SCL PORTA4
#define PIN_USI_SDA PINA6
#define PIN_USI_SCL PINA4
#define TWI_START_COND_FLAG USISIF  // Status register flag: indicates an I2C START condition on the bus (can trigger an interrupt)
#define USI_OVERFLOW_FLAG USIOIF    // Status register flag: indicates a complete bit reception/transmission (can trigger an interrupt)
#define TWI_STOP_COND_FLAG USIPF    // Status register flag: indicates an I2C STOP condition on the bus
#define TWI_COLLISION_FLAG USIDC    // Status register flag: indicates a data output collision on the bus
#define TWI_START_COND_INT USISIE   // Control register bit: defines whether an I2C START condition triggers an interrupt
#define USI_OVERFLOW_INT USIOIE     // Control register bit: defines whether a USI 4-bit counter overflow triggers an interrupt
#endif

#endif  // HARDWARE_MAPPING_H
