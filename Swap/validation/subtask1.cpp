// subtask 1
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	assert(1 <= n && n <= 500);
	int q;
	cin >> q;
	assert(1 <= q && q <= 500);
	while(q--) {
		int type;
		cin >> type;
		assert(type == 1 || type == 2);
		if(type == 1) {
			int a,b;
			cin >> a >> b;
			assert(a == b && 1 <= a && a <= n);
		}
		else {
			int l,r;
			cin >> l >> r;
			assert(1 <= l && l <= r && r <= n);
			cout << 0 << endl;
		}
	}
	return 0;
}

