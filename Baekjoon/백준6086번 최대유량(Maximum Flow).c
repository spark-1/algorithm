#include <stdio.h> // 에드몬드 카프 알고리즘(Edmonds-Karp algorithm) -> BFS (포드 풀커슨 알고리즘 -> DFS)
#include <stdlib.h>
#include <string.h>

#define element int
//#define min(a, b) ((a < b) ? a : b)
//#define max(a, b) ((a > b) ? a : b) 

typedef struct vertex { // 인접정점 연결리스트

	int destination; // 목적정점
	int capacity; // 용량
	int flow; // 유량
	struct vertex *adjacencyVertex; // 인접 정점

}Vertex;

typedef struct list { // 그래프의 각 정점 리스트

	Vertex *head;

}List;

typedef struct graph { // 그래프 구조체

	int V; // 정점의 수
	List *list; // 인덱스로 각 정점을 나타낸다

}Graph;

typedef struct dequeNode { // 앞(왼쪽)이 Front 뒤(오른쪽)이 rear

	element data;
	struct dequeNode *leftLink;
	struct dequeNode *rightLink;

}DequeNode;

typedef struct dequeType {

	int size;
	DequeNode *front;
	DequeNode *rear;

}DequeType;

int ctoi(char c);
Graph *newGraph();
void newList(Graph *graph, int max);
Vertex *newAdjacencyVertex(int destination, int capacity);
void addEdge(Graph *graph, int u, int v, int capacity);
Vertex *findEdge(Graph *graph, int u, int v);
DequeType *newDeque(); // 덱 생성
DequeNode *newDequeNode(); // 덱 노드 생성
int isEmptyDeque(DequeType *deque); // 덱이 비어있는지 확인
void enqueueRear(DequeType *deque, element data); // 덱의 뒤에 삽입
element dequeueFront(DequeType *deque); // 덱의 앞의 노드 삭제
element peekFront(DequeType *deque); // 덱의 앞의 노드 리턴

int main() {

	Graph *graph = newGraph(); // 인접리스트 그래프 생성
	DequeType *deque = NULL;
	Vertex *vertex = NULL;
	int E = 0; // 간선의 개수
	int i = 0, capacity = 0, flow = 0; // 용량과 유량
	char u = 0, v = 0; // u : 시작정점, v : 도착정점
	int total = 0; // 총 유량
	int S = ctoi('A'), T = ctoi('Z'); //  S : 소스, T : 싱크
	int *visited = (int *)malloc(sizeof(int) * 52);
	int curr = 0, next = 0; // 현재 정점과 다음정점의 키값
	int INF = 1000000000;
	
	scanf("%d", &E); // 간선의 개수 입력
	getchar();
	for (i = 0; i < E; i++) {
		scanf("%c %c %d", &u, &v, &capacity);
		getchar();
		addEdge(graph, ctoi(u), ctoi(v), capacity);
		addEdge(graph, ctoi(v), ctoi(u), capacity); // 역방향 간선을 추가해준다
	}
	
	while (1) { // 증가 경로(augmenting path)를 못 찾을 때까지 루프, 증가 경로를 BFS로 찾음

		deque = newDeque();
		enqueueRear(deque, S);
		memset(visited, -1, sizeof(int) * 52); // 방문변수 초기화
	
		while (!isEmptyDeque(deque)) { // BFS로 경로 찾기
			curr = peekFront(deque);
			dequeueFront(deque);
			vertex = graph->list[curr].head;
			while(vertex != NULL) { // curr에서 인접한 모든 정점에 대해
				// vertex->capacity - vertex->flow > 0: u에서 v로 유량을 흘릴 여유가 남고
				// visited[next] == -1: next 정점을 아직 방문 하지 않았다면
				next = vertex->destination;
				if (vertex->capacity - vertex->flow > 0 && visited[next] == -1) {
					enqueueRear(deque, next);
					visited[next] = curr; // 경로를 기억하기 위해 visited 배열 사용
					if (next == T) // 싱크에 도달하면 나옴 
						break; 
				}
				vertex = vertex->adjacencyVertex;
			}
			if (next == T && visited[T] != -1) {// 싱크에 도달하면 나옴 
				while (!isEmptyDeque(deque))
					dequeueFront(deque);
				break;
			}
		}

		// 싱크로 가는 경로가 더 없으면 루프 탈출
		if (visited[T] == -1) 
			break;

		// 경로상에서 가장 허용치가 낮은 곳을 찾음
		flow = INF;
		for (i = T; i != S; i = visited[i]) {
			vertex = graph->list[visited[i]].head;
			while (vertex->destination != i)
				vertex = vertex->adjacencyVertex;
			flow = min(flow, vertex->capacity - vertex->flow);
		}

		// 찾은 flow만큼 해당 경로에 유량 흘려줌
		for (i = T; i != S; i = visited[i]) {
			vertex = findEdge(graph, visited[i], i);
			vertex->flow += flow;
			vertex = findEdge(graph, i, visited[i]);
			vertex->flow -= flow;
		}

		// 총 유량 값 증가
		total += flow;
		free(deque);
	}

	// 결과 출력
	printf("%d\n", total);
}

