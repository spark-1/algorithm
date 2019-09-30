#include <cstdio>

int main() {

	int year;
	scanf("%d", &year);
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
}