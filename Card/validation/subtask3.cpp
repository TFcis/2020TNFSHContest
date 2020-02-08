// subtask 3
#include<bits/stdc++.h>
#define ll long long
#define maxn 300005
using namespace std;
int n;
int arr[maxn],nxt[maxn];
int brr[maxn];
void move() {
	for(int i=1;i<=n;i++)
		brr[nxt[i]] = arr[i];
	for(int i=1;i<=n;i++)
		arr[i] = brr[i];
}
string get_string() {
	string ret = "";
	for(int i=1;i<=n;i++)
		ret += (char)(arr[i]);
	return ret;
}
set<string> vis;
inline int cal() {
	int ret = 0;
	while(true) {
		string str = get_string();
		if(vis.count(str)==1)	break;
		vis.insert(str);
		move();
		ret++;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> arr[i];
	for(int i=1;i<=n;i++)
		cin >> nxt[i];
	ll k;
	cin >> k;
	
	int cyc = cal();
	k %= cyc;
	while(k--)
		move();
		
	for(int i=1;i<=n;i++) {
		if(i!=1)	cout << " ";
		cout << arr[i];
	}
	cout << endl;
	return 0;
}

