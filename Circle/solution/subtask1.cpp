// subtask 1
#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
vector<int> G[maxn];
vector<int> ans;
void dfs(int u,int pa) {
	ans.push_back(u);
	for(int v : G[u])
		if(v != pa)
			dfs(v,u);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,d;
	cin >> n >> d;
	for(int i=1,u,v;i<n;i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		sort(G[i].begin(),G[i].end());
	dfs(1,1);
	for(int i=0;i<n;i++) {
		if(i!=0)	cout << " ";
		cout << ans[i];
	}
	cout << '\n';
	return 0;
}

