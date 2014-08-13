/*

 The SD circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 10
 	 
 */

#include <SD.h>
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define LEDS 5

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS, PIN, NEO_GRB + NEO_KHZ800);
const int leds = LEDS-1;
byte red;
byte green;
byte blue;
int columns;
int rows;
byte width;
File dataFile;
int colorcount=0;
const int chipSelect = 10; 
const bool debug=1;

void setup()
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
  strip.begin();
  strip.setPixelColor(0,12,12,12);
     strip.show(); // Initialize all pixels to 'off'
     Serial.println("Pixel stick!");
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  else
  Serial.println("card initialized.");
   File dataFile = SD.open("light.txt");
   if(dataFile == 1)
   Serial.println("file opened");
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  

//  // if the file is available, write to it:
//  if (dataFile) {
//    while (dataFile.available()) {
//      Serial.println(dataFile.read());
//      
//    }
//    dataFile.close();
//  }  
//  // if the file isn't open, pop up an error:
}

void loop()
{
  
 

//  red = 0;
//  green=0;
//  blue= 0;
   //if(debug==1)
 // Serial.println("entering mainloop");
 // i=0;
  // if there's any serial available, read it:
  if (dataFile==1)
  Serial.println("datafile available");
  else
  Serial.println("datafile NOT available");
  
  
  if (dataFile==1) {
    
    if(debug==1)
    Serial.println("light.txt:");
    
    // read from the file until there's nothing else in it:
    while (dataFile.available()) {
    	Serial.write(dataFile.read());
    
    for(columns=0;columns<<leds;columns++){
      Serial.println("LED being served = ");
         Serial.println(columns);
    // look for the next valid integer in the incoming serial stream:
    for(colorcount=0;colorcount<<3;colorcount++){
       if(debug==1)
    Serial.println("entering color loop");
      if(colorcount==0){
      red=dataFile.read();
       if(debug==1)
    Serial.println("red printed");}
    
      else if(colorcount==1){
       if(debug==1)
    Serial.println("green printed");
      green=dataFile.read();}
     
     
      else if(colorcount==2){
      blue=dataFile.read();
        if(debug==1)
    Serial.println("blue printed");}
    
      
      }
      // delay(1);
    
         Serial.print("LED being served = ");
         Serial.println(columns);
       

      // fade the red, green, and blue legs of the LED: 
      
//      analogWrite(redPin, red);
//      analogWrite(greenPin, green);
//      analogWrite(bluePin, blue);
      strip.setPixelColor(columns,red,green,blue);
      strip.show();

      // print the three numbers in one string as hexadecimal:
      Serial.print("R=");
      Serial.println(red);
      Serial.print("G=");
      Serial.println(green);
      Serial.print("B=");
      Serial.println(blue);
    }  
   delay(500);
     
    
     
    }
    dataFile.close();
     Serial.print("data end");
     
     
    }                  //end if for dataFile 
  
  //break;
  
  
}

