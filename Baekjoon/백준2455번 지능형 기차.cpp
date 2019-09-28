#include <iostream>

int main() {

	int num_out[4], num_in[4], max_people_num = 0, people_num = 0;

	for (int i = 0; i < 4; i++) {
		scanf("%d %d", &num_out[i], &num_in[i]);
		people_num += num_in[i] - num_out[i];
		if (people_num > max_people_num) {
			max_people_num = people_num;
		}
	}
	printf("%d\n", max_people_num);
}