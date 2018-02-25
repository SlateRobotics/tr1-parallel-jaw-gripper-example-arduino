#include <Servo.h>

Servo servoGripper;

int fsrReading;
int gripper = 15;
bool up = true;

void setup(void) {
  Serial.begin(115200);
  servoGripper.attach(2);
}

void loop(void) {
  if (up == true && gripper >= 160) {
    gripper -= 5;
    up = false;
  } else if (up == true && gripper < 160) {
    gripper += 5;
  } else if (up == false && gripper <= 15) {
    gripper += 5;
    up = true;
  } else if (up == false && gripper > 15) {
    gripper -= 5;
  }
  
  servoGripper.write(gripper);
  fsrReading = analogRead(A0);
  
  Serial.print("FSR reading = ");
  Serial.println(fsrReading);
 
  delay(100);
}
