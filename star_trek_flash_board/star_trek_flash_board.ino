/*----------------- Star Trek Style Flashing LEDS -- Example -------

  Example showing how to use ledObject and fadeLED together.

  This example uses almost as many LEDs as possible to
  replicate the randomly flashing "led circuit boards"
  from star trek (as per request).

  If more LEDs are required, you can use the analog pins as well,
  if you still want more, run it on an arduino mega.


     Created by Declan Heard. 11/11/2020
     Released into Public Domain.

*/


#include "ledObject.h"


#include <autoDelay.h>                            // Not used for any LED functions ( though ledObject borrows from topology) // Only used for demo functions
// available @ https://github.com/PanGalacticTech/autoDelay_Library

autoDelay basicDelay;                 // Set up instance of autoDelay




// LEDs attached to NON PWM pins can be set as ledObjects

// Calling object constructors one by one is possible, but inefficient for the large number of different objects used in this example
/*
  ledObject flashLED2(2);                    // Set up instance of ledObject (1 for each Flashing LED) pass it the pin number during constructor.
  ledObject flashLED4(4);                    // Set up instance of ledObject (1 for each Flashing LED) pass it the pin number during constructor.
  ledObject flashLED7(7);                    // Set up instance of ledObject (1 for each Flashing LED) pass it the pin number during constructor.
  ledObject flashLED8(8);                    // Set up instance of ledObject (1 for each Flashing LED) pass it the pin number during constructor.
  ledObject flashLED12(12);                    // Set up instance of ledObject (1 for each Flashing LED) pass it the pin number during constructor.
  ledObject flashLED13(13);                    // Set up instance of ledObject (1 for each Flashing LED) pass it the pin number during constructor.
*/

// More efficient method calls objects as an array that can be iterated through to save alot of typing.

ledObject flash[6] = {ledObject(2), ledObject(4), ledObject(7), ledObject(8), ledObject(12), ledObject(13)};   // Set up an array of objects, each ledObject is passed an output pin

#define NUM_FLASHERS 6

#define INITIAL_STATE 1                  // Defines if LED pin starts with initial state ON or OFF - defaults to OFF




// LEDs attached to PWM capable pins can use fadeLED object (they can also use all the flashing functions from ledObject)

// Naming objects one by one.
/*
  fadeLED fadeLED3(3);                    // Set up instance of fade LED (1 for each fading LED - Must be passed PWM capable pin)
  fadeLED fadeLED5(5);                    // Set up instance of fade LED (1 for each fading LED - Must be passed PWM capable pin)
  fadeLED fadeLED6(6);                    // Set up instance of fade LED (1 for each fading LED - Must be passed PWM capable pin)
  fadeLED fadeLED9(9);                    // Set up instance of fade LED (1 for each fading LED - Must be passed PWM capable pin)
  fadeLED fadeLED10(10);                    // Set up instance of fade LED (1 for each fading LED - Must be passed PWM capable pin)
  fadeLED fadeLED11(11);                    // Set up instance of fade LED (1 for each fading LED - Must be passed PWM capable pin)
*/

// Or can be done all in one go.
fadeLED fade[6] = {fadeLED(3), fadeLED(5), fadeLED(6), fadeLED(9), fadeLED(10), fadeLED(11)};  // Set up an array of fade objects. Each LED is passed a PWM capable output pin

#define NUM_FADERS 6

#define INITIAL_BRIGHTNESS 50     //defines a starting brightness for fadeLED object. byte value from 0 - 255 valid



void setup() {

  Serial.begin(115200);

  randomSeed(analogRead(0));   // psudo random number generator for demo delay times


  // Blinking LEDs

  // each ledObject needs to be setup

  // this can be done one by one
  // flashLED2.begin(INITIAL_STATE);    // Begin ledObject library by passing the INTITAL_STATE (defaults to off if no argument passed).


  // or we can iterate through the array if we have called the objects using an array structure:

  for (int i = 0; i < NUM_FLASHERS; i++) {
    flash[i].begin(INITIAL_STATE);
    flash[i].startBlink(random(10, 7000), random(10, 5000));                                     // Calls a blink event that continues untill stopped (time high, time low); feeding random numbers for some chaos
  }

  // other ledObject functions
  // .callBlink();                          // Sets up blink event with default settings (blinks 2, time high 40 , time low 100)
  //.blinkEvent(20);                        // Sets up blink event with 20 blinks & default timing
  // .callBlink(2, 100, 200);                  // Sets up blink event with 2 blinks, 100ms ON, 200ms off

  //.startBlink();                                 // Calls a blink event that continues untill stopBlink or a callBlink is called. (can also be passed (time high, time low)

  // fade[0].startBlink(10, 200);                                     //using array, each object can be acessed by the name fade, and number[X] of its position in the array. (index starts at 0);





  // Fading LED Examples

  // fadeLED3.setup();                                 // Begin fadeLED library by passing the starting brightness. (default 150 if not passed any arguments)
  // this can be done one by one

  // or we can iterate through the array if we have called the objects using an array structure:

  for (int i = 0; i < NUM_FADERS; i++) {

    fade[i].setup(INITIAL_BRIGHTNESS);
    fade[i].startFading(0, 255, random(1, 1000));                                     // Calls a fade event that continues untill stopped (min brightness, max brightness, fadetime mS); feeding random numbers for some chaos
  }

  //N.B. Lower delay numbers = faster fading & flashing



  //.startFading(0, 100, 100);     //(min brightness, max brightness, fadetimeMilliseconds)       // Timing may not be accurate at really short delay times, but function has been confirmed down to 1ms delay with slow motion video.
  // Some low value arguments may not produce visible results.

  //.startFading();   //if no arguments are passed - default values 10, 50 500

  //.fadeMoment(0, 250, ledTwo.FADE_DOWN, 4000 );    // Sets up a Single Fade moment passed arguments (defaults) (min = 0, max = 255, direction = FADE_DOWN, timeMs=1500)

  //.fadeEvent(0, 250, 4, 300 );                 // sets up repeating fade event (min, max, number of cycles, timeMs)


}









void loop() {



  // Code here to change the frequency of flashing every random seconds between 2 and 10

  if (basicDelay.secondsDelay(random(2, 10))) {

    for (int i = 0; i < NUM_FLASHERS; i++) {
      flash[i].startBlink(random(10, 7000), random(10, 5000));    // feed new random numbers into the blink objects
    }


    for (int i = 0; i < NUM_FADERS; i++) {
      fade[i].startFading(0, 255, random(1, 1000));                    // feed new random numbers into the fade objects
    }

  }





  // .stopFading();                             // any fade events must be stopped before blink events can be called.
  //  .blinkEvent(4, 200, 200);


  // .fadeEvent(0, 250, 4, 300);    // Sets up a Single Fade moment pass arguments (defaults) (min = 0, max = 255, direction = FADE_DOWN, timeMs=1500)
  //  .fadeOut();                   // fade LED to black

  // fade events will take precidence over blink events


  // .turnOff();                    // turn the LED off instantly





  // performBlink() & performFades() must run through every loop for every object. Avoid using delay() functions in the rest of the code as it will interrupt the function of these libraries.
  // for delay() free code see autoDelay.h library @ https://github.com/PanGalacticTech/autoDelay_Library

  // we can iterate through the array if we have called the objects using the array structure:

  for (int i = 0; i < NUM_FLASHERS; i++) {

    flash[i].performBlink();
  }


  for (int i = 0; i < NUM_FADERS; i++) {

    fade[i].performFades();        // PerformFade events, also performs blink events.
  }


}
