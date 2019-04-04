#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int N, M, X, Y, K;

#define Max_Num 1000
int map[20][20];
vector<int> dice(6); // �ֻ��� 1���� 2���� 3���� 4���� 5���� 6���Ʒ�
vector<int> dice2(6);
int result[1000]; //��� ���� �����ϴ°�

bool checkroll(int a, int b) {
	if (a<0 || a>N - 1 || b<0 || b>M - 1) return false;
	else return true;
	//�ֻ��� ��ǥ�� �Ѿ���� �˻��ϱ�
}
bool checkMap(int x, int y) {
	return map[x][y];
	//���ڰ� 0�̸� false, ��������� true 
}

void roll(int rollnum, int count) {
	switch (rollnum) {
	case 1: //����
	
		if (checkroll(X, Y + 1)) {
			Y = Y + 1; //��ǥ ������
			if (checkMap(X,Y)) { //���ڰ� ���� �ִ�
				dice2[0] = dice[1];
				dice2[1] = dice[5];
				dice2[2] = dice[0];
				dice2[3] = dice[3];
				dice2[4] = dice[4];
				dice2[5] = map[X][Y];
				map[X][Y] = 0;
			}
			else { //���ڰ� ���� �ٴ�0�̶�� �ٴڿ� �� ���ڸ� �־���
				dice2[0] = dice[1];
				dice2[1] = dice[5];
				dice2[2] = dice[0];
				dice2[3] = dice[3];
				dice2[4] = dice[4];
				dice2[5] = dice[2];
				map[X][Y] = dice2[5]; //�������
			}
			dice = dice2;
			result[count] = dice[0];
			cout << result[count] << endl;
		}
		else {
			
		}
		break;
	case 2: //����
	
		if (checkroll(X, Y-1)) {
			Y = Y - 1; //��ǥ ������
			if (checkMap(X, Y)) { //���ڰ� ���� �ִ�
				dice2[0] = dice[2];
				dice2[1] = dice[0];
				dice2[2] = dice[5];
				dice2[3] = dice[3];
				dice2[4] = dice[4];
				dice2[5] = map[X][Y];
				map[X][Y] = 0;
			}
			else { //���ڰ� ���� �ٴ�0�̶�� �ٴڿ� �� ���ڸ� �־���
				dice2[0] = dice[2];
				dice2[1] = dice[0];
				dice2[2] = dice[5];
				dice2[3] = dice[3];
				dice2[4] = dice[4];
				dice2[5] = dice[1];
				map[X][Y] = dice2[5]; //�������
			}
			dice = dice2;
			result[count] = dice[0];
			cout << result[count] << endl;
		}
		else {
			
		}
		break;
	case 3: //����
		if (checkroll(X - 1, Y)) {
			X = X-1; //��ǥ ������
			if (checkMap(X, Y)) { //���ڰ� ���� �ִ�
				dice2[0] = dice[4];
				dice2[1] = dice[1];
				dice2[2] = dice[2];
				dice2[3] = dice[0];
				dice2[4] = dice[5];
				dice2[5] = map[X][Y];
				map[X][Y] = 0;
			}
			else { //���ڰ� ���� �ٴ�0�̶�� �ٴڿ� �� ���ڸ� �־���
				dice2[0] = dice[4];
				dice2[1] = dice[1];
				dice2[2] = dice[2];
				dice2[3] = dice[0];
				dice2[4] = dice[5];
				dice2[5] = dice[3];
				map[X][Y] = dice2[5]; //�������
			}
			dice = dice2;
			result[count] = dice[0];
			cout << result[count] << endl;
		}
		else {
			
		}
		break;
	case 4: //����
		if (checkroll(X + 1, Y)) {
			X = X + 1; //��ǥ ������
			if (checkMap(X, Y)) { //���ڰ� ���� �ִ�
				dice2[0] = dice[3];
				dice2[1] = dice[1];
				dice2[2] = dice[2];
				dice2[3] = dice[5];
				dice2[4] = dice[0];
				dice2[5] = map[X][Y];
				map[X][Y] = 0;
			}
			else { //���ڰ� ���� �ٴ�0�̶�� �ٴڿ� �� ���ڸ� �־���
				dice2[0] = dice[3];
				dice2[1] = dice[1];
				dice2[2] = dice[2];
				dice2[3] = dice[5];
				dice2[4] = dice[0];
				dice2[5] = dice[4];
				map[X][Y] = dice2[5]; //�������
			}
			dice = dice2;
			result[count] = dice[0];

			cout << result[count] << endl;
		}
		else {
			
		}

		break;
	default:
		break;

	}
}

int main(void) {
	dice = { 0,0,0,0,0,0 };
	dice2 = { 0,0,0,0,0,0 };
	int count = 0;

	
	cin >> N >> M >> X >> Y >> K;
	vector<int> move(K);
	for (int i = 0; i < N; i++)	for (int j = 0; j < M; j++) cin >> map[i][j];
	//�ʿ� �־��ش�.
	
	for (int i = 0; i < K; i++) cin >> move[i];
	//�Է°� �Ϸ�

	
	

	//�˰��� ����
	for (int i = 0; i < K; i++) {
		//K����ŭ �ֻ����� �����δ�.
		roll(move[i],count);
		count++;
		
	}

	//������
	//����Ǿ��� ���ʿ� ���ڵ��� ����Ѵ�
	/*for (int i = 0; i < K; i++) {
		cout << result[i] << endl;
		
	}
	*/
	
	return 0;
}