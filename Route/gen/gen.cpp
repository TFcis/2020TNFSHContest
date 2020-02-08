#include <bits/stdc++.h>
#include "testlib.h"
#define endl '\n'
using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	registerGen(argc, argv, 1);

	int MAX_N = atoi(argv[1]);
	int MAX_M = atoi(argv[2]);

	int N = rnd.next(MAX_N/10, MAX_N);
	int M = rnd.next(MAX_M/10, MAX_M);

	cout<<N<<" "<<M<<endl;

	for(int q=0; q<N; q++) {
		for(int w=0; w<M; w++) {
			cout<<rnd.next(0, 9);
		}
		cout<<endl;
	}
}
