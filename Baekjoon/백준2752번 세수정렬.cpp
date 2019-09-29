#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int num[3];
	scanf("%d %d %d", &num[0], &num[1], &num[2]);
	sort(num, num + 3);
	printf("%d %d %d\n", num[0], num[1], num[2]);
}