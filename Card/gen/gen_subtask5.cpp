// subtask 5 : n <= 3000
#include "mylib.hpp"

#define path "../tests/5"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int kase=1;kase<=6;kase++) {
		int n = 3000;
		vector<int> arr(n),nxt(n);
		iota(arr.begin(),arr.end(),1);
		iota(nxt.begin(),nxt.end(),1);
		long long k = -1;

		if(kase == 6) {		// random case
			Random::shuffle(arr);
			Random::shuffle(nxt);
			k = Random::random_64(0,(long long)1e18);
		}
		else {
			Random::shuffle(arr);

			vector<int> cyc_sz;
			if(kase == 1)	{ // n^0.5
				int sqrt_sz = sqrt(n);
				for(int t=0;t<n/sqrt_sz;t++)
					cyc_sz.emplace_back(sqrt_sz);
				cyc_sz.emplace_back(n % sqrt_sz);
			}
			else if(kase == 2) {	// almost maximize lcm({cyc_sz}) (size of cycle of the whole sequence)
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
			else if(kase == 3) { 	// almost maximize sum(i*i | i in cyc_sz)
				cyc_sz = {2998,2};
			}
			else if(kase == 4) {	// |cyc_sz| is not large
				cyc_sz = {300,299,301,500,100,297,303,290,289,321};
			}
			else if(kase == 5) {	// |cyc_sz| is not small
				for(int i=0;i<n-5;i++)
					cyc_sz.emplace_back(1);
				cyc_sz.emplace_back(2);
				cyc_sz.emplace_back(3);
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

			k = Random::random_64((long long)1e17,(long long)1e18);
		}

		Output::output(path,n,arr,nxt,k);
	}
	return 0;
}

