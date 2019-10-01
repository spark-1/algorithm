#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
	if (b > a) {
		return gcd(b, a);
	}
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}

int main() {

	long long n, a, b;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		cout << a * b / gcd(a, b) << endl;
	}
}