#include "LedMatrix.h"
#include "settings.h"
#include "config.h"
#include "WS2812_util.h"
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTONLOW_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  digitalWrite(BUTTONLOW_PIN, LOW);

  Serial.begin(115200); Serial.println("");
  printDebugMessage("Verbonden...");

  strip.begin();
  strip.setBrightness(255);
  setAllPixels(0, 255, 0, 1.0);

  //  // set up the LCD's number of columns and rows:
  //  lcd.begin(16, 2);
  //  // Print a message to the LCD.
  //  lcd.print("hello, world!");
}

void loop() {
  // put your main code here, to run repeatedly:
  getMessages();
}

void getMessages() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    printDebugMessage("Knop geklikt");
    setAllPixels(255, 0, 0, 1.0);
    printInstagramMessages();
    setAllPixels(0, 255, 0, 1.0);
  }
}



void printInstagramMessages() {
  String messages[] = {"PERSOON: Kim Feenstra. ONDERWERP: Schaars gekleed. BERICHT: Wauw, mooie foto schat. xoxo",
                       "PERSOON: Mike de Boer. ONDERWERP: Space a niffauw. BERICHT: Lekker pillen rammen, gap!",
                       "PERSOON: Sanne Kooistra ONDERWERP: Nieuwe zonnebril. BERICHT: Wejoo, snelle planga swa."
                      };

  for (int i = 0; i < 3; i++) {
    printDebugMessage("APPLYING MACHINE LEARNING PROTOCOLS");
    delay(1000);
    printDebugMessage("COMPLETED.");
    delay(500);
    printDebugMessage(messages[i]);
    printDebugMessage("");
    printDebugMessage("");
    delay(250);
  }
}

void printDebugMessage(String message) {
#ifdef DEBUG_MODE
  Serial.println(message);
#endif
}
