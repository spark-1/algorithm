#include <iostream>

int main() {

	int N, S;
	char *str;
	int result = 0, count = 0, flag = 0;

	scanf("%d %d", &N, &S);
	str = new char[S];

	scanf("%s", str);

	for (int i = 0; i < S; i++) {
		char c = str[i];
		if (c == 'I' && flag == 0) {
			flag = 1;
			continue;
		}
		if (c == 'I' && flag == 2) {
			flag = 1;
			count++;
			continue;
		}
		if (c == 'O' && flag == 1) {
			flag = 2;
			continue;
		}
		else {
			if (N <= count) {
				result += count - N + 1;
			}
			if (c == 'I') flag = 1;
			else flag = 0; 
			count = 0;
		}
	}
	if (N <= count) {
		result += count - N + 1;
	}

	printf("%d\n", result);
}