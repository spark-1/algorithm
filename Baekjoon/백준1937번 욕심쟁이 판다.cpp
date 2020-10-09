#include <iostream>
#include <vector>
using namespace std;

int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
vector<vector<int>> map;
vector<vector<int>> dp;
int n, K = 0;

int dfs(int curr_y, int curr_x) {
	
	if (dp[curr_y][curr_x]) {
		return dp[curr_y][curr_x];
	}

	dp[curr_y][curr_x] = 1;
	for (int i = 0; i < 4; i++) {
		int next_y = curr_y + dy[i], next_x = curr_x + dx[i];
		if (next_y < n && next_y >= 0 && next_x < n && next_x >= 0) {
			if (map[next_y][next_x] > map[curr_y][curr_x]) {
				dp[curr_y][curr_x] = max(dfs(next_y, next_x) + 1, dp[curr_y][curr_x]);
			}
		}
	}
	
	return dp[curr_y][curr_x];
}

int dfs_all() {
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {	
			result = max(dfs(i, j), result);
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}*/
	return result;
}

int main() {

	scanf("%d", &n);
	map.resize(n);
	dp.resize(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t;
			scanf("%d", &t);
			map[i].push_back(t);
		}
		dp[i].resize(n, 0);
	}

	K = dfs_all();
	printf("%d", K);
}