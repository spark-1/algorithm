#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Move {
	char from;
	char to;
};

void countS(int n);
int hanoi_recursion(int n, char left, char middle, char right);
void hanoi_recursion_print(int n, char left, char middle, char right);
int count_recursion = 0;
vector<Move> process;

int main() {

	int N = 0;
	
	char left = 1;
	char middle = 2;
	char right = 3;

	scanf("%d", &N);

	if (N > 20) {
		countS(N);
	}
	else {
		printf("%d\n", hanoi_recursion(N, left, middle, right));
		hanoi_recursion_print(N, left, middle, right);
	}
	
}

int hanoi_recursion(int n, char left, char middle, char right) {

	if (n == 1) {
		Move temp;
		temp.from = left;
		temp.to = right;
		process.push_back(temp);
		count_recursion++;
		return 0;
	}

	hanoi_recursion(n - 1, left, right, middle);
	hanoi_recursion(1, left, middle, right);
	hanoi_recursion(n - 1, middle, left, right);

	return count_recursion;
}

void hanoi_recursion_print(int n, char left, char middle, char right) {

	if (n == 1) {
		printf("%d %d\n", left, right);
		return;
	}

	hanoi_recursion_print(n - 1, left, right, middle);
	hanoi_recursion_print(1, left, middle, right);
	hanoi_recursion_print(n - 1, middle, left, right);

}

void countS(int n) {
	long long a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		b *= 2;
		a = a * 2 + 1;
		b += a / 1000000000000000000;
		a %= 1000000000000000000;
	}
	if (b == 0) {
		printf("%lld\n", a);
	}
	else {
		printf("%lld%lld\n", b, a);
	}
}