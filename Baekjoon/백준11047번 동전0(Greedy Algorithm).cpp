#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N(0), K(0);
	vector<int> price;
	int priceNum(0);
	int need(0);

	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &priceNum);
		price.push_back(priceNum);
	}

	N--;
	while (N >= 0) {
		if (K / price[N] == 0) {
			N--;
		}
		else {
			need += K / price[N];
			K = K % price[N];
			N--;
		}
	}

	printf("%d\n", need);
}