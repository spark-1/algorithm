#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n(0);
	vector<long long> dp;
	
	cin >> n;
	dp = vector<long long>(n + 1, 0);

	dp.insert(dp.begin() + 1, 1);
	dp.insert(dp.begin() + 2, 2);
	dp.insert(dp.begin() + 3, 3);
	dp.insert(dp.begin() + 4, 4);
	dp.insert(dp.begin() + 5, 5);
	
	for (int i = 6; i <= n; i++) {
		for (int j = 3; j < i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] * (j - 1));
		}
	}

	cout << dp[n] << endl;
}