#include <Servo.h> // Adding the Servo library
Servo myServo; // Initializing a Servo object
int const potPin = A0; // Initializing the potentiometer pin, A0
int potVal; // Potentiometer value
int angle; // Servo motor angle

void setup() {
  myServo.attach(9); // Set pin 9 as the servo motor output
  Serial.begin(9600); // Start serial communication
}

void loop() {
  potVal = analogRead(potPin); // Read the value from the potentiometer pin
  Serial.print("potVal: ");  // Print to serial monitor
  Serial.print(potVal); // Print the potentiometer value
  angle = map(potVal, 0, 1023, 0, 179); // Map the potentiometer value (0 to 1023) to the servo angle range (0 to 179)
  Serial.print(", angle: "); // Print to serial monitor
  Serial.println(angle); // Print the mapped servo angle
  myServo.write(angle); // Move the servo motor to the specified angle
  delay(15); // Delay to ensure smooth servo movement
}
