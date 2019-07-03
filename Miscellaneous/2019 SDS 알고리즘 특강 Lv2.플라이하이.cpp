#include <iostream>
#include <algorithm>
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

int dfs(int **dp, int **card, int y, int x, int N);

int main() {
	int T, N;
	int max_day = 0;
	int **card; // 카드숫자 저장
	int **dp; // dp[i][j]값은 (i,j)에서 가장 멀리 갈수 있는 길
	cin >> T;

	for (int t = 0; t < T; t++) {

		cin >> N;
		card = new int *[N];
		dp = new int *[N];
		for (int i = 0; i < N; i++) {
			card[i] = new int[N];
			dp[i] = new int[N];
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> card[i][j];
				dp[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				max_day = max(max_day, dfs(dp, card, i, j, N));
			}
		}

		cout << "#" << t + 1 << " " << max_day << endl;
		max_day = 0;
	}
}

int dfs(int **dp, int **card, int y, int x, int N) {

	if (dp[y][x] != 0) return dp[y][x];
	
	dp[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ay = y + dy[i];
		int ax = x + dx[i];

		if (ax < 0 || ay < 0 || ay >= N || ax >= N) // card배열 안의 값이어야한다
			continue;  

		if (card[ay][ax] > card[y][x]) { // 다음 칸으로 방문할 수 있는 경우
			dp[y][x] = max(dp[y][x], dfs(dp, card, ay, ax, N) + 1);
		}
	}

	return dp[y][x];
}

