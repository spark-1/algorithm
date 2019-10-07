#include <iostream>
#include <vector>
using namespace std;

struct Store {
	int a, b;
};

int N, M, time;
int **map;
int **check;
bool **visited;
vector<Store> s;
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};


int dfs(int i, int j) {
	
	visited[i][j] = true;
	for (int dir = 0; dir < 4; dir++) {
		if (i + x[dir] < N && i + x[dir] >= 0 && j + y[dir] < M && j + y[dir] >= 0) {
			if (visited[i + x[dir]][j + y[dir]] == false) {
				if (map[i + x[dir]][j + y[dir]] == 1) {
					check[i + x[dir]][j + y[dir]]++;
					if (check[i + x[dir]][j + y[dir]] == 2) {
						Store temp = { i + x[dir], j + y[dir] };
						s.push_back(temp);
					}
				}
				else {
					dfs(i + x[dir], j + y[dir]);
				}
			}
		}
	}
	return 0;
}

void reset_visited() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}
}
void reset_check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			check[i][j] = 0;
		}
	}
}

int main() {

	scanf("%d %d", &N, &M);

	map = new int *[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[M];
	}

	visited = new bool *[N];
	for (int i = 0; i < N; i++) {
		visited[i] = new bool[M];
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}

	check = new int *[N];
	for (int i = 0; i < N; i++) {
		check[i] = new int[M];
		for (int j = 0; j < M; j++) {
			check[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	while (1) {
		dfs(0, 0);
		if (s.size() == 0) {
			printf("%d\n", time);
			return 0;
		}
		while (s.size() > 0) {
			Store temp = s.back();
			s.pop_back();
			map[temp.a][temp.b] = 0;
		}
		reset_visited();
		reset_check();
		time++;
	}
}