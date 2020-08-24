#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, C;
	int s, e, m;
	vector<int> house;

	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++) {
		int t;
		scanf("%d", &t);
		house.push_back(t);
	}
	sort(house.begin(), house.end());

	s = 1;
	e = house[N - 1] + 1;

	while (s + 1 < e) {
		int l = house[0], r;
		int sum = 1;
		m = (s + e) / 2;
		for (int i = 1; i < N; i++) {
			if (house[i] - l >= m) {
				sum++;
				l = house[i];
			}
		}
		if (sum >= C) {
			s = m;
		}
		else {
			e = m;
		}
	}

	printf("%d\n", s);
}