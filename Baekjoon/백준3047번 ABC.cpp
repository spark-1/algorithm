#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	int num[3];
	int a, b, c;
	char ch;

	for (int i = 0; i < 3; i++) {
		scanf("%d", &num[i]);
	}
	
	sort(num, num + 3);
	for (int i = 0; i < 3; i++) {
		cin >> ch;
		if (ch == 'A') {
			printf("%d", num[0]);
		}
		if (ch == 'B') {
			printf("%d", num[1]);
		}
		if (ch == 'C') {
			printf("%d", num[2]);
		}
		if (i != 2) {
			printf(" ");
		}
	}

}