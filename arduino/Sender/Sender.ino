 
#include <Adafruit_NeoPixel.h>
#include <OneSheeld.h>
#include <SD.h>

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
File myFile;
int colorcount=0;
const int chipSelect = 10; 
const bool debug=1;


void setup() {
  // initialize serial:
  Serial.begin(9600);
  strip.begin();
  strip.setPixelColor(0,12,12,12);
     strip.show(); // Initialize all pixels to 'off'
     Serial.print("number of LEDS in strip:");
     Serial.println(LEDS);
      width=0;
     
      Serial.print("Initializing SD card...");
      // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
      // Note that even if it's not used as the CS pin, the hardware SS pin 
      // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
      // or the SD library functions will not work. 
       pinMode(10, OUTPUT);
       if (!SD.begin(10)) {
        Serial.println("initialization failed!");
        return;
      }
      Serial.println("initialization done.");
       myFile = SD.open("light.txt");
       width=myFile.read();

}

  

void loop() {
  if(debug==1)
  Serial.println("entering mainloop");
  red = 0;
  green=0;
  blue= 0;
 
 // i=0;
  // if there's any serial available, read it:
  if (myFile) {
    Serial.println("test.txt:");
    
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
    	//Serial.write(myFile.read());
    for(rows=0;rows<<width;rows++){
    for(columns=0;columns<<leds;columns++){
      
    // look for the next valid integer in the incoming serial stream:
    for(colorcount=0;colorcount<<3;colorcount++){
      
      if(colorcount==0)
      red=myFile.read();
      else if(colorcount==1)
      green=myFile.read();
      else if(colorcount==2)
      blue=myFile.read();
    
      
      }
       delay(1);
    
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
   delay(2000);
     
    }
     myFile.close();
    }
    
  }
  //break;
   if(debug==1)
  Serial.println("failed to find file");
}








