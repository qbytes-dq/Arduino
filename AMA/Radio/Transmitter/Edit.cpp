/*
  Edit.h - Test library for Wiring - implementation
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// include core Wiring API
//#if defined(ARDUINO) && ARDUINO >= 100
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

// include this library's description file
#include "Edit.h"

// include description files for other libraries used (if any)
#include "HardwareSerial.h"

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

Edit::Edit(){
  // initialize this instance's variables

  // do whatever is required to initialize the library

}

// Public Methods //////////////////////////////////////////////////////////////
// Functions available in Wiring sketches, this library, and other libraries


/*
  Serial.print ("pttr ");
  Serial.println(PGMSTR(pttr));
  Serial.print ("volts_x_xxxV ");
  Serial.println(PGMSTR(volts_x_xxxV));
  Serial.print ("pgmData ");
  Serial.println(PGMSTR(myMenuData.pgmData[1]));

  sprintf_P(buffer, PSTR("%S") , pttr);
  Serial.print  ("buffer 1");
  Serial.println(buffer); 

void printOutMessage(const __FlashStringHelper* message){
  char buffer[40];
  sprintf_P(buffer, PSTR("Ha Ha %S") , message);
  Serial.println(buffer); 
}

sprintf_P(buffer, PSTR("%S") , myMenuData.pgmData[1]);
Serial.print  ("buffer 2");
Serial.println(buffer); 
 */

void Edit::doMaskInit(const  char *_mask, const  char _matchChar, byte _displayPos){
  mask = _mask;
char buffer[20];
  sprintf_P(buffer, PSTR("%S") , mask);
//  utils.reverse(buffer);  
  maskSize = utils.arraySize(buffer);
  matchChar = _matchChar;
  digitCnt = utils.countCharacters(buffer, matchChar);
  courserPos = -1;
  expoFactor = 0;
  displayPos = _displayPos;

  doMaskEdit(RIGHT);
}

// INIT, first time setup for mask, set defaults....
void Edit::doMaskEdit(byte _keyPress){
//  byte ccc = Edit::bbb;

//    sprintf_P(buffer2, PSTR("%S") , mask);

char buffer[20];
  sprintf_P(buffer, PSTR("%S") , mask);
  utils.reverse(buffer);  
/* Force navigation, Don't allow this to be passed in, store locally */
//const  char *mask,      // already have it
//const  char _matchChar, // already have it
//byte _courserPos        // already have it
/* Force navigation, Don't allow this to be passed in, store locally */
  
//  sprintf_P(buffer, PSTR("%S") , mask);
//  maskSize = utils.arraySize(buffer);
//  matchChar = _matchChar;
//  digitCnt = utils.countCharacters(buffer, matchChar);
//  courserPos = _courserPos;
//  expoFactor = 0;
  
  if (false){
  Serial.print  ("IN     : '");
  Serial.print  (buffer);  
  Serial.println("'");

  Serial.print  ("size   : ");
  Serial.println(maskSize);

  Serial.print  ("cnt'");
  Serial.print  (matchChar);
  Serial.print  ("' : ");
  Serial.println(digitCnt);  
  }
    
//  utils.reverse(buffer);

  int8_t tmpCurserPos = (uint8_t)courserPos;
  boolean done = false;
  int8_t dir = 0;

      Serial.print  ("tmpCurserPos ");
      Serial.print  (tmpCurserPos);
      Serial.println();
      
  if (_keyPress == RIGHT) {
    dir = 1;
  }
  if (_keyPress == LEFT) {
    dir = -1;
  }
    
  if (dir != 0) { //_keyPress == LEFT || _keyPress == RIGHT
    // Limit move to width of mask
    while(!done){
      bool cond1 = ((tmpCurserPos+dir) < 0);
      bool cond2 = ((tmpCurserPos+dir) >= maskSize);      
      Serial.print  (" Condition T:M:C ");
      bool cond = ((tmpCurserPos+dir) < 0 || (tmpCurserPos+dir >= maskSize));
      Serial.print  (tmpCurserPos+dir);
      Serial.print  (":");
      Serial.print  (maskSize - 1);
      Serial.print  (":");
      Serial.print  (cond);
      Serial.println();
      if (cond){
            Serial.println("range ==============");
            Serial.print  ("tmpCurserPos ");
            Serial.print  (tmpCurserPos);
            Serial.println();        
        done = true;
      }
      if (!done){
        // Allow moves only to '#' cells
Serial.println("!done");        
        tmpCurserPos += dir;
        if (buffer[tmpCurserPos] == matchChar){
          courserPos = tmpCurserPos;
          expoFactor += dir;
Serial.println("Inc/Dec ==============");        
          done = true;
        }
      } else {
        // End of mask, no match, no move
Serial.println("Fail =============="); 
Serial.print  ("tmpCurserPos ");
Serial.print  (tmpCurserPos);
Serial.println();       
        done = true;
      }
    }
  }

/*
  if (dir != 0) {
        Serial.print  ("dir ");
        Serial.print  (dir);
        Serial.println();
    // Limit move to width of mask
    while(!done){
        Serial.print  (" Condition ");
        Serial.print  (tmpCurserPos > 0 && tmpCurserPos < maskSize);
        Serial.println();
      if (tmpCurserPos >= 0 && tmpCurserPos < maskSize){
        // Allow moves only to '#' cells
        Serial.println("If ");        
        tmpCurserPos += dir;
        if (buffer[tmpCurserPos] == matchChar){
          courserPos = tmpCurserPos;
          expoFactor += dir;
        Serial.println("Inc");        
          done = true;
        }
      } else {
        // End of mask, no match, no move
        Serial.println("Fail");        
        done = true;
      }
    }
  }
*/

  if (true){
    Serial.print  (" _keyPress ");
    Serial.print  (_keyPress);
    Serial.print  (" dir ");
    Serial.print  ((int8_t)dir);
    Serial.print  ("\t tmpCurserPos ");
    Serial.print  ((int8_t)tmpCurserPos);  
    Serial.print  ("  \t courserPos ");
    Serial.print  (courserPos);

    buffer[courserPos] = '?';
    
    Serial.print  (" Post 1: '");
    Serial.print  (buffer);    
    Serial.print  ("'");        

    Serial.print  (" Post 2: '");
    utils.reverse(buffer);      
    Serial.print  (buffer);    
    Serial.print  ("'");        

    Serial.print  (" displayPos() ");
    Serial.print  (getDisplayPos());
    Serial.print  (" courserPos() ");
    Serial.print  (getCourserPos());

    Serial.print  (" expoFactor ");
    Serial.print  (expoFactor);

    Serial.println();        
  }
  
  if (false){   
    Serial.print  ("Reverse: '");
    for (byte b = 0; b < maskSize; b++){
      Serial.print (buffer[b]);
    } 
    Serial.println("'");
    Serial.print  ("Buffer : '");
    Serial.print  (buffer);    
    Serial.println("'");
  }

Serial.println();
Serial.println("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");     
}


byte Edit::getDisplayPos(){
  return displayPos;
}

byte Edit::getCourserPos(){
  return ((displayPos + (maskSize - 1)) - courserPos);
}

// Private Methods /////////////////////////////////////////////////////////////
// Functions only available to other functions in this library


