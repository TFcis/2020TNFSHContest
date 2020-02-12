// O(N log N) , by Yazmau
#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int n,d;
vector<int> G[maxn];
int dp[maxn];
int max_son[maxn][2];
void dfs1(int u,int pa) {
	dp[u] = 1;
	max_son[u][0] = max_son[u][1] = -1;
	for(int v : G[u])
		if(v != pa) {
			dfs1(v,u);
			dp[u] = max(dp[u],dp[v] + 1);
			if(max_son[u][0] == -1 || dp[v] >= dp[max_son[u][0]])
				max_son[u][1] = max_son[u][0] , max_son[u][0] = v;
			else if(max_son[u][1] == -1 || dp[v] >= dp[max_son[u][1]])
				max_son[u][1] = v;
		}
}
int root;
void dfs2(int u,int pa,int up) {
	if(max(dp[u],up) < d) {
		if(root == -1 || u < root)
			root = u;
	}
	for(int v : G[u])
		if(v != pa) {
			int idx = max_son[u][0] == v ? max_son[u][1] : max_son[u][0];
			dfs2(v,u,max(up + 1,(idx == -1 ? -1 : dp[idx] + 2)));
		}
}
vector<int> ans;
void dfs3(int u,int pa) {
	ans.push_back(u);
	sort(G[u].begin(),G[u].end());
	for(int v : G[u])
		if(v != pa)
			dfs3(v,u);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> d;
	for(int i=1,u,v;i<n;i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs1(1,1);
	root = -1;
	dfs2(1,1,1);
	
	if(root == -1) {
		cout << -1 << '\n';
	}
	else {
		dfs3(root,root);
		
		for(int i=0;i<n;i++) {
			if(i != 0)	cout << " ";
			cout << ans[i];
		}
		cout << '\n';
	}
	return 0;
}

/*
7 4
1 2
1 7
1 6
3 2
3 4
5 3

6 5
1 2
2 3
3 4
4 5
5 6

7 4
1 3
1 2
2 4
2 5
3 7
3 6
*/

