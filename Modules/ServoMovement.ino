#include <Servo.h>

Servo servo_9;
int i = 0

float velMultiplier = 0.3;
int speed = 0;
int p_error = 0;
float interval = 0.5; // CDM의 interval과 일치해야하지 않을까?
int perAngle = 0;

// 화면에서 중선과 벗어난 error 계산, 길이인 error를 각으로 변환하는 함수 필요
// 움직여야하는 각도를 넣어주면 서보의 움직임이 끊김 없이 v'(t) = 0인 지점을 최소화하는 스크립트가 필요
// 전 속도와의 차이를 구해, 그에 비례하는 값을 곱한 새로운 값을 속도로 지정하면 어떨까?
// 방향(LR UD)을 +- 로만 구분해주면 되는거지. 

int calSpeed(int p_error, int error)
{
  speed = (int)((error - p_error) * velMultiplier);
  return speed;
}

void moveServo(float interval_f, int angle){
  // 서보모터의 속도에 따라 큰 상관이 없을수도 있긴한데 이동의 정확성 확보를 위해서는.
  // 특정 각을 움직일때 시간이 얼마나 걸리는지를 직접 측정하고, 그만큼의 시간 로스를 채우는 코드가 필요하겠다.
  // 10도정도를 기준으로 잡아 time[(error // 10)] 정도로 불러오면 되겠다.
  
  int j = interval_f / 0.1;
  perAngle = (int)(angle / j)
  
  for (i = 0; i< j; i++)
  {
    servo_9.write(perAngle);
    delay(10); // delay 고려한 정확한 j 계산 필요
  }
  servo_9.write();
}

// 예로, CDM의 interval이 0.1초라고 가정하자. 그러면 각 0.1초마다 얼마나 움직일지를 결정하면 되는거다.
// 서보모터가 얼마나 빨리 움직일수가 있는지가 관건이겠다.

void setup()
{
  servo_9.attach(9, 500, 2500);
}

void loop()
{
  // interval이 0.5초일때
  // [0, 20, 30, 40, 60, 80, 40, 80, 10, -20, -60, 70, -50, -20, 0]
}