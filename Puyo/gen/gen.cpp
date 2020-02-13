#include <bits/stdc++.h>
#include "testlib.h"
#define endl '\n'
using namespace std;

void gen_1color(int K) {
	int color = rnd.next(1, 5);

	cout << color << color << endl;

	int cnt = rnd.next(1, 3);

	int arr[12][6];
	memset(arr, 0, sizeof(arr));

	while (cnt--) {
		int pos = rnd.next(6);
		arr[0][pos] = color;
		for (int q = 1; q < 12; q++) {
			if (arr[q][pos] == 0) {
				swap(arr[q][pos], arr[q - 1][pos]);
			} else {
				break;
			}
		}
	}

	for (int q = 0; q < 12; q++) {
		for (int w = 0; w < 6; w++) {
			cout << arr[q][w];
		}
		cout << endl;
	}
}

bool used[12][6];
int check_connected(int arr[12][6], int posy, int posx, int color) {
	// cout << "dfs " << posy << " " << posx << endl;
	if (used[posy][posx]) {
		return 0;
	}
	if (posy < 0 || posy >= 12 || posx < 0 || posx >= 6) {
		return 0;
	}
	if (arr[posy][posx] != color) {
		return 0;
	}
	used[posy][posx] = true;
	int ans = 1;
	ans += check_connected(arr, posy - 1, posx, color);
	ans += check_connected(arr, posy + 1, posx, color);
	ans += check_connected(arr, posy, posx - 1, color);
	ans += check_connected(arr, posy, posx + 1, color);
	return ans;
}

void gen_random(int K) {
	int Cnt = 30;

	int arr[12][6];
	memset(arr, 0, sizeof(arr));

	int colors[] = {1, 2, 3, 4, 5};
	shuffle(colors, colors + 5);

	int color = rnd.next(K);
	cout << colors[color] << colors[color] << endl;

	while (Cnt) {
		int dir = rnd.next(1, 2);
		int posx1, posy1, posx2, posy2;
		if (dir == 1) {  // 水平
			posx1 = rnd.next(0, 4);
			posx2 = posx1 + 1;
			if (arr[0][posx1] == 0 && arr[0][posx2] == 0) {
				for (int q = 11; q >= 0; q--) {
					if (arr[q][posx1] == 0) {
						posy1 = q;
						break;
					}
				}
				for (int q = 11; q >= 0; q--) {
					if (arr[q][posx2] == 0) {
						posy2 = q;
						break;
					}
				}
			} else {
				posx1 = -1;
			}
		} else {  // 垂直
			posx1 = rnd.next(0, 5);
			posx2 = posx1;
			if (arr[0][posx1] == 0 && arr[1][posx2] == 0) {
				for (int q = 11; q >= 0; q--) {
					if (arr[q][posx1] == 0) {
						posy1 = q;
						posy2 = q - 1;
						break;
					}
				}
			} else {
				posx1 = -1;
			}
		}

		if (posx1 != -1) {
			color = rnd.next(K);
			arr[posy1][posx1] = colors[color];
			arr[posy2][posx2] = colors[color];
			bool ok = true;
			memset(used, 0, sizeof(used));
			// cout << "------" << endl;
			if (check_connected(arr, posy1, posx1, colors[color]) >= 4) {
				ok = false;
			} else if (check_connected(arr, posy2, posx2, colors[color]) >= 4) {
				ok = false;
			}
			if (ok) {
				Cnt--;
				// cout << "ok " << posy1 << " " << posx1 << endl;
			} else {
				arr[posy1][posx1] = 0;
				arr[posy2][posx2] = 0;
			}
		}
	}

	for (int q = 0; q < 12; q++) {
		for (int w = 0; w < 6; w++) {
			cout << arr[q][w];
		}
		cout << endl;
	}
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	registerGen(argc, argv, 1);

	string MODE = argv[1];

	if (MODE == "1color") {
		int K = atoi(argv[2]);

		gen_1color(K);
	} else if (MODE == "random") {
		int K = atoi(argv[2]);

		gen_random(K);
	} else {
		return -1;
	}
}
