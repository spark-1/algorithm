#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (a < b ? a : b)

int main() {

	int V = 0;
	int i = 0, j = 0, k = 0;
	int weight[100][100] = { 0 };  

	scanf("%d", &V);

	for (i = 0; i < V; i++) {
		for (j = 0; j < V; j++) {
			scanf("%d", &weight[i][j]);
			if (weight[i][j] == 0)
				weight[i][j] = 101;
		}
	}

	for (k = 0; k < V; k++)
		for (i = 0; i < V; i++)
			for (j = 0; j < V; j++)
				weight[i][j] = min(weight[i][j], weight[i][k] + weight[k][j]);

	for (i = 0; i < V; i++) {
		for (j = 0; j < V; j++)
			printf("%d ", weight[i][j] == 101 ? 0 : 1);
		printf("\n");
	}
}