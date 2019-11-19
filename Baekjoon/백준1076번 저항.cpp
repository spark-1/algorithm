#include <iostream>
#include <cstring>

int main() {

	char *str[3];
	long long result = 0;

	for (int i = 0; i < 3; i++) {
		str[i] = (char *)calloc(10, sizeof(char));
		scanf("%s", str[i]);
		if (i == 2) {
			if (strcmp(str[i], "black") == 0) {
				result *= 1;
			}
			else if (strcmp(str[i], "brown") == 0) {
				result *= 10;
			}
			else if (strcmp(str[i], "red") == 0) {
				result *= 100;
			}
			else if (strcmp(str[i], "orange") == 0) {
				result *= 1000;
			}
			else if (strcmp(str[i], "yellow") == 0) {
				result *= 10000;
			}
			else if (strcmp(str[i], "green") == 0) {
				result *= 100000;
			}
			else if (strcmp(str[i], "blue") == 0) {
				result *= 1000000;
			}
			else if (strcmp(str[i], "violet") == 0) {
				result *= 10000000;
			}
			else if (strcmp(str[i], "grey") == 0) {
				result *= 100000000;
			}
			else if (strcmp(str[i], "white") == 0) {
				result *= 1000000000;
			}
		}
		else {
			result *= 10;
			if (strcmp(str[i], "black") == 0) {
				result += 0;
			}
			else if (strcmp(str[i], "brown") == 0) {
				result += 1;
			}
			else if (strcmp(str[i], "red") == 0) {
				result += 2;
			}
			else if (strcmp(str[i], "orange") == 0) {
				result += 3;
			}
			else if (strcmp(str[i], "yellow") == 0) {
				result += 4;
			}
			else if (strcmp(str[i], "green") == 0) {
				result += 5;
			}
			else if (strcmp(str[i], "blue") == 0) {
				result += 6;
			}
			else if (strcmp(str[i], "violet") == 0) {
				result += 7;
			}
			else if (strcmp(str[i], "grey") == 0) {
				result += 8;
			}
			else if (strcmp(str[i], "white") == 0) {
				result += 9;
			}
		}
	}
	printf("%lld\n", result);
	
}