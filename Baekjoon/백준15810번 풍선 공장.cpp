#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N, M, t;
	vector<int> staff;
	long long time, ballon, lowest = 0, highest = 1000000000000LL;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &t);
		staff.push_back(t);
	}

	while (1) {
		ballon = 0;
		if (lowest == highest) {
			break;
		}
		int flag = 1;
		time = (highest + lowest) / 2;
		for (int i = 0; i < N; i++) {
			ballon += time / staff[i];
			if (ballon >= M) {
				flag = 0;
				break;
			}
		}

		if (flag == 0) {
			highest = time;
		}
		else {
			if (lowest + 1 == highest) {
				lowest = highest;
			}
			else {
				lowest = time;
			}
		}
	}

	printf("%lld\n", lowest);
}