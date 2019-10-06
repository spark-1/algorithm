#include <stdio.h>
#include <windows.h>

int printSierpinskiTriangle(int n, int middle, int height);
void gotoxy(int x, int y);

int main() {

	int n = 0;
	
	scanf("%d", &n);
	
	printSierpinskiTriangle(n, n, 1);
}

void gotoxy(int x, int y) {

	COORD Pos = { x - 1 , y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int printSierpinskiTriangle(int n, int middle, int height) {

	int i = 0;

	if (n == 3) {
		gotoxy(middle, height++);
		printf("*");
		gotoxy(middle - 1, height++);
		printf("* *");
		gotoxy(middle - 2, height);
		printf("*****");
		return 0;
	}

	printSierpinskiTriangle(n/2, middle, height);
	printSierpinskiTriangle(n/2, middle - n / 2, height + n / 2);
	printSierpinskiTriangle(n/2, middle + n / 2, height + n / 2);

}