#include <iostream>

int main() {

	int test(1);
	int L(0), P(0), V(0);
	int result(0);

	while (1) {
		scanf("%d %d %d", &L, &P, &V);
		if (L == 0 && P == 0 && V == 0) {
			break;
		}
		else {
			if((V % P) < L)
				result = ((V / P) * L) + (V % P);
			else
				result = ((V / P) * L) + L;
			printf("Case %d: %d\n", test, result);
			test++;
		}
	}

}