#include <iostream>
#include <vector>

using namespace std;

vector<int> p;

int find(int n) {
	if (p[n] < 0) return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[a] += p[b];
	p[b] = a;
}

int main() {

	int computer, pair_num, u, v;

	scanf("%d %d", &computer, &pair_num);

	p = vector<int>(computer, -1);
	for (int i = 0; i < pair_num; i++) {
		scanf("%d %d", &u, &v);
		merge(u - 1, v - 1);
	}

	printf("%d\n", -1 * p[find(0)] - 1);
}