#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, s, e;
vector<vector<int>> adj;

int bfs() {
	queue<int> Q;
	vector<bool> visited(n, false);
	int level = 0;

	Q.push(s - 1);
	visited[s - 1] = true;

	while (!Q.empty()) {
		int size = Q.size();
		for (int i = 0; i < size; i++) {
			int curr = Q.front();
			Q.pop();
			if (curr == e - 1) {
				return level;
			}
			for (int next : adj[curr]) {
				if (!visited[next]) {
					visited[next] = true;
					Q.push(next);
				}
			}
		}
		level++;
	}
	return -1;
}

int main() {
	scanf("%d %d %d %d", &n, &s, &e, &m);
	adj.resize(n);

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}

	printf("%d\n", bfs());
}