#include <iostream>
using namespace std;

int main() {

	int N, max_count = 0, count = 0, newest_maintain_count = 0;
	int *num;
	bool increase, maintain;

	scanf("%d", &N);
	
	num = new int[N];
	
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	if (N <= 2) {
		printf("%d\n", N);
		return 0;
	}

	count = 1;
	newest_maintain_count = 1;
	maintain = true;
	increase = true;

	for (int i = 0; i < N - 1; i++) {
		if (num[i] == num[i + 1]) {
			if (maintain == true) {
				count++;
				newest_maintain_count++;
			}
			else {
				count++;
				newest_maintain_count = 2;
				maintain = true;
			}
		}
		else if (num[i] < num[i + 1]) {
			if (maintain == true && increase == true) {
				count++;
			}
			else if (maintain == true && increase == false) {
				count = newest_maintain_count;
				count++;
				increase = true;
			}
			else if (increase == true) {
				count++;
			}
			else if (increase == false) {
				count = 2;
				increase = true;
			}
			maintain = false;
		}
		else if (num[i] > num[i + 1]) {
			if (maintain == true && increase == true) {
				count = newest_maintain_count;
				count++;
				increase = false;
			}
			else if (maintain == true && increase == false) {
				count++;
			}
			else if (increase == true) {
				count = 2;
				increase = false;
			}
			else if (increase == false) {
				count++;
			}
			maintain = false;
		}

		if (max_count < count) {
			max_count = count;
		}
	}

	printf("%d\n", max_count);
}