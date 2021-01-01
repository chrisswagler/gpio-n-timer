//Christopher Swagler
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>
using namespace std;

/* Cyclone V HPS devices */
const unsigned int HPS_BRIDGE_BASE 	= 0xFF700000;  // Base offset
const unsigned int HPS_BRIDGE_SPAN 	= 0x006FFFFF;  // Span

const unsigned int gpio1_dr_offset	= 0x9000;	// output
const unsigned int gpio1_ddr_offset	= 0x9004;	// set I/O
const unsigned int gpio1_ext_port_offset= 0x9050;	// input
const unsigned int timer0_load_reg 	= 0x508000;	// load timer
const unsigned int timer0_curr_val_reg	= 0x508004;	// get current timer
const unsigned int timer0_control_reg	= 0x508008;	// control timer
const unsigned int timer0_eoi_reg	= 0x50800C;	// clear interrupt
const unsigned int timer0_int_stat_reg	= 0x508010;	// interrupt status

//class for main functions of the de1soc board from previous program
class DE1SoChps
{
private:
	//private members
	char *pBase;
	int fd;
public:
	//default constructor (Initialize from previous program)
	DE1SoChps();
	//destructor (Finalize from previous program)
	~DE1SoChps();
	//write to the board
	void RegisterWrite(unsigned int offset, int value);
	//read from the board
	int RegisterRead(unsigned int offset);
};
