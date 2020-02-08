#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
int arr[maxn],pos[maxn];
set<int> idxs;
void my_swap(int a,int b) {
	if(a == b)	return;
	swap(pos[arr[a]],pos[arr[b]]);
	swap(arr[a],arr[b]);
	for(int idx : {a,b})
		if(arr[idx] != idx)
			idxs.insert(idx);
		else if(idxs.count(idx) == 1)
			idxs.erase(idx);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
//	assert(1 <= n && n <= 500000);
	for(int i=1;i<=n;i++)
		arr[i] = i , pos[i] = i;
	int q;
	cin >> q;
//	assert(1 <= q && q <= 500000);
	while(q--) {
		int type;
		cin >> type;
//		assert(type == 1 || type == 2);
		if(type == 1) {
			int a,b;
			cin >> a >> b;
//			assert(1 <= a && a <= n && 1 <= b && b <= n);
			my_swap(a,b);
		}
		else {
			int l,r;
			cin >> l >> r;
//			assert(1 <= l && l <= r && r <= n);
			
			int ans = 0;
			while(true) {
				auto it = idxs.lower_bound(l);
				if(it == idxs.end() || *it > r)		break;
				my_swap(*it,pos[*it]);
				ans++;
			}
			
			cout << ans << '\n';
		}
	}
	return 0;
}

