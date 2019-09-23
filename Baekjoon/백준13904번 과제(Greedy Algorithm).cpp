#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b);

int main() {

	int N, d, w, max_day = 0, max_score = 0;
	vector<bool> possible_day;
	vector<pair<int, int>> homework;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &d, &w);
		homework.push_back(make_pair(d, w));
		if (d > max_day) {
			max_day = d;
		}
	}

	possible_day = vector<bool>(max_day, true);

	sort(homework.begin(), homework.end(), compare);

	for (int i = 0; i < N; i++) {
		for (int j = homework[i].first - 1; j >= 0; j--) {
			if (possible_day[j] == true) {
				possible_day[j] = false;
				max_score += homework[i].second;
				break;
			}
		}
	}

	printf("%d\n", max_score);
}

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) { // 점수가 같을 때는 기간이 짧은거 부터 먼저
		return a.first < b.first;
	}
	else { // 점수 내림차순 
		return a.second > b.second;
	}
}