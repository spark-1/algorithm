#include <iostream>

struct Person {
	int w;
	int h;
};

int main() {

	int N, rank = 1;
	Person *p;
	scanf("%d", &N);
	p = new Person[N];

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &p[i].w, &p[i].h);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (p[i].w < p[j].w && p[i].h < p[j].h) {
				rank++;
			}
		}
		if (i != N - 1) {
			printf("%d ", rank);
		}
		else {
			printf("%d", rank);
		}
		rank = 1;
	}
}