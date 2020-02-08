#include<bits/stdc++.h>
using namespace std;

class Random {
	public:
		static int random(int l,int r) {
			static mt19937 Rand(chrono::steady_clock::now().time_since_epoch().count());
			return uniform_int_distribution<int>(l, r)(Rand);
		}
		static long long random_64(long long l,long long r) {
			static mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());
			return uniform_int_distribution<long long>(l, r)(Rand);
		}
		static bool random(double P) {
			assert(0.0<=P && P<=100.0);
			int now = P*10000;
			return random(1,10000*100) <= now;
		}
		template <class T>
		static void shuffle(vector<T> &v,int st=0,int sz=-1) {
			assert(0 <= st && st < (int)v.size());
			assert(sz == -1 || (sz > 0 && st + sz <= (int)v.size()));
			static mt19937 Rand(chrono::steady_clock::now().time_since_epoch().count());
			std::shuffle(v.begin()+st,(sz==-1 ? v.end() : v.begin()+st+sz),Rand);
		}
};

class Other {
	public:
		static long long string_to_int(string s) {		// assume int(s) is a valid and 64-bit number
			long long ret = 0 , coe = 1;
			for(char c : s)
				if(c == '-')
					coe = -1;
				else
					ret = ret * 10 + c - '0';
			return coe * ret;
		}
		static string int_to_string(long long val) {
			if(val == 0)	return "0";
			
			bool neg = false;
			if(val < 0) {
				neg = true;
				val = -val;
			}
			
			string ret = "";
			while(val > 0) {
				ret += (char)(val % 10 + '0');
				val /= 10;
			}
			if(neg)		ret += "-";
			reverse(ret.begin(),ret.end());
			return ret;
		}
		static vector<int> get_prime_table(int n) {
			assert(1 <= n && n <= 1000000);
			vector<int> ret;
			vector<bool> vis(n+5,false);
			for(int i=2;i<=n;i++) {
				if(!vis[i])	ret.emplace_back(i);
				for(int j=0;i*ret[j] <= n;j++) {
					vis[i*ret[j]] = true;
					if(i % ret[j] == 0)	break;
				}
			}
			return ret;
		}
};

class Output {
	public:
		// file format : "../testdata/5" (generate 5th subtask in "../testdata")
		static void output(string file,int n,vector<int> &arr,vector<int> &nxt,long long k) {
			// check the range of task
			check(n,arr,nxt,k);

			// file name setting 
			static int task_idx = 1;
			if(task_idx < 10)	file += "0";
//			assert(task_idx<10);		// too many task , judge will feel tired :(
			file += Other::int_to_string(task_idx);
			file += ".in";
			
			task_idx++;
			freopen(file.c_str(),"w",stdout);
		//=======================================
			#define endl '\n'
			cout << n << endl;
			for(auto &cont : {arr,nxt}) {
				for(int i=0;i<n;i++) {
					if(i!=0)	cout << " ";
					cout << cont[i];
				}
				cout << endl;
			}
			cout << k << endl;
		//=======================================
			cout.flush();
		}
	private:
		static const int maxn = 300000;
		static const long long maxk = 1000000000000000000ll;
		static void check(const int n,const vector<int> &arr,const vector<int> &nxt,const long long k) {
			assert(1 <= n && n <= maxn);
			assert(n == (int)arr.size() && n == (int)nxt.size());
			assert(0 <= k && k <= maxk);
			vector<bool> vis(n,false);
			for(auto &cont : {arr,nxt}) {
				fill(vis.begin(),vis.end(),false);
				for(int val : cont) {
					assert(1 <= val && val <= n);
					assert(!vis[val-1]);
					vis[val-1] = true;
				}
			}
		}
};
