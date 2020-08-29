#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int curr) {
	visited[curr] = true;
	for (int next : adj[curr]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
}

int dfs_all() {
	int components = 0;
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			dfs(i);
			components++;
		}
	}
	return components;
}

int main() {

	scanf("%d %d", &N, &M);
	adj.resize(N);
	visited.resize(N);

	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}

	printf("%d\n", dfs_all());
}