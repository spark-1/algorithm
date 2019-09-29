#include <iostream>

int main() {

	int burger, cheap_burger = 10000, drink, cheap_drink = 10000;

	for (int i = 0; i < 3; i++) {
		scanf("%d", &burger);
		if (cheap_burger > burger) {
			cheap_burger = burger;
		}
	}
	for (int i = 0; i < 2; i++) {
		scanf("%d", &drink);
		if (cheap_drink > drink) {
			cheap_drink = drink;
		}
	}
	printf("%d\n", cheap_burger + cheap_drink - 50);
}