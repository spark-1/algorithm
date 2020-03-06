#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N, M, i, l;
	vector<int> lesson;
	long long blueray, temp, lowest = 1, highest = 1000000000LL;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%d", &l);
		if (l > lowest) {
			lowest = l;
		}
		lesson.push_back(l);
	}

	while (1) {
		if (lowest == highest) {
			break;
		}
		int count = 1;
		temp = (highest + lowest) / 2;
		blueray = temp;
		for (i = 0; i < N; i++) {
			blueray -= lesson[i];
			if (blueray < 0) {
				count++;
				blueray = temp - lesson[i];
			}
		}
		if (count > M) {
			if (lowest + 1 == highest) {
				lowest = highest;
			}
			else {
				lowest = temp;
			}
		}
		else {
			highest = temp;
		}
	}

	printf("%d\n", lowest);
}