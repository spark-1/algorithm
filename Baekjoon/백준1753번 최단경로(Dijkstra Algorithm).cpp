#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>

using namespace std;
const int MAX_V = 20000; // 최대 노드의 개수
const int INF = 1000000000; // 절대 나올 수 없는 경로값 10억 설정
typedef pair<int, int> P;

int main() {
	int V, E, source, target;
	vector<P> adj[MAX_V]; // 인접 리스트 
	scanf("%d %d %d", &V, &E, &source);
	source--;

	for (int i = 0; i<E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u - 1].push_back(P(v - 1, w));
		//adj[v - 1].push_back(P(u - 1, w)); 양방향 그래프일 경우 필요
	}

	int dist[MAX_V]; // 거리 배열
	int prev[MAX_V]; // 경로 기억 배열
	fill(dist, dist + MAX_V, INF);
	bool visited[MAX_V] = { 0 }; // 방문 여부 배열
	priority_queue<P, vector<P>, greater<P>> PQ; // 우선순위 큐

												 // 다익스트라 알고리즘
	dist[source] = 0; // 시작점으로의 거리는 0
	PQ.push(P(0, source)); // 시작점만 PQ에 넣고 시작
	while (!PQ.empty()) { // PQ가 비면 종료
		int curr;
		do {
			curr = PQ.top().second; // 우선순위 큐 내에서 가장 짧은 거리의 정점을 가져온다
			PQ.pop();
		} while (!PQ.empty() && visited[curr]); // curr가 방문한 정점이면 무시
												// 더 이상 방문할 수 있는 정점이 없으면 종료
		if (visited[curr]) break; // 더 이상 방문할 수 있는 정점이 없어졌을때 종료

		visited[curr] = true; // 방문
		for (auto &p : adj[curr]) {
			int next = p.first, d = p.second;

			if (dist[next] > dist[curr] + d) { // 거리가 갱신될 경우 PQ에 새로 넣음
				dist[next] = dist[curr] + d;
				prev[next] = curr;
				PQ.push(P(dist[next], next));
			}
		}
	}

	// 결과
	for (int i = 0; i < V; i++) {
		if (dist[i] == INF) puts("INF");
		else printf("%d\n", dist[i]);
	}
}