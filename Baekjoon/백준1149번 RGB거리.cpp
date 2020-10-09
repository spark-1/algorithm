#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	vector<vector<int>> house;
	vector<vector<int>> dp; // first index: house, second index: prev color

	scanf("%d", &N);
	house.resize(N);
	dp.resize(N + 1);

	for (int i = 0; i < N; i++) {
		int r, g, b;
		scanf("%d %d %d", &r, &g, &b);
		house[i].push_back(r);
		house[i].push_back(g);
		house[i].push_back(b);
		dp[i + 1].resize(3);
	}
	dp[0].push_back(0);
	dp[0].push_back(0);
	dp[0].push_back(0);

	for (int i = 0; i < N; i++) {
		dp[i + 1][0] = min(dp[i][1] + house[i][1], dp[i][2] + house[i][2]);
		dp[i + 1][1] = min(dp[i][0] + house[i][0], dp[i][2] + house[i][2]);
		dp[i + 1][2] = min(dp[i][1] + house[i][1], dp[i][0] + house[i][0]);
	}

	printf("%d", min(min(dp[N][0], dp[N][1]), dp[N][2]));
}