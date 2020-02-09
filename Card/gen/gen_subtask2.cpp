// subtask 2 : n <= 10 and k <= 100
#include "mylib.hpp"

#define path "../tests/2"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int kase=1;kase<=4;kase++) {
		int n = 10;
		vector<int> arr(n),nxt(n);
		iota(arr.begin(),arr.end(),1);
		iota(nxt.begin(),nxt.end(),1);
		long long k = -1;

		if(kase == 1) {		// random case
			Random::shuffle(arr);
			Random::shuffle(nxt);
			k = Random::random(0,100);
		}
		else {
			Random::shuffle(arr);

			vector<int> cyc_sz;
			if(kase==2)
				cyc_sz = {10};
			else if(kase==3)
				cyc_sz = {2,2,2,2,2};
			else
				cyc_sz = {2,3,5};

			{
				int tem = 0;
				for(int sz : cyc_sz)
					tem += sz;
				assert(tem == n);
			}

			vector<int> tem(n);
			iota(tem.begin(),tem.end(),1);
			Random::shuffle(tem);

			for(int sz : cyc_sz) {
				for(int i=0;i<sz;i++) {
					int u = tem[(int)tem.size()-1-i];
					int v = (i==sz-1 ? tem.back() : tem[(int)tem.size()-1-i-1]);
					nxt[u-1] = v;
				}
				for(int i=0;i<sz;i++)
					tem.pop_back();
			}

			k = Random::random(90,100);
		}

		Output::output(path,n,arr,nxt,k);
	}
	return 0;
}

