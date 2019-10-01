#include <iostream>
#include <cstring>

char str[21];
char bridge1[101];
char bridge2[101];
int dp[2][21][101];
int flag;

int main() {

	scanf("%s", str);
	scanf("%s %s", bridge1, bridge2);
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= strlen(bridge1); j++) {
			dp[i][0][j] = 1;
		}
	}

	flag = 1;
	for (int i = 1; i <= strlen(str); i++) {
		for (int j = 1; j <= strlen(bridge1); j++) {
			if (flag == 1) {
				if (bridge1[j - 1] != str[i - 1]) {
					dp[0][i][j] = dp[0][i][j - 1];
				}
				else if (bridge1[j - 1] == str[i - 1]) {
					dp[0][i][j] = dp[0][i][j - 1] + dp[0][i - 1][j - 1];
				}
			}
			else {
				if (bridge2[j - 1] != str[i - 1]) {
					dp[0][i][j] = dp[0][i][j - 1];
				}
				else if (bridge2[j - 1] == str[i - 1]) {
					dp[0][i][j] = dp[0][i][j - 1] + dp[0][i - 1][j - 1];
				}
			}
		}
		flag *= -1;
	}
	flag = -1;
	for (int i = 1; i <= strlen(str); i++) {
		for (int j = 1; j <= strlen(bridge1); j++) {
			if (flag == 1) {
				if (bridge1[j - 1] != str[i - 1]) {
					dp[1][i][j] = dp[1][i][j - 1];
				}
				else if (bridge1[j - 1] == str[i - 1]) {
					dp[1][i][j] = dp[1][i][j - 1] + dp[1][i - 1][j - 1];
				
				}
			}
			else {
				if (bridge2[j - 1] != str[i - 1]) {
					dp[1][i][j] = dp[1][i][j - 1];
				}
				else if (bridge2[j - 1] == str[i - 1]) {
					dp[1][i][j] = dp[1][i][j - 1] + dp[1][i - 1][j - 1];
			
				}
			}
		}
		flag *= -1;
	}

	printf("%d\n", dp[0][strlen(str)][strlen(bridge1)] + dp[1][strlen(str)][strlen(bridge1)]);
}