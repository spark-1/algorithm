#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct histo {
	int height;
	int index;
};

int main() {

	vector<histo> stack, histogram;
	int N, i, maxSquare(0), poped(0), poped_index(0), base(0);
	histo element;

	cin >> N;

	for (i = 0; i < N; i++) { // 입력할때마다 처리해도 되지만 가독성을 위해 값을 받고 처리한다
		scanf("%d", &element.height);
		element.index = i;
		histogram.push_back(element);
	}

	for (i = 0; i < N + 1; i++) {
		if ((i != N) && (stack.empty() || stack.back().height < histogram[i].height)) { //마지막 단계가 아니고 스택이 비어있거나 현재 탐색부분의 높이가 더 크다면
		}
		else { // 그렇지 않다면 
			base = 0;
			while ((i == N) || (!stack.empty() && stack.back().height >= histogram[i].height)) { // 마지막 단계이거나 스택이 비어있지 않아야 하고 스택의 top이 현재 탐색보다 크거나 같으면 pop한다
				if (stack.empty()) { // 스택이 비었다면 
					break;
				}
				poped = stack.back().height; // 스택의 top을 정보를 가져온다
				poped_index = stack.back().index;
				stack.pop_back();
				if (stack.empty()) { // 스택이 비었다면 
					base = i;
				}
				else { // 스택이 비어있지 않다면 poped된 인덱스와 전 히스토그램의 인덱스 크기차이가 밑변이 된다
					base += poped_index - stack.back().index;
				}
				maxSquare = max(maxSquare, poped * base);
			}
		}
		if (i != N) {
			stack.push_back(histogram[i]); // 스택에 데이터를 푸시해준다
		}
	}
	
	cout << maxSquare << endl;
}