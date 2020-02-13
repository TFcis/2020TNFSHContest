#include<bits/stdc++.h>
#define pii pair<int,int>
#define maxn 12
using namespace std;
string s[maxn];
bool vis[maxn][6];
int _x[] = {-1,0,1,0};
int _y[] = {0,-1,0,1};
int bfs(int i,int j) {
	vis[i][j] = true;
	if(s[i][j] == '0')	return 0;
	
	queue<pii> q;
	q.push(make_pair(i,j));
	char col = s[i][j];
	int ret = 1;
	
	while(!q.empty()) {
		pii now = q.front();
		q.pop();
		int x = now.first , y = now.second;
		for(int t=0;t<4;t++) {
			int nx = x +_x[t] , ny = y + _y[t];
			if(nx < 0 || ny < 0 || nx >= 12 || ny >= 6)		continue;
			if(vis[nx][ny] || s[nx][ny] != col)		continue;
			vis[nx][ny] = true;
			q.push(make_pair(nx,ny));
			ret++;
		}
	}
	
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string op;
	cin >> op;
	for(int i=0;i<12;i++)
		cin >> s[i];

	for(char c : op)
		assert('0' <= c && c <= '5');
	for(int i=0;i<12;i++)
		for(char c : s[i])
			assert('0' <= c && c <= '5');
	
	// no combo in the beginning
	for(int i=0;i<12;i++)
		for(int j=0;j<6;j++)
			if(!vis[i][j])
				assert(bfs(i,j) < 4);
				
	// no floating puyo
	for(int i=0;i<11;i++)
		for(int j=0;j<6;j++)
			assert(s[i][j] == '0' || s[i+1][j] != '0');
			
	cout << "Succes" << endl;
	return 0;
}

