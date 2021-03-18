# ledObject *(V2.0.0)*
#### Built and maintained by [Declan Heard](mailto:pangalactictech@gmail.com "Email me!") on behalf of [Pan Galactic Tech](https://PanGalacticTech.com)

## Features
* Object Orientated library for controling single LEDs.
* Seperate class defintions for "blink" (digital) and "fade" (PWM) LED outputs.
* fadeLED inherets all functions from ledObject (blink) LEDs.
* Add values to a counter which will count down a specific number of ledEvents before ending.
* Set up blinks and fades that continue until stop method is called.
* Functions work with both AVR (ATmega) / Arduino Boards & ESP32/8266 Espressif Microcontrollers.

___________________________________________________________________________________________________________

## Getting Started
### Deployment
1. Clone or Download library folder into Arduino IDE libraries folder.
2. Extract files from zipped folder if required.
3. Open Arduino IDE and select from example programs.

___________________________________________________________________________________________________________

## Use:

### Precompiler Requirements:

`#include <ledObject.h>   // Libary include N.B.This includes both ledObject & fadeLED methods `


#### <u>AVR</u>
Define the LED pin and the initial state.

`#define ledPin 9                         // Define LED pin. If undefined - defaults to pin 13.`
`#define initialState 1                  // Defines if LED pin starts with initial state ON or OFF - defaults to OFF`

#### <u>ESP32 / espressif</u>
For ESP32 & espressif boards, additional variables are required for setup.

`#define PWM_PIN 2                       // PWM drive capable pin`
`#define LED_CH  0                        // PWM Channel (ESP32 up to 16 channels total)`
`#define PWM_FREQ 5000                    // PWM Frequency (Hz)`
`#define PWM_RESO 8                       // PWM Resolution (bits)       ` 

<br>
___________________________________________________________________________________________________________

### Object Constructors

#### <u>AVR</u>
Declaring a blink LED object:

`ledObject led(LED_PIN) `

Declaring a fade LED object:

`fadeLED led(LED_PIN);      		// LED pin passed as argument to constructor `

#### <u>ESP32 / espressif</u>
Declaring a fade LED object:

`fadeLED led(PWM_PIN, LED_CH, PWM_FREQ, PWM_RESO);      // ESP32 Requires 4 arguments for constructor`

<br>

___________________________________________________________________________________________________________

### Setup Functions:

 (Coming Soon)

<br>

___________________________________________________________________________________________________________

### Loop Functions:

 (Coming Soon)


<br>
<br>
___________________________________________________________________________________________________________

### Limitations:
- Not tested on ATtiny controllers. 


<br>

### Known Issues V1.0
  - Please report any bugs or issues found.

<br>

### Features to be Added 

<br>
<br>

## About
### Built With
* [Arduino IDE](https://www.arduino.cc/) - Default IDE


### Author
#### Declan Heard
* [LinkedIn](https://www.linkedin.com/in/declan-heard-91103b58/)
* Email: [Personal](mailto:dec.h38@gmail.com "dec.h38@gmail.com") | [Company](mailto:PanGalacticTech@gmail.com "PanGalacticTech@gmail.com")
* [Github Profile](https://github.com/PanGalacticTech)
