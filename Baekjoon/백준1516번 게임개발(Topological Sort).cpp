#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int N, time[500], result[500] = { 0 }, indegree[500] = { 0 };
	vector<int> adj[500];
	queue<int> Q;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", time + i);
		while (1) {
			int pre;
			scanf("%d", &pre);
			if (pre == -1) break;
			indegree[i]++;
			adj[pre - 1].push_back(i);
		}
		
		if (indegree[i] == 0) { // indegree = 0인 정점을 큐에 넣어 둠
			result[i] = time[i];
			Q.push(i);
		}
	}

	// 위상 정렬
	for (int i = 0; i < N; i++) {
		int curr = Q.front();
		Q.pop();
		for (int next : adj[curr]) {
			result[next] = max(result[next], result[curr] + time[next]); // 최소 건설 완료 시간 갱신
			if (--indegree[next] == 0) Q.push(next); // 간선을 삭제하여 next의 indegree가 0이 되면 next도 큐에 넣음
		}
	}

	for (int i = 0; i < N; i++)
		printf("%d\n", result[i]);
}