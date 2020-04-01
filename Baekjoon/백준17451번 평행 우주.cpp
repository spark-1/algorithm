#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;
	vector<long long> speed;
	long long result = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		long long s;
		scanf("%lld", &s);
		speed.push_back(s);
	}

	result = speed[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (speed[i] >= result) {
			result = speed[i];
		}
		else {
			if (result % speed[i] == 0) {
				continue;
			}
			else {
				long long a;
				a = (speed[i] + result) / speed[i];
				result = speed[i] * a;
			}
		}
	}

	printf("%lld\n", result);
}