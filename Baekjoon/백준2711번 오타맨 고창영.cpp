#include <iostream>
#include <string>
using namespace std;

int main() {

	int T, mistake;
	string str;
	
	cin >> T;

	for (int i = 0; i < T; i++) {
		scanf("%d", &mistake);
		cin >> str;
		str.erase(mistake - 1, 1);
		cout << str << endl;
	}
	
}