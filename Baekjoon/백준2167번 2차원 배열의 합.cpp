#include <iostream>

int main() {

	int matrix[300][300];
	int N, M, K, i, j, x, y;

	scanf("%d %d", &N, &M);
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			scanf("%d", &matrix[n][m]);
		}
	}
	scanf("%d", &K);
	for (int k = 0; k < K; k++) {
		int sum = 0;
		scanf("%d %d %d %d", &i, &j, &x, &y);
		for (int n = i - 1; n < x; n++) {
			for (int m = j - 1; m < y; m++) {
				sum += matrix[n][m];
			}
		}
		printf("%d\n", sum);
	}
}