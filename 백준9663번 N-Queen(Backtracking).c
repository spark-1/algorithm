#include <stdio.h>

int n, cnt;
int map[15][15];
int visit[15][15];

int check(int x, int y)
{
	//세로 검사
	for (int i = 0; i < x; i++)
	{
		if (visit[i][y] == 1)
		{
			return 0;
		}
	}

	//대각선 검사
	int tmp_x, tmp_y;

	//우상 검사
	tmp_x = x;
	tmp_y = y;
	while (0 <= tmp_x && tmp_y < n)
	{
		if (visit[tmp_x][tmp_y] == 1)
		{
			return 0;
		}
		tmp_x--;
		tmp_y++;
	}

	//좌상 검사
	tmp_x = x;
	tmp_y = y;
	while (0 <= tmp_x && 0 <= tmp_y)
	{

		if (visit[tmp_x][tmp_y] == 1)
		{
			return 0;
		}

		tmp_x--;
		tmp_y--;
	}

	return 1;
}

void backtrack(int x, int y, int d)
{

	if (visit[x][y] == 1)
	{
		return;
	}

	if (d == n - 1)
	{
		cnt++;
		return;
	}

	visit[x][y] = 1;

	for (int i = 0; i < n; i++)
	{

		if (check(x + 1, i))
		{
			backtrack(x + 1, i, d + 1);
			visit[x + 1][i] = 0;
		}
	}
}

int main()
{
	scanf("%d", &n);
	cnt = 0;

	for (int i = 0; i < n; i++)
	{
		backtrack(0, i, 0);
		visit[0][i] = 0;
	}

	printf("%d", cnt);
	return 0;
}