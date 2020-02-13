// By xiplus
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> A, B;
	int a, b;
	for (int q = 0; q < N; q++) {
		cin >> a >> b;
		A.emplace_back(a);
		B.emplace_back(b);
	}

	vector<int> A2(A.begin(), A.end());
	sort(A2.begin(), A2.end());
	for (int q = 0; q < N; q++) {
		A[q] = lower_bound(A2.begin(), A2.end(), A[q]) - A2.begin();
	}

	vector<int> B2(B.begin(), B.end());
	sort(B2.begin(), B2.end());
	for (int q = 0; q < N; q++) {
		B[q] = lower_bound(B2.begin(), B2.end(), B[q]) - B2.begin();
	}

	for (int q = 0; q < N; q++) {
		B2[B[q]] = q;
	}

	int dir = 0;
	int ans = 0;
	for (int q = 0; q < N; q++) {
		if (dir == 0) {
			if (B2[A[q]] < q) {
				ans++;
				dir = 1;
			}
		} else {
			if (B2[A[q]] >= q) {
				ans++;
				dir = 0;
			}
		}
	}
	cout << ans << endl;

	return 0;
}
