#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int N(0), W(0), T(0), maxnum(0);
	vector<int> plum;
	vector< vector< vector<int> > > dp;

	cin >> T >> W;

	plum = vector<int>(T + 1, 0);
	dp = vector< vector< vector<int> > >(3, vector< vector<int> >(W + 1, vector<int>(T + 1, 0)));

	for (int i = 1; i <= T; i++) {
		cin >> plum[i];
	}

	for (int t = 1; t <= T; t++) {
		if (plum[t] == 1) {
			dp[1][0][t] = dp[1][0][t - 1] + 1;
		}
	}

	for (int w = 1; w <= W; w++) {
		for (int t = 1; t <= T; t++) {
			if (plum[t] == 1) {
				dp[1][w][t] = max(dp[1][w][t - 1], dp[2][w - 1][t - 1]) + 1;
				dp[2][w][t] = max(dp[1][w - 1][t - 1], dp[2][w][t - 1]);
			}
			else if (plum[t] == 2) {
				dp[1][w][t] = max(dp[1][w][t - 1], dp[2][w - 1][t - 1]);
				dp[2][w][t] = max(dp[1][w - 1][t - 1], dp[2][w][t - 1]) + 1;
			}
		}
	}

	for (int w = 0; w <= W; w++) {
		maxnum = max(maxnum, dp[1][w][T]);
		maxnum = max(maxnum, dp[2][w][T]);
	}

	printf("%d\n", maxnum);
}
