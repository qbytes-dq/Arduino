///*
//  _Test.h - _Test library for Wiring - implementation
//  Copyright (c) 2006 John Doe.  All right reserved.
//*/
//
//// include core Wiring API
////#if defined(ARDUINO) && ARDUINO >= 100
//#if ARDUINO >= 100
//  #include "Arduino.h"
//#else
//  #include "WProgram.h"
//  #include "pins_arduino.h"
//  #include "WConstants.h"
//#endif
//
//// include this library's description file
//#include "_Test.h"
//
//// include description files for other libraries used (if any)
//#include "HardwareSerial.h"
//
//// Constructor /////////////////////////////////////////////////////////////////
//// Function that handles the creation and setup of instances
//
//_Test::_Test(int givenValue){
//  // initialize this instance's variables
//  value = givenValue;
//
//  // do whatever is required to initialize the library
////  pinMode(13, OUTPUT);
////  Serial.begin(115200);
//}
//
//// Public Methods //////////////////////////////////////////////////////////////
//// Functions available in Wiring sketches, this library, and other libraries
//
//void _Test::doSomething(void)
//{
//  // eventhough this function is public, it can access
//  // and modify this library's private variables
//  Serial.print("value is ");
//  Serial.println(value);
//
//  // it can also call private functions of this library
//  doSomethingSecret();
//}
//
//// Private Methods /////////////////////////////////////////////////////////////
//// Functions only available to other functions in this library
//
//void _Test::doSomethingSecret(void)
//{
//  digitalWrite(13, HIGH);
//  delay(200);
//  digitalWrite(13, LOW);
//  delay(200);
//}
//
//// Protected Methods //////////////////////////////////////////////////////////
//// Functions only available to other functions in this library and inherited classes
//

