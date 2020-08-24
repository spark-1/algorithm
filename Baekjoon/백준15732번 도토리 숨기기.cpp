#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N, K, D;
	int s, e, m;
	vector<int> A, B, C;

	scanf("%d %d %d", &N, &K, &D);

	int a, b, c;
	for (int i = 0; i < K; i++) {
		scanf("%d %d %d", &a, &b, &c);
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
	}

	s = 1;
	e = N; 
	long long sum = 0;
	while (s < e) {
		m = (s + e) / 2;
		sum = 0;
		for (int i = 0; i < K; i++) {
			if (B[i] < m) {
				sum += (B[i] - A[i]) / C[i] + 1;
			}
			else if (A[i] <= m) {
				sum += (m - A[i]) / C[i] + 1;
			}
		}

		if (D <= sum) {
			e = m;
		}
		else {
			s = m + 1;
		}
	}

	printf("%d\n", e);
}