#include <stdio.h>

int main() {

	int N, type, a, h;
	long long atk, hp(0), ans(0);

	scanf("%d %lld", &N, &atk);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &type, &a, &h);
		if (type == 1) { // 몬스터일 경우 체력은 누적 딜량
			long long turn = (h - 1) / atk;
			hp += turn * a;
		}
		else { // 포션일 경우 필요한 체력이 줄으나 0보다 줄 수 는없다.
			atk += a;
			hp -= h;
			if (hp < 0) {
				hp = 0;
			}
		}

		if (ans < hp) { // 던전을 돌게되는 도중 받은 누적딜량중 최고값을 기억해낸다 아닐시 그 구간을 통과할 수 없다
			ans = hp;
		}
	}
	printf("%lld\n", ans + 1); // 총 누적딜량 - 힐량 + 1이 최소로 필요한 영웅 체력이 된다
}