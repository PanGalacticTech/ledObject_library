/*

     Library to control a single LED

     Can be used to make simple animiations for basic UIs
     Utelising single LEDs

     Created by Declan Heard. 01/08/2020
     Released into Public Domain.

*/







#include "ledObject.h"


ledObject::ledObject() {    // ANything needed to set up instance goes here



}



void ledObject::begin(int pin, int initialState) {              // Sets up ledPin as output pin.

  ledPin = pin;
  pinMode(ledPin, OUTPUT);

  if (initialState) {
    ledObject::turnOn();
  } else {
    ledObject::turnOff();
  }
  
  delay(5000);

}






void ledObject::turnOn() {

  digitalWrite(ledPin, HIGH);


}




void ledObject::turnOff() {

  digitalWrite(ledPin, LOW);


}
