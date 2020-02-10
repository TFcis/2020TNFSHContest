#include <bits/stdc++.h>
#include "testlib.h"
#define endl '\n'
using namespace std;

void gen_1color(int K) {
	int color = rnd.next(1, 5);

	cout<<color<<color<<endl;

	for (int q=0; q<11; q++) {
		cout<<"000000"<<endl;
	}

	int pos1 = -1;
	int pos2 = -1;
	if (K == 1) {
		pos1 = rnd.next(6);
	} else if (K == 2) {
		pos1 = rnd.next(0, 1);
		if (pos1 == 1) {
			pos2 = rnd.next(4, 5);
		} else {
			pos2 = 5;
		}
	}

	for (int q=0; q<6; q++) {
		if (q == pos1 || q == pos2) {
			cout<<color;
		} else {
			cout<<"0";
		}
	}
	cout<<endl;
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	registerGen(argc, argv, 1);

	string MODE = argv[1];

	if (MODE == "1color") {
		int K = atoi(argv[2]);

		gen_1color(K);
	} else {
		return -1;
	}
}
