//Christopher Swagler

#include "DE1SoChps.h"
#include "GPIOControl.h"

//constructor to set bits for I/O on GPIOs
GPIOControl::GPIOControl() {
	cout << "Initializing GPIOs...!" << endl;
	int current = RegisterRead(gpio1_ddr_offset);
	//bit 24 needs to be set to 1 for output
	current = current | (1 << 24);
	//bit 25 needs to be set to 0 for input
	current = current & ~(1 << 25);
	//write these values
	RegisterWrite(gpio1_ddr_offset, current);
}

//destructor
GPIOControl::~GPIOControl() {
	cout << "Done using GPIOs...!" << endl;
}

//set led
void GPIOControl::LEDOnOff(int state) {
	int ledreg = RegisterRead(gpio1_dr_offset);
	//distinguish on/off state
	if (state == 1) {
		//turn on the led bit
		ledreg = ledreg | (1 << 24);
	} else if (state == 0) {
		//turn off the led bit
		ledreg = ledreg & ~(1 << 24);
	}
	//write to the register to output on/off
	RegisterWrite(gpio1_dr_offset, ledreg);
}

//read value from button
int GPIOControl::ButtonRead() {
	int btn = RegisterRead(gpio1_ext_port_offset);
	//if the 25 bit is 1, button is not pressed, return 0
	if (((btn >> 25) % 2) == 1) {
		return 0;
	//if the 25 bit is 0, button is pressed, return 1
	} else if (((btn >> 25) % 2)  == 0) {
		return 1;
	}
}

//setup timer
void GPIOControl::Timer0Setup(int s) {
	//set bit2 to unmask interrupt: 0
	//set bit1 to put in user defined count mode: 1
	//set bit0 to disable timer: 0
	//says other bit values don't need to be maintained, so just write this
	RegisterWrite(timer0_control_reg, 0b010);
	//load timer with inputted value times 100 M so timer interrupt every s seconds
	RegisterWrite(timer0_load_reg, (s * 100000000));
	//set bit0 to enable the timer: 1
	RegisterWrite(timer0_control_reg, 0b011);
}

//obtains interrupt status of timer
int GPIOControl::Timer0Int() {
	//set interrupt to the value of the interrupt status
	//bit0 is 1 if active, 0 otherwise
	int interrupt = RegisterRead(timer0_int_stat_reg) % 2;
	//read from this register to clear the timer if active
	if (interrupt == 1) {
		int reset = RegisterRead(timer0_eoi_reg);
	}
	return interrupt;
}
