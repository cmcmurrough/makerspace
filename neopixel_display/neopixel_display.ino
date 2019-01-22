// Adafruit_NeoMatrix example for single NeoPixel Shield.
// Scrolls 'Howdy' across the matrix in a portrait (vertical) orientation.

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define PIN 20

// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_GRBW    Pixels are wired for GRBW bitstream (RGB+W NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)


// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(64, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

const uint16_t colors[] = 
{
  // red, green, blue, yellow
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255), matrix.Color(255, 255, 0)
};

void setup() 
{
  matrix.begin();
  matrix.setRotation(1);
  matrix.setTextWrap(true);
  matrix.setBrightness(20);
  matrix.setTextColor(colors[0]);
}

int x = matrix.width();
int pass = 0;

void loop() 
{

  for(int i = 0; i < 2; i++)
  {
    matrix.fillScreen(matrix.Color(0, 0, 0));
/*
    matrix.setTextColor(colors[0]);
    matrix.setCursor(i+1, 0);
    matrix.print(F("M"));

    matrix.setTextColor(colors[1]);
    matrix.setCursor((i+1)%2+1, 8);
    matrix.print(F("A"));

    matrix.setTextColor(colors[2]);
    matrix.setCursor(i+1, 16);
    matrix.print(F("K"));

    matrix.setTextColor(colors[0]);
    matrix.setCursor((i+1)%2+1, 24);
    matrix.print(F("E"));

    matrix.setTextColor(colors[1]);
    matrix.setCursor(i+1, 33);
    matrix.print(F("H"));

    matrix.setTextColor(colors[2]);
    matrix.setCursor((i+1)%2+1, 41);
    matrix.print(F("E"));

    matrix.setTextColor(colors[0]);
    matrix.setCursor(i+1, 49);
    matrix.print(F("R"));

    matrix.setTextColor(colors[1]);
    matrix.setCursor((i+1)%2+1, 57);
    matrix.print(F("E"));
*/

    matrix.setTextColor(colors[0]);
    matrix.setCursor(i+1, 0);
    matrix.print(F("M"));

    matrix.setTextColor(colors[1]);
    matrix.setCursor((i+1)%2+1, 7);
    matrix.print(F("A"));

    matrix.setTextColor(colors[2]);
    matrix.setCursor(i+1, 14);
    matrix.print(F("K"));

    matrix.setTextColor(colors[0]);
    matrix.setCursor((i+1)%2+1, 21);
    matrix.print(F("E"));

    matrix.setTextColor(colors[1]);
    matrix.setCursor(i+1, 29);
    matrix.print(F("S"));

    matrix.setTextColor(colors[2]);
    matrix.setCursor((i+1)%2+1, 36);
    matrix.print(F("T"));

    matrix.setTextColor(colors[0]);
    matrix.setCursor(i+1, 43);
    matrix.print(F("U"));

    matrix.setTextColor(colors[1]);
    matrix.setCursor((i+1)%2+1, 50);
    matrix.print(F("F"));

    matrix.setTextColor(colors[2]);
    matrix.setCursor(i+1, 57);
    matrix.print(F("F"));

    /*
    // draw the border
    for(int i = 0; i < matrix.width(); i++)
    {
      for(int j = 0; j < matrix.height(); j++)
      {
        if(i == 0 || i == matrix.width() - 1 || j == 0 || j == matrix.height() - 1)
        {
          matrix.drawPixel(i, j, colors[3]);
          //matrix.show();
          //delay(5);
        }
      }
    }
    */
    
    delay(500);
    matrix.show();
  }
}
