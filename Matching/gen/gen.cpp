#include <bits/stdc++.h>
#include "testlib.h"
#define endl '\n'
using namespace std;

void gen_norm(int MIN_N, int MAX_N) {
	int N = rnd.next(MIN_N, MAX_N);

	cout<<N<<endl;

	vector<int> A, B;

	for(int q=1; q<=N; q++) {
		A.emplace_back(q);
		B.emplace_back(q);
	}

	shuffle(A.begin(), A.end());
	shuffle(B.begin(), B.end());

	for(int q=0; q<N; q++) {
		cout<<A[q]<<" "<<B[q]<<endl;
	}
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	registerGen(argc, argv, 1);

	string MODE = argv[1];

	if (MODE == "norm") {
		int MIN_N = atoi(argv[2]);
		int MAX_N = atoi(argv[3]);

		gen_norm(MIN_N, MAX_N);
	} else {
		return -1;
	}
}
