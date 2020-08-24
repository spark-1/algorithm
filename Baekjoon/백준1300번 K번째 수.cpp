#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, k, s, e, m;

	scanf("%d %d", &N, &k);

	long long sum;
	s = 1;
	e = 1000000000;

	while (s < e) {
		m = (s + e) / 2;
		sum = 0;
		for (int i = 1; i <= N; i++) {
			sum += min((m / i), N);
		}
		if (k <= sum) {
			e = m;
		}
		else {
			s = m + 1;
		}
	}

	printf("%d\n", e);
}