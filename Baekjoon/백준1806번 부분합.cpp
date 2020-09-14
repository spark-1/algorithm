#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, S;
	int result = 100001;
	vector<int> num;
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		int t;
		scanf("%d", &t);
		num.push_back(t);
	}
	int s = 0, e = 1;
	int sum = num[0];
	while (s < N) {
		if (sum >= S) {
			result = min(result, e - s);
			sum -= num[s];
			s++;
		}
		else {
			if (e == N) {
				break;
			}
			sum += num[e];
			e++;
		}
	}
	if (result == 100001) {
		result = 0;
	}
	printf("%d\n", result);
}