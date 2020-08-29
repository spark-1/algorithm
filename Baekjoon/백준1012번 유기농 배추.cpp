#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, M, N, K;
int ewns[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
vector<vector<int>> cabbage;
vector<vector<bool>> visited;

int dfs(int y, int x) {
	int nodes = 1;
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int a = y + ewns[i][1], b = x + ewns[i][0];
		if (a >= 0 && b >= 0 && a < N && b < M && !visited[a][b] && (cabbage[a][b] == 1)) {
			nodes += dfs(a, b);
		}
	}
	return nodes;
}

int dfs_all() {
	int components = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && (cabbage[i][j] == 1)) {
				int nodes = dfs(i, j);
				components++;
				//printf("nodes = %d\n", nodes);
			}
		}
	}
	return components;
}

int main() {

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d %d %d", &N, &M, &K);
		cabbage.resize(N);
		visited.resize(N);
		
		for (int i = 0; i < N; i++) {
			cabbage[i].resize(M);
			visited[i].resize(M);
		}
		
		for (int i = 0; i < N; i++) {
			fill(visited[i].begin(), visited[i].end(), false);
			fill(cabbage[i].begin(), cabbage[i].end(), 0);
		}

		for (int i = 0; i < K; i++) {
			int X, Y;
			scanf("%d %d", &X, &Y);
			cabbage[X][Y] = 1;
		}

		printf("%d\n", dfs_all());
	}
}