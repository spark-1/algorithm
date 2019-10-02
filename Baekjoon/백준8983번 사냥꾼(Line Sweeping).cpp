#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Animal {
	int x, y;
};

int compare_aniaml(Animal a, Animal b) {
	if (a.x == b.x) {
		return a.y < b.y;
	}
	else {
		return a.x < b.x;
	}
}

int main() {

	int M, N, L, *gun, a, b, result = 0;
	vector<Animal> animal;
	scanf("%d %d %d", &M, &N, &L);

	gun = new int[M];

	for (int i = 0; i < M; i++) {
		cin >> gun[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		Animal temp;
		temp.x = a;
		temp.y = b;
		animal.push_back(temp);
	}

	sort(gun, gun + M);
	sort(animal.begin(), animal.end(), compare_aniaml);

	/*
	for (int i = 0; i < M; i++) {
		cout << gun[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << animal[i].x << " " << animal[i].y << endl;
	}
	cout << endl;
	*/

	int animal_line = 0;
	int gun_line = 1;
	while (1) {
		if (animal_line == N) {
			break;
		}
		while (1) {
			if (animal[animal_line].x < gun[gun_line]) {
				break;
			}
			else {
				gun_line++;
				if (gun_line == M) {
					gun_line--;
					break;
				}
			}
		}
		if (M == 1) {
			gun_line = 0;
		}
		else if (gun_line == 0) {
			gun_line++;
		}
		if (M > 1) {
			if ((abs(gun[gun_line] - animal[animal_line].x) + animal[animal_line].y <= L) || (abs(gun[gun_line - 1] - animal[animal_line].x) + animal[animal_line].y <= L)) {
				result++;
			}
		}
		else if (abs(gun[gun_line] - animal[animal_line].x) + animal[animal_line].y <= L) {
			result++;
		}
		animal_line++;
	}
	printf("%d\n", result);
}

/* koosaga ÄÚµå parametric search
#include <cstdio>
#include <algorithm>
#define AVG (s+e)/2

int search(int a[], int v, int err, int s, int e) {
	if (a[AVG] <= v + err && a[AVG] >= v - err) return 1;
	if (s == e) return 0;
	if (a[AVG]>v + err) return search(a, v, err, s, AVG);
	if (a[AVG]<v - err) return search(a, v, err, AVG + 1, e);
}

int main() {
	int m, n, l;
	scanf("%d %d %d", &m, &n, &l);
	int *a, x, y, r = 0;
	a = new int[m];
	for (int i = 0; i<m; i++) {
		scanf("%d", &a[i]);
	}
	std::sort(a, a + m);
	for (int i = 0; i<n; i++) {
		scanf("%d %d", &x, &y);
		if (search(a, x, l - y, 0, m - 1)) r++;
	}
	printf("%d", r);
}*/