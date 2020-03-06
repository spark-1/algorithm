#include <iostream>
#include <vector>
using namespace std;

int main() {

	long long N, M, money, lowest = 1, highest = 1000000000L;
	long long count, i, least_amount;
	vector<int> withdrawal;

	scanf("%lld %lld", &N, &M);

	for (i = 0; i < N; i++) {
		scanf("%lld", &money);
		if (money >= lowest) {
			lowest = money;
		}
		withdrawal.push_back(money);
	}

	while (1) {
		if (lowest == highest) {
			break;
		}
		count = 1;
		least_amount = (highest + lowest) / 2;
		money = least_amount;
		for (i = 0; i < N; i++) {
			money -= withdrawal[i];
			if (money < 0) {
				count++;
				money = least_amount - withdrawal[i];
			}
		}
		if (count > M) {
			if (lowest + 1 == highest) {
				lowest = highest;
			}
			else {
				lowest = least_amount;
			}
		}
		else {
			highest = least_amount;
		}
		//printf("%d %d\n", lowest, highest);
	}

	printf("%lld\n", lowest);
}