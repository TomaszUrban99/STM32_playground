#ifndef I2C_H_
#define I2C_H_

#include <stm32l4s5xx.h>

/* Addressing modes */
#define I2C_BITS_ADDR_7		0
#define I2C_BITS_ADDR_10	1

/* Speed modes */
#define I2C_STANDARD_MODE 		0

/* I2C mode */
#define SLAVE_TRANSMITTER		0
#define SLAVE_RECEIVER			1
#define MASTER_TRANSMITTER		2
#define MASTER_RECEIVER			3

/* PINS */
#define PIN0					0
#define PIN1					1

/* Alternate function */
#define ALTERNATE_FUNCTION		2

#define AF4						8

/* Pull-up/pull-down register */
#define PULL_UP					1
#define PULL_DOWN				2

/*!
 *
 */
struct i2c {

	uint8_t _addressing_mode;
	uint8_t _speed_mode;

	uint32_t *_interface;

};

void configure_pins_i2c (struct i2c *self);

void init_i2c (struct i2c *self);

#endif
