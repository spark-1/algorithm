#include <iostream>
using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
int ewsn[4], N;
bool map[100][100];
double result;

void dfs(int cnt, int curr_y, int curr_x, double p) {
	
	if (cnt == N) {
		//printf("%d %d %d %f %f\n", cnt, curr_y, curr_x, p, result);
		return;
	}

	map[curr_y][curr_x] = true;
	for (int i = 0; i < 4; i++) {
		int next_y = curr_y + dy[i];
		int next_x = curr_x + dx[i];
		if (!ewsn[i]) {
			continue;
		}
		p *= (double)ewsn[i] / 100;
		//printf("%d (%d %d)(%d %d) %f %f\n", cnt, curr_y, curr_x, next_y, next_x, p, result);
		if (map[next_y][next_x]) {
			result += p;
		}
		else {
			dfs(cnt + 1, next_y, next_x, p);
		}
		p *= (double)100 / ewsn[i];
	}
	map[curr_y][curr_x] = false;
}

int main() {
	scanf("%d %d %d %d %d", &N, &ewsn[0], &ewsn[1], &ewsn[2], &ewsn[3]);

	dfs(0, 50, 50, 1);

	printf("%.10f", 1 - result);
}