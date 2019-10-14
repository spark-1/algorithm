#include <iostream>

int main() {

	char num[10];
	int i = 0, result = 0, count = 0;

	while (1) {
		scanf("%s", num);
		if (num[0] == '0') {
			break;
		}

		result = 0;
		i = 0;
		count = 0;
		while (num[i]) {
			count++;
			i++;
		}
		i = 0;
		while (num[i]) {
			int temp = 1;
			for (int i = 1; i <= count; i++)
				temp *= i;
			result += (num[i] - '0') * temp;
			i++;
			count--;
		}

		printf("%d\n", result);
	}

}