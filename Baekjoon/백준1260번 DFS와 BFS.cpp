#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, V;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int curr) {
	printf("%d ", curr);
	visited[curr] = true;
	for (int next : adj[curr]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
}

void bfs(int curr) {
	queue<int> Q;
	Q.push(curr);
	visited[curr] = true;
	while (!Q.empty()) {
		printf("%d ", Q.front());
		curr = Q.front();
		Q.pop();
		for (int next : adj[curr]) {
			if (!visited[next]) {
				visited[next] = true;
				Q.push(next);
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &V);
	adj.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	
	dfs(V);
	printf("\n");
	fill(visited.begin(), visited.end(), false);
	bfs(V);
}