//Christopher Swagler

#include "DE1SoChps.h"
#include "GPIOControl.h"

int main() {
	//declare object for GPIOControl class
	GPIOControl gpio;
	//while the button is not pressed
	while (gpio.ButtonRead() != 1) {
		//setup the timer to be 2 seconds
		gpio.Timer0Setup(2);
		//while the interrupt status is not active and button not press
		//once it turns to 1, it breaks the loop
		//and the function already resets the timer interrupt when happens
		while ((gpio.Timer0Int() == 0) && (gpio.ButtonRead() != 1)) {
			//have the led on
			gpio.LEDOnOff(1);
		}
		//setup the timer to be 2 seconds
		gpio.Timer0Setup(2);
		//while the interrupt status is not active and button not press
		while ((gpio.Timer0Int() == 0) && (gpio.ButtonRead() != 1)) {
			//have the led off
			gpio.LEDOnOff(0);
		}
	}
	return 0;
}
