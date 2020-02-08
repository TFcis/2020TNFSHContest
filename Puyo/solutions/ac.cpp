#include <stdio.h>
#include <string.h>

const int N = 12;
const int M = 6;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int board[N+5][M], temp[N+5][M];
int used[N+5][M];
int qx[(N+5)*M], qy[(N+5)*M];
int ucnt;

int max(int p, int q)
{
	return p>q ? p : q;
}

void adjust()
{
	int i, j, k;
	for (j=0; j<M; j++)
	{
		for (i=0, k=0; i<N+2; i++)
		{
			if (temp[i][j])
			{
				temp[k][j] = temp[i][j];
				k++;
			}
		}
		for (; k<N+2; k++)
		{
			temp[k][j] = 0;
		}
	}
}

int floodfill(int sx, int sy, int replace)
{
	int color, i, j, k, x, y, tx, ty;
	qx[0] = sx;
	qy[0] = sy;
	color = temp[sx][sy];
	ucnt++;
	used[sx][sy] = ucnt;
	for (i=0, j=1; i<j; i++)
	{
		x = qx[i];
		y = qy[i];
		temp[x][y] = replace;
		for (k=0; k<4; k++)
		{
			tx = x + dx[k];
			ty = y + dy[k];
			if (tx >= 0 && tx < N+2 && ty >= 0 && ty < M)
			{
				if (used[tx][ty] != ucnt && temp[tx][ty] == color)
				{
					used[tx][ty] = ucnt;
					qx[j] = tx;
					qy[j] = ty;
					j++;
				}
			}
		}
	}
	return j;
}

int combo()
{
	int res, i, j;
	adjust();
	res = 0;
	for (j=0; j<M; j++)
	{
		for (i=0; i<N+2; i++)
		{
			if (temp[i][j])
			{
				if (floodfill(i, j, temp[i][j]) >= 4)
				{
					floodfill(i, j, 0);
					res++;
				}
			}
		}
	}
	return res;
}

int solve()
{
	int res;
	memcpy(temp, board, sizeof(temp));
	res = 0;
	while (combo())
	{
		res++;
	}
	return res;
}

int main()
{
	int i, j, p, q, ans;
	while (scanf("%1d%1d", &p, &q) == 2)
	{
		for (i=N-1; i>=0; i--)
		{
			for (j=0; j<M; j++)
			{
				scanf("%1d", &board[i][j]);
			}
		}
		ans = 0;
		for (i=0; i<M; i++)
		{
			// p
			// q
			board[N+1][i] = p;
			board[N][i] = q;
			ans = max(ans, solve());
			// q
			// p
			board[N+1][i] = q;
			board[N][i] = p;
			ans = max(ans, solve());
			board[N][i] = 0;
			if (i+1 < M)
			{
				// pq
				board[N+1][i] = p;
				board[N+1][i+1] = q;
				ans = max(ans, solve());
				// qp
				board[N+1][i] = q;
				board[N+1][i+1] = p;
				ans = max(ans, solve());
				board[N+1][i+1] = 0;
			}
			board[N+1][i] = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}
