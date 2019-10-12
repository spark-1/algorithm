#include <iostream>

int main() {

	int N;

	scanf("%d", &N);

	for (int n = 0; n < N; n++) {
		for (int i = 0; i < n + 1; i++) {
			printf("*");
		}
		for (int i = 0; i < 2 * N + -2 * (n + 1); i++) {
			printf(" ");
		}
		for (int i = 0; i < n + 1; i++) {
			printf("*");
		}
		printf("\n");
	}

	for (int n = 1; n < N; n++) {
		for (int i = 0; i < N - n; i++) {
			printf("*");
		}
		for (int i = 0; i < 2 * n; i++) {
			printf(" ");
		}
		for (int i = 0; i < N - n; i++) {
			printf("*");
		}
		printf("\n");
	}
}