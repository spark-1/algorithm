#include <iostream>

int main() {

	int N;

	scanf("%d", &N);

	for (int n = 0; n < N; n++) {
		for (int i = 0; i < n; i++) {
			printf(" ");
		}
		for (int i = (N - n) * 2 - 1; i > 0; i--) {
			printf("*");
		}
		printf("\n");
	}
}