# gpioMain Makefile

lab5: main.o DE1SoChps.o GPIOControl.o
	g++ main.o DE1SoChps.o GPIOControl.o -o lab5

main.o : main.cpp DE1SoChps.h GPIOControl.h
	g++ -c main.cpp

DE1SoChps.o : DE1SoChps.cpp DE1SoChps.h
	g++ -c DE1SoChps.cpp

GPIOControl.o : GPIOControl.cpp GPIOControl.h
	g++ -c GPIOControl.cpp

clean:
	rm main.o DE1SoChps.o GPIOControl.o
