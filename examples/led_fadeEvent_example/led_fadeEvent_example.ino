/*----------------- Fade Event Library -- Example -------

     Library to control a single LED using PWM outputs

     adds PWM, brightness and fading functions to the 
     
     ledObject library.

     Can be used to make simple animiations for basic UIs
     Utelising single LEDs

     Created by Declan Heard. 01/08/2020
     Released into Public Domain.

*/


#include "ledObject.h"

#include <autoDelay.h>                            // Not used for any LED functions ( though ledObject borrows from topology) // Only used for demo functions

#define LED_PIN 9                         // Define LED pin. If undefined - defaults to pin 13.
#define INITIAL_STATE 1                  // Defines if LED pin starts with initial state ON or OFF - defaults to OFF

//ledObject ledONE;

autoDelay basicDelay;                 // Set up instance of autoDelay
autoDelay basicDelay2;                 // Set up instance of autoDelay

fadeLED ledTwo;



void setup() {

Serial.begin(115200);

// Blinking LED examples

//ledONE.begin(LED_PIN, INITIAL_STATE);    // Begin ledObject library by passing the pin of an LED & the initialState

//ledONE.begin();                            // Begins library with default values (pin 13, initialState OFF)

//ledONE.begin(9);                           // If only a single value is passed, this will set the LED pin. Initial state will be OFF.

// ledONE.callBlink();                          // Sets up blink event with default settings (2, 40, 100)
  
// ledTwo.blinkEvent(200);                        // Sets up blink event with 20 blinks & default timing

//  ledONE.callBlink(2, 100, 200);                  // Sets up blink event with 20 blinks, 100ms ON, 200ms off

//ledONE.startBlink();                                 // Calls a blink event that continues untill stopBlink or a callBlink is called.

//ledONE.startBlink(10, 200);                                     // Calls a blink event that continues untill stopped
     
                                                              
                                                              
                                                              
                                                              // Passed values (onTime, offTime);
// Fading LED Examples

ledTwo.setup();                                 // Begin fadeLED library by passing the PWM pin and the starting brightness default values pin 9, 150 brightness 

//ledTwo.startFading(0, 100, 100);     //(min brightness, max brightness, fadetimeMilliseconds)       // Timing may not be accurate at really short delay times, but function has been confirmed down to 1ms delay with slow motion video.
                                                                                                     // Some low value arguments may not produce visible results.
 ledTwo.startFading();   //if no arguments are passed - default values 10, 50 500    

//ledTwo.fadeMoment(0, 250, ledTwo.FADE_DOWN, 4000 );    // Sets up a Single Fade moment pass arguments (defaults) (min = 0, max = 255, direction = FADE_DOWN, timeMs=1500)

//ledTwo.fadeEvent(0, 250, 4, 300 );                 // sets up repeating fade event (min, max, number of cycles, timeMs)  
                                                                                                        
                                                                                                       
}









void loop() {







 //if (basicDelay.millisDelay(5000)){

 // ledTwo.stopFading();                             // any fade events must be stopped before blink events can be called.                                

    //  ledTwo.blinkEvent(4, 200, 200);              


 
if (basicDelay2.millisDelay(7500)){

 // ledTwo.fadeEvent(0, 250, 4, 300);    // Sets up a Single Fade moment pass arguments (defaults) (min = 0, max = 255, direction = FADE_DOWN, timeMs=1500)
  ledTwo.fadeOut();  
  
}                                       // fade events will take precidence over blink events
 // ledONE.turnOff();                   








ledTwo.performFades();   // PerformFade events, also performs blink events. 

}
