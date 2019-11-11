#include <string>
#include <vector>

using namespace std;
int link[10][10] = { 0 }; // ¹ê¿¡¼­ À¯Àú
int answer = 0;
int visited[10] = { 0 };
vector<int> a;

int find(int ban, int u_size, int b_size) {

	if (ban == b_size) {
		int num = 0;
		int tmp = 1;
		int flag = 1;
		for (int i = 0; i < 10; i++) {
			if (visited[i] == 1) {
				num += tmp;
			}
			tmp *= 2;
			//printf("%d ", visited[i]);
		}
		printf("%d ", num);

		for (int i = 0; i < a.size(); i++) {
			if (a[i] == num) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			a.push_back(num);
			answer++;
		}
		return 0;
	}

	for (int i = 0; i < u_size; i++) {
		if (link[ban][i] == 1 && visited[i] == 0) {
			visited[i] = 1;
			find(ban + 1, u_size, b_size);
			visited[i] = 0;
		}
	}
	return 0;
}

int solution(vector<string> user_id, vector<string> banned_id) {

	for (int i = 0; i < banned_id.size(); i++) {
		for (int j = 0; j < user_id.size(); j++) {
			int flag = 1;
			if (banned_id[i].length() != user_id[j].length()) {
				continue;
			}
			for (int s = 0; s < banned_id.size(); s++) {
				if ((banned_id[i][s] != user_id[j][s]) && banned_id[i][s] != '*') {
					flag = 0;
					break;
				}
			}
			if (flag == 1) {
				link[i][j] = 1;
			}
		}
	}

	find(0, user_id.size(), banned_id.size());

	return answer;
}