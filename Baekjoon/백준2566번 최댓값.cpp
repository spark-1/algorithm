#include <iostream>

int main() {

	int num, max = 0, x = 0, y = 0;

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			scanf("%d", &num);
			if (max < num) {
				max = num;
				x = i;
				y = j;
			}
		}
	}

	printf("%d\n%d %d\n", max, x, y);
}