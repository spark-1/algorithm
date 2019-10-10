#include <iostream>


int main() {

	char str[10] = { 0 };
	int i = 0, num = 0;

	scanf("%s", str);

	
	while (str[i]) {
		num *= 16;
		if (str[i] >= 'A') {
			num += str[i] - 'A' + 10;
		}
		else {
			num += str[i] - '0';
		}
		i++;
	}

	printf("%d\n", num);
}