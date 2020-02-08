// subtask 3
#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
int arr[maxn],pos[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
//	assert(1 <= n && n <= 5000);
	for(int i=1;i<=n;i++)
		arr[i] = pos[i] = i;
	int q;
	cin >> q;
//	assert(1 <= q && q <= 5000);
	while(q--) {
		int type;
		cin >> type;
//		assert(type == 1 || type == 2);
		if(type == 1) {
			int a,b;
			cin >> a >> b;
//			assert(1 <= min(a,b) && max(a,n) <= n);
			swap(pos[arr[a]],pos[arr[b]]);
			swap(arr[a],arr[b]);
		}
		else {
			int l,r;
			cin >> l >> r;
//			assert(1 <= l && l <= r && r <= n);
			
			int ans = 0;
			for(int i=l;i<=r;i++)
				if(arr[i] != i) {
					int a = i , b = pos[i];
					swap(pos[arr[a]],pos[arr[b]]);
					swap(arr[a],arr[b]);
					ans++;
				}
				
			cout << ans << endl;
		}
	}
	return 0;
}

