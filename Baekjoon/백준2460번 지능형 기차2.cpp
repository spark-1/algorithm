#include <iostream>

int main() {

	int max = 0, num = 0, in, out;

	for (int i = 0; i < 10; i++) {
		scanf("%d %d", &out, &in);
		num += in - out;
		if (max < num) max = num;
	}

	printf("%d\n", max);
}
