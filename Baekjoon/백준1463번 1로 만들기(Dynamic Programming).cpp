#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b, int c);
int min(int a, int b);

int main() {

	vector<int> count;
	int N(0);

	cin >> N;

	count.push_back(0);

	count.push_back(0);
	for (int i = 2; i <= N; i++) {
		if (i % 2 == 0 && i % 3 == 0) {
			count.push_back(min(count[i / 2], count[i / 3], count[i - 1]) + 1);
		}
		else if (i % 2 == 0) {
			count.push_back(min(count[i / 2], count[i - 1]) + 1);
		}
		else if (i % 3 == 0) {
			count.push_back(min(count[i / 3], count[i - 1]) + 1);
		}
		else {
			count.push_back(count[i - 1] + 1);
		}
	}

	cout << count[N] << endl;
}

int min(int a, int b, int c) {
	if (a <= b && a <= c)
		return a;
	else
		return min(a, b);
}

int min(int a, int b) {
	if (a <= b)
		return a;
	else
		return b;
}