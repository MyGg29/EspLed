/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include <Arduino.h>

// Set LED_BUILTIN if it is not defined by Arduino framework
// #define LED_BUILTIN 2

bool isOn = false;
void setup()
{
  // initialize LED digital pin as an output.
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void toggleLed(){
  if(isOn){
    digitalWrite(4, LOW);
    digitalWrite(16, LOW);
    digitalWrite(17, LOW);
  }
  else{
    digitalWrite(4, HIGH);
    digitalWrite(16, HIGH);
    digitalWrite(17, HIGH);
  }
  isOn = !isOn;
}

int buttonState;
int lastButtonState = HIGH;
void loop()
{
  buttonState = digitalRead(2);
  if(lastButtonState != buttonState){
    if (buttonState == HIGH)
    {
      toggleLed();
    }
  }
  lastButtonState = buttonState;
  delay(100);
}
