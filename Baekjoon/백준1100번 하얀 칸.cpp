#include <iostream>
using namespace std;

int main(){
	
	char c;
	int result = 0; 

	for (int i = 0; i < 64; i++) {
		cin >> c;
		if ((c == 'F') && (((i / 8) + i) % 2 == 0)) {
			//printf("%d %c\n", i, c);
			result++;
		}
	}
	printf("%d\n", result);
}