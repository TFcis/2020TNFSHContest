// subtask 4 : n <= 100
#include "mylib.hpp"

#define path "../testdata/4"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int kase=1;kase<=4;kase++) {
		int n = 100;
		vector<int> arr(n),nxt(n);
		iota(arr.begin(),arr.end(),1);
		iota(nxt.begin(),nxt.end(),1);
		long long k = -1;
		
		if(kase == 1) {		// random case
			Random::shuffle(arr);
			Random::shuffle(nxt);
			k = Random::random_64(0,(long long)1e18);
		}
		else {
			Random::shuffle(arr);
					
			vector<int> cyc_sz;
			if(kase==4)	// n^0.5
				cyc_sz = {10,10,10,10,10,10,10,10,10,10};
			else if(kase==2)	// maximize lcm({cyc_sz}) (size of cycle of the whole sequence)
				cyc_sz = {23,19,17,13,11,7,5,3,2};
			else 	// almost maximize sum(i*i | i in cyc_sz)
				cyc_sz = {98,2};
			
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
			
			k = Random::random_64((long long)1e17,(long long)1e18);
		}
		
		Output::output(path,n,arr,nxt,k);
	}
	return 0;
}

