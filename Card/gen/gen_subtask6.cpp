// subtask 6 : n <= 300000
#include "mylib.hpp"

#define path "../tests/6"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int kase=1;kase<=6;kase++) {
		int n = 300000;
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
			if(kase == 2)	{ // n^0.5
				int sqrt_sz = sqrt(n);
				for(int t=0;t<n/sqrt_sz;t++)
					cyc_sz.emplace_back(sqrt_sz);
				cyc_sz.emplace_back(n % sqrt_sz);
			}
			else if(kase == 3) {	// almost maximize lcm({cyc_sz}) (size of cycle of the whole sequence)
				vector<int> prime = Other::get_prime_table(n/10);
				Random::shuffle(prime);
				int tem = n;
				for(int val : prime)
					if(val <= tem) {
						cyc_sz.emplace_back(val);
						tem -= val;
					}
				if(tem > 0)
					cyc_sz.emplace_back(tem);
			}
			else if(kase == 4) { 	// almost maximize sum(i*i | i in cyc_sz)
				cyc_sz = {n-3,3};
			}
			else if(kase == 5) {	// |cyc_sz| is not large
				cyc_sz = {30000,29987,30013,50000,10000,29997,30003,29977,29980,30043};
			}
			else if(kase == 6) {	// |cyc_sz| is not small
				for(int i=0;i<n-7;i++)
					cyc_sz.emplace_back(1);
				cyc_sz.emplace_back(3);
				cyc_sz.emplace_back(4);
			}

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

			k = Random::random_64((long long)1e11,(long long)1e18);
		}

		Output::output(path,n,arr,nxt,k);
	}
	return 0;
}

