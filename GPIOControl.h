//Christopher Swagler

class GPIOControl : public DE1SoChps
{
public:
	//constructor to set GPIO1 bits
	GPIOControl();
	//destructor
	~GPIOControl();
	//turn LED on or off
	void LEDOnOff(int state);
	//return state of button
	int ButtonRead();
	//load the timer
	void Timer0Setup(int s);
	//queries interrupt status of timer
	int Timer0Int();
};
