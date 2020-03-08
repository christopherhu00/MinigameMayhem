#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    6
 
// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 300
 
// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)


void setup() {
  // put your setup code here, to run once:
  strip.begin();
  for (int i = 5; i < 41; i+=3) {
    strip.fill(strip.Color(0, 200, 200), i, 2); // Stops at index 40
  }
  for (int j = 53; j < 89; j+=3) {
    strip.fill(strip.Color(0, 200, 0), j, 2); // Stops at index 88
  }
  for (int k = 103; k < 139; k+=3) {
    strip.fill(strip.Color(200, 200, 0), k, 2); // Stops at index 138
  }
  for (int l = 153; l < 188; l+=3) {
    strip.fill(strip.Color(200, 100, 0), l, 2); // Stops at index 187
  }
  for (int m = 203; m < 238; m+=3) {
    strip.fill(strip.Color(200, 0, 0), m, 2); // Stops at index 237
  }
  for (int n = 253; n < 288; n+=3) {
    strip.fill(strip.Color(200, 0, 200), n, 2); // Stops at index 287
  }
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // put your main code here, to run repeatedly:
  //strip.fill(color, first, count);
}
