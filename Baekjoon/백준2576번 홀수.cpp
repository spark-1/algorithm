#include <iostream>

int main() {

	int num, min_odd = 100, sum = 0;

	for (int i = 0; i < 7; i++) {
		scanf("%d", &num);
		if (num % 2 == 1) {
			sum += num;
			if (num < min_odd) {
				min_odd = num;
			}
		}
	}
	if (min_odd == 100) {
		printf("-1\n");
		return 0;
	}

	printf("%d\n%d\n", sum, min_odd);
}