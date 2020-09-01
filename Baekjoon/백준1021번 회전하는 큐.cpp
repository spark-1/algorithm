#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int main() {
	int N, M, result = 0;
	deque<int> number;
	queue<int> q;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		number.push_back(i + 1);
	}
	for (int i = 0; i < M; i++) {
		int t;
		scanf("%d", &t);
		q.push(t);
	}

	while (!q.empty()) {
		int find = q.front();
		int i = 0;
		while (number[i] != find) {
			i++;
		}
		if (i <= number.size() / 2) { // 왼쪽으로 밀기
			result += i;
			for (int j = 0; j < i; j++) {
				int t = number.front();
				number.pop_front();
				number.push_back(t);
			}
		}
		else { // 오른쪽으로 밀기
			result += number.size() - i;
			for (int j = 0; j < number.size() - i; j++) {
				int t = number.back();
				number.pop_back();
				number.push_front(t);
			}
		}
		number.pop_front();
		q.pop();
	}
	printf("%d\n", result);
}