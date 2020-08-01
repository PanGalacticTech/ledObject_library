/*
 * 
 *   Library to control a single LED
 *   
 *   Can be used to make simple animiations for basic UIs
 *   Utelising single LEDs
 *   
 *   Created by Declan Heard. 01/08/2020
 *   Released into Public Domain. 
 * 
 */





 
#ifndef ledObject_h
#define ledObject_h

#if (ARDUINO >=100)
 #include <Arduino.h>
#else
  #include <wProgram.h>
#endif




                   


 class ledObject
 {
   public:
    
    // constructor
    ledObject();

  
    // Methods
 //   bool delayScript(int delayTime);
    
    void begin(int ledPin = 13, int initialState = 0);

    void turnOn();

    void turnOff();
    
 //   boolean delayComplete;

  // variables


int initialState = 0;

  
  private:

   int ledPin;
   
  //    long currentMillis;
   //   long previousMillis;
    

 };
 
#endif
