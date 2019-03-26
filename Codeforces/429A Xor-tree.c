#include <stdio.h>
#include "stack.h"

typedef struct xorTree {

	Node *root;
	Node *nodes;
} XorTree;

XorTree *newXorTree();
Node *newNode(int number);
Node **newLink(Node **link);
void makeNodes(XorTree *xorTree, int number);
void linkNodes(Node *childNode, Node *parentNode);
void insertNodeValue(Node *node, int value);
int searchDifNodes(Node *node, int *goal, int *switchNode, int number);
void changeValueDFS(Node *node, int number);

int main() {

	int number = 0;
	int i = 0;
	int count = 0;
	int value = 0;
	int childKey = 0;
	int parentKey = 0;
	int *goal = NULL;
	int *switchNode = NULL;
	XorTree *xorTree = NULL;
	xorTree = newXorTree();
	
	scanf("%d", &number);
	makeNodes(xorTree, number); // number개 노드의 생성

	for (i = 1; i < number; i++) { // 노드 연결시켜주기
		scanf("%d %d", &childKey, &parentKey);
		linkNodes(&(xorTree->nodes[childKey - 1]), &(xorTree->nodes[parentKey - 1]));
	}

	for (i = 0; i < number; i++) { // 노드 value 지정하기
		scanf("%d", &value);
		insertNodeValue(&(xorTree->nodes[i]), value);
	}

	goal = (int *)calloc(number, sizeof(int));
	for (i = 0; i < number; i++) { // 도달할 value값들 저장하기
		scanf("%d", &value);
		goal[i] = value;
	}

	switchNode = (int *)calloc(number, sizeof(int));
	count = searchDifNodes(xorTree->root, goal, switchNode, number);
	printf("%d\n", count);
	
	for (i = 0; i < count; i++)
		printf("%d\n", switchNode[i]);
}

XorTree *newXorTree() {
	return (XorTree *)calloc(1, sizeof(XorTree));
}

Node *newNode(int number) {
	return (Node *)calloc(number, sizeof(Node));
}

Node **newLink(Node **link) {
	link = (Node **)realloc(link, sizeof(link) + sizeof(Node *));
	return link;
}

void makeNodes(XorTree *xorTree, int number) {

	int i = 0;
	xorTree->nodes = newNode(number);

	for (i = 0; i < number; i++) {
		xorTree->nodes[i].key = i + 1;
	}

	xorTree->root = &(xorTree->nodes[0]);
}

void linkNodes(Node *childNode, Node *parentNode) {

	int i = 0;

	parentNode->link = newLink(parentNode->link);

	parentNode->link[parentNode->childNum] = childNode; // 부모 자식 노드 연결 시켜주기
	parentNode->childNum++; // 부모는 자식개수 1추가
}

void insertNodeValue(Node *node, int value) {

	node->value = value;
}

int searchDifNodes(Node *node, int *goal, int *switchNode, int number) {
	
	int i = 0;
	int countDif = 0;
	StackType *s = newStack();
	int *check = (int *)calloc(number, sizeof(int));
	int canMove = 0;

	push(s, node);

	while (!isEmptyStack(s)) { // 스택이 비어있을때 까지 반복

		canMove = 0;
		check[node->key] = 1;

		if (node->value != goal[node->key - 1]) {
			changeValueDFS(node, number);
			switchNode[countDif] = node->key;
			countDif++;
		}

		for (i = 0; i < node->childNum; i++) { // 노드의 자식을 push 한다
			if (check[node->link[i]->key] == 0) {// 아직 방문하지 않은 자식이라면
				push(s, node->link[i]); // push 한다
				canMove++;
				break;
			}
		}

		if (canMove == 0) { // 현재 위치에서 움직일곳이 없다면 pop한다
			pop(s);
		}
		
		node = peek(s);
	}

	return countDif;
}

void changeValueDFS(Node *node, int number) {

	int i = 0;
	int change = 1;
	StackType *s = newStack();
	int *check = (int *)calloc(number, sizeof(int));
	int canMove = 0;

	push(s, node);

	while (!isEmptyStack(s)) { // 스택이 비어있을때 까지 반복

		canMove = 0;

		if (change == 1  && check[node->key] == 0) {
			if (node->value == 1)
				node->value = 0;
			else if (node->value == 0)
				node->value = 1;
		}

		check[node->key] = 1;

		for (i = 0; i < node->childNum; i++) { // 노드의 자식을 push 한다
			if (check[node->link[i]->key] == 0) {// 아직 방문하지 않은 자식이라면
				push(s, node->link[i]); // push 한다
				canMove++;
				break;
			}
		}

		if (canMove == 0) { // 현재 위치에서 움직일곳이 없다면 pop한다
			pop(s);
		}

		if (change == 1)
			change = 0;
		else if (change == 0)
			change = 1;

		node = peek(s);
	}
}