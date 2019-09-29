#include <iostream>

int main() {

	int max = 0, count = 0, num;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &num);
		if (num > max) {
			max = num;
			count = i + 1;
		}
	}
	printf("%d %d\n", max, count);
}