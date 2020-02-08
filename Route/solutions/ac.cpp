#include <stdio.h>
#include <vector>

const int N = 1024;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int board[N][N];
long long dp[N][N];
std::vector<int> v[10];

int main()
{
	int n, m, i, j, k, t, x, y, tx, ty;
	long long ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<=9; i++)
		{
			v[i].clear();
		}
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				scanf("%1d", &board[i][j]);
				v[board[i][j]].emplace_back(i*m+j);
				if (!board[i][j])
				{
					dp[i][j] = 1;
				}
			}
		}
		for (i=1, ans=0; i<=9; i++)
		{
			for (j=0; j<v[i].size(); j++)
			{
				t = v[i][j];
				x = t / m;
				y = t % m;
				dp[x][y] = 0;
				for (k=0; k<4; k++)
				{
					tx = x + dx[k];
					ty = y + dy[k];
					if (tx >= 0 && tx < n && ty >= 0 && ty < m && board[tx][ty] == board[x][y]-1)
					{
						dp[x][y] += dp[tx][ty];
					}
				}
				if (i == 9)
				{
					ans += dp[x][y];
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
