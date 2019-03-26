#include <iostream>
#include <vector>
#include <cmath> // pow 사용 위해 필요
#include <algorithm>
#include <functional> // greater 사용 위해 필요 
using namespace std;

typedef struct cube {

	int num;
	int size;

}Cube;

bool compare(Cube a, Cube b); 

int main() { 

	int side[3] = { 0 };
	int V(0);
	int N(0), k(0); // N은 큐브 종류의 개수, k는 큐브의 변길이 변수
	int result(0);
	vector<Cube> cube;

	scanf("%d %d %d", &side[0], &side[1], &side[2]);
	scanf("%d", &N);

	cube = vector<Cube>(N);

	for (int i(0); i < cube.capacity(); i++) {
		scanf("%d %d", &k, &cube[i].num);
		cube[i].size = (int)pow(2, k);
	}

	sort(cube.begin(), cube.end(), compare);
	sort(side, side + 3);
	V = side[0] * side[1] * side[2];

	for (int i(0); i < cube.capacity(); i++) {

		while (V - cube[i].size * cube[i].size * cube[i].size >= 0 && cube[i].num > 0) { // 큐브 개수가 있고 부피상으로 들어갈 수 있다면
			while (side[0] < cube[i].size) { // 변길이를 가능 할때까지 검사한다
				i++;
				if (i == cube.capacity())
					break;
			}
			if (i == cube.capacity())
				break;
			V = V - cube[i].size * cube[i].size * cube[i].size;
			cube[i].num--;
			result++;
			side[2] -= cube[i].size;
			sort(side, side + 3);
			printf("큐브 한변 크기 %d 1개 사용 남은 큐브수 %d개\n", cube[i].size, cube[i].num);
			printf("남은 부피양 %d\n", V);
		}

	}

	if (V > 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", result);
	}
}

bool compare(Cube a, Cube b) {

	return a.size > b.size;
}

/*
3 3 8
2
1 100
0 100
44
*/