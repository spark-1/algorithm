#include <iostream>

int gcd(int a, int b) {

	if (a < b) 
		gcd(b, a);
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
	
}

int lcm(int a, int b) {

	return a * (b / gcd(a, b));
}

int main() {

	int a, b, x, y, i, j;
	int g, l;

	scanf("%d %d %d %d", &a, &b, &x, &y);

	l = lcm(b, y);
	a *= l / b;
	x *= l / y;

	i = a + x;
	j = l;

	g = gcd(i, j);
	i /= g;
	j /= g;

	printf("%d %d\n", i, j);
}