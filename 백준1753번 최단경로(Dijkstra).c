#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int main() {

	int V = 0, E = 0;
	int s = 0; // 시작 정점이자 현재 정점
	int **weight = NULL; // V * V 가중치 인접행렬 
	int i = 0, u = 0, v = 0, w = 0;
	int mind = 0;
	int finish = 0;
	int *d = NULL; // 시작 정점에서의 최단거리
	int *p = NULL; // 1이면 영구적 0이면 임시적

	scanf("%d %d", &V, &E); // 정점과 간선의 개수 입력
	scanf("%d", &s); // 탐색 시작 정점 입력
	
	weight = (int **)calloc(V + 1, sizeof(int *));
	for (i = 0; i <= V; i++) 
		weight[i] = (int *)calloc(V + 1, sizeof(int));
	
	for (i = 0; i < E; i++) { // 각 간선의 가중치 입력
		scanf("%d %d %d", &u, &v, &w);
		weight[u][v] = w;
	}
	
	d = (int *)calloc(V + 1, sizeof(int));
	for (i = 1; i <= V; i++)
		d[i] = INT_MAX;
	d[s] = 0;

	p = (int *)calloc(V + 1, sizeof(int));
	p[s] = 1;
	// 초기화 완료

	while (1) {
		mind = INT_MAX;
		for (i = 1; i <= V; i++) {
			if (weight[s][i] != 0) { // 현재 정점에서 갈 수 있는 정점이면
				d[i] = min(d[i], d[s] + weight[s][i]); // 비교하여 작은 거리를 택한다.
			}
		}
		for (i = 1; i <= V; i++) { // 정점중 임시적 최소거리가 가장 작은것을 찾아 현재 노드를 그 정점으로 바꾸어준다.
			if (p[i] == 0 && mind >= d[i]) {
				mind = d[i];
				s = i;
			}
		}
		p[s] = 1;
		for (i = 1; i <= V; i++) { // 모든 정점이 영구적인지 확인
			if (p[i] == 0) {
				finish = 0;
				break;
			}
			else {
				finish = 1;
			}
		}
		if (finish == 1)
			break;
	}

	for (i = 1; i <= V; i++) { // 각 정점으로의 최단 거리 출력
		if (d[i] == INT_MAX)
			printf("INF\n");
		else
			printf("%d\n", d[i]);
	}
}