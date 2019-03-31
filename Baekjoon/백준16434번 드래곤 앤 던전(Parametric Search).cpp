#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Map {
	int type;
	int atk;
	int hp;
};

struct Hero {
	long long atk;
	long long hp;
};

int main() {

	int N, heroATK;
	long long minHP(0), maxHP(0), hp(0);
	vector<Map> map;
	Hero hero;

	cin >> N >> heroATK;
	map = vector<Map>(N);

	for (int i = 0; i < N; i++) {
		cin >> map[i].type >> map[i].atk >> map[i].hp;
		if (map[i].type == 1) { // 용사가 최악의 경우 이겨야되는 최대 체력치를 계산한다 (Parametric Search의 양극단중 만족하는 경우의 값을 알아야하기 때문)
			maxHP += (long long)((map[i].hp / heroATK) + 1) * map[i].atk; // 형변환 필수!
		}
	}

	//printf("초기 가능 최대 체력: %lld\n", maxHP);

	while (1) {

		hp = (maxHP + minHP) / 2; // 만족과 불만족 사이 히어로의 임시 체력값을 정해준다
		//printf("새로운 임시 체력: %lld\n", hp);
		hero.atk = heroATK; // 히어로의 정보 초기화
		hero.hp = hp;

		for (int i = 0; i < N; i++) {
			if (map[i].type == 1) { // 해당 인덱스 던전에 몬스터가 있다면

				int turn = ((map[i].hp - 1) / hero.atk); // 영웅은 해당 턴만큼 공격을 받게된다
				hero.hp -= (long long)turn * map[i].atk; // 영웅 체력 정보 갱신

				if (hero.hp <= 0) { // 영웅이 교전후 죽었다면 던전 도는것을 그만두고 새로운 영웅 체력정보로 재시작한다
					break;
				}
			}
			else if (map[i].type == 2) { // 해당 인덱스 던전에 포션이 있다면 영웅정보를 갱신한다
				hero.hp += map[i].hp;
				hero.atk += map[i].atk;
				if (hero.hp > hp) { // 영웅은 체력이 최대체력을 넘을 수 없다
					hero.hp = hp;
				}
			}	
		}

		if (hero.hp > 0) { // 영웅의 체력 조건이 던전을 깨기에 만족, min ~ 중간
			maxHP = hp;
		}
		else { // 영웅의 체력 조건이 던전을 깨기에 불만족, 중간 ~ max
			minHP = hp;
		}
		if (minHP + 1 == maxHP) {
			break;
		}
	}
	cout << maxHP << endl;
}