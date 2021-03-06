/*
  Menu.h - Menu library for Wiring - description
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef Menu_h
#define Menu_h

// include types & constants of Wiring core API
//#if defined(ARDUINO) && ARDUINO >= 100
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif


#include <LiquidCrystal_I2C.h>
#include "config.h"
#include "def.h"
#include "types.h"
#include "utils.h"

#include "CustomChar.h"
#include "Data.h"
#include "DataStore.h"
#include "Display.h"
#include "DisplayMask.h"

// library interface description
class Menu
{
  Utils utils;
  // ===========================================
  // user-accessible "public" interface
  // ===========================================
  public:
    Menu(Data *, DataStore *);

    boolean isScreenRefreshNeeded(void);
    void updateLCD(byte);

    void updateFPS(void);
    
    void menuDisplay(void);
    void menuChangeCheck(void);
    void menuKeyboard(byte);

    void forceMenuChange(byte);
    
    void funcKeyboard(byte);
    void funcChangeCheck(void);
    void funcDisplay(byte);
    
    void setMenu(byte, byte [], byte);
    void setVisible(void);

    void lcdPrint(byte, byte, PGM_P);

    boolean cntrlHome();
    // ===========================================
    // *   0 -   1 = Main Menu(s)
    // ===========================================
    void lcdMenu000(void);
    void lcdMenu001(void);

    // ===========================================
    // *   2 -  49 = Transmitter
    // ===========================================
    void lcdTx002(void);
    void lcdTx003(void);    
    void lcdTx010(void);
    void lcdTx011(void);
    void lcdTx012(void);
    void lcdTx013(void);
    void lcdTx014(void);

    void lcdTx022(void);

    // ===========================================
    // *  50 -  99 = Models
    // ===========================================
    void lcdMod050(void);
    
    
    // ===========================================
    // * 100 - 149 = System (Resistors, Voltages)
    // ===========================================
    void lcdSys100(void); // OHMs & Volts / Controls / Factory Reset

    void lcdSys101(void); // OHMs & Volts
    
    void lcdSys102(void); // OHMs for Pre, Pst & V5.0    
    void lcdSys104(void); // OHMs Vin pre 1.1 & 1.2 OHMs
    void lcdSys105(void); // OHMs Vin pst 2.1 & 2.2 OHMs
    void lcdSys106(void); // OHMs V5.0    3.1 & 3.2 OHMs

    void lcdSys110(void); // Volts for Shunt & 5V Ref
    void lcdSys112(void); // Volts Shunt OHMs 
    void lcdSys114(void); // Volts V5.0 Reference
    
    void lcdSys116(void); // Voltage for Pre, Post & V5 Regulator

    void lcdSys122(void); // Switch / Trim / Menu buttons

    void lcdSys130(void); // Controls - Aux / Joystick / Sw & Btn
    
      void lcdSys131(void); // Throttle - Joystick select Left/Right range limits  
        void lcdSys134(void); // Edit - Throttle - Joystick range limits (Uses             editJoystick 0)    
    //  void lcdSys135(void); // Edit - Yoke     - Joystick range limits (Uses lcdSys134 , editJoystick 1)
    //  void lcdSys138(void); // Edit - Roll     - Joystick range limits (Uses lcdSys134 , editJoystick 2)
    //  void lcdSys139(void); // Edit - Pitch    - Joystick range limits (Uses lcdSys134 , editJoystick 3)

  
      void lcdSys140(void); // AUX [0-3](Display all)
      void lcdSys141(void); // AUX [0]
      void lcdSys142(void); // AUX [1]
      void lcdSys143(void); // AUX [2]
      void lcdSys144(void); // AUX [3]
      void lcdSys145(void); // Edit - AUX [x] Range Limit Edit


    void lcdSys149(void); // System Reset

    
    // ===========================================
    // * 150 - 199 = START/INIT
    // ===========================================
    void lcdInit150(void); // Starting [click (select) out to 254]
    void lcdInit151(void); // Splash   [no click 'select button' out to 151]
    
    void lcdInit191(void); // Save to EEPROM
    void lcdInit192(void); // Control check

    void lcdInit199(void); // Error, restart

    // ===========================================
    // * 200 - 254 = Functions
    // ===========================================
//  void lcdFunc200(void); // Bool T/F
//  void lcdFunc201(void); // Bool Y/N
//  void lcdFunc207(void); //  8 bit Signed
//  void lcdFunc208(byte); //  8 bit Unsigned
    void lcdFunc215(void); // 16 bit Signed
    void lcdFunc216(byte); // 16 bit Unsigned
//  void lcdFunc231(void); // 32 bit Signed
//  void lcdFunc232(byte); // 32 bit Unsigned

    void lcdFunc237(void); // EEPROM Erase  --> move to 25x range
    void lcdFunc238(void); // EEPROM Read   --> move to 25x range
    void lcdFunc239(void); // EEPROM Write  --> move to 25x range
    
    void lcdFunc240(void); // Joystick Controls Range 
    void lcdFunc241(void); // Aux Controls Range 
    // ===========================================
    // *       255 = Reserved for FUNCTION switch indicator 
    // ===========================================
    void lcdInit255(void); // this is an error, 255 is reserved 


    // ===========================================
    // ===========================================
    
    CustomChar customChar = CustomChar();
    Display display = Display();


    char buffer[20];  //  Hold The Convert Data (width of the LCD)
    
    byte menuRow = 0;
    byte menuCol = 0;
    
    byte repeatCount = 0;
    
    byte menuSelected = INITMENU;

    byte error;
    
    byte function = 0;
    boolean isMenuChange = true;
    boolean isFuncChange = true;
   
    //===============================================================================
    //===============================================================================
    //===============================================================================
    
    // Declare variables
    //https://arduino.stackexchange.com/questions/19748/copy-content-of-array
    //https://arduino.stackexchange.com/questions/21095/how-to-write-array-of-functions-in-arduino-library
    //https://arduino.stackexchange.com/questions/21095/how-to-write-array-of-functions-in-arduino-library

    // =======================================
    // =======================================
    // =======================================
    // *         0 = Main Menu(s)
    // =======================================
    // =======================================
    // =======================================
    byte menuOptions000 [1] = {1};
    byte menuOptions001 [4] = {MAINMENU, 2, 50, 100};


    // =======================================
    // =======================================
    // =======================================
    // *   2 -  49 = Transmitter
    //
    // #define MAINMENU  1   // Main Menu
    // #define X_MITTER  2   // Transmitter Main Menu   
    // =======================================
    // =======================================
    // =======================================    
    
    byte menuOptions002 [1] = {MAINMENU};
    byte menuOptions003 [1] = {MAINMENU};
    
    byte menuOptions010 [4] = {MAINMENU, 11, 12, 13};
    byte menuOptions011 [1] = {10};
    byte menuOptions012 [1] = {10};
    byte menuOptions013 [1] = {10};
    byte menuOptions014 [1] = {10};

    
    // =======================================
    // =======================================
    // =======================================
    // *  50 -  99 = Models
    //
    // #define MODEL     50  // Model Main Menu
    // =======================================
    // =======================================
    // =======================================
    byte menuOptions050 [1] = {MAINMENU};
    
    // =======================================
    // =======================================
    // =======================================
    // * 100 - 149 = System (Resistors, Voltages, Switches and Controls values/limits)
    //
    // #define SYSTEM    100 // System Menu
    // =======================================
    // =======================================
    // =======================================
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//===============================
// System - Ohms or Voltage / Control Range / Reset 
byte menuOptions100 [4] = {MAINMENU, 101, 130, 149};
//===============================
  
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // (101) - Ohms / Switches / Voltages
  byte menuOptions101 [3] = {SYSTEM, 102, 110};

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // (102) - Ohms
  byte menuOptions102 [4] = {104,105, 106, 112};  // Pre, Pst, Ref Menu & Shunt
  //-------------------------------
    byte menuOptions104 [2] = {101, 216};  // Vin  pre 1.1 & 1.2 OHMs
    byte menuOptions105 [2] = {101, 216};  // Vin  pst 2.1 & 2.2 OHMs
    byte menuOptions106 [2] = {101, 216};  // V5.0 Ref 3.1 & 3.2 OHMs
    byte menuOptions112 [2] = {101, 216};  // Shunt OHMs

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // (110) -  Reference
  byte menuOptions110 [3] = {101, 114, 116};
  //-------------------------------
    byte menuOptions114 [2] = {110, 216};      // 110 - V5.1 Reference Voltage Measured
    byte menuOptions116 [1] = {110};           // 110 - All Voltages (Pre, Post & V5 Regulator)
  //-------------------------------
  byte menuOptions140 [4] = {141, 142, 143, 144};           // 101 - Aux[0-3]
  byte menuOptions141 [2] = {130, 241};           // Aux[0]
//  byte menuOptions142 [2] = {130, 241};           // Aux[1]
//  byte menuOptions143 [2] = {130, 241};           // Aux[2]
//  byte menuOptions144 [2] = {130, 241};           // Aux[3]

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    //-------------------------------
    byte menuOptions122 [1] = {130};      // Switches * Btns

//===============================
byte menuOptions130 [4] = {SYSTEM,140,131, 122};// AUX, Joystick, Switches
  //-------------------------------
      
  byte menuOptions131 [4] = {134,135,136,137}; // Control Range Limits (all)    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        byte menuOptions134 [2] = {130, 240};      // Throttle
//      byte menuOptions135 [2] = {130, 240};      // Yaw
//      byte menuOptions136 [2] = {130, 240};      // Roll
//      byte menuOptions137 [2] = {130, 240};      // Pitch


//===============================
// Reset Menu
byte menuOptions149 [3] = {SYSTEM, 237, SYSTEM};      // Factory Reset  (149 should be Y/N function)
//===============================

    // =======================================
    // =======================================
    // =======================================
    // * 150 - 199 = START/INIT
    // =======================================
    // =======================================
    // =======================================
    byte menuOptions150 [1] = {INITMENU};           // Starting   [no click (select) out of 150]
    byte menuOptions151 [3] = {SPLASH};             // Splash     [no click (select) out of 151]
    
    byte menuOptions152 [3] = {154,216,216};        // Vin pre 1.1 & 1.2 OHMs
    byte menuOptions154 [3] = {156,216,216};        // Vin pst 2.1 & 2.2 OHMs
    byte menuOptions156 [3] = {162,216,216};        // V5.0    3.1 & 3.2 OHMs

    byte menuOptions162 [2] = {164,216};            // Shunt OHMs
    byte menuOptions164 [2] = {172,216};            // V5.0    Reference Voltage 

    byte menuOptions172 [1] = {182};                // Switches & Btns
//    byte menuOptions174 [1] = {176};                // Trim
//    byte menuOptions176 [1] = {182};                // Menu

    byte menuOptions182 [2] = {183,240};            // Throttle - Joystick range limits
    byte menuOptions183 [2] = {184,240};            // Yaw      - Joystick range limits
    byte menuOptions184 [2] = {185,240};            // Roll     - Joystick range limits
    byte menuOptions185 [2] = {186,240};            // Pitch    - Joystick range limits

    byte menuOptions186 [2] = {187,241};            // Aux range limits 0
    byte menuOptions187 [2] = {188,241};            // Aux range limits 1
    byte menuOptions188 [2] = {189,241};            // Aux range limits 2
    byte menuOptions189 [2] = {191,241};            // Aux range limits 3


    // 190 -- // Need to show voltages here???? or on the Resister screen???
     byte menuOptions191 [1] = {CTLCHECK};       // Save data to EEPROM
    
    byte menuOptions192 [1] = {CTLCHECK};           // Control Check (make sure all surfaces & switches are homed. (Prevent flight by mistake) [no click (select) out of 192]
    byte menuOptions199 [1] = {INITMENU};           // Error, run INIT

    // =======================================
    // =======================================
    // =======================================
    // * 200 - 254 = Functions
    // =======================================
    // =======================================
    // =======================================
    //byte menuOptions207 [1] = {FUNCTION};       // Function for number edit
    //byte menuOptions208 [1] = {FUNCTION};       // Function for number edit

    //byte menuOptions215 [1] = {FUNCTION};       // Function for number edit
    //byte menuOptions216 [1] = {FUNCTION};       // Function for number edit

    //byte menuOptions231 [1] = {FUNCTION};       // Function for number edit
    //byte menuOptions232 [1] = {FUNCTION};       // Function for number edit

    //byte menuOptions237 [1] = {FUNCTION};       // Function for EEPROM erase
    //byte menuOptions238 [1] = {FUNCTION};       // Function for EEPROM read
    //byte menuOptions239 [1] = {FUNCTION};       // Function for EEPROM write

    //byte menuOptions240 [1] = {FUNCTION};       // Function to do Joystick Range settings
    //byte menuOptions241 [1] = {FUNCTION};       // Function to do AUX Range settings

    //byte menuOptions25x [1] = {FUNCTION};       // Function for check for Factory Reset
    //byte menuOptions25x [1] = {FUNCTION};       // Function to do Factory Reset

    // =======================================
    // =======================================
    // =======================================
    // * 254 = Reserved for Error Display
    // * 255 = Reserved for FUNCTION switch indicator
    // =======================================
    // =======================================
    // =======================================  
    byte menuOptions254 [0] = {/* Do NOT use: reserved */};
    byte menuOptions255 [0] = {/* Do NOT use: reserved */};    

    // ===========================================
    // library-accessible "private" interface
    // ===========================================
    private:

      byte editControl = 0;

      byte menuOptions[4];
      byte menuSize;

      enum MenuAction {
        doInit,
        doMenu,
        doFunc,
      } menuAction = doInit;

      void printDrmc(void);  // test only, delete this and the method
      void clearDisplayMask(void);
      
      Data * data;   
      DataStore * dataStore;
      DisplayMask displayMask[4];

      byte menuCarrotStart;

    // ===========================================
    // Screen RefreshTiming Vars
    // ===========================================
    unsigned long  intervalScreenRefresh = 1000 / 4; // 4 times per second
    unsigned long  previousScreenRefreshMiilis = 0;

    // ===========================================
    // Screen RefreshTiming Vars
    // ===========================================
    unsigned long previousMillisFPS = 0;        // will store last time LED was updated
    const unsigned long intervalFPS = 1000;           // interval at which to update screen (milliseconds)
    
    int showFPS = 0;
    int cntFPS  = 0;  

  // ===========================================
  // library-accessible "protected" interface
  // ===========================================
  protected:
  
};

#endif

