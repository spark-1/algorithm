#include <iostream>

int main() {
	int length, result = 0;;
	char name[1000] = {};

	scanf("%d", &length);
	scanf("%s", &name);
	
	for (int i = 0; i < length; i++) {
		result += name[i] - 'A' + 1;
	}
	
	printf("%d\n", result);
}