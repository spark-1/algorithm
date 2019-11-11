#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
	int answer = 0;
	int num = 0, max = 0, mid = 0, l = 0, r = 0, t = 0;

	vector<int> temp;
	vector<int> min_num = stones;
	sort(min_num.begin(), min_num.end());
	min_num.erase(unique(min_num.begin(), min_num.end()), min_num.end());

	r = min_num.size();

	while (1) {

		t = 0;
		max = 0;
		temp = stones;
		mid = (l + r) / 2;

		for (int i = 0; i < temp.size(); i++) {
			temp[i] = temp[i] - min_num[mid];
		}

		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] <= 0) {
				t++;
				if (max < t) {
					max = t;
				}
			}
			else {
				t = 0;
			}
		}
		if (max >= k) {
			r = mid;
		}
		else {
			l = mid;
		}
		if (l + 1 == r || l == r) {
			max = 0;
			t = 0;
			if (l == 0) {
				temp = stones;
				for (int i = 0; i < temp.size(); i++) {
					temp[i] = temp[i] - min_num[0];
				}

				for (int i = 0; i < temp.size(); i++) {
					if (temp[i] <= 0) {
						t++;
						if (max < t) {
							max = t;
						}
					}
					else {
						t = 0;
					}
				}
				if (max >= k) {
					answer = min_num[l];
				}
				else {
					answer = min_num[r];
				}
			}
			else {
				answer = min_num[r];
			}
			break;
		}
	}

	return answer;
}