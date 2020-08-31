#include <iostream>
#include <cstring>

int main(void) {
	char octal[333335];
	scanf("%s", octal);

	switch (octal[0]) {
	case '0': printf("%s", "0"); break;
	case '1': printf("%s", "1"); break;
	case '2': printf("%s", "10"); break;
	case '3': printf("%s", "11"); break;
	case '4': printf("%s", "100"); break;
	case '5': printf("%s", "101"); break;
	case '6': printf("%s", "110"); break;
	case '7': printf("%s", "111"); break;
	}

	int len = strlen(octal);
	for (int i = 1; i < len; i++) {
		switch (octal[i]) {
		case '0': printf("%s", "000"); break;
		case '1': printf("%s", "001"); break;
		case '2': printf("%s", "010"); break;
		case '3': printf("%s", "011"); break;
		case '4': printf("%s", "100"); break;
		case '5': printf("%s", "101"); break;
		case '6': printf("%s", "110"); break;
		case '7': printf("%s", "111"); break;
		}
	}

}