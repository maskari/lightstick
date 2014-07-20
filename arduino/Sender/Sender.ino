/*
  Reading a serial ASCII-encoded string.
 
 This sketch demonstrates the Serial parseInt() function.
 It looks for an ASCII string of comma-separated values.
 It parses them into ints, and uses those to fade an RGB LED.
 
 Circuit: Common-anode RGB LED wired like so:
 * Red cathode: digital pin 3
 * Green cathode: digital pin 5
 * blue cathode: digital pin 6
 * anode: +5V
 
 created 13 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 */
 
#include <Adafruit_NeoPixel.h>
#include <OneSheeld.h>

#define PIN 6
#define LEDS 2

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS+1, PIN, NEO_GRB + NEO_KHZ800);

int red;
int green;
int blue;
// pins for the LEDs:
//const int red = 3;
//const int green = 5;
//const int blue = 6;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  strip.begin();
  strip.setPixelColor(0,12,12,12);
     strip.show(); // Initialize all pixels to 'off'
  // make the pins outputs:
//  pinMode(redPin, OUTPUT); 
//  pinMode(greenPin, OUTPUT); 
//  pinMode(bluePin, OUTPUT); 

}

void loop() {
  red = 0;
  green=0;
  blue= 0;
  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
      red = Serial.parseInt(); 
    // do it again:
      green = Serial.parseInt(); 
    // do it again:
       blue = Serial.parseInt();

    // look for the newline. That's the end of your
    // sentence:
    if (Serial.read() == '\n') {
      // constrain the values to 0 - 255 and invert
      // if you're using a common-cathode LED, just use "constrain(color, 0, 255);"
//      red = constrain(red, 0, 255);
//      green = constrain(green, 0, 255);
//      blue = constrain(blue, 0, 255);

      // fade the red, green, and blue legs of the LED: 
      
//      analogWrite(redPin, red);
//      analogWrite(greenPin, green);
//      analogWrite(bluePin, blue);
      strip.setPixelColor(2,red,green,blue);
      strip.show();

      // print the three numbers in one string as hexadecimal:
      Serial.print("R=");
      Serial.println(red);
      Serial.print("G=");
      Serial.println(green);
      Serial.print("B=");
      Serial.println(blue);
    }
  }
}








