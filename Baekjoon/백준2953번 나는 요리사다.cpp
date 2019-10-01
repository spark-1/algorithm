#include <iostream>

int main() {

	int num, sum = 0, winner = 0, max_sum = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &num);
			sum += num;
		}
		if (max_sum < sum) {
			max_sum = sum;
			winner = i + 1;
		}
		sum = 0;
	}
	printf("%d %d\n", winner, max_sum);
}