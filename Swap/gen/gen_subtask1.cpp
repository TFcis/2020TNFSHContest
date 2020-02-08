// subtask 1 : n,q <= 500 and a = b
#include "mylib.hpp"

#define path "../testdata/1"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int kase=1;kase<=3;kase++) {
		int n = Random::random(100,500) , q = Random::random(100,500);
		vector<op> ops;
		
		// random case
		ops.reserve(q);
		for(int t=0;t<q;t++) {
			op now = {-1,-1,-1,-1,-1};
			now.type = Random::random(1,2);
			if(now.type == 1)
				now.a = now.b = Random::random(1,n);
			else {
				now.l = Random::random(1,n);
				now.r = Random::random(1,n);
				if(now.l > now.r)	swap(now.l,now.r);
			}
			
			ops.emplace_back(now);
		}
		
		Output::output(path,n,q,ops);
	}
	return 0;
}

