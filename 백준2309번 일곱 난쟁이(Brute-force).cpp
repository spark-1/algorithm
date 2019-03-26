#include <cstdio>
#include <algorithm>
using namespace std;

int main() {

	int height[9] = { 0 };
	int sum(0);
	int i(0), j(0), num(0);

	for (i = 0; i < 9; i++) {
		scanf("%d", &height[i]);
	}

	for (i = 0; i < 8; i++) {
		for (j = i + 1; j < 9; j++) {
			for (num = 0; num < 9; num++) {
				if (num != i && num != j)
					sum += height[num];
			}
			if (sum == 100) {
				height[i] = 100;
				height[j] = 100;
				i = 10;
				j = 10;
			}
			sum = 0;
		}
	}

	sort(height, height + 9);

	for (num = 0; num < 9; num++) {
			printf("%d\n", height[num]);
	}
}