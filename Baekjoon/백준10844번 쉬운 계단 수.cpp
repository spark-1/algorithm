#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N;
	vector<vector<int>> dp;
	scanf("%d", &N);
	dp.resize(N);
	dp[0].resize(10);
	dp[0].push_back(0);
	for (int i = 1; i < 10; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < N; i++) {
		dp[i].resize(10);
		for (int d = 0; d < 10; d++) {
			if (d == 0) {
				dp[i][d] = dp[i - 1][d + 1];
			}
			else if (d == 9) {
				dp[i][d] = dp[i - 1][d - 1];
			}
			else {
				dp[i][d] = (dp[i - 1][d - 1] + dp[i - 1][d + 1]) % 1000000000;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 10; i++) {
		result += dp[N - 1][i];
		result %= 1000000000;
	}
	printf("%d", result % 1000000000);
}