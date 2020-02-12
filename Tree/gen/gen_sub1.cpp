#include <bits/stdc++.h>
using namespace std;
const int MINN = 80000;
const int MAXN = 100000;
const int MIND = 10;
int p[MAXN+5];
int getN[11] = {0, 8888, 99999, 100000, 89898, 98989,
				   59887, 99999, 100000, 8898, 98989};
// int getD[11] = {0, 999,   171,   258  ,  89898, 199,
				   // 195 ,   171,   226,    196  , 123 };

// bool ign[11] = {0, 1, 1, 1, 1, 0,
				   // 1, 1, 1, 1, 1};
int find(int x) {
	return (p[x]==x ? x : (p[x]=find(p[x])));
}
typedef pair<int,int> pii;
vector<pii> E;
vector<int> G[MAXN+5];
int D[MAXN+5];
void dfs(int x, int fa) {
	for ( int i : G[x] ) {
		if ( i == fa )	continue;
		D[i] = D[x]+1;
		dfs(i,x);
	}
}
int main() {
	srand(time(NULL));
	ios::sync_with_stdio(false);
	cin.tie(0);
	const string FILE_PREFIX = "01";
	for ( int i=1; i<=10; ++i ) {
		// if ( ign[i] )	continue;
		string filename = FILE_PREFIX;
		filename.push_back('0'+i/10);
		filename.push_back('0'+i%10);
		filename += ".in";
		const int N = getN[i];

		memset(D,0,sizeof(D));
		for ( int i=0; i<=N; ++i )	G[i].clear();
		E.clear();
		for ( int i=1; i<=N; ++i )	p[i] = i;


		// const int D = getD[i];
		// fprintf(pF, "%d %d\n", N, D);
	
		int edge = 0;
		while ( edge < N-1 ) {
			int u = 1 + rand()%N;
			int v = 1 + rand()%N;
			if ( find(u) != find(v) ) {
				p[find(v)] = find(u);
				E.emplace_back(pii{u,v});
				G[u].emplace_back(v);
				G[v].emplace_back(u);
				// fprintf(pF, "%d %d\n", u, v);
				edge++;
			}
		}
		D[1] = 1;
		dfs(1,1);
		int idx = 2;
		for ( int i=3; i<=N; ++i )
			if ( D[i] > D[idx] )	idx = i;
		D[idx] = 1;
		dfs(idx,idx);
		int ans = 1;
		for ( int i=2; i<=N; ++i )
			if ( D[i] > D[ans] )	ans = i;
		int mn = D[ans] + 1;

		FILE *pF = fopen(filename.c_str(), "w");

		fprintf(pF, "%d %d\n", N, mn+rand()%(N-mn+1));
		for ( pii i : E ) {
			assert(1 <= i.first && i.first <= N);
			assert(1 <= i.second && i.second <= N);
			fprintf(pF, "%d %d\n", i.first, i.second);
		}
		fclose(pF);
	}
	return 0;
}