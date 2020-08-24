#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N, s, e, m, total, max = 0;
	vector<int> province;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int t;
		scanf("%d", &t);
		province.push_back(t);
		if (max < t) {
			max = t;
		}
	}
	scanf("%d", &total);

	s = 1;
	e = 100000;

	while (s + 1 < e) {
		int sum = 0;
		int m = (s + e) / 2;
		for (int i = 0; i < N; i++) {
			sum += province[i];
		}
		if (sum <= total) {
			s = max;
			break;
		}
		else {
			sum = 0;
		}
		for (int i = 0; i < N; i++) {
			if (m < province[i]) {
				sum += m;
			}
			else {
				sum += province[i];
			}
		}
		if (sum > total) {
			e = m;
		}
		else {
			s = m;
		}
	}

	printf("%d\n", s);
}