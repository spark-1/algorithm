#include <iostream>

int main() {

	int N, sum = 1, plug;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &plug);
		sum += plug - 1;
	}
	printf("%d\n", sum);
}