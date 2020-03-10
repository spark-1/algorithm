#include <iostream>

int main() {

	char str[1000];
	int T, A, B;

	scanf("%s", str);
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &A, &B);
		char temp = str[A];
		str[A] = str[B];
		str[B] = temp;
	}

	printf("%s\n", str);
}