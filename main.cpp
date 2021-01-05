#include <iostream>
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
int main(void) {
	cBall c(0, 0);
	cout << c << endl;
	c.randomDirection(); // ���⺯�� 
	cout << c << endl;
	c.Move();
	cout << c << endl;
	c.randomDirection(); // ���⺯�� 
	c.Move();
	cout << c << endl;
	return 0;
}