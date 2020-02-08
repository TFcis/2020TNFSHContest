#include <bits/stdc++.h>
#include "testlib.h"
#define endl '\n'
using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	registerGen(argc, argv, 1);

	int MIN_N = atoi(argv[1]);
	int MAX_N = atoi(argv[2]);
	int MIN_M = atoi(argv[3]);
	int MAX_M = atoi(argv[4]);

	int N = rnd.next(MIN_N, MAX_N);
	int M = rnd.next(MIN_M, MAX_M);

	cout<<N<<" "<<M<<endl;

	int arr[N+18][M+18];
	memset(arr, -1, sizeof(arr));

	int R = N*M/10;

	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};
	int d, nx, ny;

	vector<pair<int, int>> notused;
	for(int q=9; q<N+9; q++) {
		for(int w=9; w<M+9; w++) {
			notused.push_back({q, w});
		}
	}
	shuffle(notused.begin(), notused.end());

	for(int e=notused.size()-1; e>=0; e--){
		int x = notused[e].first;
		int y = notused[e].second;
		if (arr[x][y] != -1) {
			continue;
		}
		arr[x][y] = 0;
		set<pair<int, int>> path;
		path.insert({x, y});
		int c = 0;
		for(int q=1; q<=9; q++) {
			for(int w=0; w<4; w++) {
				d = rnd.next(4);
				nx = x+dx[d];
				ny = y+dy[d];
//				cout<<q<<" "<<nx<<" "<<ny<<endl;
				if(path.count({nx, ny}) == 0) {
					x = nx;
					y = ny;
					c++;
					arr[x][y] = c;
					break;
				}
			}
			if (c != q) { // No path
//				cout<<R<<" no path "<<q<<endl;
				break;
			}
		}
	}
	for(int q=9; q<N+9; q++) {
		for(int w=9; w<M+9; w++) {
			cout<<arr[q][w];
		}
		cout<<endl;
	}
}
