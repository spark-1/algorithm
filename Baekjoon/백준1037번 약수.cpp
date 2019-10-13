#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

int main() {

	long long N, *num, result;

	cin >> N;

	num = new long long[N];

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	
	sort(num, num + N);

	result = num[0];
	for (int i = 0; i < N - 1; i++) {
		result = lcm(num[i], num[i + 1]);
	}

	if (result == num[N - 1]) {
		result *= num[0];
	}

	cout << result << endl;
}