#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	string word;
	string result;

	cin >> word;

	for (int i = 1; i < word.size() - 1; i++) {
		for (int j = i + 1; j < word.size(); j++) {
			string temp(word);
			reverse(temp.begin(), temp.begin() + i);
			reverse(temp.begin() + i, temp.begin() + j);
			reverse(temp.begin() + j, temp.end());
			if (i == 1 && j == 2) {
				result.replace(0, result.size(), temp);
			}
			if (temp.compare(result) < 0) {
				result.replace(0, result.size(), temp);
			}
		}
	}

	printf("%s\n", result.c_str());
}