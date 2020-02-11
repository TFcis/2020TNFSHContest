#include <bits/stdc++.h>
#include "testlib.h"
#define endl '\n'
using namespace std;

void gen_norm(int MIN_N, int MAX_N, int MIN_M, int MAX_M) {
	int N = rnd.next(MIN_N, MAX_N);
	int M = rnd.next(MIN_M, MAX_M);

	cout << N << " " << M << endl;

	int arr[N + 18][M + 18];
	memset(arr, -1, sizeof(arr));

	int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
	int dy[] = {1, -1, 1, 0, -1, 1, 0, -1};
	int d, nx, ny;

	vector<pair<int, int>> notused;
	for (int q = 9; q < N + 9; q++) {
		for (int w = 9; w < M + 9; w++) {
			notused.push_back({q, w});
		}
	}
	shuffle(notused.begin(), notused.end());

	for (int e = notused.size() - 1; e >= 0; e--) {
		int x = notused[e].first;
		int y = notused[e].second;
		if (arr[x][y] != -1) {
			continue;
		}
		arr[x][y] = 0;
		set<pair<int, int>> path;
		path.insert({x, y});
		int c = 0;
		for (int q = 1; q <= 9; q++) {
			for (int w = 0; w < 8; w++) {
				d = rnd.next(8);
				nx = x + dx[d];
				ny = y + dy[d];
				//				cout<<q<<" "<<nx<<" "<<ny<<endl;
				if (path.count({nx, ny}) == 0) {
					x = nx;
					y = ny;
					c++;
					arr[x][y] = c;
					break;
				}
			}
			if (c != q) {  // No path
						   //				cout<<R<<" no path "<<q<<endl;
				break;
			}
		}
	}
	for (int q = 9; q < N + 9; q++) {
		for (int w = 9; w < M + 9; w++) {
			cout << arr[q][w];
		}
		cout << endl;
	}
}

void gen_nm1(int dir, int MIN_N, int MAX_N) {
	int N = rnd.next(MIN_N, MAX_N);

	if (dir == 1) {
		cout << 1 << " " << N << endl;
	} else {
		cout << N << " " << 1 << endl;
	}

	int arr[N + 18];
	memset(arr, -1, sizeof(arr));

	vector<int> notused;
	for (int q = 9; q < N + 9; q++) {
		notused.push_back(q);
	}
	shuffle(notused.begin(), notused.end());

	for (int e = notused.size() - 1; e >= 0; e--) {
		int x = notused[e];
		if (arr[x] != -1) {
			continue;
		}
		arr[x] = 0;
		int d = rnd.next(1, 2);
		for (int q = 1; q <= 9; q++) {
			if (d == 1) {
				x++;
			} else {
				x--;
			}
			arr[x] = q;
		}
	}
	if (dir == 1) {
		for (int w = 9; w < N + 9; w++) {
			cout << arr[w];
		}
		cout << endl;
	} else {
		for (int w = 9; w < N + 9; w++) {
			cout << arr[w] << endl;
		}
	}
}

void gen_slope(int N, int M) {
	cout << N << " " << M << endl;

	for (int q = 0; q < N; q++) {
		for (int w = 0; w < M; w++) {
			cout << (q + w) % 10;
		}
		cout << endl;
	}
}

void gen_slope2(int N, int M) {
	cout << N << " " << M << endl;

	for (int q = 0; q < N; q++) {
		for (int w = 0; w < M; w++) {
			cout << 9 - abs((q + w) % 18 - 9);
		}
		cout << endl;
	}
}

void gen_straight(int MIN_N, int MAX_N, int MIN_M, int MAX_M) {
	int N = rnd.next(MIN_N, MAX_N);
	int M = rnd.next(MIN_M, MAX_M);

	cout << N << " " << M << endl;

	int arr[N + 18][M + 18];
	memset(arr, -1, sizeof(arr));

	int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
	int dy[] = {1, -1, 1, 0, -1, 1, 0, -1};
	int d, nx, ny;

	vector<pair<int, int>> notused;
	for (int q = 9; q < N + 9; q++) {
		for (int w = 9; w < M + 9; w++) {
			notused.push_back({q, w});
		}
	}
	shuffle(notused.begin(), notused.end());

	for (int e = notused.size() - 1; e >= 0; e--) {
		int x = notused[e].first;
		int y = notused[e].second;
		if (arr[x][y] != -1) {
			continue;
		}
		arr[x][y] = 0;
		int dircnt = rnd.next(1, 4);
		for (int q = 0; q < dircnt; q++) {
			int d = rnd.next(8);
			for (int w = 1; w <= 9; w++) {
				nx = x + dx[d];
				ny = y + dy[d];
				if (arr[nx][ny] != -1) {
					break;
				}
				bool ok = true;
				for (int e = 0; e < 8; e++) {
					if (arr[nx + dx[e]][ny + dy[e]] == w - 1 && !(nx + dx[e] == x && ny + dy[e] == y)) {
						ok = false;
						break;
					}
				}
				if (!ok) {
					break;
				}
				x = nx;
				y = ny;
				arr[x][y] = w;
			}
		}
	}
	for (int q = 9; q < N + 9; q++) {
		for (int w = 9; w < M + 9; w++) {
			cout << arr[q][w];
		}
		cout << endl;
	}
}

void gen_rhombus(int N, int M) {
	cout << N << " " << M << endl;

	int HALF_N = N / 2;
	int HALF_M = M / 2;

	for (int q = 0; q < N; q++) {
		for (int w = 0; w < M; w++) {
			cout << (abs(q - HALF_N) + abs(w - HALF_M)) % 10;
		}
		cout << endl;
	}
}

void gen_L(int N, int M) {
	cout << N << " " << M << endl;

	for (int q = 0; q < N; q++) {
		for (int w = 0; w < M; w++) {
			cout << max(q % 10, w % 10);
		}
		cout << endl;
	}
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	registerGen(argc, argv, 1);

	string MODE = argv[1];

	if (MODE == "norm") {
		int MIN_N = atoi(argv[2]);
		int MAX_N = atoi(argv[3]);
		int MIN_M = atoi(argv[4]);
		int MAX_M = atoi(argv[5]);

		gen_norm(MIN_N, MAX_N, MIN_M, MAX_M);
	} else if (MODE == "n1") {
		int MIN_M = atoi(argv[2]);
		int MAX_M = atoi(argv[3]);

		gen_nm1(1, MIN_M, MAX_M);
	} else if (MODE == "m1") {
		int MIN_N = atoi(argv[2]);
		int MAX_N = atoi(argv[3]);

		gen_nm1(2, MIN_N, MAX_N);
	} else if (MODE == "straight") {
		int MIN_N = atoi(argv[2]);
		int MAX_N = atoi(argv[3]);
		int MIN_M = atoi(argv[4]);
		int MAX_M = atoi(argv[5]);

		gen_straight(MIN_N, MAX_N, MIN_M, MAX_M);
	} else if (MODE == "slope") {
		int N = atoi(argv[2]);
		int M = atoi(argv[3]);

		gen_slope(N, M);
	} else if (MODE == "slope2") {
		int N = atoi(argv[2]);
		int M = atoi(argv[3]);

		gen_slope2(N, M);
	} else if (MODE == "rhombus") {
		int N = atoi(argv[2]);
		int M = atoi(argv[3]);

		gen_rhombus(N, M);
	} else if (MODE == "L") {
		int N = atoi(argv[2]);
		int M = atoi(argv[3]);

		gen_L(N, M);
	} else {
		cout << "FAIL" << endl;
		return -1;
	}
}
