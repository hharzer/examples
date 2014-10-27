/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

 * Note: because most Arduinos have a built-in LED attached
 to pin 13 on the board, the LED is optional.


 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 This example code is in the public domain.

 http://arduino.cc/en/Tutorial/AnalogInput

 */

#include "AppBuilder.h"

AppBuilder appb(4, 1, String("AVH\0"), 2048);
uid8 label_poti = 0, text = 0;
int count = 0;

int sensorPin = A0;    // select the input pin for the potentiometer
// select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void serialEvent()
{
    appb.serial_event();
}

void onconnect(uid8 egal, char *ebenso)
{
    uid8 root = appb.start_layout();
    text = appb.add_label();
    label_poti = appb.add_label();
    appb.end_layout(root);

    appb.send_components();
    appb.set_text(text, "Zaehler:\0");
}

void setup()
{
    // declare the ledPin as an OUTPUT:
    Serial.begin(9600);

    appb.set_onconnect(onconnect);

}

void loop()
{
    // read the value from the sensor:
    appb.refresh();
    count++;
    sensorValue = analogRead(sensorPin);
    char mydelaystr[32];
    String(sensorValue).toCharArray(mydelaystr, 32);
    appb.set_text(label_poti, mydelaystr);

    char mydelaystr2[32];
    String(count).toCharArray(mydelaystr2, 32);
    appb.set_text(text, mydelaystr2);
    delay(sensorValue);
}