#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX_N 10000000
long N, B, C, result;
//N���ǽ� ��, B�� �ְ��� 1�� ����, C�� 0���̻� �ƽ�����
long bang[MAX_N];

void hop() {

	for (long i = 0; i < N; i++) {

		bang[i] -= B;
		long count = 0;

		if (bang[i] > 0) {
			result += bang[i] / C;
			if (bang[i] % C > 0) result += 1; //���࿡ ������ ����� 1�߰�����

		}
		
	}
}

int main(void) {
	cin >> N, result = 0;; 
	bang[N];
	for (long i = 0; i < N; i++) cin >> bang[i];
	cin >> B >> C;
	hop();
	cout << result+N << endl;
	return 0;
}