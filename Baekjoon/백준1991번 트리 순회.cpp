#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> parent;
vector<int> left_child, right_child;

void set_children(int p, int l, int r);
void preorder(int root);
void inorder(int root);
void postorder(int root);

int main() {

	scanf("%d", &N);
	parent.resize(N, -1);
	left_child.resize(N, -1);
	right_child.resize(N, -1);
	
	for (int i = 0; i < N; i++) {
		char p, l, r;
		getchar();
		scanf("%c %c %c", &p, &l, &r);
		if (l == '.') {
			l = -1;
		}
		else {
			l -= 'A';
		}
		if (r == '.') {
			r = -1;
		}
		else {
			r -= 'A';
		}
		p -= 'A';
		set_children(p, l, r);
	}

	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
	printf("\n");
}

void set_children(int p, int l, int r) {
	if (l != -1) parent[l] = p;
	if (r != -1) parent[r] = p;
	left_child[p] = l;
	right_child[p] = r;
}

void preorder(int root) {
	printf("%c", root + 'A');
	if (left_child[root] != -1) preorder(left_child[root]);
	if (right_child[root] != -1) preorder(right_child[root]);
}
void inorder(int root) {
	if (left_child[root] != -1) inorder(left_child[root]);
	printf("%c", root + 'A');
	if (right_child[root] != -1) inorder(right_child[root]);
}
void postorder(int root) {
	if (left_child[root] != -1) postorder(left_child[root]);
	if (right_child[root] != -1) postorder(right_child[root]);
	printf("%c", root + 'A');
}