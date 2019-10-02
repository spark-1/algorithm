#include <iostream>
#include <cstring>

bool up;

int main() {

	int result = 10;
	char str[51];
	scanf("%s", str);

	if (str[0] == '(') {
		up = true;
	}
	for (int i = 1; i < strlen(str); i++) {
		if (str[i] == '(') {
			if (up) result += 5;		
			else result += 10;
			up = true;
		}
		else if (str[i] == ')'){
			if (up) result += 10;
			else result += 5;
			up = false;
		}
	}
	printf("%d\n", result);
}