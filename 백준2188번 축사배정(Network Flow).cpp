#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX_N = 200;
const int MAX_V = MAX_N * 2 + 2;
const int S = MAX_V - 2;
const int E = MAX_V - 1;

int main() {
	// 소 정점은 0 ~ MAX_N-1, 축사 정점은 MAX_N ~ MAX_N*2-1 의 범위를 가짐
	int N, M, c[MAX_V][MAX_V] = { 0 }, f[MAX_V][MAX_V] = { 0 };
	vector<int> adj[MAX_V];
	scanf("%d %d", &N, &M);
	for (int i = 0; i<N; i++) {
		int K;
		scanf("%d", &K);
		for (int k = 0; k<K; k++) {
			int j;
			scanf("%d", &j);
			j = MAX_N + j - 1;
			// 가능한 간선 추가
			c[i][j] = 1;
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
		// 시작점에서 소 정점으로 가는 길
		c[S][i] = 1;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	for (int i = MAX_N; i<MAX_N + M; i++) {
		// 축사 정점에서 도착점으로 가는 길
		c[i][E] = 1;
		adj[i].push_back(E);
		adj[E].push_back(i);
	}

	int total = 0;

	while (1) {
		// BFS로 증가 경로 찾기
		int prev[MAX_V];
		fill(prev, prev + MAX_V, -1);
		queue<int> Q;
		Q.push(S);
		while (!Q.empty()) {
			int curr = Q.front();
			Q.pop();
			for (int next : adj[curr]) {
				// c[i][j]-f[i][j] > 0: i에서 j로 유량을 흘릴 여유가 남았는가?
				// prev[next] == -1: next 정점을 아직 방문하지 않았는가?
				if (c[curr][next] - f[curr][next] > 0 && prev[next] == -1) {
					Q.push(next);
					prev[next] = curr; // 경로를 기억하기 위해 prev 배열 사용
					if (next == E) break; // 싱크에 도달하면 나옴
				}
			}
		}
		// 싱크로 가는 경로가 더 없으면 루프 탈출
		if (prev[E] == -1) break; 

			// 매번 흘리는 유량은 반드시 1이므로 값을 따로 안 구해도 됨
			for (int i = E; i != S; i = prev[i]) {
				f[prev[i]][i]++;
				f[i][prev[i]]--;
			}
		total++;
	}
	printf("%d\n", total);
}