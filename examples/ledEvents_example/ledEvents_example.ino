/*

     Library to control a single LED

     Can be used to make simple animiations for basic UIs
     Utelising single LEDs

     Created by Declan Heard. 01/08/2020
     Released into Public Domain.

*/


#include "ledObject.h"

#include <autoDelay.h>                            // Not used for any LED functions ( though ledObject borrows from topology) // Only used for demo functions

#define ledPin 9                         // Define LED pin. If undefined - defaults to pin 13.
#define initialState 1                  // Defines if LED pin starts with initial state ON or OFF - defaults to OFF

ledObject ledONE;

autoDelay basicDelay;                 // Set up instance of autoDelay





void setup() {

ledONE.begin(ledPin, initialState);    // Begin ledObject library by passing the pin of an LED & the initialState

//ledONE.begin();                            // Begins library with default values (pin 13, initialState OFF)

//ledONE.begin(9);                           // If only a single value is passed, this will set the LED pin. Initial state will be OFF.

// ledONE.callBlink();                          // Sets up blink event with default settings (2, 40, 100)
  
//  ledONE.callBlink(20);                        // Sets up blink event with 20 blinks & default timing

//  ledONE.callBlink(2, 100, 200);                  // Sets up blink event with 20 blinks, 100ms ON, 200ms off

//ledONE.startBlink();                                 // Calls a blink event that continues untill stopBlink or a callBlink is called.

ledONE.startBlink(10, 200);                                     // Calls a blink event that continues untill stopped
                                                              // Passed values (onTime, offTime);

}









void loop() {



  
  ledONE.performBlink();                               // performs the blink event that has been set up 
                                                      // N.B. if additional blink events are called before the last blink event has finished it will overwrite the
                                                       //initial blink event completely.

 if (basicDelay.delayScript(5000)){

  ledONE.stopBlink();                                       // Function that stops any blink events and resets to stable (off) state                            
  
 }

//  ledONE.turnOff();

 // delay(1000);



}
