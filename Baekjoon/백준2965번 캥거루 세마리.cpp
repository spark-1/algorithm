#include <iostream>

int main() {

	int a, b, c, result, temp;

	scanf("%d %d %d", &a, &b, &c);

	result = (b - a > c - b) ? (b - a) : (c - b);
	printf("%d\n", result - 1);
}