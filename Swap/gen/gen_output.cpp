#include "mylib.hpp"

inline string int_to_string(int val) {
	return (val < 10 ? "0" : "") + Other::int_to_string(val);
}
int main() {
	const int subtask_number = 4;
	int task_number[subtask_number] = {3,3,3,8};    // tot 17
	for(int i=1;i<=subtask_number;i++) {
		for(int j=1;j<=task_number[i-1];j++) {
			string id = (char)(i + '0') + int_to_string(j);
			string path = "../tests/";

			string in = path + id + ".in";
			string out = path + id + ".out";

			string op = "100pt.exe";

			op = op + " < " + in + " > " + out;
//			op = op + " < " + in;
			cout << op << endl;
			double t1 = clock();
			system(op.c_str());
			cout << clock()-t1 << " ms" << endl;
		}
	}
	return 0;
}

