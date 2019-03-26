#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long segmentalArr(vector<long long> &width, int start, int end);

// 분할 정복으로 부분배열 고르기
int main() {

	int N(0); // 배열의 수
	vector<long long> width;
	scanf("%d", &N);
	width = vector<long long>(N);
	for (int i = 0; i < N; i++)
		scanf("%lld", &width[i]);
	printf("%lld\n", segmentalArr(width, 0, N));
}

long long segmentalArr(vector<long long> &width, int start, int end) {

	if (start == end) // base case 넓이 0 
		return 0;
	if (start + 1 == end) // base case 배열하나
		return width[start] * width[start];

	int mid = (start + end) / 2;
	long long result = max(segmentalArr(width, start, mid), segmentalArr(width, mid, end)); // 각 양쪽 구간검사해서 최댓값

	long long baseLine = width[mid], maxHeight = width[mid], left = mid, right = mid;

	while (right - left + 1 < end - start) {

		long long leftMax = left > start ? min(maxHeight, width[left - 1]) : -1; // 왼쪽으로 확장했을 경우의 높이
		long long rightMax = right < end - 1 ? min(maxHeight, width[right + 1]) : -1; // 오른쪽으로 확장했을 경우의 높이

		if (leftMax >= rightMax) { // 더 높은 높이를 가진 쪽으로 확장
			maxHeight = leftMax;
			left--;
			baseLine += width[left];
		}
		else {
			maxHeight = rightMax;
			right++;
			baseLine += width[right];
		}
		result = max(result, baseLine * maxHeight); // 최댓값 갱신
	}

	return result;
}