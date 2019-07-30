#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

#define CONSTRUCT_NUM 1000

void clearQueue(queue<int> &Q);

int main() {

	int T, N, K, D[CONSTRUCT_NUM] = { 0 }, indegree[CONSTRUCT_NUM] = { 0 }, time[CONSTRUCT_NUM] = { 0 };
	vector<int> adj[CONSTRUCT_NUM];

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		
		int u, v, finish;
		scanf("%d %d", &N, &K);
		
		for (int i = 0; i < N; i++) {
			scanf("%d", &D[i]);
		}
		
		for (int k = 0; k < K; k++) {
			scanf("%d %d", &u, &v);
			adj[u - 1].push_back(v);
			indegree[v - 1]++;
		}
		scanf("%d", &finish);

		// 위상정렬 시작
		queue<int> Q;
		for (int i = 0; i < N; i++) {
			if (indegree[i] == 0) {
				time[i] = D[i];
				Q.push(i + 1);
			}
		}

		for (int i = 0; i < N; i++) {
			int curr = Q.front();
			Q.pop();
			if (curr == finish) {
				printf("%d\n", time[finish - 1]);
				break;
			}

			for (int next : adj[curr - 1]) {
				time[next - 1] = max(time[next - 1], time[curr - 1] + D[next - 1]);
				indegree[next - 1]--;
				if (indegree[next - 1] == 0) {
					Q.push(next);
				}
			}
		}

		// adj indegree Q 초기화
		fill_n(indegree, N, 0);
		fill_n(time, N, 0);
		for (int i = 0; i < N; i++) {
			adj[i].clear();
		}
		clearQueue(Q);
	}
}

void clearQueue(queue<int> &Q) {
	queue<int> empty;
	swap(Q, empty);
}
