#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxScore(vector< vector<int> > &sticker, int n);

int main() {

	int T(0), n(0), score;
	vector< vector<int> > sticker(2);

	cin >> T;

	for (int i = 0; i < T; i++) { // 점수 배열 입력
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> score;
			sticker[0].push_back(score);
		}
		for (int j = 0; j < n; j++) {
			cin >> score;
			sticker[1].push_back(score);
		}

		printf("%d\n", maxScore(sticker, n)); // 최댓값 출력
		sticker = vector< vector<int> >(2); // 점수 배열 초기화
	}

}

int maxScore(vector< vector<int> > &sticker, int n) {

	vector< vector<int> > dp(n + 1, vector<int>(3, 0)); // dp의 두번째
	
	for (int i = 0; i < n; i++) { // 스티커는 0열부터 시작한다고 가정, dp는 1열부터 시작한다고 가정
		dp[i + 1][0] = max(dp[i][0], max(dp[i][1], dp[i][2])); // i열 스티커를 둘다 떼지 않았을때 
		dp[i + 1][1] = max(dp[i][0], dp[i][2]) + sticker[0][i]; // i열 스티커를 위 스티커를 떼었을때
		dp[i + 1][2] = max(dp[i][0], dp[i][1]) + sticker[1][i]; // i열 스티커를 아래 스티커를 떼었을때
	}

	return max(dp[n][0], max(dp[n][1], dp[n][2]));
}