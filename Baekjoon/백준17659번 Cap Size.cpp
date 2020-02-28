#include <iostream>
using namespace std;

int main() {

	int K, t, n, s[102] = {};
	int c, f; // f -> -1:큼, 0:맞음, 1:작음
	int upper_limit, lower_limit, adequate, flag;

	scanf("%d", &K);

	for (int k = 0; k < K; k++) {
		upper_limit = 1001;
		lower_limit = -1;
		adequate = -1;
		flag = 1; // 가능 여부

		scanf("%d %d", &n, &t);
		for (int i = 0; i < n; i++) {
			scanf("%d", &s[i]);
		}
		for (int i = 0; i < t; i++) {
			scanf("%d %d", &c, &f);
			if (f == -1) {
				if (upper_limit > c) {
					upper_limit = c;
				}
			}
			if (f == 0) {
				if (adequate == -1) {
					adequate = c;
				}
				else {
					if (adequate != c) {
						flag = -1;
					}
				}
			}
			if (f == 1) {
				if (lower_limit < c) {
					lower_limit = c;
				}
			}
		}

		if (upper_limit <= lower_limit) {
			flag = -1;
		}
		if (adequate != -1 && adequate > upper_limit) {
			flag = -1;
		}
		if (adequate != -1 && adequate < lower_limit) {
			flag = -1;
		}

		printf("Data Set %d:\n", k + 1);
		if (flag == -1) {
			printf("Inconsistent feedback\n");
		}
		else {
			int count = 0;
			// printf("하한선 : %d, 상한선 %d\n", lower_limit, upper_limit);
			if (adequate != -1) {
				printf("%d\n", 1);
			}
			else {
				for (int i = 0; i < n; i++) {
					if (s[i] > lower_limit && s[i] < upper_limit) {
						count++;
					}
					if (s[i] >= upper_limit) {
						break;
					}
				}
				printf("%d\n", count);
			}
		}
		printf("\n");
	}
}