int ctoi(char c) { // 알파벳 문자를 0~51 사이의 정수로 바꿔주는 함수
	if (c <= 'Z') 
		return c - 'A';
	else
		return c - 'a' + 26;
}

Graph *newGraph() {
	return (Graph *)calloc(1, sizeof(Graph));
}

void newList(Graph *graph, int max) {

	int i = 0;

	if (graph->list == NULL) { // 초기 그래프의 정점개수만큼의 리스트 데이터할당
		graph->list = (List *)calloc(max + 1, sizeof(List));
	}

	else {
		graph->list = (List *)realloc(graph->list, (max + 1) * sizeof(List)); // 새로운 제일 큰 정점의 크기만큼 재할당 해주고
		for (i = graph->V + 1; i <= max; i++) { // 기존 최대 정점 이후부터 새로운 최대 정점까지 초기화 해준다
			graph->list[i].head = NULL;
		}
	}

	graph->V = max; // 정점개수 갱신
}

Vertex *newAdjacencyVertex(int destination, int capacity) {

	Vertex *vertex = (Vertex *)calloc(1, sizeof(Vertex));
	vertex->destination = destination;
	vertex->capacity = capacity;

	return vertex;
}

void addEdge(Graph *graph, int u, int v, int capacity) {

	Vertex *vertex = NULL;
	Vertex *temp = NULL;

	if (graph->V < max(u, v)) { // 현재 그래프의 정점수보다 큰 정점이 들어오면 정점수 갱신
		newList(graph, max(u, v));
	}

	vertex = graph->list[u].head;

	if (vertex == NULL || vertex->destination > v) { // u 정점에 인접 노드가 하나도 없거나 처음 나오는 인접정점보다 작은 크기면
		graph->list[u].head = newAdjacencyVertex(v, capacity);
		graph->list[u].head->adjacencyVertex = vertex;
	}
	else { // 처음 나오는 인접 정점보다 크거나 같으면 적절한 위치를 찾는다
		temp = vertex;
		while (vertex != NULL && vertex->destination < v) {
			temp = vertex;
			vertex = vertex->adjacencyVertex;
		}
		if (temp->destination == v)
			temp->capacity += capacity;
		else {
			temp->adjacencyVertex = newAdjacencyVertex(v, capacity);
			temp->adjacencyVertex->adjacencyVertex = vertex;
		}
	}

}

Vertex *findEdge(Graph *graph, int u, int v) {
	
	Vertex *vertex = graph->list[u].head;

	while (vertex != NULL && vertex->destination != v)
		vertex = vertex->adjacencyVertex;

	return vertex;
}

DequeType *newDeque() { // 덱 생성
	return (DequeType *)calloc(1, sizeof(DequeType));
}

DequeNode *newDequeNode() { // 덱 노드 생성
	return (DequeNode *)calloc(1, sizeof(DequeNode));
}

int isEmptyDeque(DequeType *deque) { // 덱이 비어있는지 확인
	return (deque->size == 0); // 사이즈가 0이면 1리턴, 그외는 0리터
}

void enqueueRear(DequeType *deque, element data) { // 덱의 rear에 data를 추가한다

	DequeNode *node = newDequeNode();

	node->data = data;

	if (isEmptyDeque(deque)) { // 덱이 비어 있다면
		deque->front = node;
	}
	else { // 덱이 비어있지 않다면
		node->leftLink = deque->rear;
		deque->rear->rightLink = node;
	}
	deque->rear = node;
	deque->size++;
}

element dequeueFront(DequeType *deque) { // 덱의 front에 있는 data를 삭제하고 data를 리턴한다.

	DequeNode *temp = NULL;
	element data = 0;

	if (isEmptyDeque(deque)) // 덱이 비어있다면 그냥 종료한다
		return 0;

	else if (deque->front == deque->rear) // 덱에 노드가 하나 뿐이라면 꼬리를 NULL 시켜준다.
		deque->rear = NULL;

	temp = deque->front;
	data = temp->data;

	deque->front = temp->rightLink;
	free(temp);
	deque->size--;

	if (!isEmptyDeque(deque)) // 삭제후 덱에 노드가 하나라도 남아있다면
		deque->front->leftLink = NULL; // 앞의 왼쪽 연결을 초기화시켜준다.

	return data;
}

element peekFront(DequeType *deque) { // 덱의 front에 있는 data를 peek한다

	if (isEmptyDeque(deque)) // 덱이 비어있다면 그냥 종료한다
		return 0;

	else
		return deque->front->data;
}