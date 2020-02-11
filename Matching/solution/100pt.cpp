#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int l_arr[maxn],r_pos[maxn]; 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1,a,b;i<=n;i++) {
		cin >> a >> b;
		l_arr[i] = a;
		r_pos[b] = i;
	}
	bool rev = false;
	int ans = 0;
	for(int i=1;i<=n;i++) {
		if(i < r_pos[l_arr[i]]) {
			if(rev) {
				ans++;
				rev = !rev;
			}	
		}
		else if(i > r_pos[l_arr[i]]) {
			if(!rev){
				ans++;
				rev = !rev;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

