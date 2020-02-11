#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main() {
	registerValidation();

	int N = inf.readInt(1, 10);
	inf.readEoln();

	for (int q = 0; q < N; q++) {
		inf.readInt(1, N);
		inf.readSpace();
		inf.readInt(1, N);
		inf.readEoln();
	}

	inf.readEof();

	return 0;
}
