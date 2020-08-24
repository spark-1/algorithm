#include <iostream>
#include <vector>

using namespace std;

int main() {

	int K, N;
	long long s, e, m;
	vector<int> LAN;

	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++) {
		int t;
		scanf("%d", &t);
		LAN.push_back(t);
	}

	s = 1;
	e = 3000000000;

	while (s + 1 < e) {
		long long sum = 0;
		m = (s + e) / 2;
		for (int i = 0; i < K; i++) {
			sum += LAN[i] / m;
		}
		if (sum < N) {
			e = m;
		}
		else {
			s = m;
		}
	}
	printf("%d\n", s);
}