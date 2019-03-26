#include <stdio.h>

int main() {

	int t = 0;
	int n = 0;
	int i = 0;
	int j = 0;
	int partition = 0;
	int prime[10000] = { 0 };

	for (i = 2; i < 10000; i++)
		prime[i] = 1;

	for (i = 2; i < 10000; i++) { //에라토스테네스의 체 
		for (j = 2; (i * j) < 10000 && (prime[i] == 1); j++) {
			if (prime[i * j] == 1) {
				prime[i * j] = 0;
			}
		}
	}

	scanf("%d", &t);
	while (t-- > 0) {

		scanf("%d", &n);
		partition = n / 2;

		while (1) {
			if ((prime[partition] + prime[n - partition]) == 2)
				break;
			else
				partition--;
		}
		printf("%d %d\n", partition, n - partition);
	}
}