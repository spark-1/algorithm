#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int main() {

	int T, N, M;
	deque<pair<int, int>> printer;

	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int count = 1;
		printer.clear();
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			int q;
			scanf("%d", &q);
			printer.push_back(make_pair(q, i));
		}
		while (1) {
			pair<int, int> q = printer.front();
			int i = 0, flag = 0;
			while (printer[i].first <= q.first) {
				i++;
				if (printer.size() == i) {
					flag = 1;
					break;
				}
			}
			if (flag == 1 && q.second == M) {
				printf("%d\n", count);
				break;
			}
			if (flag == 0) {
				printer.push_back(q);
			}
			else {
				count++;
			}
			printer.pop_front();
		}
	}
}