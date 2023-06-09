#include <Servo.h>
#include <stdlib.h>

Servo Sv;

int MaxSpeed = 10;
int MaxDiff = 10;
int MaxAnglePerChunk = 1;
int LoopPerChunk = 5;

int Angle = 0;
int AnglePerLoop = 0;

int diffToAngle(int diff) {
  int angle = 0;
  // consuming the screen is 640*480
  angle = (int)(diff * 0.0971875);
  return angle;
}

void moveServo(int targetDiff) {
  if (abs(targetDiff) > abs(MaxDiff)){
     // Move Servo on the max speed available + LR
    int i = 0;
    for (i = 0; i< LoopPerChunk; i++){
      if(targetDiff < 0){
        Sv.write(-1 * MaxAnglePerChunk);
        delay(10);
      } else {
        Sv.write(MaxAnglePerChunk);
        delay(10);
      }
    }
  } else {
    int i = 0;
    //change diff -> angle
    Angle = diffToAngle(targetDiff);
    AnglePerLoop = (int)(Angle / LoopPerChunk);

    for (i = 0; i< LoopPerChunk; i++){
      Sv.write(AnglePerLoop);
      delay(10);
    }
  }
}

void setup(){
  Sv.attach(9, 500, 2500);
}

void loop() {
  moveServo(10);
  moveServo(20);
  moveServo(-30);
  moveServo(20);
  moveServo(50);
  moveServo(150);
  moveServo(0);

}