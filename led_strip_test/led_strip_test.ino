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

#define ROW0  5
#define ROW1  53
#define ROW2  103
#define ROW3  153
#define ROW4  203
#define ROW5  253

int red[6][12];
int green[6][12];
int blue[6][12];

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  for (int y = 0; y < 6; y++) {
    for (int x = 0; x < 12; x++) {
      switch(y) {
        case(0):
          red[y][x] = 0;
          green[y][x] = 200;
          blue[y][x] = 200;
          break;
        case(1):
          red[y][x] = 0;
          green[y][x] = 0;
          blue[y][x] = 200;
          break;
        case(2):
          red[y][x] = 200;
          green[y][x] = 0;
          blue[y][x] = 200;
          break;
        case(3):
          red[y][x] = 200;
          green[y][x] = 0;
          blue[y][x] = 0;
          break;
        case(4):
          red[y][x] = 200;
          green[y][x] = 200;
          blue[y][x] = 0;
          break;
        case(5):
          red[y][x] = 0;
          green[y][x] = 200;
          blue[y][x] = 0;
          break;
        default:
          break;
      }
    }
  }
  
  for (int i = ROW0; i < 41; i+=3) {
    delay(100);
    strip.fill(strip.Color(red[0][(i-ROW0)/3], green[0][(i-ROW0)/3], blue[0][(i-ROW0)/3]), 43-i, 2); // Stops after index 38
    strip.show();
  }
  for (int j = ROW1; j < 89; j+=3) {
    delay(100);
    strip.fill(strip.Color(red[1][(j-ROW1)/3], green[1][(j-ROW1)/3], blue[1][(j-ROW1)/3]), j, 2); // Stops after index 86
    strip.show();
  }
  for (int k = ROW2; k < 139; k+=3) {
    delay(100);
    strip.fill(strip.Color(red[2][(k-ROW2)/3], green[2][(k-ROW2)/3], blue[2][(k-ROW2)/3]), 239-k, 2); // Stops after index 136
    strip.show();
  }
  for (int l = ROW3; l < 188; l+=3) {
    delay(100);
    strip.fill(strip.Color(red[3][(l-ROW3)/3], green[3][(l-ROW3)/3], blue[3][(l-ROW3)/3]), l, 2); // Stops after index 186
    strip.show();
  }
  for (int m = ROW4; m < 239; m+=3) {
    delay(100);
    strip.fill(strip.Color(red[4][(m-ROW4)/3], green[4][(m-ROW4)/3], blue[4][(m-ROW4)/3]), 439-m, 2); // Stops after index 236
    strip.show();
  }
  for (int n = ROW5; n < 288; n+=3) {
    delay(100);
    strip.fill(strip.Color(red[5][(n-ROW5)/3], green[5][(n-ROW5)/3], blue[5][(n-ROW5)/3]), n, 2); // Stops after index 286
    strip.show();
  }
  strip.show(); // Initialize all specific pixels to 'on'
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);

  for (int x = 0; x < 12; x++) {
    int prev_red = red[0][x];
    int prev_green = green[0][x];
    int prev_blue = blue[0][x];
    int y = 1;
    while (y < 6) {
      red[y-1][x] = red[y][x];
      green[y-1][x] = green[y][x];
      blue[y-1][x] = blue[y][x];
      y++;
    }
    red[5][x] = prev_red;
    green[5][x] = prev_green;
    blue[5][x] = prev_blue;
  }

  for (int i = ROW0; i < 41; i+=3) {
    strip.fill(strip.Color(red[0][(i-ROW0)/3], green[0][(i-ROW0)/3], blue[0][(i-ROW0)/3]), 43-i, 2); // Stops after index 38
    //strip.show();
  }
  for (int j = ROW1; j < 89; j+=3) {
    strip.fill(strip.Color(red[1][(j-ROW1)/3], green[1][(j-ROW1)/3], blue[1][(j-ROW1)/3]), j, 2); // Stops after index 86
    //strip.show();
  }
  for (int k = ROW2; k < 139; k+=3) {
    strip.fill(strip.Color(red[2][(k-ROW2)/3], green[2][(k-ROW2)/3], blue[2][(k-ROW2)/3]), 239-k, 2); // Stops after index 136
    //strip.show();
  }
  for (int l = ROW3; l < 188; l+=3) {
    strip.fill(strip.Color(red[3][(l-ROW3)/3], green[3][(l-ROW3)/3], blue[3][(l-ROW3)/3]), l, 2); // Stops after index 186
    //strip.show();
  }
  for (int m = ROW4; m < 239; m+=3) {
    strip.fill(strip.Color(red[4][(m-ROW4)/3], green[4][(m-ROW4)/3], blue[4][(m-ROW4)/3]), 439-m, 2); // Stops after index 236
    //strip.show();
  }
  for (int n = ROW5; n < 288; n+=3) {
    strip.fill(strip.Color(red[5][(n-ROW5)/3], green[5][(n-ROW5)/3], blue[5][(n-ROW5)/3]), n, 2); // Stops after index 286
    //strip.show();
  }
  strip.show();
}