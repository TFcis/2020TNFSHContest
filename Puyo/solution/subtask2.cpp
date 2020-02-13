#include <bits/stdc++.h>
using namespace std;

int main() {
	char c;
	cin >> c >> c;
	int cnt = 2;
	for (int q = 0; q < 12; q++) {
		for (int w = 0; w < 6; w++) {
			cin >> c;
			if (c != '0') {
				cnt++;
			}
		}
	}
	cout << cnt / 4 << endl;
}
