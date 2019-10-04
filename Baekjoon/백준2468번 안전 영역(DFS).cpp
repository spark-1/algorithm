#include <iostream>

int x[4] = { 1, -1, 0, 0 };
int y[4] = { 0, 0, 1, -1 };
int **map, N, height, max, count;

void reset_visited(bool **visited);
int dfs(bool **visited, int i, int j, int h);

int main() {

	scanf("%d", &N);
	map = new int *[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
		for (int j = 0; j < N; j++) {
			scanf("%d", &height);
			map[i][j] = height;
		}
	}

	bool **visited;
	visited = new bool *[N];
	for (int i = 0; i < N; i++) {
		visited[i] = new bool[N];
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}

	for (int h = 0; h <= 100; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == false && map[i][j] > h) {
					dfs(visited, i, j, h);
					count++;
				}
			}
		}
		//printf("%d높이일때 %d개 가능\n", h, count);
		if (max < count) {
			max = count;
		}
		count = 0;
		reset_visited(visited);
	}
	printf("%d\n", max);
}

int dfs(bool **visited, int i, int j, int h) {

	visited[i][j] = true;

	for (int dir = 0; dir < 4; dir++) {
		if (i + x[dir] < N && i + x[dir] >= 0 && j + y[dir] < N && j + y[dir] >= 0) {
			if (visited[i + x[dir]][j + y[dir]] == false && map[i][j] > h) {
				dfs(visited, i + x[dir], j + y[dir], h);
			}
		}
	}
	return 0;
}

void reset_visited(bool **visited) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}