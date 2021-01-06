#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

// ������ ���� ������
enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, 
	DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};

class cBall { // OOP�� ���� ball class ����
	int x, y;
	int originalX, originalY; // origin ��ġ
	eDir direction; // �������� 
public:
	cBall(int posX, int posY) // �ʱ�ȭ
	{
		originalX = posX; // ������ġ
		originalY = posY;
		x = posX; y = posY; // ���� �� ��ġ
		direction = STOP;
	}
	void Reset() {  // ����ġ�� origin���� 
		x = originalX; y = originalY;
		direction = STOP;
	}
	void changeDirection(eDir d) // ���� ���⺯��
	{
		direction = d;
	}
	void randomDirection() // ������ ����
	{
		direction = (eDir)((rand() % 6) + 1); // eDir�� 1~6 random�� ����
	}
	int getX() { return x; } // �ڵ� inline�Լ��� ����
	int getY() { return y; }
	eDir getDirection() { return direction; }
	void Move() {
		switch (direction)
		{ // ���ʻ�ܸ����̰� ��ǥ���� �߽�
		case STOP:
			break;
		case LEFT:
			x--; // --�� �ؾ� left�� ������
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
		default: // ���Ʒ��δ� ���� �������� ����, ����X
			break;
		}
	}
	friend ostream& operator<<(ostream& o, cBall c) // output_stream �����ε�
	{
		o << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]";
		return o;
	}
};

class cPaddle { // ����� class
	int x, y;
	int originalX, originalY;
public:
	cPaddle() : cPaddle(0, 0) {} // ���ӻ�����
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
	void moveUp() { y--; } // ����� ����
	void moveDown() { y++; } // ����� �Ʒ��� 

	friend ostream& operator<<(ostream& o, cPaddle c) // output_stream �����ε�
	{
		o << "Paddle [" << c.x << "," << c.y << "]";
		return o;
	}
};

class cGameManager {
	int width, height;
	int score1, score2; // player�� ���� 
	char up1, down1, up2, down2; // �÷��̾��� ���ٿ�
	bool quit; // �������� 
	cBall* ball;
	cPaddle* player1;
	cPaddle* player2;
public:
	cGameManager(int w, int h)
	{
		srand(time(NULL));
		quit = false; // ����������
		up1 = 'w'; up2 = 'i'; // ����Ű
		down1 = 's'; down2 = 'k';
		score1 = score2 = 0; // ����
		width = w; height = h;
		ball = new cBall(w / 2, h / 2); // ���� �� �߾Ӻ��� ����
		player1 = new cPaddle(1, h / 2 - 3); // ����
		player2 = new cPaddle(w-2, h / 2 - 3); // ������
	}
	~cGameManager() // �����Ҵ� ���� heap �޸� ��ȯ
	{
		delete ball, player1, player2;
	}
	void ScoreUp(cPaddle* player) // �������
	{
		if (player == player1)
			score1++;
		else if (player == player2)
			score2++;

		ball->Reset();; // ���������� ��, �÷��̾� ��ġ �ʱ�ȭ
		player1->Reset();
		player2->Reset();
	}
	void Draw() {
		system("cls"); // ������ CLS���� �۵�, Linux������ �ȵ�
		for (int i(0); i < width + 2; i++)  // ��� ��
			cout << "#"; 
		cout << endl;

		for (int i(0); i < height; i++) // I�� y-coordinate
		{ 
			for (int j(0); j < width; j++) // J�� x-coordinate
			{
				int ballx = ball->getX();
				int bally = ball->getY();
				int player1x = player1->getX();
				int player2x = player2->getX();
				int player1y = player1->getY();
				int player2y = player2->getY();

				if (j == 0)
					cout << "#";

				if (ballx == j && bally == i) // ���� ��ġ 
					cout << "O";
				else if (player1x == j && player1y == i) // player 1 ���� 
					cout << "#;"
				else if (player2x == j && player2y == i) // player 2 ���� 
					cout << "#;"
				else
					cout << " ";

				if (j == width-1)
					cout << "#";
			}
			cout << endl;
		}

		for (int i(0); i < width + 2; i++)  // �ϴ� �� 
			cout << "#";
		cout << endl;
	}
};

int main(void) 
{
	cGameManager c(40, 20);
	c.Draw();

	return 0;
}