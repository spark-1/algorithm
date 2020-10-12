#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int L, C, n, m, p; // 모음 자음
vector<char> alpha;
string pw;

void dfs(int curr, int index) {
	if (curr == L) {
		if (m > 0 && p > 1) {
			cout << pw << endl;
		}
		return;
	}

	if (n - index >= L - curr) {
		for (int i = index; i < n; i++) {
			pw.push_back(alpha[i]);
			if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u') {
				m++;
			}
			else p++;
			dfs(curr + 1, i + 1);
			pw.pop_back();
			if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u') {
				m--;
			}
			else p--;
		}
	}
	return;
}

int main() {
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++) {
		char a;
		getchar();
		scanf("%c", &a);
		alpha.push_back(a);
	}

	n = alpha.size();
	sort(alpha.begin(), alpha.end());

	dfs(0, 0);
}