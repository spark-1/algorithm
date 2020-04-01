#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int price[3];
	int weight[3];
	double cost_ratio[3] = { 0 };

	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &price[i], &weight[i]);
	}

	for (int i = 0; i < 3; i++) {
		cost_ratio[i] = 10 * weight[i];
		if (price[i] * 10 >= 5000) {
			cost_ratio[i] /= (10 * price[i]) - 500;
		}
		else {
			cost_ratio[i] /= 10 * price[i];
		}
	}

	if (cost_ratio[0] > cost_ratio[1] && cost_ratio[0] > cost_ratio[2]) {
		printf("S\n");
	}
	else if (cost_ratio[1] > cost_ratio[2]) {
		printf("N\n");
	}
	else {
		printf("U\n");
	}
}