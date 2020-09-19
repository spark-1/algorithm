#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, n, cnt;
vector<int> student;
vector<bool> visited;
vector<bool> finished;

void dfs(int curr) {
	visited[curr] = true;
	int next = student[curr];
	if (visited[next]) {
		if (!finished[next]) {
			for (int temp = next; temp != curr; temp = student[temp]) cnt++; // 순회하며 카운트
			cnt++; // 자기 자신
		}
	}
	else dfs(next);
	finished[curr] = true;
}

int main() {
	
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &n);
		student.resize(n, 0);
		visited.resize(n, false);
		finished.resize(n, false);
		fill(student.begin(), student.end(), 0);
		fill(visited.begin(), visited.end(), false);
		fill(finished.begin(), finished.end(), false);
		for (int i = 0; i < n; i++) {
			scanf("%d", &student[i]);
			student[i]--;
		}
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		printf("%d\n", n - cnt);
		cnt = 0;
	}
}