#include <iostream>
#include <vector>

using namespace std;

int main() {

	int student, ticket;
	vector<int> line;

	scanf("%d", &student);
	for (int i = 0; i < student; i++) {
		scanf("%d", &ticket);
		line.insert(line.begin() + i - ticket, i);
	}

	for (int i = 0; i < student; i++) {
		printf("%d ", line[i] + 1);
	}
}