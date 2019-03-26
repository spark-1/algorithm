#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int N, check(1);
	vector<int> weight;
	cin >> N;

	weight = vector<int>(N);

	for (int i = 0; i < N; i++) {
		cin >> weight[i];
	}

	sort(weight.begin(), weight.end());

	for (int i = 0; i < N; i++) {
		if (weight[i] > check) {
			break;
		}
		else {
			check += weight[i];
		}
	}
	
	cout << check << endl;
}