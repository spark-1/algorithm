#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<int>> maze;
vector<vector<bool>> visited;
int N, M;
int ewsn[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int bfs() {
	queue<pair<int, int>> Q;
	int level = 0;
	Q.push(make_pair(0, 0));
	visited[0][0] = true;
	while (!Q.empty()) {
		int size = Q.size();
		for (int i = 0; i < size; i++) {
			pair<int, int> curr = Q.front();
			if (curr.first == N - 1 && curr.second == M - 1) {
				return level;
			}
			Q.pop();
			for (int j = 0; j < 4; j++) {
				int y = curr.first + ewsn[j][0];
				int x = curr.second + ewsn[j][1];
				if (y < N && y >= 0 && x < M && x >= 0 && !visited[y][x] && maze[y][x]) {
					Q.push(make_pair(y, x));
					visited[y][x] = true;
				}
			}
		}
		level++;
	}

}

int main() {
	
	scanf("%d %d", &N, &M);
	maze.resize(N);
	visited.resize(N);
	getchar();

	for (int i = 0; i < N; i++) {
		visited[i].resize(M, false);
		fill(visited[i].begin(), visited[i].end(), false);
		for (int j = 0; j < M; j++) {
			char c;
			scanf("%c", &c);
			maze[i].push_back(c - '0');
		}
		getchar();
	}
	
	printf("%d\n", bfs() + 1);
}