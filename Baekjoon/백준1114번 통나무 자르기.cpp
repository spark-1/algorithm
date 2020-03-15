#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, K, C, p, first_cut_point, cnt;
int r, cut, flag;
vector<int> point;
int sol(int m);

int main() {

	int s, e;

	scanf("%d %d %d", &L, &K, &C);

	for (int i = 0; i < K; i++) {
		scanf("%d", &p);
		point.push_back(p);
	}
	point.push_back(0); // sol 함수 편의상 0 추가
	point.push_back(L);
	sort(point.begin(), point.end());

	s = 1; e = L;
	while (s != e) {
		//printf("s = %d, e = %d\n", s, e);
		int m = (s + e) / 2;
		if (sol(m)) {
			e = m;
		}
		else {
			s = m + 1;
		}
	}

	if (cnt == C) {
		first_cut_point = r;
	}
	else {
		first_cut_point = point[1];
	}
	
	printf("%d %d\n", s, first_cut_point);
}

int sol(int m) {

	flag = 0;
	cnt = 0;
	cut = L;
	r = L;

	for (int i = K; i >= 0; i--) {
		cut = point[i];
		if (point[i + 1] - point[i] > m) { // 한 단위가 최대 기준 m보다 크면 조기 종료
			flag = -1;
		}
		if (r - cut > m) {
			r = point[i + 1];
			cnt++;
		}
	}

	//printf("m = %d, cnt = %d, flag = %d\n", m, cnt, flag);
	if (cnt > C || flag == -1) {
		return 0;
	}
	else {
		return 1;
	}
}