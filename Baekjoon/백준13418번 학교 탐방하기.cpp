#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int uf[1001]; // 유니온 파인드

int find(int a) {
	if (uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false; // 이미 둘이 한 집합
	uf[b] = a;
	return true; // 둘이 한 집합이 아니였음
}

struct Edge {
	int u, v, w;
	Edge(int u, int v, int w) : u(u), v(v), w(w) {}
	bool operator <(Edge e) {
		return w < e.w;
	}
};

bool compare(Edge e1, Edge e2) {
	return e1.w > e2.w;
}

int main() {
	int N, M, ascent, best, worst, cnt;
	
	scanf("%d %d", &N, &M);
	vector<Edge> e;

	for (int i = 0; i < M + 1; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		e.push_back(Edge(u, v, w));
	}
	sort(e.begin(), e.end());
	/*
	for (int i = 0; i < M + 1; i++) {
		printf("%d %d %d\n", e[i].u, e[i].v, e[i].w);
	}*/

	fill(uf, uf + N + 1, -1);
	
	cnt = 0;
	ascent = 0;
	for (int i = 0; ; i++) {
		if (merge(e[i].u, e[i].v)) {
			if (e[i].w == 0) ascent++;
			if (++cnt == N) break; // N개 간선을 뽑으면 나감
		}
	}
	
	//printf("%d\n", ascent); // 최악일때
	worst = ascent * ascent;

	fill(uf, uf + N + 1, -1);
	sort(e.begin(), e.end(), compare);
	cnt = 0;
	ascent = 0;
	for (int i = 0; ; i++) {
		if (merge(e[i].u, e[i].v)) {
			if (e[i].w == 0) ascent++;
			if (++cnt == N) break; // N개 간선을 뽑으면 나감
		}
	}
	//printf("%d\n", ascent); // 최선일때
	best = ascent * ascent;

	printf("%d\n", worst - best);
}