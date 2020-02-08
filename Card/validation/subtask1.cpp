// subtask 1
#include<bits/stdc++.h>
#define maxn 300005
#define ll long long
using namespace std;
int ans[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1,val;i<=n;i++)
		cin >> val;
	for(int i=1,val;i<=n;i++)
		cin >> val , ans[val] = i;
	ll k;
	cin >> k;
	
	for(int i=1;i<=n;i++) {
		if(i!=1)	cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}

