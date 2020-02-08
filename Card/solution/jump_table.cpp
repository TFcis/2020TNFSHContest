// 倍增法 O(n log k) 
#include<bits/stdc++.h>
#define maxn 300005
#define ll long long
using namespace std;
int arr[maxn],nxt[61][maxn];
int ans[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) 
		cin >> arr[i];
	for(int i=1;i<=n;i++)
		cin >> nxt[0][i];
	ll k;
	cin >> k;
	
	for(int i=1;i<=60;i++)
		for(int j=1;j<=n;j++)
			nxt[i][j] = nxt[i-1][nxt[i-1][j]];
	for(int i=1;i<=n;i++) {
		int u = i , cur = 0;
		ll tem = k;
		while(tem > 0) {
			if(tem&1)	u = nxt[cur][u];
			tem >>= 1;
			cur++;
		}
		ans[u] = arr[i];
	}
	
	for(int i=1;i<=n;i++) {
		if(i!=1)	cout << " ";
		cout << ans[i];
	}
	cout << '\n';
	return 0;
}

