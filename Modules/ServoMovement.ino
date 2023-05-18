/*
- 컨벤션의 소개
언어 또는 프레임워크 등에 따라 개발자들간의 암묵적인 룰이 있다.
수학에도 컨벤션이 있다. 우리는 모르는 미지수를 보면 x로 잡곤 하는데, 사실 j 로 잡아도 아무도 뭐라 안하지만 "굳이 x놔두고?" 라는 의문 한 번 쯤 나곤 한다.
이처럼 규칙에 어긋나진 않으나 안 지키면 어색함을 느끼는 암묵적인 관례, 이를 코드 컨벤션이라 한다.

- 네이밍 컨벤션 소개
코드를 이루는 모든 요소에는 컨벤션이 있고 나 또한 모르는 것이 많으나 가장 기본적인 컨벤션인 네이밍 컨벤션을 간단히 소개해본다.

-> Python 네이밍 컨벤션
보통 snake_case 를 사용한다. snake_case 에서는 줄임말을 자주 쓰곤한다. ex) initialize_keyboard -> init_kb
```
cool_project/modules/cool.py    -> 디렉토리 네이밍도 컨벤션을 지키자.

some_var = 5;                   -> 변수명

def change_some_var_to_eight(): -> 함수명
    some_var = 8
```
그 외에도 클래스명 등에도 웬만하면 snake_case 를 사용하는 걸로 안다.
-> C/C++ 네이밍 컨벤션
이런 언어처럼 역사가 깊은 경우, 한 언어인데도 갈래가 갈라지는 경우가 있다.

C/C++ 공식 함수 등을 보면 snake_case 나 camelCase 를 사용한다. 해킹, 로봇, OS 등 거의 모든 분야에서 이를 따른다.
camelCase 에서의 줄임말 사용은, 알잘딱이다. 애매함. ex) initializeKeyboard -> initKeyboard / initKB / ...
```
cool_project/modules/cool.c

int SomeVar = 5;                -> snake_case 는 Python에서 소개했으니 C에서는 camelCase 를 써본다. 전역변수는 PascalCase. PascalCase 에 대한 자세한 설명은 밑에.

void changeSomeVarToEight() {   -> 중괄호는 선언 옆에.
    someVar = 8;
}
```
하지만 마이크로소프트를 필두로한 게임이나 윈도우 앱 프로그래밍에서는 PascalCase 를 사용한다. 그렇다. 마소만 아니었어도 C++ 유저 100%가 공식 컨벤션을 썼을 것이다.
PascalCase 에서의 줄임말 사용은, 거의 없다. 너무 길지 않은 이상 다 풀어 쓴다. 이는 C#에서 적나라하게 보여진다. ex) InitializeKeyboard
```
CoolProject/Modules/Cool.cpp

int SomeVar = 5;                -> 상수 또는 전역 변수는 PascalCase

void ChangeSomeVarToGivenValue(int value) -> 함수, 클래스 등도 PascalCase. 인자나 지역변수는 camelCase.
{                               -> 중괄호는 선언 아랫줄에.
    SomeVar = value;
}
```
- 네이밍 컨벤션 외의 함수 컨벤션
C언어의 절차지향 프로그래밍, C++, Java의 객체지향 프로그래밍에 이어 새 트렌드로 함수형 프로그래밍이 등장 하고 있는데, 사실 이런 거창한 이론이 나오기 전에도
많은 함수를 사용하는게 이쁜 코드로 여겨진지는 오래다. 전역변수를 배척하는 것과 같은 맥락임.

```배척할 코드
GayLord Gay = CreateGayLord();

void Foo()
{
    if (Gay.IsAngry())
    {
        Say("dont fuck ma ass TT");
    }
}
```
```지향할 코드 (함수형 프로그래밍)
GayLord GetGayLord()
{
    GayLord gay = CreateGayLord();
    
    return gay;
}

void Foo()
{
    GayLord gayLord = GetGayLord();
    
    if (gayLord.IsAngry())
    {
        Say("dont fuck ma ass TT");
    }
}
*/


#include <Servo.h>

Servo Servo9;

float VelocityRatio = 0.3; // !!!! 비율이라는 의미인 Ratio 를 자주 쓴다.
int PError = 0; // !!!! P가 무슨 약자인지 몰라서 그냥 PError 로 했는데, 알맞는 단어를 길게 쓰도록 하자. PenguinError 라든지..
float Interval = 0.5f; // CDM의 interval과 일치해야하지 않을까? // !!!! float 값에는 f를 붙여야해. 0.1(x) 0.1f(o)
int PerAngle = 0;

// 화면에서 중선과 벗어난 error 계산, 길이인 error를 각으로 변환하는 함수 필요
// 움직여야하는 각도를 넣어주면 서보의 움직임이 끊김 없이 v'(t) = 0인 지점을 최소화하는 스크립트가 필요
// 전 속도와의 차이를 구해, 그에 비례하는 값을 곱한 새로운 값을 속도로 지정하면 어떨까?
// 방향(LR UD)을 +- 로만 구분해주면 되는거지. 

int calSpeed(int pError, int error) {
    // !!!! speed 와 같은 전역변수는 줄이자. 전역변수는 절대악이다. 물론 Python 의 기억, 아두이노 특유의 형태 때문에 전역변수를 쓰게 되겠지만 그래도 최대한 줄이려고 노력하자.
    return (int)((error - pError) * VelocityRatio); // !!!! 타입 전환 꼼꼼히 한거 너무 칭찬해
}

void moveServo(float interval, int angle) { // !!!! 아마 interval 전역변수 때문에 쓸 거 없어서 타입 표시 한 거 같은데, 이런 센스는 칭찬한다. 하지만 타입 표시 할 때는 camelCase 를 쓴다. fInterval. 하지만 지금은 전역변수명이 달라졌기 때문에 그냥 interval 로 가자.
  // 서보모터의 속도에 따라 큰 상관이 없을수도 있긴한데 이동의 정확성 확보를 위해서는.
  // 특정 각을 움직일때 시간이 얼마나 걸리는지를 직접 측정하고, 그만큼의 시간 로스를 채우는 코드가 필요하겠다.
  // 10도정도를 기준으로 잡아 time[(error // 10)] 정도로 불러오면 되겠다.
  
  int j = (int)(interval / 0.1); // !!!! 웬만하면 컴파일러가 알잘딱 하지만 꼼꼼히 타입 전환으로 예상치 못한 에러를 예방하자.
  PerAngle = (int)(angle / j);
  
  int i = 0; // !!!! for 문을 위해 태어난 아이를 감히 전역변수로 쓴다고?
  for (i = 0; i < j; i++)
  {
    Servo9.write(PerAngle);
    delay(10); // delay 고려한 정확한 j 계산 필요
  }
  Servo9.write();
}

// 예로, CDM의 interval이 0.1초라고 가정하자. 그러면 각 0.1초마다 얼마나 움직일지를 결정하면 되는거다.
// 서보모터가 얼마나 빨리 움직일수가 있는지가 관건이겠다.

void setup()
{
  Servo9.attach(9, 500, 2500);
}

void loop()
{
  // interval이 0.5초일때
  // [0, 20, 30, 40, 60, 80, 40, 80, 10, -20, -60, 70, -50, -20, 0]
}
