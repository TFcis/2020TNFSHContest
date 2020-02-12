#include <bits/stdc++.h>
using namespace std;
const int MINN = 80000;
const int MAXN = 100000;
const int MIND = 10;
int p[MAXN+5];
int getN[11] = {0, 88888, 99999, 100000, 89898, 98989,
				   99887, 99999, 100000, 89898, 98989};
int getD[11] = {0, 999,   171,   258  ,  89898, 199,
				   195 ,   171,   226,    196  , 123 };

// bool ign[11] = {0, 1, 1, 1, 1, 0,
				   // 1, 1, 1, 1, 1};
int find(int x) {
	return (p[x]==x ? x : (p[x]=find(p[x])));
}
int main() {
	srand(time(NULL));
	ios::sync_with_stdio(false);
	cin.tie(0);
	const string FILE_PREFIX = "03";
	for ( int i=1; i<=10; ++i ) {
		// if ( ign[i] )	continue;
		string filename = FILE_PREFIX;
		filename.push_back('0'+i/10);
		filename.push_back('0'+i%10);
		filename += ".in";
		FILE *pF = fopen(filename.c_str(), "w");
		const int N = getN[i];
		const int D = getD[i];
		fprintf(pF, "%d %d\n", N, D);
		for ( int i=1; i<=N; ++i )	p[i] = i;
		int edge = 0;
		while ( edge < N-1 ) {
			int u = 1 + rand()%N;
			int v = 1 + rand()%N;
			if ( find(u) != find(v) ) {
				p[find(v)] = find(u);
				fprintf(pF, "%d %d\n", u, v);
				edge++;
			}
		}
		fclose(pF);
	}
	return 0;
}