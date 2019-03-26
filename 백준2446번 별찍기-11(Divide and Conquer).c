#include <stdio.h>

char arr[3072][6144];

int printSierpinskiTriangle(int n, int middle, int height);

int main() {

	int n = 0;

	scanf("%d", &n);

	printSierpinskiTriangle(n, n, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n * 2); j++) {
			if (arr[i][j] == '*')
				printf("%c", arr[i][j]);
			else
				printf("%c", ' ');
		}
		printf("\n");
	}
}

int printSierpinskiTriangle(int n, int middle, int height) {

	int i = 0;

	if (n == 3) {
		arr[height++][middle - 1] = '*';
		arr[height][middle - 2] = '*';
		arr[height++][middle] = '*';
		arr[height][middle - 3] = '*';
		arr[height][middle - 2] = '*';
		arr[height][middle - 1] = '*';
		arr[height][middle] = '*';
		arr[height][middle + 1] = '*';
		return 0;
	}

	printSierpinskiTriangle(n / 2, middle, height);
	printSierpinskiTriangle(n / 2, middle - n / 2, height + n / 2);
	printSierpinskiTriangle(n / 2, middle + n / 2, height + n / 2);

}