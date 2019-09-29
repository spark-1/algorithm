#include <iostream>

int main() {
	int T, N, num, sum = 0;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &num);
			sum += num;
		}
		printf("%d\n", sum);
		sum = 0;
	}
}