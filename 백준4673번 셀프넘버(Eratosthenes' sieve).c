#include <stdio.h>

int main() {

	int i = 0;
	int constructor = 0;
	int selfNumber[10100] = { 0 };
	
	for (i = 0; i < 10001; i++)
		selfNumber[i] = i;

	for (i = 0; i < 10001; i++) {
		constructor = i + (i % 10) + (i / 10) % 10 + (i / 100) % 10 + (i / 1000) % 10 + i / 10000;
		selfNumber[constructor] = 0;
	}

	for (i = 0; i < 10001; i++) {
		if (selfNumber[i] != 0)
			printf("%d\n", selfNumber[i]);
	}
}