#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {

	int x, y, N, *a, *b, w, h, sum = 0;

	scanf("%d %d %d", &w, &h, &N);
	a = new int[N];
	b = new int[N];

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	scanf("%d %d", &x, &y);
	
	for (int i = 0; i < N; i++) {
		if (x == 1) {
			if (a[i] == 1) {
				sum += abs(b[i] - y);
			}
			else if (a[i] == 2) {
				sum += min(h + b[i] + y, h + 2 * w - b[i] - y);
			}
			else if (a[i] == 3) {
				sum += b[i] + y;
			}
			else if (a[i] == 4) {
				sum += w - y + b[i];
			}
		}
		else if (x == 2) {
			if (a[i] == 1) {
				sum += min(h + b[i] + y, h + 2 * w - b[i] - y);
			}
			else if (a[i] == 2) {
				sum += abs(b[i] - y);
			}
			else if (a[i] == 3) {
				sum += h - b[i] + y;
			}
			else if (a[i] == 4) {
				sum += h - b[i] + w - y;
			}
		}
		else if (x == 3) {
			if (a[i] == 1) {
				sum += b[i] + y;
			}
			else if (a[i] == 2) {
				sum += h - y + b[i];
			}
			else if (a[i] == 3) {
				sum += abs(b[i] - y);
			}
			else if (a[i] == 4) {
				sum += min(w + b[i] + y, w + 2 * h - b[i] - y);
			}
		}
		else if (x == 4) {
			if (a[i] == 1) {
				sum += w - b[i] + y;
			}
			else if (a[i] == 2) {
				sum += h - y + w - b[i];
			}
			else if (a[i] == 3) {
				sum += min(w + b[i] + y, w + 2 * h - b[i] - y);
			}
			else if (a[i] == 4) {
				sum += abs(b[i] - y);
			}
		}
	}

	printf("%d\n", sum);
}