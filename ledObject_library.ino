/*

     Library to control a single LED

     Can be used to make simple animiations for basic UIs
     Utelising single LEDs

     Created by Declan Heard. 01/08/2020
     Released into Public Domain.

*/


#include "ledObject.h"

#define ledPin 9                         // Define LED pin. If undefined - defaults to pin 13.
#define initialState 1                  // Defines if LED pin starts with initial state ON or OFF - defaults to OFF

ledObject ledONE;






void setup() {

ledONE.begin(ledPin, initialState);    // Begin library by passing the pin of an LED & the initialState

//ledONE.begin();                            // Begins library with default values (pin 13, initialState OFF)

//ledONE.begin(9);                           // If only a single value is passed, this will set the LED pin. Initial state will be OFF.

}









void loop() {


  ledONE.turnOn();

  delay(1000);

  ledONE.turnOff();

  delay(1000);



}
