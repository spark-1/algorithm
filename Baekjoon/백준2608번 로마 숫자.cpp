#include <iostream>
#include <string>
#include <utility>

using namespace std;

pair<string, int> rome[7] = { make_pair("I", 1), make_pair("V", 5), make_pair("X", 10), make_pair("L", 50), make_pair("C", 100), make_pair("D", 500), make_pair("M", 1000) };
pair<string, int> p[6] = { make_pair("IV", 4), make_pair("IX", 9), make_pair("XL", 40), make_pair("XC", 90), make_pair("CD", 400), make_pair("CM", 900) };
pair<string, int> rome2[13] = { make_pair("I", 1), make_pair("IV", 4), make_pair("V", 5),  make_pair("IX", 9), make_pair("X", 10), make_pair("XL", 40), make_pair("L", 50), make_pair("XC", 90), make_pair("C", 100), make_pair("CD", 400), make_pair("D", 500), make_pair("CM", 900), make_pair("M", 1000) };

int read(string s) {
	int num = 0;
	for (int i = 0; i < s.size();) {
		for (int j = 0; j < 6 && i < s.size(); j++) {
			if (s.substr(i, 2).compare(p[j].first) == 0) {
				num += p[j].second;
				i += 2;
				j = -1;
			}
		}
		for (int j = 0; j < 7 && i < s.size(); j++) {
			if (s.substr(i, 1).compare(rome[j].first) == 0) {
				num += rome[j].second;
				i++;
				//cout << num << endl;
				break;
			}
		}
	}
	return num;
}

string write(int num) {
	string s = "";
	for (int i = 12; i >= 0; i--) {
		if (num / rome2[i].second > 0) {
			s += rome2[i].first;
			num -= rome2[i].second;
			i = 13;
			//cout << num << endl;
		}
	}
	return s;
}

int main() {

	string a = "", b = "";
	int result;
	
	cin >> a >> b;

	result = read(a) + read(b); // CDXLIV 444
	
	cout << result << endl;
	if (result == 4000) {
		cout << "MMMCMC" << endl;
	}
	else {
		cout << write(result) << endl;
	}
}