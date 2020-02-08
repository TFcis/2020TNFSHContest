// subtask 5
#include<bits/stdc++.h>
#define maxn 300005
#define ll long long
using namespace std;
int arr[maxn],nxt[maxn];
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
	
	for(int i=1;i<=n;i++) {
		int u = nxt[i] , cyc = 1;
		while(u != i) {
			u = nxt[u];
			cyc++;
		}
		int step = k % cyc;
		u = i;
		while(step--)
			u = nxt[u];
		ans[u] = arr[i];
	}
	
	for(int i=1;i<=n;i++) {
		if(i!=1)	cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}

