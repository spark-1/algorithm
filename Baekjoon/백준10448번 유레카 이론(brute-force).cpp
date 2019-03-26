#include <iostream> // 유레카 이론
#include <vector>
using namespace std;

int main() {

	int T(0), i(0), j(0), k(0), num(0), find(0);
	vector<int> K;
	vector<int> triangleNum;

	cin >> T;
	K = vector<int>(T);

	for (i = 0; i < T; i++)
		cin >> K[i];

	i = 1;
	while (num < 1000) {
		num += i;
		triangleNum.push_back(num);
		i++;
	}
	
	for (num = 0; num < K.size(); num++) {
		for (i = 0; i < triangleNum.size(); i++) {
			for (j = 0; j < triangleNum.size(); j++) {
				for (k = 0; k < triangleNum.size(); k++) {
					if (K[num] == triangleNum[i] + triangleNum[j] + triangleNum[k]) {
						printf("1\n");
						find = 1;
						k = 1000;
						j = 1000;
						i = 1000;
					}
				}
			}
		}
		if (find == 0)
			printf("0\n");
		find = 0;
	}
}