#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

int main() {

	int num, diff = 0, result = 0, minus = 0, add = 0;
	int a[26] = {}, b[26] = {};
	int a_length, b_length;
	string s;

	scanf("%d", &num);

	cin >> s;
	a_length = s.size();
	for (int i = 0; i < a_length; i++) {
		a[s[i] - 'A']++;
	}

	for (int i = 1; i < num; i++) {
		memset(b, 0, sizeof(b));
		diff = 0, add = 0, minus = 0;
		cin >> s;
		b_length = s.size();
		for (int j = 0; j < b_length; j++) {
			b[s[j] - 'A']++;
		}

		if (a_length == b_length) {
			for (int j = 0; j < 26; j++) {
				diff += abs(a[j] - b[j]);
				if (a[j] - b[j] == 1) {
					add++;
				}
				if (a[j] - b[j] == -1) {
					minus++;
				}
			}
			if (diff == 0 || (diff == 2 && add == 1 && minus == 1)) {
				result++;
			}
		}
		else {
			for (int j = 0; j < 26; j++) {
				diff += abs(a[j] - b[j]);
			}
			if (diff <= 1) {
				result++;
			}
		}
	}
	printf("%d\n", result);
}