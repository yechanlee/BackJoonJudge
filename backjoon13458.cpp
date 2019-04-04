#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX_N 10000000
long N, B, C, result;
//N강의실 수, B는 주감독 1명씩 포함, C는 0명이상 맥스까지
long bang[MAX_N];

void hop() {

	for (long i = 0; i < N; i++) {

		bang[i] -= B;
		long count = 0;

		if (bang[i] > 0) {
			result += bang[i] / C;
			if (bang[i] % C > 0) result += 1; //만약에 나머지 생기면 1추가해줘

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