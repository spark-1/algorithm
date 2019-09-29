#include <iostream>

int main() {

	int hour, minute, time;
	scanf("%d %d %d", &hour, &minute, &time);

	minute += time;
	hour += minute / 60;
	minute %= 60;
	hour %= 24;

	printf("%d %d\n", hour, minute);
}