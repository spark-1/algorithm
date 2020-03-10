#include <iostream>
#include <vector>
using namespace std;

vector<int> num;
long long swap_count;

void mergeSort(int left, int right);
void merge(int left, int right);

int main() {

	int N, n;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		num.push_back(n);
	}
	mergeSort(0, N);

	printf("%lld\n", swap_count);
}

void mergeSort(int left, int right) {

	int middle;

	if (left + 1 == right)
		return;
	middle = (left + right) / 2;
	mergeSort(left, middle);
	mergeSort(middle, right);
	merge(left, right);
}

void merge(int left, int right) {

	int middle, mid_temp, temp = left;
	vector<int> sorted_num;

	middle = (left + right) / 2;
	mid_temp = middle;

	for (int i = 0; i < right - temp; i++) {
		if (middle == right || num[left] <= num[middle] && left != mid_temp) {
			sorted_num.push_back(num[left]);
			left++;
		}
		else {
			sorted_num.push_back(num[middle]);
			middle++;
			swap_count += mid_temp - left; // 스왑이 카운트 되는 부분
		}
	}

	for (int i = 0; i < sorted_num.size(); i++) {
		num[temp + i] = sorted_num[i];
	}
}