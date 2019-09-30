#include <cstdio>

int main() {
	int H, M;
	scanf("%d %d", &H, &M);
	M += 60;
	H -= 1;
	M -= 45;
	H += M / 60;
	H += 24;
	M %= 60;
	H %= 24;
	printf("%d %d\n", H, M);
}