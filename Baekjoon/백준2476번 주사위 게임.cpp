#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int N, a, b, c, big, price, result = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &a, &b, &c);

		if (a == b && b == c) {
			price = 10000 + a * 1000;
		}
		else if (a == b || b == c) {
			price = 1000 + 100 * b;
		}
		else if (a == c) {
			price = 1000 + 100 * a;
		}
		else {
			big = max(a, max(b, c));
			price =  big * 100;
		}
		if (result < price) {
			result = price;
		}
		//printf("%d\n", price);
	}
	printf("%d\n", result);
}