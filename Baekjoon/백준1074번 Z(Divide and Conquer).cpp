#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int Z(int N, int count, int x, int y, int r, int c);

int main() {

	int N(0), r(0), c(0);

	scanf("%d %d %d", &N, &r, &c);

	printf("%d\n", Z(N, 0, 0, 0, r, c));
}

int Z(int N, int count, int x, int y, int r, int c) {

	if (N == 1) {
		if (y == r && x == c)
			return count;
		else if(y == r && x + 1 == c)
			return count + 1;
		else if (y + 1 == r && x == c)
			return count + 2;
		else
			return count + 3;
	}

	else {
		if ((c >= x && c < x + pow(2, N - 1)) && (r >= y && r < y + pow(2, N - 1))) // 왼쪽 위
			Z(N - 1, count, x, y, r, c);
		else if ((c >= x + pow(2, N - 1) && c < x + 2 * pow(2, N - 1)) && (r >= y && r < y + pow(2, N - 1))) // 오른쪽 위
			Z(N - 1, count + pow(4, N - 1), x + pow(2, N - 1), y, r, c);
		else if ((c >= x && c < x + pow(2, N - 1)) && (r >= y + pow(2, N - 1) && r < y + 2 * pow(2, N - 1))) // 왼쪽 아래
			Z(N - 1, count + pow(4, N - 1) * 2, x, y + pow(2, N - 1), r, c);
		else // 오른쪽 아래
			Z(N - 1, count + pow(4, N - 1) * 3, x + pow(2, N - 1), y + pow(2, N - 1), r, c);
	}
}