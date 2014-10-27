/* 
 Controlling a servo position using a potentiometer (variable resistor) 
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h> 
#include "AppBuilder.h"

AppBuilder appb(4,1,String("AVH\0"),2048);

int ss = 0;
 
Servo myservo;  // create servo object to control a servo 

void serialEvent() {
	appb.serial_event();
}

void inc(uid8 id, char* text) {
	ss = atoi(text);
}
 
int potpin = 0;  // analog pin used to connect the potentiometer
int val = 0;    // variable to read the value from the analog pin 

void cnt(uid8 c, char* cc) {
	uid8 root = appb.start_layout();
	uid8 label = appb.add_label();
	uid8 text = appb.add_input();
	appb.end_layout(root);

	appb.send_components();

	appb.add_callback(text, inc);
}
 
void setup() 
{ 
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);

  appb.set_onconnect(cnt);

} 
 
void loop() 
{ 
	appb.refresh();
  val++;            // reads the value of the potentiometer (value between 0 and 1023) 
  // val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
  myservo.write(ss); 
  //myservo.refresh();                 // sets the servo position according to the scaled value 
  delay(15);                           // waits for the servo to get there 
} 
