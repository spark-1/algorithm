#include <iostream>

int main() {

	long long a = 0, b = 1, n;

	scanf("%lld", &n);

	if (n == 0) {
		printf("0\n");
		return 0;
	}

	for (int i = 1; i < n; i++) {
		long long t;
		t = b;
		b = a + b;
		a = t;
	}

	printf("%lld\n", b);
}