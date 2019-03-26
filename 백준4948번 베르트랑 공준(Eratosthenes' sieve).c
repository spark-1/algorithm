#include<stdio.h>

int main() {

	int n = 0;
	int i = 0;
	int j = 0;
	int count = 0;
	int prime[(123456 * 2) + 1] = { 0 };

	for (i = 2; i <= 123456 * 2; i++)
		prime[i] = 1;

	for (i = 2; i <= 123456 * 2; i++) { //에라토스테네스의 체 
		for (j = 2; (i * j) <= (123456 * 2) && (prime[i] == 1); j++) {
			if (prime[i * j] == 1) {
				prime[i * j] = 0;
			}
		}
	}

	while (1) {

		scanf("%d", &n);
		if (n == 0)
			break;
		else
			for (i = n + 1; i <= 2 * n; i++) 
				count += prime[i];
		printf("%d\n", count);
		count = 0;
	}
}