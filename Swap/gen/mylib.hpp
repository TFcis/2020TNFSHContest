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
};

struct op {
	int type;
	int a,b;
	int l,r;
};

class Output {
	public:
		// file format : "../testdata/5" (generate 5th subtask in "../testdata")
		static void output(string file,int n,int q,vector<op> ops) {
			// check the range of task
			check(n,q,ops);

			// file name setting 
			static int task_idx = 1;
			if(task_idx < 10)	file += "0";
//			assert(task_idx<10);		// too many task , judge will feel tired :(
			file += Other::int_to_string(task_idx);;
			file += ".in";
			
			task_idx++;
			freopen(file.c_str(),"w",stdout);
		//=======================================
			#define endl '\n'
			cout << n << " " << q << endl;
			for(op now : ops) {
				cout << now.type << " ";
				if(now.type == 1)
					cout << now.a << " " << now.b << endl;
				else
					cout << now.l << " " << now.r << endl;
			}
		//=======================================
			cout.flush();
		}
	private:
		static void check(int n,int q,vector<op> ops) {
			assert(1 <= n && n <= 500000);
			assert(1 <= q && q <= 500000 && q == (int)ops.size());
			for(op now : ops) {
				assert(now.type == 1 || now.type == 2);
				if(now.type == 1)
					assert(1 <= min(now.a,now.b) && max(now.a,now.b) <= n);
				else
					assert(1 <= now.l && now.l <= now.r && now.r <= n);
			}
		}
};

