#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN 6
#define NUMPIXELS 12

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 120

void setup(){
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(9600);
}
void loop(){
  if (Serial.available()){
      int r = Serial.readStringUntil(',').toInt();

      int g = Serial.readStringUntil(',').toInt();

      int b = Serial.readStringUntil(',').toInt();

    for (int i = 0; i < NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show();
    delay(DELAYVAL);
    }
    delay(1000);
  }
}