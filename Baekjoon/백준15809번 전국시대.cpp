#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

long long national[100002];
vector<long long> result;

long long find(int n);
void merge(int a, int b);

int main() {
	int N, M, people, record, p, q, number = 0;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &people);
		national[i] = people * (-1);
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &record, &p, &q);
		if (record == 1) { // µ¿¸Í 
			merge(p, q);
		}
		else if (record == 2) { // ÀüÀï 
			int a = find(p);
			int b = find(q);
			if (national[a] == national[b]) {
				national[a] = 0;
				national[b] = 0;
			}
			else if (national[a] < national[b]) {
				national[a] -= national[b];
				national[b] = a;
			}
			else if (national[a] > national[b]) {
				national[b] -= national[a];
				national[a] = b;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		//printf("%d ", national[i]);
		if (national[i] < 0) {
			number++;
			result.push_back(national[i] * (-1));
		}
	}
	//printf("\n");
	sort(result.begin(), result.end());

	printf("%d\n", number);
	for (int i = 0; i < result.size(); i++) {
		printf("%lld ", result[i]);
	}
}

long long find(int n) {
	if (national[n] < 0) return n;
	national[n] = find(national[n]);
	return national[n];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	national[a] += national[b];
	national[b] = a;
}