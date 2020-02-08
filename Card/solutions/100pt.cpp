#include<bits/stdc++.h>
#define maxn 300005
#define ll long long
using namespace std;
int arr[maxn],nxt[maxn];
vector<int> cyc[maxn];
int src[maxn],pos[maxn];
void dfs(int u,int s) {
	src[u] = s;
	pos[u] = (int)cyc[s].size();
	cyc[s].emplace_back(u);
	if(pos[nxt[u]] == -1)
		dfs(nxt[u],s);
}
int ans[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> arr[i];
	for(int i=1;i<=n;i++)
		cin >> nxt[i];
	ll k;
	cin >> k;
	
	memset(pos,-1,sizeof pos);
	for(int i=1;i<=n;i++)
		if(pos[i] == -1)
			dfs(i,i);
	for(int i=1;i<=n;i++) {
		int step = k % (ll)cyc[src[i]].size();
		int idx = (pos[i] + step) % (int)cyc[src[i]].size();
		ans[cyc[src[i]][idx]] = arr[i];
	}
	
	for(int i=1;i<=n;i++) {
		if(i!=1)	cout << " ";
		cout << ans[i];
	}
	cout << '\n';
	return 0;
}

