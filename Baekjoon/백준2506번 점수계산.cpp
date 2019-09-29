#include <iostream>

int main() {

	int N, num, score = 0, sum = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		num == 1 ? score++ : score = 0;
		sum += score;
	}
	printf("%d\n", sum);
}