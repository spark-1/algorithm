#include <iostream>

int main() {

	int num, result = 0;

	scanf("%d", &num);
	result += num / 5;
	result += num / 25;
	result += num / 125;
	
	printf("%d\n", result);
}