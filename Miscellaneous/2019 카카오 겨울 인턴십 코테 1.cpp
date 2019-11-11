#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	int height[100] = { 0 };
	vector<int> stack;

	for (int i = 0; i < board[0].size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[j][i] != 0) {
				height[i] = j;
				break;
			} 
		}
	}

	int pick = 0;
	int top = -1;

	for (int i = 0; i < moves.size(); i++) {
		if (height[moves[i] - 1] == board[0].size()) {
			continue;
		}
		pick = board[height[moves[i] - 1]][moves[i] - 1];
		height[moves[i] - 1]++;
		stack.push_back(pick);
		top++;
		if (stack.size() >= 2 && stack[top] == stack[top - 1]) {
			while (stack.size() >= 2) {
				if (stack[top] == stack[top - 1]) {
					stack.pop_back();
					stack.pop_back();
					top = top - 2;
					answer = answer + 2;
				}
				else {
					break;
				}
			}
		}
	}




	return answer;
}