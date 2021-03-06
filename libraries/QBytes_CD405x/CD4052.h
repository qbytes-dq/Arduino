/*
  Test.h - Test library for Wiring - description
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef CD4052_h
#define CD4052_h

// include types & constants of Wiring core API
#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif


// library interface description
class CD4052{
  // user-accessible "public" interface
  public:
	CD4052(void);
	CD4052(int _addrA, int _addrB, int _pinX, int _pinY);
	void setChannel(int channel);
	int analogReadX();
	int analogReadY();
	int digitalReadX();
	int digitalReadY();
		
  // library-accessible "private" interface
  private:
	int addrA;
	int addrB;
	int adcX;
	int adcY;
};

#endif //CD4052_h
