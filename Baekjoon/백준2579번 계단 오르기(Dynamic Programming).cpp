#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	vector<int> stair;
	vector< vector<int> >dp; // 첫번째 인덱스 0:한칸전에서 올라온 경우, 1:두칸전에서 올라온경우
							// 두번째 인덱스 계단위치
	cin >> N;

	stair = vector<int>(N + 1, 0);
	dp = vector< vector<int> >(2, vector<int>(N + 1, 0));

	for (int i = 1; i < N + 1; i++) {
		scanf("%d", &stair[i]);
	}

	dp[0][1] = stair[1];
	dp[1][1] = stair[1];
	
	for (int i = 2; i < N + 1; i++) {
		dp[0][i] = dp[1][i - 1] + stair[i];
		dp[1][i] = max(dp[0][i - 2], dp[1][i - 2]) + stair[i];
	}

	cout << max(dp[0][N], dp[1][N]) << endl;
}