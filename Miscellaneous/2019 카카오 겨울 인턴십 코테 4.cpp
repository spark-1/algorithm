#include <string>
#include <vector>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;

	vector<long long> redirect = vector<long long>(k + 1, 0);

	for (int i = 0; i < room_number.size(); i++) {
		if (redirect[room_number[i]] == 0) {
			answer.push_back(room_number[i]);
			redirect[room_number[i]] = room_number[i] + 1;
		}
		else {
			int old_room = room_number[i];
			int new_room = redirect[room_number[i]];
			while (1) {
				if (redirect[new_room] != 0) { // 새로 배정받은 방도 비어있지 않다면
					redirect[old_room] = redirect[new_room];
					new_room = redirect[new_room];
					old_room = new_room;
				}
				else {
					break;
				}
			}
			answer.push_back(new_room);
			redirect[new_room] = new_room + 1;
			redirect[old_room] = new_room + 1;
		}
	}

	return answer;
}