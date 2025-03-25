#include "i2c.h"

void configure_pins_i2c (struct i2c *self){

	/* Check which I2C interface */
	if (self->_interface == (uint32_t *) I2C2 ){

		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOFEN;

		/* I2C -> for STM32L4+ QF100 package PORTF F0, F1 */
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOFEN;

		/* Set to alternate functions (AF4) */
		GPIOF->MODER |= ALTERNATE_FUNCTION << GPIO_MODER_MODE0_Pos;
		GPIOF->MODER |= ALTERNATE_FUNCTION << GPIO_MODER_MODE1_Pos;

		/* Set alternate function */
		GPIOF->AFR |= AF4 << GPIO_AFRL_AFSEL0_Pos;
		GPIOF->AFR |= AF4 << GPIO_AFRL_AFSEL1_Pos;

		/* Set pins to open drain */
		GPIOF->OTYPER |= GPIO_OTYPER_OT0;
		GPIOF->OTYPER |= GPIO_OTYPER_OT1;

		/* Set pins to pull up */
		GPIOF->PUPDR |= PULL_UP << GPIO_PUPDR_PUPD0_Pos;
		GPIOF->PUPDR |= PULL_UP << GPIO_PUPDR_PUPD1_Pos;
	}
}

void init_i2c (struct i2c *self){

	/* Configure pins */
	configure_pins_i2c(self);

	/* Configure F0 and F1 as alternate function */

	/* Configure SCLH and SCLL in the I2C_TIMINGR */
}


