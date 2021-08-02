/*
 *  NB USI-device interrupt-free TWI driver
 *  Author: Gustavo Casanova
 *  .............................................
 *  File: nb-usitwisl-if.h (Slave driver headers)
 *  .............................................
 *  Version: 1.1.0 / 2021-07-25
 *  gustavo.casanova@nicebots.com
 *  .............................................
 *  Based on work by Atmel (AVR312) et others
 *  .............................................
 */

#ifndef NB_USITWISL_IF_H
#define NB_USITWISL_IF_H

// Includes
#include <avr/interrupt.h>
#include <stdbool.h>

#include "hw-mapping.h"

// Driver buffer definitions

// Allowed RX buffer sizes: 1, 2, 4, 8, 16, 32, 64, 128 or 256
#ifndef TWI_RX_BUFFER_SIZE
//#define TWI_RX_BUFFER_SIZE 32
#if defined(__AVR_ATtiny85__) | \
    defined(__AVR_ATtiny84__) | \
	defined(__AVR_ATtiny861__)
	#define TWI_RX_BUFFER_SIZE 128	// TWI RX buffer size, 8 KB flash, 64 B page devices
#elif defined(__AVR_ATtiny25__) | \
	  defined(__AVR_ATtiny24__) | \
	  defined(__AVR_ATtiny2313__) | \
	  defined(__AVR_ATtiny261__)
	#define TWI_RX_BUFFER_SIZE 32	// TWI RX buffer size, 2 KB flash, 32 B page devices
#elif defined(__AVR_ATtiny45__) | \
      defined(__AVR_ATtiny44__) | \
	  defined(__AVR_ATtiny4313__) | \
	  defined(__AVR_ATtiny43U__)
	#define TWI_RX_BUFFER_SIZE 64	// TWI RX buffer size, 4 KB flash, 64 B page devices
#elif defined(__AVR_ATtiny87__) | \
      defined(__AVR_ATtiny167__)
	#define TWI_RX_BUFFER_SIZE 128	// TWI RX buffer size, 8/16 KB flash, 128 B page devices
#else
	#define TWI_RX_BUFFER_SIZE 32	// TWI RX buffer size, undefined devices
#endif
#endif // TWI_RX_BUFFER_SIZE

#define TWI_RX_BUFFER_MASK (TWI_RX_BUFFER_SIZE - 1)

#if (TWI_RX_BUFFER_SIZE & TWI_RX_BUFFER_MASK)
#error TWI RX buffer size is not a power of 2
#endif // TWI_RX_BUFFER_SIZE & TWI_RX_BUFFER_MASK

// Allowed TX buffer sizes: 1, 2, 4, 8, 16, 32, 64, 128 or 256
#ifndef TWI_TX_BUFFER_SIZE
//#define TWI_TX_BUFFER_SIZE 32
#if defined(__AVR_ATtiny85__) | \
    defined(__AVR_ATtiny84__) | \
	defined(__AVR_ATtiny861__)
	#define TWI_TX_BUFFER_SIZE 128	// TWI TX buffer size, 8 KB flash, 64 B page devices
#elif defined(__AVR_ATtiny25__) | \
	  defined(__AVR_ATtiny24__) | \
	  defined(__AVR_ATtiny2313__) | \
	  defined(__AVR_ATtiny261__)
	#define TWI_TX_BUFFER_SIZE 32	// TWI TX buffer size, 2 KB flash, 32 B page devices
#elif defined(__AVR_ATtiny45__) | \
      defined(__AVR_ATtiny44__) | \
	  defined(__AVR_ATtiny4313__) | \
	  defined(__AVR_ATtiny43U__)
	#define TWI_TX_BUFFER_SIZE 64	// TWI TX buffer size, 4 KB flash, 64 B page devices
#elif defined(__AVR_ATtiny87__) | \
      defined(__AVR_ATtiny167__)
	#define TWI_TX_BUFFER_SIZE 128	// TWI TX buffer size, 8/16 KB flash, 128 B page devices
#else
	#define TWI_TX_BUFFER_SIZE 32	// TWI TX buffer size, undefined devices
#endif
#endif // TWI_TX_BUFFER_SIZE

#define TWI_TX_BUFFER_MASK (TWI_TX_BUFFER_SIZE - 1)

#if (TWI_TX_BUFFER_SIZE & TWI_TX_BUFFER_MASK)
#error TWI TX buffer size is not a power of 2
#endif // TWI_TX_BUFFER_SIZE & TWI_TX_BUFFER_MASK

// TWI driver operational modes
typedef enum {
    STATE_CHECK_RECEIVED_ADDRESS = 0,
    STATE_SEND_DATA_BYTE = 1,
    STATE_RECEIVE_ACK_AFTER_SENDING_DATA = 2,
    STATE_CHECK_RECEIVED_ACK = 3,
    STATE_RECEIVE_DATA_BYTE = 4,
    STATE_PUT_BYTE_IN_RX_BUFFER_AND_SEND_ACK = 5
} OverflowState;

// Function pointers
void (*p_receive_event)(uint8_t);

// USI TWI driver prototypes
void UsiTwiTransmitByte(const uint8_t data_byte);
uint8_t UsiTwiReceiveByte(void);
void UsiTwiDriverInit(void);
void TwiStartHandler(void);
bool UsiOverflowHandler(void);

#endif  // NB_USITWISL_IF_H
