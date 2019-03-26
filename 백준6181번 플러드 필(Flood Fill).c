#include <stdio.h>
#include <stdlib.h>

#define element int
#define max(a, b) ((a > b) ? a : b)

typedef struct point {

	int x;
	int y;
	
}Point;

typedef struct vertex { // 인접정점

	int destination; // 목적정점
	struct vertex *adjacencyVertex; // 인접 정점

}Vertex;

typedef struct list { // 그래프의 각 정점

	Point V;
	Vertex *head;
	int visited;

}List;

typedef struct graph { // 그래프 구조체 

	int V; // 정점의 수
	List *list; // 인덱스로 각 정점을 나타낸다

}Graph;

typedef struct stackNode { // 스택노드

	element data;
	struct stackNode *link;

}StackNode;

typedef struct stackType { // 스택타입 ADT

	int size;
	StackNode *top;

}StackType;

Graph *newGraph();
List *newList(Graph *graph, List *list, int max);
Vertex *newAdjacencyVertex(int destination);
void addEdge(Graph *graph, int u, int v);

StackType *newStack();
StackNode *newStackNode();
void initStack(StackType **s);
int isEmptyStack(StackType *s);
void push(StackType *s, element data);
element pop(StackType *s);
element peek(StackType *s);

int main() {

	Graph *graph = newGraph();
	StackType *stack = newStack();
	int D = 0; // 맨하튼거리의 크기
	int i = 0, j = 0;
	int graphCount = 0;
	int graphMaxSize = 0;
	int graphSize = 0;
	int vertex;
	Vertex *temp = NULL;
	Point point;
	
	scanf("%d %d", &(graph->V), &D); // 그래프의 정점개수와 맨하튼거리를 입력받음
	graph->list = newList(graph, graph->list, graph->V); // 정점수 만큼 리스트 크기 할당
	for (i = 0; i <= graph->V; i++) { // 리스트 첫인접 정점인 헤드 초기화
		graph->list[i].head = NULL;
	}

	for (i = 0; i < graph->V; i++) { // 각 정점의 위치입력
		scanf("%d %d", &(point.x), &(point.y));
		graph->list[i].V.x = point.x;
		graph->list[i].V.y = point.y;
	}

	for (i = 0; i < graph->V; i++) { // 맨하튼 거리를 비교하여 D이하면 간선연결
		for (j = i + 1; j < graph->V; j++) {
			if (abs(graph->list[i].V.x - graph->list[j].V.x) + abs(graph->list[i].V.y - graph->list[j].V.y) <= D) {
				addEdge(graph, i, j);
				addEdge(graph, j, i);
			}
		}
	}

	/*
	for (i = 0; i < graph->V; i++) { // 인접리스트 내용 출력
		printf("%d %d: ", graph->list[i].V.x, graph->list[i].V.y);
		temp = graph->list[i].head;
		while (temp != NULL) {
			printf("%d %d   ", graph->list[temp->destination].V.x , graph->list[temp->destination].V.y);
			temp = temp->adjacencyVertex;
		}
		printf("\n");
	}
	*/

	for (i = 0; i < graph->V; i++) { // DFS방식으로 탐색하여 그래프의 크기 및 개수 확인

		vertex = i; // 현재 탐색정점의 위치를 i라 설정
		push(stack, i); // i를 스택에 푸시

		if (graph->list[vertex].visited != 1) { // 현재위치가 방문된 정점이 아니라면
			graph->list[vertex].visited = 1; // 방문표시
			graphSize++; // 그래프 크기 1증가

			while (!isEmptyStack(stack)) { // 스택이 비어있을때 까지 반복

				if (graph->list[vertex].visited == 1)
					pop(stack);

				temp = graph->list[vertex].head;

				while (temp != NULL) {
					if (graph->list[temp->destination].visited != 1) {
						push(stack, temp->destination);
						graph->list[temp->destination].visited = 1;
						graphSize++;
					}
					temp = temp->adjacencyVertex;
				}

				vertex = peek(stack); // 현재 위치는 스택의 top이다
			}
		}
		else {
			pop(stack);
		}

		if (graphSize != 0)
			graphCount++;
		graphMaxSize = max(graphMaxSize, graphSize);
		graphSize = 0;
	}

	printf("%d %d\n", graphCount, graphMaxSize);
}

Graph *newGraph() {
	return (Graph *)calloc(1, sizeof(Graph));
}

List *newList(Graph *graph, List *list, int max) {
	int i = 0;

	list = (List *)realloc(list, (max + 1) * sizeof(List)); // 새로운 제일 큰 정점의 크기만큼 재할당 해주고
	for (i = graph->V; i <= max; i++) { // 기존 최대 정점 이후부터 새로운 최대 정점까지 초기화 해준다
		list[i].head = NULL;
	}
	return list;
}

Vertex *newAdjacencyVertex(int destination) {
	Vertex *vertex = (Vertex *)calloc(1, sizeof(Vertex));
	vertex->destination = destination;

	return vertex;
}

void addEdge(Graph *graph, int u, int v) {

	Vertex *vertex = NULL;
	Vertex *temp = NULL;

	if (graph->V < max(u, v)) { // 현재 그래프의 정점수보다 큰 정점이 들어오면 정점수 갱신
		graph->list = newList(graph, graph->list, max(u, v));
		graph->V = max(u, v);
	}

	vertex = graph->list[u].head;

	if (vertex == NULL) { // u 정점에 인접 노드가 하나도 없었다면 
		graph->list[u].head = newAdjacencyVertex(v); // 바로연결
	}

	else { // 인접 정점이 있었다면 목적정점의 크기순으로 넣어준다
		temp = vertex;
		if (vertex->destination > v) { // 처음 나오는 인접정점보다 작은 크기면
			graph->list[u].head = newAdjacencyVertex(v);
			graph->list[u].head->adjacencyVertex = vertex;
		}
		else { // 처음 나오는 인접 정점보다 큰 크기면 적절한 위치를 찾는다
			while (vertex != NULL && vertex->destination < v) {
				temp = vertex;
				vertex = vertex->adjacencyVertex;
			}
			temp->adjacencyVertex = newAdjacencyVertex(v);
			temp->adjacencyVertex->adjacencyVertex = vertex;
		}
	}
}

StackType *newStack() { // 스택 생성
	return (StackType *)calloc(1, sizeof(StackType));
}

StackNode *newStackNode() { // 스택노드 생성
	return (StackNode *)calloc(1, sizeof(StackNode));
}

void initStack(StackType **s) { // 스택 초기화
	free(*s);
	*s = NULL;
}

int isEmptyStack(StackType *s) { // 스택이 비어있는지 확인
	return (s->top == NULL);
}

void push(StackType *s, element data) { // 스택의 data를 push

	StackNode *node = newStackNode();

	if (node == NULL)
		return;

	node->data = data;
	node->link = s->top;
	s->top = node;
	s->size++;
}

element pop(StackType *s) { // 스택의 data를 pop

	StackNode *tempStackNode = newStackNode();
	element data;

	if (isEmptyStack(s))
		return 0;

	tempStackNode = s->top;
	data = tempStackNode->data;
	s->top = tempStackNode->link;
	free(tempStackNode);
	s->size--;

	return data;
}

element peek(StackType *s) { // 스택의 data를 peek

	if (isEmptyStack(s))
		return 0;

	return s->top->data;
}