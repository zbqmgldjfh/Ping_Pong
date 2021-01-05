#include <iostream>
#include <time.h>
#include <conio.h>

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

class cPaddle { // 막대기 class
	int x, y;
	int originalX, originalY;
public:
	cPaddle() : cPaddle(0, 0) {} // 위임생성자
	cPaddle(int posX, int posY)
	{
		originalX = posX;
		originalY = posY;
		x = posX; y = posY;
	}
	void Reset() {
		x = originalX;
		y = originalY;
	}
	int getX() { return x; }
	int getY() { return y; }
	void moveUp() { y--; } // 막대기 위로
	void moveDown() { y++; } // 막대기 아래로 

	friend ostream& operator<<(ostream& o, cPaddle c) // output_stream 오버로딩
	{
		o << "Paddle [" << c.x << "," << c.y << "]";
		return o;
	}
};

class cGameManager {
	int width, height;
	int score1, score2; // player의 점수 
	char up1, down1, up2, down2; // 플레이어의 업다운
	bool quit; // 게임종료 
	cBall* ball;
	cPaddle* player1;
	cPaddle* player2;
public:
	cGameManager(int w, int h)
	{
		srand(time(NULL));
		quit = false; // 게임진행중
		up1 = 'w'; up2 = 'i'; // 방향키
		down1 = 's'; down2 = 'k';
		score1 = score2 = 0; // 점수
		width = w; height = h;
		ball = new cBall(w / 2, h / 2); // 공은 정 중앙부터 시작
		player1 = new cPaddle(1, h / 2 - 3); // 왼쪽
		player2 = new cPaddle(w-2, h / 2 - 3); // 오른쪽
	}
	~cGameManager() // 동적할당 받은 heap 메모리 반환
	{
		delete ball, player1, player2;
	}
	void ScoreUp(cPaddle* player) // 점수계산
	{
		if (player == player1)
			score1++;
		else if (player == player2)
			score2++;

		ball->Reset();; // 점수득점시 공, 플레이어 위치 초기화
		player1->Reset();
		player2->Reset();
	}
};

int main(void) {
	cPaddle p1(0, 0);
	cPaddle p2(10, 0);
	cout << p1 << endl;
	cout << p2 << endl;
	p1.moveUp();
	p2.moveDown();
	cout << p1 << endl;
	cout << p2 << endl; 

	return 0;
}