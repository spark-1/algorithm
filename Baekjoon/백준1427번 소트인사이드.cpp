#include <iostream>
#include <string>

using namespace std;

int compare(int *a, int *b)
{
	return *a < *b;
}

int main() {

	int *num;
	string str;

	cin >> str;
	num = new int[str.size()];

	for (int i = 0; i < str.size(); i++) {
		num[i] = str[i] - 48;
	}

	qsort(num, str.size(), sizeof(int), (int(*)(const void *, const void *))compare);

	for (int i = 0; i < str.size(); i++) {
		printf("%d", num[i]);
	}
}

/* koosaga
int compare(const void *b,const void *a){
	return ( *(char*)a - *(char*)b );
}
int main(){
	char s[20];
	scanf("%s",s);
	qsort(s, strlen(s), sizeof(char), compare);
	printf(s);
}
*/