// subtask 2
#include<bits/stdc++.h>
#define maxn 3005
#define ll long long
using namespace std;
int arr[maxn][maxn];
int f[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> arr[0][i];
	for(int i=1;i<=n;i++)
		cin >> f[i];
	ll k;
	cin >> k;
	
	for(int t=1;t<=k;t++)
		for(int i=1;i<=n;i++)
			arr[t][f[i]] = arr[t-1][i];
	
	for(int i=1;i<=n;i++) {
		if(i!=1)	cout << " ";
		cout << arr[k][i];
	}
	cout << endl;
	return 0;
}

