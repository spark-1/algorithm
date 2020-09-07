#include <iostream>
#include <queue>

using namespace std;

int main() {

	priority_queue<int, vector<int>, less<int>> PQ;
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		if (num > 0) {
			PQ.push(num);
		}
		else {
			if (PQ.empty()) {
				printf("0\n");
			}
			else {
				num = PQ.top();
				printf("%d\n", num);
				PQ.pop();
			}
		}
	}
}