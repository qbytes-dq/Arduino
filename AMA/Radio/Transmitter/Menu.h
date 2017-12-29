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

#include "CustomChar.h"
#include "Data.h"
#include "Display.h"
#include "DisplayMask.h"

// library interface description
class Menu
{
  // ===========================================
  // user-accessible "public" interface
  // ===========================================
  public:
    //Menu();
    Menu(Data *);

    boolean isScreenRefreshNeeded(void);
    //void updateLCD(byte, int);
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

 
    // ===========================================
    //  *         0 = Reserved
    // ===========================================
    void lcdMenu000(void);

    // ===========================================
    // *   1 -  49 = Transmitter
    // ===========================================
    void lcdMenu001(void);

    // Menu Items
    void lcdMenu002(void);
    void lcdMenu003(void);    
    void lcdMenu010(void);
    void lcdMenu011(void);
    void lcdMenu012(void);
    void lcdMenu013(void);
    void lcdMenu014(void);

    // ===========================================
    // *  50 -  99 = Models
    // ===========================================
    
    
    // ===========================================
    // * 100 - 149 = System (Resistors, Voltages)
    // ===========================================
    void lcdSys102(void); // Vin pre 1.1 & 1.2 ohms
    void lcdSys104(void); // Vin pst 2.1 & 2.2 ohms
    void lcdSys106(void); // V5.0    3.1 & 3.2 ohms

    void lcdSys112(void); // Shunt ohms 
    void lcdSys114(void); // V5.0 Reference

    void lcdSys122(void); // Switch
    void lcdSys124(void); // Trim
    void lcdSys126(void); // Menu buttons

    void lcdSys135(void); // Throttle - Joystick range limits (Uses             editJoystick 0)  // s/b 134
//  void lcdSys136(void); // Yoke     - Joystick range limits (Uses lcdSys135 , editJoystick 1)
//  void lcdSys138(void); // Roll     - Joystick range limits (Uses lcdSys135 , editJoystick 2)
//  void lcdSys139(void); // Pitch    - Joystick range limits (Uses lcdSys135 , editJoystick 3)

    void lcdSys148(void); // System Reset

    
    // ===========================================
    // * 150 - 199 = START/INIT
    // ===========================================
    void lcdInit150(void); // Starting [click (select) out to 254]
    void lcdInit151(void); // Splash   [no click 'select button' out to 151]
    
    void lcdInit192(void); // Control check


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
    void lcdFunc238(void); // EEPROM Read   --> move to 25x range
    void lcdFunc239(void); // EEPROM Write  --> move to 25x range
    
    void lcdFunc240(void); // Controls Range 
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
    
    byte function = 0;
    boolean isMenuChange = true;
    boolean isFuncChange = true;

    //boolean isSetVisable = false;
   
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
    // *         0 = Reserved
    // =======================================
    // =======================================
    // ======================================= 
    byte menuOptions000 [0] = {/* Do NOT use: reserved */}; 


    // =======================================
    // =======================================
    // =======================================
    // *   1 -  49 = Transmitter
    //
    // #define MAINMENU  1   // Main Menu
    // #define X_MITTER  2   // Transmitter Main Menu   
    // =======================================
    // =======================================
    // =======================================    
    byte menuOptions001 [5] = {10, 11, 12, 13, 14};
    
    byte menuOptions002 [1] = {MAINMENU};
    byte menuOptions003 [1] = {MAINMENU};
    
