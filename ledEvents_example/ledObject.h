/*

     Library to control a single LED

     Can be used to make simple animations for basic UIs
     Using single LEDs

     Created by Declan Heard. 01/08/2020
     Released into Public Domain.

*/






#ifndef ledObject_h
#define ledObject_h

#if (ARDUINO >=100)
#include <Arduino.h>
#else
#include <wProgram.h>
#endif



#define blinkEvent callBlink     // Set up Synonyms for common functions



class ledObject
{
  public:

    // constructor
    ledObject();


    //Basic Methods

    void begin(int ledPin = 13, int initialState = 0);

    void turnOn();

    void turnOff();
	
	void toggleLED();

    void startBlink(long onDuration = 40, long offDuration = 130);                                 // default values allow startBlink() with no arguments. // performBlink must be called in main loop to actuate

    void stopBlink();                                                                                   // Stops any blink events dead.


    // Blink Event Methods
    // Blink events contain a call to set up and performBlink in main loop to carry out the action.
    void callBlink(int numberofBlinks = 2, long onDuration = 40, long offDuration = 130 );    // Default values allow simple callBlink() with no arguments to default to these settings. callBlink(5); single argument only sets number of blinks.

    void performBlink();                                                                      // Must be Called in the main loop if using blink functions. performs the actions of callBlink and StartBlink

    // variables
    bool ledState;      // stores the state of the LED




  private:

    int ledPin;

    unsigned long currentAction;    // Global variables to hold the time of the current, and the previous timed actions
    unsigned long lastAction;

    int blinkQuantity;              // Global Variables used for blink events
    long blinkOnDuration;
    long blinkOffDuration;


     bool blinkActive;     // remains true while blink Event functions are active (and need to be repeated) Not used


};

#endif
