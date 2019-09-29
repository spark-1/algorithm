#include <iostream>

int main() {

	int x, y, w, h, min = 1000;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	if (w - x < x) {
		min = w - x;
	}
	else {
		min = x;
	}
	if (h - y < y) {
		if (h - y < min) {
			min = h - y;
		}
	}
	else {
		if (y < min) {
			min = y;
		}
	}
	printf("%d\n", min);
}