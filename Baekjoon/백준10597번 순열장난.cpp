#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
string num;
vector<int> result;
vector<bool> check;

int success() {
	int flag = 1;
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			flag = 0;
			break;
		}
	}
	return flag;
}

void dfs(int cnt, int length) {

	if (cnt == n || length == num.size()) {
		if (success()) {
			for (int i = 0; i < n; i++) {
				printf("%d ", result[i]);
			}
			exit(0);
		}
		else {
			return;
		}
	}

	int t;
	string temp;
	temp.push_back(num[length]);
	t = stoi(temp);
	if (t == 0) {
		return;
	}
	if (!check[t]) {
		check[t] = true;
		result.push_back(t);
		//printf("%d확인\n", t);
		dfs(cnt + 1, length + 1);
		//printf("%d제외\n", t);
		check[t] = false;
		result.pop_back();
	}

	if (length + 1 < num.size()) {
		temp.push_back(num[length + 1]);
		t = stoi(temp);
		if (t <= n) {
			if (check[t]) {
				return;
			}
			check[t] = true;
			result.push_back(t);
			//printf("%d확인\n", t);
			dfs(cnt + 1, length + 2);
			//printf("%d제외\n", t);
			check[t] = false;
			result.pop_back();
		}
	}
}

int main() {

	cin >> num;

	if (num.size() < 10) {
		n = num.size();
		check.resize(n + 1, 0);
	}
	else {
		n = (num.size() - 9) / 2 + 9;
		check.resize(n + 1, 0);
	}
	
	dfs(0, 0);
}