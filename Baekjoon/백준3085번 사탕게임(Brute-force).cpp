#include <iostream>
#include <vector>
using namespace std;

void init_change(vector< vector<char> > &change, vector< vector<char> > &board, int N);
int maxToEat(vector< vector<char> > &change, int N);
void print(vector< vector<char> > &change, int N);

int main() {
	
	int N(0);
	int i(0), j(0);
	int max(1);
	char temp;
	vector< vector<char> > board;
	vector< vector<char> > change;
	
	cin >> N;

	board = vector< vector<char> >(N, vector<char>(N));
	change = vector< vector<char> >(N, vector<char>(N));

	for (i = 0; i < N; i++) 
		for (j = 0; j < N; j++)
			cin >> board[i][j];

	for (i = 0; i < N; i++) { // 가로바꾸기
		for (j = 0; j < N - 1; j++) {
			init_change(change, board, N);
			temp = change[i][j];
			change[i][j] = change[i][j + 1];
			change[i][j + 1] = temp;
			if(maxToEat(change, N) > max)
				max = maxToEat(change, N);
		}
	}
	for (j = 0; j < N; j++) { // 세로바꾸기
		for (i = 0; i < N - 1; i++) {
			init_change(change, board, N);
			temp = change[i][j];
			change[i][j] = change[i + 1][j];
			change[i + 1][j] = temp;
			if (maxToEat(change, N) > max)
				max = maxToEat(change, N);
		}
	}

	printf("%d\n", max);
	
}

void init_change(vector <vector <char>> &change, vector <vector <char>> &board, int N) {
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			change[i][j] = board[i][j];
}

int maxToEat(vector <vector <char>> &change, int N) {

	int i(0), j(0);
	int max(1);
	int result(1);

	for (i = 0; i < N; i++) { // 가로검사
		for (j = 0; j < N - 1; j++) {
			while (1) {
				if (j < N - 1 && (change[i][j] == change[i][j + 1])) {
					max++;
					j++;
				}
				else
					break;
			}
			if (max > result) {
				result = max;
			}
			max = 1;
		}
	}
	for (j = 0; j < N; j++) { // 세로검사
		for (i = 0; i < N - 1; i++) {
			while (1) {
				if (i < N - 1 && (change[i][j] == change[i + 1][j])) {
					max++;
					i++;
				}
				else
					break;
			}
			if (max > result) {
				result = max;
			}
			max = 1;
		}
	}
	
	return result;
}

void print(vector <vector <char>> &change, int N) {

	int i(0), j(0);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%c", change[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}