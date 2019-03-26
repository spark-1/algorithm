#include <cstdio>

int main() {

	int N(0);
	int i(0);
	int num(0);
	int generator(0); // »ı¼ºÀÚ

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		num = i;
		generator += num;
		while (1) {
			generator += num % 10;
			num /= 10;
			if (num == 0)
				break;
		}
		if (generator == N)
			break;
		else if (i == N - 1) {
			i = 0;
			break;
		}
		else
			generator = 0;
		
	}
	printf("%d\n", i);
}