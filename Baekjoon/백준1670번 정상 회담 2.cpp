#include <iostream>
using namespace std;

long long dp[10001];

int main() {

	int N; 

	scanf("%d", &N);
	
	dp[0] = 1;
	dp[2] = 1;
	for (int i = 4; i <= N; i += 2) {
		for (int j = 0; j < i; j += 2) {
			dp[i] += (dp[i - (j + 2)] * dp[j]) % 987654321;
		}
		dp[i] %= 987654321;
	}

	printf("%lld\n", dp[N]);
}