#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main() {

	string monster_num[100001];
	map<string, int> monster_name;
	int key, q;

	scanf("%d %d", &key, &q);
	for (int i = 0; i < key; i++) {
		char name[21];
		scanf("%s", name);
		monster_num[i + 1] = name;
		monster_name.insert(make_pair(name, i + 1));
	}
	
	for (int i = 0; i < q; i++) {
		char name[21];
		scanf("%s", name);
		if (name[0] <= 'Z' && name[0] >= 'A') {
			printf("%d\n", monster_name.find(name)->second);
		}
		else {
			int num = atoi(name);
			printf("%s\n", monster_num[num].c_str());
		}
	}
}