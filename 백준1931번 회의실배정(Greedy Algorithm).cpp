#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct conference{

	int start;
	int end;

}Conference;

bool compare(Conference a, Conference b);

int main() {

	int N(0), time(0), max(0);
	Conference con;
	vector<Conference> meeting;
	
	scanf("%d", &N);

	for (int i(0); i < N; i++) {
		scanf("%d %d", &con.start, &con.end);
		meeting.push_back(con);
	}

	sort(meeting.begin(), meeting.end(), compare); // 끝나는 시간에 맞춰서 정렬
	
	//for (int i(0); i < N; i++)
	//	printf("%d %d\n", meeting[i].start, meeting[i].end);

	for (int i(0); i < N; i++) { // 회의 번호를 차례대로 확인
		while (time > meeting[i].start) {
			i++;
			if (i == N)
				break;
		}
		if (i == N)
			break;
		max++;
		time = meeting[i].end;
	}

	cout << max << "\n";
}

bool compare(Conference a, Conference b) {
	
	if (a.end == b.end) { // 끝나는 시간이 같으면 시작시간이 이름순
		return a.start < b.start;
	}
	else { // 끝나는 시간이 다르면 끝나는 일찍 끝나는 시간순
		return a.end < b.end;
	}
}