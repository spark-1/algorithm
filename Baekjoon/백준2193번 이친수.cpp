#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
long long dp[91][2];

long long f(int x, int y) {
	if (x == N) {
		return 1;
	}
	if (~dp[x][y]) {
		return dp[x][y];
	}
	long long ret = 0;

	if (y == 0) {
		ret += f(x + 1, 1);
	}
	ret += f(x + 1, 0);

	dp[x][y] = ret;
	return dp[x][y];
}

int main() {

	scanf("%d", &N);

	memset(dp, -1, sizeof(dp));

	printf("%lld", f(1, 1));
}