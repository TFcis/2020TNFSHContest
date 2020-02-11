// By xiplus
#include <bits/stdc++.h>
using namespace std;

int board[1002][1002], cnt[1002][1002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(board, -1, sizeof(board));
	memset(cnt, 0, sizeof(cnt));
	int N, M;
	cin >> N >> M;
	string s;
	set<pair<int, int>> pool, newpool;
	for (int q = 0; q < N; q++) {
		cin >> s;
		for (int w = 0; w < M; w++) {
			board[q + 1][w + 1] = s[w] - '0';
			if (board[q + 1][w + 1] == 0) {
				pool.insert({q + 1, w + 1});
				cnt[q + 1][w + 1] = 1;
			}
		}
	}
	// int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
	// int dy[] = {1, -1, 1, 0, -1, 1, 0, -1};
	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};
	int nx, ny;
	for (int n = 1; n <= 9; n++) {
		newpool.clear();
		for (auto pos : pool) {
			for (int e = 0; e < 4; e++) {
				nx = pos.first + dx[e];
				ny = pos.second + dy[e];
				if (board[nx][ny] == n) {
					cnt[nx][ny] += cnt[pos.first][pos.second];
					newpool.insert({nx, ny});
				}
			}
		}
		pool = newpool;
	}
	long long ans = 0;
	for (auto pos : pool) {
		ans += cnt[pos.first][pos.second];
	}
	cout << ans << endl;

	return 0;
}
