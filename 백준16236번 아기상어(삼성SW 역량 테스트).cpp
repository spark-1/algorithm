#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;
int eaten(0); // 현재 배부름의 상태
int check[20][20] = { 0 }; // 몇번째로 먹는지 확인해주는 배열
int q[20][20] = { 0 }; // 큐의 몇번째인지 확인해주는 배열
int c = 1, k = 0; // 몇번째로 먹은것, 큐의 몇번째 상태

struct Point {
	int i;
	int j;
};

Point moveWNES(Point point, int dir);
int bfsQueue(vector< vector<int> >& map, Point& now, int& N, int& baby_shark);

int main() {

	int N(0), baby_shark(2), result(0), temp(0);
	Point now;
	vector< vector<int> > map;
	cin >> N;
	map = vector< vector<int> >(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				now.i = i;
				now.j = j;
			}
		}
	}

	map[now.i][now.j] = 0;

	while (1) {
		temp = result;
		result += bfsQueue(map, now, N, baby_shark);

		/*printf("덱의 상황, 상어크기%d  배부름 %d\n", baby_shark, eaten);
		for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
		printf("%3d ", q[i][j]);
		}
		cout << endl;
		}
		cout << endl;
		memset(q, 0, sizeof(q));
		k = 0;*/

		if (temp == result) {
			break;
		}
	}

	/*printf("먹는 순서 상황\n");
	for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j++) {
	cout << check[i][j] << " ";
	}
	cout << endl;
	}*/

	cout << result << endl;
}

Point moveWNES(Point point, int dir) { // dir가 0북 1서 2동 3남 point형 반환 

	if (dir == 0)
		point.i--;
	else if (dir == 1)
		point.j--;
	else if (dir == 2)
		point.j++;
	else if (dir == 3)
		point.i++;

	return point;
}

int bfsQueue(vector< vector<int> >& map, Point& now, int& N, int& baby_shark) { // now 위치부터 큐(덱)를 이용하여 탐색하기(BFS)

	int dir(0), i(0), j(0);
	Point temp1, temp2;
	int visited[20][20] = { 0 }; // 방문한 셀 위치인지의 여부
	int depth[20][20] = { 0 }; // 시작점에서 그 셀 위치까지의 간선의 길이(깊이)
	memset(depth, -1, sizeof(depth)); // 깊이 배열을 -1로 모두 초기화
	depth[now.i][now.j] = 0; //시작위치의 깊이는 0이다
	int already_in_deq = 0;
	deque<Point> deq; // 덱 생성

	deq.push_back(now); // 현재 위치를 덱에 넣는다

	while (1) { // 덱이 빌때 까지 반복한다 먹을 수 있는 물고기가 없고 갈 수 있는곳이 없을 때 까지
		i = now.i;
		j = now.j;

		if (map[i][j] < baby_shark && map[i][j] > 0) { // 현재 위치한곳이 자기크기보다 작은 물고기 있는 곳이면 먹고 끝낸다
			map[i][j] = 0; // 물고기를 치우고
			eaten++; // 배부름 +1
			if (eaten == baby_shark) { // 배부름이 자신의 크기와 같으면
				baby_shark++; // 상어크기 +1
				eaten = 0; // 배부름 = 0
			}
			check[i][j] = c++; // 해당 위치의 물고기를 몇번째로 먹는지 배열에 저장
			q[i][j] = k++; // 해당 위치의 물고기가 덱의 원소였는지 저장
			return depth[i][j]; // 거리를 리턴하고 함수 종료
		}

		else { // 현재 위치한곳에 먹을 수 있는 물고기가 없다면 (못먹는 물고기가 있거나 vs 아무것도 없거나)

			deq.pop_front(); // 현재위치인 덱의 헤드를 뺀다
			visited[i][j] = 1;

			for (dir = 0; dir < 4; dir++) { // 현재 위치에서 북서동남으로 확인을 해본다
				now = moveWNES(now, dir); // 위치가 바뀌고
				already_in_deq = 0;
				for (int z = 0; z < deq.size(); z++) {
					if (now.i == deq[z].i && now.j == deq[z].j) { // 이미 덱에 같은 내용이 있다면
						already_in_deq = 1;
						break;
					}
				}

				if (already_in_deq == 0 && now.i >= 0 && now.j >= 0 && now.i < N && now.j < N && map[now.i][now.j] >= 0 && map[now.i][now.j] <= baby_shark && visited[now.i][now.j] == 0) { // 현재 위치에서 북서동남순으로 검사하여 갈 수 있는 곳이면
					deq.push_back(now); // 그 위치를 덱의 뒤에 넣는다
					depth[now.i][now.j] = depth[i][j] + 1; // 확인한 위치는 현재 위치보다 깊이가 1더 큰곳이다
					if (deq.size() >= 2 && deq[deq.size() - 1].i >= 0 && deq[deq.size() - 2].i >= 0 && ((deq[deq.size() - 1].i + 1 == deq[deq.size() - 2].i) || ((deq[deq.size() - 1].i == deq[deq.size() - 2].i) && (deq[deq.size() - 1].j < deq[deq.size() - 2].j))) && (depth[deq[deq.size() - 1].i][deq[deq.size() - 1].j] == depth[deq[deq.size() - 2].i][deq[deq.size() - 2].j])) { // 덱에 새로 들어온 정보가 이전 정보보다 y축상 하나 위에 있을때
						temp1 = deq.back(); // temp1은 이번에 들어온 정보
						deq.pop_back();
						temp2 = deq.back(); // temp2는 이전에 들어온 정보
						deq.pop_back();
						deq.push_back(temp1); // 이번에 들어온 정보를 먼저 넣고
						deq.push_back(temp2); // 이후에 들어온 정보를 나중에 넣는다
					}
				}
				now.i = i;
				now.j = j;
			}
		}

		q[i][j] = k++;

		if (deq.empty() == 1) { // 덱이 빌때까지 찾지 못한다면
			break;
		}

		now = deq.front(); // 현재위치는 덱의 맨앞의 위치이다.
	}

	return 0;
}