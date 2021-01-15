# Ping_Pong

## 컴퓨터공학 포토폴리오 김지우

<img src = "https://user-images.githubusercontent.com/60593969/104157253-228fa480-542e-11eb-9d6b-379f3032b449.gif" width="700px">\

**간단한 C++ 연습용 게임 만들기**

## Class 설계
______________________
|Name|State|Behavior|
|:--:|:--:|--|
|**cBall**|위치정보(originalX, originalY), 방향(direction)| 현위치 초기화:Reset(), 방향변경:changeDirection(eDir d), 움직이기:Move()|
|**cPaddle**|위치정보(originalX, originalY)|현위치 초기화:Reset(), 위아래이동:moveUP(),moveDown()|
|**cGameManager**|console높너비, 점수판, 플레이어입력key값| 점수계산:ScoreUp(), 출력문:Draw(), 공이동:Input(), 공방향지정:Logic(), 실행:Run()|

## mian내부의 중요 함수 3가지
```C
Draw(); // 화면에 출력하는 함수
Input(); // user의 input을 받아들이고 작용하는
Logic(); // 공의방향지정, paddle의 움직임, 종료조건등 논리부분
```

## 방향설계

```C
enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, 
	DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};
```
열거형을 사용하여 방향지정에 용의하도록 하였습니다. 다음코드에서 활용됩니다.

```C
// 왼쪽 막대
for (int i = 0; i < 4; i++)
	if (ballx == player1x + 1)
		if (bally == player1y + i)
			ball->changeDirection((eDir)((rand() % 3) + 4)); // 공이 맞으면 튕길 방향이 4, 5, 6중 하나여야함

// 오른쪽 막대
for (int i = 0; i < 4; i++)
	if (ballx == player2x - 1)
		if (bally == player2y + i)
			ball->changeDirection((eDir)((rand() % 3) + 1)); // 공이 맞으면 튕길 방향이 1, 2, 3중 하나여야함
```
void Logic()함수의 일부입니다. rand()를 통해 나온 random값을 나머지 연산을 이용해 방향을 정해줍니다.   
위에서 **eDir을 열거형으로 해논 이유**가 이를 위해서 입니다.

#### 이외의 부분은 주석으로 설명해 두었습니다. 위의 내용이 가장 핵심 이였습니다.
