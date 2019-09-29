#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a < b;
}

int main() {

	int N, *num;
	scanf("%d", &N);
	num = new int[N];

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + N, compare);

	for (int i = 0; i < N; i++) {
		printf("%d\n", num[i]);
	}
}