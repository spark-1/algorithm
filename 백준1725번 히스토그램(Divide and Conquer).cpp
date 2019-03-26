#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int histogram(vector<int> &height, int start, int end);

// 분할 정복으로 히스토그램문제 해결하기
int main() {

	int N(0); // 칸 수
	vector<int> height;
	scanf("%d", &N);
	height = vector<int>(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &height[i]);
	printf("%d\n", histogram(height, 0, N));
}

int histogram(vector<int> &height, int start, int end) {

	if (start == end) // base case 넓이 0 
		return 0;
	if (start + 1 == end) // base case 막대 하나크기
		return height[start];

	int mid = (start + end) / 2;
	int result = max(histogram(height, start, mid), histogram(height, mid, end)); // 각 양쪽 구간검사해서 최댓값
															
	int width = 1, maxHeight = height[mid], left = mid, right = mid;

	while (right - left + 1 < end - start) {

		int leftMax = left > start ? min(maxHeight, height[left - 1]) : -1; // 왼쪽으로 확장했을 경우의 높이
		int rightMax = right < end - 1 ? min(maxHeight, height[right + 1]) : -1; // 오른쪽으로 확장했을 경우의 높이
												
		if (leftMax >= rightMax) { // 더 높은 높이를 가진 쪽으로 확장
			maxHeight = leftMax;
			left--;
		}
		else {
			maxHeight = rightMax;
			right++;
		}
		width++;
		result = max(result, width * maxHeight); // 최댓값 갱신
	}

	return result;
}