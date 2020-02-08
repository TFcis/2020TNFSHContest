// subtask 2
#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
int arr[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
//	assert(1 <= n && n <= 500);
	iota(arr+1,arr+1+n,1);
	int q;
	cin >> q;
//	assert(1 <= q && q <= 500);
	while(q--) {
		int type;
		cin >> type;
//		assert(type == 1 || type == 2);
		if(type == 1) {
			int a,b;
			cin >> a >> b;
//			assert(1 <= min(a,b) && max(a,n) <= n);
			swap(arr[a],arr[b]);
		}
		else {
			int l,r;
			cin >> l >> r;
//			assert(1 <= l && l <= r && r <= n);
			
			int ans = 0;
			for(int i=r;i>=l;i--)
				if(arr[i] != i) {
					for(int j=1;j<=n;j++)
						if(arr[j] == i) {
							swap(arr[i],arr[j]);
							break;
						}
					ans++;
				}
				
			cout << ans << endl;
		}
	}
	return 0;
}

