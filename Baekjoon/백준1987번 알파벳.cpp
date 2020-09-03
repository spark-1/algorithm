#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int R, C, result, cnt;
char adj[21][21];
bool visited[21][21];
bool alpha[21];
int ewsn[4][2] = { { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 } };

void dfs(int curr_y, int curr_x) {
	
	visited[curr_y][curr_x] = true;
	alpha[adj[curr_y][curr_x] - 'A'] = true;
	cnt++;

	for (int t = 0; t < 4; t++) {
		int i = curr_y + ewsn[t][0], j = curr_x + ewsn[t][1];
		if (i >= 0 && j >= 0 && i < R && j < C && !visited[i][j] && !alpha[adj[i][j] - 'A']) {
			dfs(i, j);
		}
	}

	if (cnt > result) {
		result = cnt;
	}
	cnt--;
	visited[curr_y][curr_x] = false;
	alpha[adj[curr_y][curr_x] - 'A'] = false;
}

int main() {

	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		scanf("%s", adj[i]);
	}

	dfs(0, 0);
	printf("%d\n", result); 
}