#include <cstdio>
#include <map>

using namespace std;

int main() {

	int num1, num2, result = 0;
	map<int, int> A;
	map<int, int> B;

	scanf("%d %d", &num1, &num2);
	for (int i = 0; i < num1; i++) {
		int a;
		scanf("%d", &a);
		A[a] = a;
	}
	for (int i = 0; i < num2; i++) {
		int b;
		scanf("%d", &b);
		B[b] = b;
	}

	result = A.size() + B.size();

	for (auto i = A.begin(); i != A.end(); i++) {
		if (B.find(i->first) != B.end()) {
			result -= 2;
		}
	}
	printf("%d\n", result);
}