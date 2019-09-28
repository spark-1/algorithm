#include <iostream>

int main() {

	int validation_num = 0, num;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &num);
		validation_num += (num * num) % 10;
	}
	validation_num %= 10;

	printf("%d\n", validation_num);
}