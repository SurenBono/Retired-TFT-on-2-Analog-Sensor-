/*
  Arduino TFT text example

  This example demonstrates how to draw text on the
  TFT with an Arduino. The Arduino reads the value
  of an analog sensor attached to pin A0, and writes
  the value to the LCD screen, updating every
  quarter second.

  This example code is in the public domain

  Created 15 April 2013 by Scott Fitzgerald

  http://www.arduino.cc/en/Tutorial/TFTDisplayText

 */

#include <TFT.h>  // Arduino LCD library
#include <SPI.h>

// pin definition for the Uno
#define cs   10
#define dc   9
#define rst  12
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0  
#define WHITE   0xFFFF
// pin definition for the Leonardo
// #define cs   7
// #define dc   0
// #define rst  12

// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);

// char array to print to the screen
// Add more array for more sensor reading on analog pins
char sensorPrintout_0[4]; //A0
char sensorPrintout_1[4]; //A1

void setup() {

  // Put this line at the beginning of every sketch that uses the GLCD:
  TFTscreen.begin();
  TFTscreen.setRotation(6);//0=PORTRAIT DOWN ,1=LANDSCAPE_1, 2=PORTRAIT UP, 3= LANDSCAPE_2 ,0=4,1=5,2=6..ETC
  // clear the screen with an alternate black background
  TFTscreen.background(0, 0, 0);

  // write the static text to the screen
  // set the font color to white
  TFTscreen.stroke(WHITE);
  // set the font size
  TFTscreen.setTextSize(0);
  // write the text to the top left corner of the screen
  TFTscreen.text("Sensor Value :\n ", 25,20);
  // ste the font size very large for the loop
  TFTscreen.setTextSize(2);
   TFTscreen.text("A0 :", 25,50);
   TFTscreen.text("A1 :", 25,70);
}

void loop() {

  // Read the value of the sensor on A0
  String sensorVal_0 = String(analogRead(A0));
  String sensorVal_1 = String(analogRead(A1));
  // convert the reading to a char array
  sensorVal_0.toCharArray(sensorPrintout_0, 4);
  sensorVal_1.toCharArray(sensorPrintout_1, 4);

  // set the font color
  TFTscreen.stroke(GREEN);
  TFTscreen.text(sensorPrintout_0, 65, 50);
  TFTscreen.stroke(YELLOW);
  TFTscreen.text(sensorPrintout_1, 65, 70);
 
  delay(250);
  // erase 
  TFTscreen.stroke(0, 0, 0);
  TFTscreen.text(sensorPrintout_0, 65, 50);
  TFTscreen.stroke(0, 0, 0);
  TFTscreen.text(sensorPrintout_1, 65, 70);
}
