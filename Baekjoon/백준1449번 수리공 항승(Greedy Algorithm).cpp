#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int N(0), L(0);
	int temp(0);
	int need(0);
	vector<int> pos;

	scanf("%d %d", &N, &L);
	pos = vector<int>(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &pos[i]);
	}
	sort(pos.begin(), pos.end());
	
	for (int i = 0; i < N;) {
		temp = pos[i] + L - 1;
		need++;
		while (i < N && temp >= pos[i]) {
			i++;
		}
	}
	printf("%d\n", need);
}
