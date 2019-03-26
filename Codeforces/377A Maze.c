#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int x;
	int y;
	int path; //이미 지나온길인지 아닌지
	struct node *link;

}Node;

typedef struct stacktype {

	struct node *top;

}StackType;

StackType *makeStack();
Node *makeNode();
int isEmpty(StackType *s);
int push(StackType *s, int x, int y);
void pushLoc(StackType *s, char **maze, int x, int y, int m, int n);
int pop(StackType *s);

int main() {

	int i = 0;
	char **maze = NULL;
	int m = 0, n = 0, change = 0;
	int x = 0, y = 0;
	StackType *s = makeStack();

	FILE *file1= NULL;
	FILE *file2 = NULL;
	file1 = fopen("Text.txt", "r");
	file2 = fopen("Text2.txt", "w");
	fscanf(file1, "%d %d %d", &m, &n, &change);

	//scanf("%d %d %d", &m, &n, &change);
	//getchar(); //엔터 버퍼 먹기 

	maze = (char **)calloc(m, sizeof(char *));
	for(i = 0; i < m; i++)
		maze[i] = (char *)calloc(n + 1, sizeof(char));
	
	 
	for (i = 0; i < m; i++) {//미로 구조 받기
		//gets(maze[i]);
		fscanf(file1, "%s", maze[i]);
	}

	while (maze[y][x] != '.') { //탐색 시작할 x,y 찾기
		if (x == n - 1) {
			x = 0;
			y++;
		}
		else
			x++;
	}
	
	while (change != 0) { //이거 마무리 해야함
		pushLoc(s, maze, x, y + 1, m ,n);
		pushLoc(s, maze, x + 1, y, m, n);
		pushLoc(s, maze, x, y - 1, m, n);
		pushLoc(s, maze, x - 1, y, m, n);
	}

	for (i = 0; i < m; i++) { // 미로 출력
		//printf("%s\n", maze[i]);
		fprintf(file2, "%s\n", maze[i]);
	}
}

StackType *makeStack() {

	return (StackType *)calloc(1, sizeof(StackType));
}

Node *makeNode() {

	return (Node *)calloc(1, sizeof(Node));
}

int isEmpty(StackType *s) {

	if (s->top == NULL)
		return 1;
	else
		return 0;
}

int push(StackType *s, int x, int y) {

	Node *newNode = makeNode();

	if (newNode == NULL) 
		return 0;

	newNode->x = x;
	newNode->y = y;
	newNode->link = s->top;
	s->top = newNode;
}

int pop(StackType *s) {

	Node *tempNode = makeNode();

	if (isEmpty(s)) {
		return 0;
	}

	tempNode = s->top;
	s->top = tempNode->link;
	free(tempNode);

	return 0;
}

void pushLoc(StackType *s, char **maze, int x, int y, int m, int n) {

	if (x < 0 || y < 0 || x >= m || y >= n) 
		return;
	if (maze[x][y] == '.') {
		push(s, x ,y);
	}
}