#include <iostream>

int main() {

	long long S, num = 0, N = 0;

	scanf("%lld", &S);

	for (int i = 1; i < 200000; i++) {
		num += i;
		if (S < num) break;
		N++;
	}
	printf("%lld\n", N);
}