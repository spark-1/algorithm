#include <iostream>
using namespace std;

int N, num, result, temp;
int **map;
int **bishop;

int backtracking(int x, int y, int flag) {

	if (x == N) {
		return 0;
	}

	if (map[x][y] == 1 && bishop[x][y] == 0) {
		num++;
		//printf("(%d %d)¿¡ ºñ¼óÀ» µÒ ÆÇ¿¡ °³¼ö %d°³\n", x, y, num);
		if (temp < num) {
			temp = num;
		}
		for (int n = 0; n < N; n++) {
			if (x + n < N && y + n < N)
				bishop[x + n][y + n]++;
			if (x + n < N && y - n >= 0)
				bishop[x + n][y - n]++;
			if (x - n >= 0 && y + n < N)
				bishop[x - n][y + n]++;
			if (x - n >= 0 && y - n >= 0)
				bishop[x - n][y - n]++;
		}

		if (y >= N - 2) {
			if (flag == 0) {
				backtracking(x + 1, ((x + 1) % 2), flag);
			}
			else {
				backtracking(x + 1, ((x + 1) % 2)^1, flag);
			}
			num--;
		}
		else {
			backtracking(x, y + 2, flag);
			num--;
		}
		for (int n = 0; n < N; n++) {
			if (x + n < N && y + n < N && bishop[x + n][y + n] > 0)
				bishop[x + n][y + n]--;
			if (x + n < N && y - n >= 0 && bishop[x + n][y - n] > 0)
				bishop[x + n][y - n]--;
			if (x - n >= 0 && y + n < N && bishop[x - n][y + n] > 0)
				bishop[x - n][y + n]--;
			if (x - n >= 0 && y - n >= 0 && bishop[x - n][y - n] > 0)
				bishop[x - n][y - n]--;
		}
		//printf("(%d %d)¿¡ ºñ¼óÀ» »­ ÆÇ¿¡ °³¼ö %d°³\n", x, y, num);
	}

	
	if (y >= N - 2) {
		if (flag == 0) {
			backtracking(x + 1, ((x + 1) % 2), flag);
		}
		else {
			backtracking(x + 1, ((x + 1) % 2)^1, flag);
		}
	}
	else {
		backtracking(x, y + 2, flag);
	}

	return 0;
}

int main() {

	scanf("%d", &N);

	map = new int *[N];
	bishop = new int *[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int [N];
		bishop[i] = new int [N];
		for (int j = 0; j < N; j++) {
			bishop[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	temp = 0;
	result = 0;
	num = 0;
	backtracking(0, 0, 0);
	result += temp;
	//printf("Èò»ö : %d\n", temp);
	temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			bishop[i][j] = 0;
		}
	}
	backtracking(0, 1, 1);
	//printf("°ËÀº»ö: %d\n", temp);
	result += temp;
	printf("%d\n", result);
}

/*
10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1

*/