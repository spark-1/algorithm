#include <iostream>

int main() {

	int time, hour, minute, second;

	scanf("%d %d %d %d", &hour, &minute, &second, &time);

	second += time % 60;
	if (second >= 60) {
		second -= 60;
		minute++;
	}
	minute += (time / 60) % 60;
	if (minute >= 60) {
		minute -= 60;
		hour++;
	}
	hour += time / 3600;
	hour = hour % 24;

	printf("%d %d %d\n", hour, minute, second);
}