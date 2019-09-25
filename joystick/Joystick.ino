#include <SerialCommand.h>

#include <SoftwareSerial.h>
SerialCommand sCmd;

// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
int dataX;

void pingHandler () {
  //Serial.print("X-Axis:");
  Serial.println(analogRead(X_pin));
  //Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
}

void echoHandler () {
  char *arg;
  arg = sCmd.next();
  if (arg != NULL)
    Serial.println(arg);
  else
    Serial.println("nothing to echo");
}
void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  while (!Serial);

  sCmd.addCommand("PING", pingHandler);
}

void loop() {
 // Serial.print("Switch:  ");
  //Serial.print(digitalRead(SW_pin));
  //Serial.print("\n");
  //Serial.print("X-axis: ");
    //string dataX = analogRead(X_pin);
//  Serial.print("\n");
  
//  Serial.print("\n\n");
  //delay(500);

  if (Serial.available() > 0)
    sCmd.readSerial();

}