    byte menuOptions010 [5] = {MAINMENU, 11, 12, 13, 14};
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
// Ohms & Voltage  (SYSTEM)
byte menuOptions100 [4] = {MAINMENU,102,104, 106};
//===============================
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Ohms (101)
  byte menuOptions101 [4] = {SYSTEM,102,104, 106};  // Pre, Pst & Ref Menu
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    byte menuOptions102 [3] = {101,216,216};  // Vin  pre 1.1 & 1.2 ohms
    byte menuOptions104 [3] = {101,216,216};  // Vin  pst 2.1 & 2.2 ohms
    byte menuOptions106 [3] = {101,216,216};  // V5.0 Ref 3.1 & 3.2 ohms

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Shunt, Reference & V5 menu
  byte menuOptions110 [3] = {SYSTEM, 112, 114};
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    byte menuOptions112 [2] = {110,216};      // Shunt ohms
    byte menuOptions114 [2] = {110,216};      // V5.0    Reference Voltage Measured
    byte menuOptions116 [1] = {110};      // Pre, Post & V5 Regulator

//===============================
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Switch menu
  byte menuOptions120 [4] = {SYSTEM, 122, 124, 126};      // Menu, Trim & Switch Menu.
    //-------------------------------
    byte menuOptions122 [2] = {120,216};      // Switch
    byte menuOptions124 [2] = {120,216};      // Trim
    byte menuOptions126 [2] = {120,216};      // Menu


//===============================
// Control Range Limits (Left/Right)    // Control Range menu  (Left Right)
byte menuOptions130 [3] = {SYSTEM,133,137};      
//===============================
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Left (Throttle or Yaw)
  byte menuOptions133 [3] = {130,134,135};
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      byte menuOptions134 [2] = {133,240};      // Throttle
      byte menuOptions135 [2] = {133,240};      // Yaw
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Right (Roll or Pitch)
  byte menuOptions137 [3] = {130,138,139};
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      byte menuOptions138 [2] = {137,240};      // Roll
      byte menuOptions139 [2] = {137,240};      // Pitch

//===============================
// Reset Menu
byte menuOptions148 [2] = {SYSTEM,149};      // Factory Reset
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
    
    byte menuOptions152 [3] = {154,216,216};        // Vin pre 1.1 & 1.2 ohms
    byte menuOptions154 [3] = {156,216,216};        // Vin pst 2.1 & 2.2 ohms
    byte menuOptions156 [3] = {162,216,216};        // V5.0    3.1 & 3.2 ohms

    byte menuOptions162 [2] = {164,216};            // Shunt ohms
    byte menuOptions164 [2] = {172,216};            // V5.0    Reference Voltage 

    byte menuOptions172 [1] = {174};                // Switch
    byte menuOptions174 [1] = {176};                // Trim
    byte menuOptions176 [1] = {182};                // Menu

    byte menuOptions182 [2] = {183,240};            // Joystick range limits
    byte menuOptions183 [2] = {184,240};            // Joystick range limits
    byte menuOptions184 [2] = {185,240};            // Joystick range limits
    byte menuOptions185 [2] = {CTLCHECK,240};       // Joystick range limits

// Need to show voltages here???? or on the Resister screen???
    
    byte menuOptions192 [1] = {CTLCHECK};           // Control Check (make sure all surfaces & switches are homed. (Prevent flight by mistake) [no click (select) out of 192]

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

    //byte menuOptions238 [1] = {FUNCTION};       // Function for EEPROM read
    //byte menuOptions239 [1] = {FUNCTION};       // Function for EEPROM write

    //byte menuOptions240 [1] = {FUNCTION};       // Function to do Control Range settings

    //byte menuOptions25x [1] = {FUNCTION};       // Function for check for Factory Reset
    //byte menuOptions25x [1] = {FUNCTION};       // Function to do Factory Reset

    // =======================================
    // =======================================
    // =======================================
    // * 255 = Reserved for FUNCTION switch indicator
    // =======================================
    // =======================================
    // =======================================  
    byte menuOptions255 [0] = {/* Do NOT use: reserved */};

    

    // ===========================================
    // library-accessible "private" interface
    // ===========================================
    private:

      byte editJoyStick = 0;

      byte menuOptions[5];
      byte menuSize;

      enum MenuAction {
        doInit,
        doMenu,
        doFunc,
      } menuAction = doInit;

      void printDrmc(void);  // test only, delete this and the method
      void clearDisplayMask(void);
      
      Data * data;   
      DisplayMask displayMask[4];

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

