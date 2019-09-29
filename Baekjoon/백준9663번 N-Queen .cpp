#include <iostream>
#include <cstring>

int N, result;
int queen(int chess[], int line, int possible);

int main() {

	int *chess;
	scanf("%d", &N);

	chess = new int[N] {}; // 라인별 퀸의 위치를 갖는 배열
	for (int i = 0; i < N; i++) {
		chess[i] = -1;
	}
	printf("%d\n", queen(chess, 0, 1));

}

int queen(int chess[], int line, int possible) { // 몇번째 line을 체크중인지

	if (possible == 0) {
		return 0;
	}
	if (line == N) {
		result++;
		return 1;
	}

	for (int i = 0; i < N; i++) { // i는 열의 위치를 의미한다
		for (int j = 0; j < line; j++) { // i열의 위치에 둘 수 있는지 이전 라인을 통해 확인
			if (i == chess[j])
				possible = 0;
			if ((i == chess[j] - (line - j)) || (i == chess[j] + (line - j)))
				possible = 0;
		}
		chess[line] = i;
		queen(chess, line + 1, possible);
		possible = 1;
	}

	return result;
}