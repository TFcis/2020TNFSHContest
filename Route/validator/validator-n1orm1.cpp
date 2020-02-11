#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main() {
	registerValidation();

	int N = inf.readInt(1, 1000);
	inf.readSpace();
	int M = inf.readInt(1, 1000);
	inf.readEoln();

	ensure(N * M == max(N, M));  // task 2

	char format[100];
	sprintf(format, "[0-9]{%d}", M);

	for (int q = 0; q < N; q++) {
		inf.readToken(format);
		inf.readEoln();
	}

	inf.readEof();

	return 0;
}
