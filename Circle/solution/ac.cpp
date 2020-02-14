#include <iostream>
#include <vector>
#include <algorithm>
#define mx 100005
#define int long long
using namespace std;
typedef pair<int,int> pii;
vector<int> G[mx];
struct data {
	pii one, two;  // 最遠, 次遠
} D[mx];
int dfs_pre(int x, int fa) {
	for ( int i : G[x] )
		if ( i != fa ) {
			int temp = dfs_pre(i,x) + 1;
			if ( temp > D[x].two.second )
				D[x].two.first = i, D[x].two.second = temp;
			if ( D[x].two.second > D[x].one.second )
				swap(D[x].one,D[x].two);
		}
	return D[x].one.second;
}
void dfs_ans(int x, int fa, int w) {
	for ( int i : G[x] )
		if ( i != fa ) {
			if ( i != D[x].one.first ) {
				if ( D[i].one.second < D[x].one.second+1 ) {
					D[i].one.first = x;
					D[i].one.second = D[x].one.second+1;
				} else if ( D[i].two.second < D[x].one.second+1 ) {
					D[i].two.first = x;
					D[i].two.second = D[x].one.second+1;
				}
			} else if ( i != D[x].two.first ) {
				if ( D[i].one.second < D[x].two.second+1 ) {
					D[i].one.first = x;
					D[i].one.second = D[x].two.second+1;
				} else if ( D[i].two.second < D[x].two.second+1 ) {
					D[i].two.first = x;
					D[i].two.second = D[x].two.second+1;
				}
			}
			dfs_ans(i,x,w+1);
		}
}
vector<int> ans;
void dfs_min(int x, int fa) {
	ans.emplace_back(x);
	sort(G[x].begin(), G[x].end());
	for ( int i : G[x] ) {
		if ( i == fa )	continue;
		dfs_min(i,x);
	}
}
int32_t main()  {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, d;
	cin >> n >> d;
	for ( int i=1; i<n; i++ ) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs_pre(1,0);
	dfs_ans(1,0,0);
	int st = 0;
	for ( int i=1; i<=n; ++i ) {
		// cout << D[i].one.second << ' ';
		if ( D[i].one.second+1 < d ) {
			st = i;
			break;
		}
	}
	// cout << '\n';
	if ( st == 0 )	cout << -1 << '\n';
	else {
		dfs_min(st,st);
		bool firstitem = true;
		for ( int i : ans ) {
			if (!firstitem) {
				cout << ' ';
			}
			cout << i;
			firstitem = false;
		}
		cout << '\n';
	}
	// for ( int i=1; i<=n; ++i ) {
	// 	cout << D[i].one.second << '\n';
	// }
	// int ans = D[1].one.second;
	// for ( int i=2; i<=n; i++ )
	// 	ans ^= D[i].one.second;
	// cout << ans << '\n';
	return 0;
}