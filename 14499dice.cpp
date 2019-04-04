#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int N, M, X, Y, K;

#define Max_Num 1000
int map[20][20];
vector<int> dice(6); // 주사위 1번위 2번좌 3번우 4번앞 5번뒤 6번아래
vector<int> dice2(6);
int result[1000]; //결과 윗면 저장하는곳

bool checkroll(int a, int b) {
	if (a<0 || a>N - 1 || b<0 || b>M - 1) return false;
	else return true;
	//주사위 좌표가 넘어가는지 검사하기
}
bool checkMap(int x, int y) {
	return map[x][y];
	//숫자가 0이면 false, 들어있으면 true 
}

void roll(int rollnum, int count) {
	switch (rollnum) {
	case 1: //동쪽
	
		if (checkroll(X, Y + 1)) {
			Y = Y + 1; //좌표 움직임
			if (checkMap(X,Y)) { //숫자가 원래 있다
				dice2[0] = dice[1];
				dice2[1] = dice[5];
				dice2[2] = dice[0];
				dice2[3] = dice[3];
				dice2[4] = dice[4];
				dice2[5] = map[X][Y];
				map[X][Y] = 0;
			}
			else { //숫자가 없고 바닥0이라면 바닥에 그 숫자를 넣어줘
				dice2[0] = dice[1];
				dice2[1] = dice[5];
				dice2[2] = dice[0];
				dice2[3] = dice[3];
				dice2[4] = dice[4];
				dice2[5] = dice[2];
				map[X][Y] = dice2[5]; //복사시켜
			}
			dice = dice2;
			result[count] = dice[0];
			cout << result[count] << endl;
		}
		else {
			
		}
		break;
	case 2: //서쪽
	
		if (checkroll(X, Y-1)) {
			Y = Y - 1; //좌표 움직임
			if (checkMap(X, Y)) { //숫자가 원래 있다
				dice2[0] = dice[2];
				dice2[1] = dice[0];
				dice2[2] = dice[5];
				dice2[3] = dice[3];
				dice2[4] = dice[4];
				dice2[5] = map[X][Y];
				map[X][Y] = 0;
			}
			else { //숫자가 없고 바닥0이라면 바닥에 그 숫자를 넣어줘
				dice2[0] = dice[2];
				dice2[1] = dice[0];
				dice2[2] = dice[5];
				dice2[3] = dice[3];
				dice2[4] = dice[4];
				dice2[5] = dice[1];
				map[X][Y] = dice2[5]; //복사시켜
			}
			dice = dice2;
			result[count] = dice[0];
			cout << result[count] << endl;
		}
		else {
			
		}
		break;
	case 3: //북쪽
		if (checkroll(X - 1, Y)) {
			X = X-1; //좌표 움직임
			if (checkMap(X, Y)) { //숫자가 원래 있다
				dice2[0] = dice[4];
				dice2[1] = dice[1];
				dice2[2] = dice[2];
				dice2[3] = dice[0];
				dice2[4] = dice[5];
				dice2[5] = map[X][Y];
				map[X][Y] = 0;
			}
			else { //숫자가 없고 바닥0이라면 바닥에 그 숫자를 넣어줘
				dice2[0] = dice[4];
				dice2[1] = dice[1];
				dice2[2] = dice[2];
				dice2[3] = dice[0];
				dice2[4] = dice[5];
				dice2[5] = dice[3];
				map[X][Y] = dice2[5]; //복사시켜
			}
			dice = dice2;
			result[count] = dice[0];
			cout << result[count] << endl;
		}
		else {
			
		}
		break;
	case 4: //남쪽
		if (checkroll(X + 1, Y)) {
			X = X + 1; //좌표 움직임
			if (checkMap(X, Y)) { //숫자가 원래 있다
				dice2[0] = dice[3];
				dice2[1] = dice[1];
				dice2[2] = dice[2];
				dice2[3] = dice[5];
				dice2[4] = dice[0];
				dice2[5] = map[X][Y];
				map[X][Y] = 0;
			}
			else { //숫자가 없고 바닥0이라면 바닥에 그 숫자를 넣어줘
				dice2[0] = dice[3];
				dice2[1] = dice[1];
				dice2[2] = dice[2];
				dice2[3] = dice[5];
				dice2[4] = dice[0];
				dice2[5] = dice[4];
				map[X][Y] = dice2[5]; //복사시켜
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
	//맵에 넣어준다.
	
	for (int i = 0; i < K; i++) cin >> move[i];
	//입력값 완료

	
	

	//알고리즘 실행
	for (int i = 0; i < K; i++) {
		//K번만큼 주사위를 움직인다.
		roll(move[i],count);
		count++;
		
	}

	//결과출력
	//저장되었던 윗쪽에 숫자들을 출력한다
	/*for (int i = 0; i < K; i++) {
		cout << result[i] << endl;
		
	}
	*/
	
	return 0;
}