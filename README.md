# ledObject *(V2.0.0)*
#### Built and maintained by [Declan Heard](mailto:pangalactictech@gmail.com "Email me!") on behalf of [Pan Galactic Tech](https://PanGalacticTech.com)

## Features
* Object Orientated library for controling single LEDs.
* Seperate class defintions for "blink" (digital) and "fade" (PWM) LED outputs.
* fadeLED inherets all functions from ledObject (blink) LEDs.
* Add values to a counter which will count down a specific number of ledEvents before ending.
* Set up blinks and fades that continue until stop method is called.
* Functions work with both AVR (ATmega) / Arduino Boards & ESP32/8266 Espressif Boards.

## Getting Started
### Deployment
1. Clone or Download library folder into Arduino IDE libraries folder.
2. Extract files from zipped folder if required.
3. Open Arduino IDE and select from example programs.




## Use:

### Precompiler Requirements:

`#include <ledObject.h>   // Libary include N.B. This includes both ledObject & fadeLED `


###AVR
Define the LED pin and the initial state:

`#define ledPin 9                         // Define LED pin. If undefined - defaults to pin 13.
#define initialState 1                  // Defines if LED pin starts with initial state ON or OFF - defaults to OFF`

###ESP32 / espressif
For ESP32 & espressif boards, additional variables are required for setup:

`#define PWM_PIN 2                       // PWM drive capable pin
#define LED_CH  0                        // PWM Channel (ESP32 up to 16 channels total)
#define PWM_FREQ 5000                    // PWM Frequency (Hz)
#define PWM_RESO 8                       // PWM Resolution (bits)       ` 


### Object Constructors:

###AVR
Declaring a blink LED object:

`ledObject led(LED_PIN) `

Declaring a fade LED object:

`fadeLED led(LED_PIN);      		// LED pin passed as argument to constructor `

####ESP32 / espressif
Declaring a fade LED object:

`fadeLED led(PWM_PIN, LED_CH, PWM_FREQ, PWM_RESO);      // ESP32 Requires 4 arguments for constructor`


### Setup Functions:

 (Coming Soon)


### Loop Functions:

 (Coming Soon)




### Limitations:
	- Not tested on ATtiny controllers. 




### Known Issues V1.0:
  - Please report any bugs or issues found.
    
### Features to be Added:  


## About
### Built With
* [Arduino IDE](https://www.arduino.cc/) - Default IDE


### Author
#### Declan Heard
* [LinkedIn](https://www.linkedin.com/in/declan-heard-91103b58/)
* Email: [Personal](mailto:dec.h38@gmail.com "dec.h38@gmail.com") | [Company](mailto:PanGalacticTech@gmail.com "PanGalacticTech@gmail.com")
* [Github Profile](https://github.com/PanGalacticTech)
