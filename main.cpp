#include <iostream>
using namespace std;
// 방향을 위한 열거형
enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, 
	DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};

class cBall { // OOP를 위한 ball class 구현
	int x, y;
	int originalX, originalY; // origin 위치
	eDir direction; // 방향지정 
public:
	cBall(int posX, int posY) // 초기화
	{
		originalX = posX; // 시작위치
		originalY = posY;
		x = posX; y = posY; // 공의 현 위치
		direction = STOP;
	}
	void Reset() {  // 현위치가 origin으로 
		x = originalX; y = originalY;
		direction = STOP;
	}
	void changeDirection(eDir d) // 공의 방향변경
	{
		direction = d;
	}
	void randomDirection() // 무작위 방향
	{
		direction = (eDir)((rand() % 6) + 1); // eDir의 1~6 random수 생성
	}
	int getX() { return x; } // 자동 inline함수로 변경
	int getY() { return y; }
	eDir getDirection() { return direction; }
	void Move() {
		switch (direction)
		{ // 왼쪽상단모퉁이가 좌표축의 중심
		case STOP:
			break;
		case LEFT:
			x--; // --를 해야 left로 움직임
			break;
		case RIGHT:
			x++; 
			break;
		case UPLEFT:
			x--; y--;
			break;
		case DOWNLEFT:
			x--; y++;
			break;
		case UPRIGHT:
			x++; y--;
			break;
		case DOWNRIGHT:
			x++; y++;
			break;
		default: // 위아래로는 공이 움직이지 않음, 구현X
			break;
		}
	}
	friend ostream& operator<<(ostream& o, cBall c) // output_stream 오버로딩
	{
		o << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]";
		return o;
	}
};
int main(void) {
	cBall c(0, 0);
	cout << c << endl;
	c.randomDirection(); // 방향변경 
	cout << c << endl;
	c.Move();
	cout << c << endl;
	c.randomDirection(); // 방향변경 
	c.Move();
	cout << c << endl;
	return 0;
}