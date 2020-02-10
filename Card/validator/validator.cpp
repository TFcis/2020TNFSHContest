#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main() {
	registerValidation();

	int N = inf.readInt(1, 300000);
	inf.readEoln();

	inf.readInt();
	for (int q = 1; q < N; q++) {
		inf.readSpace();
		inf.readInt();
	}
	inf.readEoln();

	inf.readInt();
	for (int q = 1; q < N; q++) {
		inf.readSpace();
		inf.readInt();
	}
	inf.readEoln();

	inf.readLong();
	inf.readEoln();

	inf.readEof();

	return 0;
}
