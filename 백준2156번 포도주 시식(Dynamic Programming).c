#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, i;
	int dp[10002] = { 0 };
	int wine[10002] = { 0 };
	cin >> n;
	for (i = 0; i<n; i++) cin >> wine[i];
	dp[0] = wine[0];
	dp[1] = wine[1] + wine[0];
	dp[2] = max(dp[1], max(wine[0] + wine[2], wine[1] + wine[2]));
	for (i = 3; i<n; i++) dp[i] = max(dp[i - 1], max(dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i]));
	cout << dp[n - 1];
}