#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main() {
	registerValidation();

	int N = inf.readInt(1, 500000);
	inf.readSpace();
	ensure(N <= 500);
	int Q = inf.readInt(1, 500000);
	inf.readEoln();
	ensure(Q <= 500);

	for (int q = 0; q < Q; q++) {
		int t = inf.readInt();
		inf.readSpace();
		int a = inf.readInt();
		inf.readSpace();
		int b = inf.readInt();
		inf.readEoln();
		if (t == 1) {
			ensure(a == b);
		}
	}

	inf.readEof();

	return 0;
}
