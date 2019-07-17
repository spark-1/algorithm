// 에드몬드 카프 알고리즘 BFS, 포드 풀커슨 알고리즘 DFS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX_V = 800;

struct Edge {
	int to, capacity, flow;
	Edge *dual;
	Edge() : Edge(-1, 0) {} 
	Edge(int to, int capacity) : to(to), capacity(capacity), flow(0), dual(nullptr) {}
	int spare() { 
		return capacity - flow;
	}
	void addFlow(int flow) { 
		this->flow += flow;
		dual->flow -= flow;
	}
};

int main() {
	
	int N, M; // N: 소 개수, M: 축사 개수
	int total = 0, S = 0, T = 0; // total: 총 유량, S: 소스, T: 싱크
	vector<Edge *> adj[MAX_V]; // 인접 리스트
	scanf("%d %d", &N, &M);

	S = 0; // 소스 인덱스
	// 소스에서 소로가는 용량 1인 간선 추가
	for (int i = 0; i < N; i++) {
		int u = 0, v = i + 1;
		Edge *e1 = new Edge(v, 1);
		Edge *e2 = new Edge(u, 0);
		e1->dual = e2;
		e2->dual = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
	}

	T = N + M + 1; // 싱크 인덱스
	// 축사에서 싱크로가는 용량 1인 간선 추가
	for (int i = 0; i < M; i++) {
		int u = i + N + 1, v = T;
		Edge *e1 = new Edge(v, 1);
		Edge *e2 = new Edge(u, 0);
		e1->dual = e2;
		e2->dual = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
	}

	// 간선을 입력받아 맞게 방향 간선 추가
	for (int i = 0; i < N; i++) {
		int capable_num, barn;
		scanf("%d", &capable_num);
		for (int j = 0; j < capable_num; j++) {
			scanf("%d", &barn);
			int u = i + 1; // 소 인덱스
			int v = N + barn; // 가려는 축사 인덱스
			Edge *e1 = new Edge(v, 1);
			Edge *e2 = new Edge(u, 0);
			e1->dual = e2;
			e2->dual = e1;
			adj[u].push_back(e1);
			adj[v].push_back(e2);
		}
	}

	// 최대 유량 구하기
	while (1) {
		Edge *prev[MAX_V] = { NULL }; // 경로를 기억하기 위해 prev 배열 사용 
		queue<int> Q;
		Q.push(S);

		while (!Q.empty() && prev[T] == NULL) { // 큐가 차있고 싱크로 간 길이 없으면 반복한다, 증가 경로를 BFS로 찾음
			int curr = Q.front();
			Q.pop();
			for (Edge *next : adj[curr]) { // 현재 노드에서 인접한 간선들에 대해
				// next->spare() - 1 >= 0: 현재 정점에서 다음 정점으로 유량을 흘릴 여유가 남았는가?
				// prev[next] == NULL: next->to 정점을 아직 방문하지 않았는가?
				if (next->spare() - 1 >= 0 && prev[next->to] == NULL) {
					Q.push(next->to);
					prev[next->to] = next; // 경로를 기억하기 위해 prev 배열 사용
					if (next->to == T) break; // 싱크에 도달하면 나옴
				}
			}
		}
		// 싱크로 가는 경로가 더 없으면 루프 탈출
		if (prev[T] == NULL) break;

		// 경로상에서 가장 허용치가 낮은 곳을 찾음 이 문제에서는 필요 없는 부분
		int flow = 100;
		for (int i = T; i != S; i = prev[i]->dual->to) {
			flow = min(flow, prev[i]->spare());
		}
		// 찾은 flow만큼 해당 경로에 유량 흘려줌
		for (int i = T; i != S; i = prev[i]->dual->to) {
			prev[i]->addFlow(flow);
			// printf("%d->%d ", prev[i]->to, prev[i]->dual->to);
		}
		// 총 유량 값 증가
		total += flow;
	}
	
	printf("%d\n", total);
}

