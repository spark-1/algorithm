#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1000000000;

int main() {
	
	vector<vector<int>> dist;
	int N;
	scanf("%d", &N);
	dist.resize(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int t;
			scanf("%d", &t);
			dist[i].push_back((t == 0) ? INF : 1);
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", (dist[i][j] == INF) ? 0 : 1);
		}
		printf("\n");
	}
}