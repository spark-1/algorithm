#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<vector<bool>> visited;
vector<int> result;
int ewsn[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int M, N, K;

int dfs(int curr_y, int curr_x) {
	int nodes = 1;
	visited[curr_y][curr_x] = true;
	for (int t = 0; t < 4; t++) {
		int i = curr_y + ewsn[t][0], j = curr_x + ewsn[t][1];
		if (i >= 0 && j >= 0 && i < M && j < N && !visited[i][j] && !adj[i][j]) {
			nodes += dfs(i, j);
		}
	}
	return nodes;
}

int dfs_all() {
	int components = 0;
	int nodes;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] & !adj[i][j]) {
				nodes = dfs(i, j);
				components++;
				result.push_back(nodes);
			}
		}
	}
	return components;
}

int main() {
	scanf("%d %d %d", &M, &N, &K);
	adj.resize(M);
	visited.resize(M);

	for (int i = 0; i < M; i++) {
		adj[i].resize(N);
		visited[i].resize(N);
	}

	for (int i = 0; i < K; i++) {
		int A, B, X, Y, x, y;
		scanf("%d %d %d %d", &A, &B, &X, &Y);
		for (y = M - Y; y < M - B; y++) {
			for (x = A; x < X; x++) {
				adj[y][x] = 1;
			}
		}
	}

	printf("%d\n", dfs_all());
	sort(result.begin(), result.end());
	for(int i = 0; i < result.size(); i++){
		printf("%d ", result[i]);
	}
}