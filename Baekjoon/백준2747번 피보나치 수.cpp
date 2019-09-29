#include <iostream>

int main() {

	int a = 0, b = 1, c = 1, n;

	scanf("%d", &n);

	if (n == 0) {
		printf("0\n");
		return 0;
	}
	if (n == 1) {
		printf("1\n");
		return 0;
	}

	for (int i = 2; i < n; i++) {
		a = b;
		b = c;
		c = a + b;
	}
	printf("%d\n", c);
}