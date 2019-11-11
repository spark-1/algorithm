#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int t, a[3];

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d %d", &a[0], &a[1], &a[2]);
		sort(a, a + 3);
		printf("Scenario #%d:\n", i + 1);
		printf(a[0] * a[0] + a[1] * a[1] == a[2] * a[2] ? "yes\n" : "no\n");
		if (i != t - 1)
			printf("\n");
	}

}