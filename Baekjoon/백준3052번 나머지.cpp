#include <iostream>

int main() {

	int num, result = 0;
	int count[42] = { 0 };

	//memset(count, 0, sizeof(count));

	for (int i = 0; i < 10; i++) {
		scanf("%d", &num);
		num %= 42;
		count[num]++;
	}
	for (int i = 0; i < 42; i++) {
		if (count[i] > 0) {
			result++;
		}
	}
	printf("%d\n", result);
}