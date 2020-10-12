#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N;
	vector<int> P;
	vector<vector<int>> dp; // 카드종류, 카드개수 

	scanf("%d", &N);
	P.resize(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &P[i]);
	}

	dp.resize(N + 1);
	for (int i = 0; i <= N; i++) {
		dp[i].resize(N + 1, 0);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (j - i >= 0) {
				dp[i][j] = max(dp[i][j], dp[i][j - i] + P[i]);
			}
		}
	}

	printf("%d", dp[N][N]);
}