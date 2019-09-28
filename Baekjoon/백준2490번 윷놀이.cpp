#include <iostream>

int main() {

	int result = 0, num;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &num);
			result += num;
		}
		if (result == 0) printf("D\n");
		else if (result == 4) printf("E\n");
		else printf("%c\n", 'D' - result);
		result = 0;
	}
}