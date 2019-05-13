#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void constructSegmentTree(vector<long long> &segmentTree, vector<long long> arr, long long leafNodeSize);
void updateSegmentTree(vector<long long> &segmentTree, long long leafNodeSize, int arrIndex, long long changedValue);
long long sumArrSection(vector<long long> &segmentTree, int arrLeftIndex, int arrRightIndex, long long nodeLeftIndex, long long nodeRightIndex, long long treeIndex);
void showSegmentTree(vector<long long> &segmentTree, long long leafNodeSize);

int main() {

	int N, M, K, treeHeight, mode, a;
	long long b, leafNodeSize;
	vector<long long> segmentTree;
	vector<long long> arr;

	cin >> N >> M >> K;

	treeHeight = int(log2(N - 1)) + 1;
	leafNodeSize = (long long)(pow(2, treeHeight));
	segmentTree = vector<long long>(leafNodeSize * 2, 0);
	arr = vector<long long>(N, 0);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}

	constructSegmentTree(segmentTree, arr, leafNodeSize); // arr배열 기반으로 구간 합 세그먼트 트리 구성
														  //showSegmentTree(segmentTree, leafNodeSize);

	for (int i = 0; i < M + K; i++) {
		cin >> mode >> a >> b;

		if (mode == 1) { // update 세그먼트 트리
			a -= 1; // 인덱스는 1 차이가 나므로
			updateSegmentTree(segmentTree, leafNodeSize, a, b);
			//showSegmentTree(segmentTree, leafNodeSize);
		}
		else if (mode == 2) { // 세그먼트 트리 특정 구간 합 출력하기
			a -= 1; // 인덱스는 1 차이가 나므로
			b -= 1; // 인덱스는 1 차이가 나므로
			cout << sumArrSection(segmentTree, a, b, 0, leafNodeSize - 1, 1) << endl;
		}
	}

}

void constructSegmentTree(vector<long long> &segmentTree, vector<long long> arr, long long leafNodeSize) {

	for (int i = 0; i < arr.size(); i++) { // 리프노드 구성하기
		segmentTree[leafNodeSize + i] = arr[i];
	}

	for (int i = leafNodeSize - 1; i > 0; i--) { // 나머지 노드 구성하기
		segmentTree[i] = segmentTree[i * 2] + segmentTree[i * 2 + 1];
	}
}

void updateSegmentTree(vector<long long> &segmentTree, long long leafNodeSize, int arrIndex, long long changedValue) {

	long long treeIndex = leafNodeSize + arrIndex;
	segmentTree[treeIndex] = changedValue; // 리프 노드 갱신

	while (treeIndex > 1) { // 낮은 높이에서 부터 갱신해준다
		treeIndex /= 2;
		segmentTree[treeIndex] = segmentTree[treeIndex * 2] + segmentTree[treeIndex * 2 + 1];
	}
}

long long sumArrSection(vector<long long> &segmentTree, int arrLeftIndex, int arrRightIndex, long long nodeLeftIndex, long long nodeRightIndex, long long treeIndex) {

	if (arrLeftIndex > nodeRightIndex || arrRightIndex < nodeLeftIndex) { // 세그먼트 트리 구간이 합을 구해야 하는 arr 구간에 전혀 포함되지 않는 경우
		return 0;
	}

	else if (arrLeftIndex <= nodeLeftIndex && nodeRightIndex <= arrRightIndex) { // 세그먼트 트리 구간이 합을 구해야 하는 arr 구간에 완전 포함되는 경우
		return segmentTree[treeIndex];
	}

	else { // 세그먼트 트리 구간이 합을 구해야 하는 arr 구간에 일부 포함되는 경우
		int mid = (nodeLeftIndex + nodeRightIndex) / 2;
		return sumArrSection(segmentTree, arrLeftIndex, arrRightIndex, nodeLeftIndex, mid, treeIndex * 2) + sumArrSection(segmentTree, arrLeftIndex, arrRightIndex, mid + 1, nodeRightIndex, treeIndex * 2 + 1);
	}
}

void showSegmentTree(vector<long long> &segmentTree, long long leafNodeSize) {

	for (int i = 1; i < leafNodeSize * 2; i++) {
		cout << segmentTree[i] << " ";
	}
	cout << endl;
}