// subtask 1 : permutation = {1,2,3,...n} and n <= 10 and k = 1
#include "mylib.hpp"

#define path "../tests/1"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int kase=1;kase<=3;kase++) {
		int n = -1;
		vector<int> arr,nxt;
		long long k = -1;

		if(kase == 1) {		// sample 1
			n = 5;
			arr = {1,2,3,4,5};
			nxt = {3,1,4,5,2};
			k = 1;
		}
		else if(kase == 2) {	// random case
			n = 10;
			for(int i=1;i<=n;i++) {
				arr.push_back(i);
				nxt.push_back(i);
			}
			Random::shuffle(nxt);
			k = 1;
		}
		else {
			n = 10;
			for(int i=1;i<=n;i++) {
				arr.push_back(i);
				nxt.push_back(i);
			}
			Random::shuffle(nxt,0,5);
			Random::shuffle(nxt,6,4);
			k = 1;
		}

		Output::output(path,n,arr,nxt,k);
	}
	return 0;
}

