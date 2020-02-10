// Source: https://github.com/MikeMirzayanov/testlib/blob/master/checkers/fcmp.cpp
#include <sstream>
#include <string>
#include <vector>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
	setName("compare files as sequence of lines");
	registerTestlibCmd(argc, argv);

	std::string strAnswer;

	int n = 0;
	while (!ans.eof()) {
		std::string j = ans.readString();

		if (j == "" && ans.eof())
			break;

		strAnswer = j;
		std::string p = ouf.readString();

		n++;

		if (j != p)
			quitf(_wa, "Wrong Answer: %d%s lines differ - expected: '%s', found: '%s'", n, englishEnding(n).c_str(), compress(j).c_str(), compress(p).c_str());
	}

	quitf(_ok, "Accepted");
}
