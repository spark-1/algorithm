#include <iostream> // 부분집합의 합
#include <vector>
using namespace std;

int sum(vector<int> &element, int N, int S);
int dfs(vector<int> element, int N, int S, int num, int sum, int include, int elementNum);

int main() {

	int N(0), S(0);
	int e(0), num(0);
	vector<int> element;

	scanf("%d %d", &N, &S);

	for (int i = 0; i < N; i++) {
		scanf("%d", &e);
		element.push_back(e);
	}

	printf("%d\n", sum(element, N, S));
}

int sum(vector<int> &element, int N, int S) {
	return dfs(element, N, S, 0, 0, 1, 0) + dfs(element, N, S, 0, 0, 0, 0);
}

int dfs(vector<int> element, int N, int S, int num, int sum, int include, int elementNum) {

	if (include == 1) {
		sum += element[num];
		elementNum++;
	}

	if (num == N - 1) {
		if (sum == S && elementNum != 0)
			return 1;
		else
			return 0;
	}
	
	return dfs(element, N, S, num + 1, sum, 1, elementNum) + dfs(element, N, S, num + 1, sum, 0, elementNum);
}