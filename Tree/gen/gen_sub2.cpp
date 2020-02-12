#include <bits/stdc++.h>
using namespace std;
const int MINN = 80000;
const int MAXN = 100000;
const int MIND = 10;
int p[MAXN+5];
int getN[11] = {0, 888, 999, 1000, 898, 989,
				   998, 912, 1000, 808, 971};
int getD[11] = {0,  39,  41,   58,  38,  29,
				    35, 912,   42,  33,  31};

bool ign[11] = {0, 1, 0, 1, 1, 1,
				   1, 1, 1, 1, 1};
int find(int x) {
	return (p[x]==x ? x : (p[x]=find(p[x])));
}
int main() {
	srand(time(NULL));
	ios::sync_with_stdio(false);
	cin.tie(0);
	const string FILE_PREFIX = "02";
	for ( int i=1; i<=10; ++i ) {
		if ( ign[i] )	continue;
		string filename = FILE_PREFIX;
		filename.push_back('0'+i/10);
		filename.push_back('0'+i%10);
		filename += ".in";
		FILE *pF = fopen(filename.c_str(), "w");
		const int N = getN[i];
		const int D = getD[i];
		assert(1 <= N && N <= 1000);
		assert(1 <= D && D <= N);
		fprintf(pF, "%d %d\n", N, D);
		for ( int i=1; i<=N; ++i )	p[i] = i;
		int edge = 0;
		while ( edge < N-1 ) {
			int u = 1 + rand()%N;
			int v = 1 + rand()%N;
			if ( find(u) != find(v) ) {
				p[find(v)] = find(u);
				assert(1 <= u && u <= N);
				assert(1 <= v && v <= N);
				fprintf(pF, "%d %d\n", u, v);
				edge++;
			}
		}
		fclose(pF);
	}
	return 0;
}