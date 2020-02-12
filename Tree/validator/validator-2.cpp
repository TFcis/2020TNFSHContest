#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main() {
	registerValidation();

	int N = inf.readInt(1, 100000);
	ensure(N <= 1000);
	inf.readSpace();
	int D = inf.readInt(1, 100000);
	inf.readEoln();

	for (int q = 0; q < N - 1; q++) {
		inf.readInt();
		inf.readSpace();
		inf.readInt();
		inf.readEoln();
	}

	inf.readEof();

	return 0;
}
