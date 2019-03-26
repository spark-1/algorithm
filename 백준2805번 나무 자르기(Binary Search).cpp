#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	long long n, m;
	long long max, min, h, tree(0);
	vector<int> height;

	cin >> n >> m;
	height = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}

	sort(height.begin(), height.end());
	min = 0;
	max = height[n - 1];

	while (1) {
		
		h = (max + min) / 2;

		for (int i = n - 1; i >= 0; i--) {
			if (height[i] - h > 0) {
				tree += height[i] - h;
			}
			else
				break;
		}

		if (tree >= m) { // 조건을 만족, 중간 ~ max
			min = h;
		}
		else { // 조건을 불만족, min ~ 중간
			max = h;
		}
		if (min + 1 == max) {
			break;
		}
		tree = 0;
	}
	cout << min << endl;
}