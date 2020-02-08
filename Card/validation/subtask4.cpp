// subtask 4
#include<bits/stdc++.h>
#define maxn 3005
#define ll long long
using namespace std;
int tran[maxn][maxn],mat[maxn];
int tem_tran[maxn][maxn],tem_mat[maxn];
void mul1(int n) {
	memset(tem_mat,0,sizeof tem_mat);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			tem_mat[i] += tran[i][j] * mat[j];
	for(int i=1;i<=n;i++)
		mat[i] = tem_mat[i];
}
void mul2(int n) {
	memset(tem_tran,0,sizeof tem_tran);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				tem_tran[i][j] += tran[i][k] * tran[k][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			tran[i][j] = tem_tran[i][j];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> mat[i];
	for(int i=1,nxt;i<=n;i++) {
		cin >> nxt;
		tran[nxt][i] = 1;
	}
	ll k;
	cin >> k;
	
	while(k > 0) {
		if(k & 1)	mul1(n);
		mul2(n);
		k >>= 1;
	}
	
	for(int i=1;i<=n;i++) {
		if(i!=1)	cout << " ";
		cout << mat[i];
	}
	cout << endl;
	return 0;
}

