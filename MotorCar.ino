#include <TLE94112.h>
#include <TLE94112_Motor.h>

// The TLE94112 has only got 3 PWM channels
// There is no one left for motor4
// This means, we cannot control its speed
Tle94112Motor motor1(tle94112, tle94112.TLE_PWM1);
Tle94112Motor motor2(tle94112, tle94112.TLE_PWM3);

//motor1 ->Left
//motor2 ->Right

void setup()
{
  // call begin for the TLE94112 firs
  tle94112.begin();
  // motor1 is connected to 2 halfbridges on each side
  motor1.connect(tle94112.TLE_HB1, motor1.HIGHSIDE);
  motor1.connect(tle94112.TLE_HB2, motor1.LOWSIDE);
  motor2.connect(tle94112.TLE_HB3, motor2.HIGHSIDE);
  motor2.connect(tle94112.TLE_HB4, motor2.LOWSIDE);



  motor1.begin();
  motor2.begin();

  
}



void loop()
{
  moveForward();
  delay(1000);

//  moveBackward();
//  delay(1000);

  moveRight();
  delay(500);
  
  moveForward();
  delay(1000);

  moveLeft();
  delay(500);

  motor1.stop();
  motor2.stop();
}

void moveForward(){
  motor2.stop();
  motor1.stop();
  delay(500);
  motor1.start(127);
  motor2.start(127);  
  delay(1000);
}

void moveBackward(){
  motor2.stop();
  motor1.stop();
  delay(500);
  motor1.start(-127);
  motor2.start(-127);  
  delay(1000);
}

void moveRight(){  
  motor2.stop();
  motor1.stop();
  delay(500);
  motor1.start(127); 
  motor2.start(-63);  
  delay(500);
}

void moveLeft(){  
  motor1.stop();
  motor2.stop();
  delay(500);
  motor2.start(127);  
  motor1.start(-63);  
  delay(500);
}
