#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main() {
	registerValidation();

	int N = inf.readInt(1, 500000);
	inf.readSpace();
	ensure(N <= 5000);
	int Q = inf.readInt(1, 500000);
	inf.readEoln();
	ensure(Q <= 5000);

	for (int q = 0; q < Q; q++) {
		inf.readInt();
		inf.readSpace();
		inf.readInt();
		inf.readSpace();
		inf.readInt();
		inf.readEoln();
	}

	inf.readEof();

	return 0;
}
