#include <FastLED.h> 
#define NUM_LEDS 3 
#define DATA_PIN 2 
// Define the array of leds 
CRGB leds[NUM_LEDS]; 

void setup() { 
  LEDS.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS); 
  LEDS.setBrightness(255); 
} 

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }

void loop() { 
  static uint8_t hue = 0; 
  // First slide the led in one direction 
  for(int i = 0; i < NUM_LEDS; i++) { 
    // Set the i'th led to red 
    leds[i] = CHSV(hue++, 255, 255); 
    // Show the leds 
    FastLED.show(); 
    // now that we've shown the leds, reset the i'th led to black 
    // leds[i] = CRGB::Black; 
    fadeall(); 
    // Wait a little bit before we loop around and do it again 
    delay(40); 
  } 
  // Now go in the other direction. 
  for(int i = (NUM_LEDS)-1; i >= 0; i--) { 
    // Set the i'th led to red 
    leds[i] = CHSV(hue++, 255, 255); 
    // Show the leds 
    FastLED.show(); 
    // now that we've shown the leds, reset the i'th led to black 
    // leds[i] = CRGB::Black; 
    fadeall(); 
    // Wait a little bit before we loop around and do it again 
    delay(40); 
  } 
} 
