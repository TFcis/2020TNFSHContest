#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main() {
	registerValidation();

	inf.readToken("[1-5]{2}");
	inf.readEoln();

	for (int q = 0; q < 12; q++) {
		inf.readToken("[0-5]{6}");
		inf.readEoln();
	}

	inf.readEof();

	return 0;
}
