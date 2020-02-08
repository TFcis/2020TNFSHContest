// subtask 2 : n,q <= 500
#include "mylib.hpp"

#define path "../testdata/2"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int kase=1;kase<=3;kase++) {
		int n = -1 , q = -1;
		vector<op> ops;

		if(kase == 1) {		// sample
			n = 6;	q = 7;
			ops.emplace_back(op{1,1,2,-1,-1});
			ops.emplace_back(op{1,2,3,-1,-1});
			ops.emplace_back(op{1,4,4,-1,-1});
			ops.emplace_back(op{2,-1,-1,4,4});
			ops.emplace_back(op{1,5,6,-1,-1});
			ops.emplace_back(op{2,-1,-1,1,4});
			ops.emplace_back(op{2,-1,-1,3,6});
		}
		else { // random case
			n = q = 500;
			ops.reserve(q);
			for(int t=0;t<q;t++) {
				op now = {-1,-1,-1,-1,-1};
				now.type = Random::random(1,2);
				if(now.type == 1) {
					now.a = Random::random(1,n);
					now.b = Random::random(1,n);
				}
				else {
					now.l = Random::random(1,n);
					now.r = Random::random(1,n);
					if(now.l > now.r)	swap(now.l,now.r);
				}
				
				ops.emplace_back(now);
			}
		}
		
		Output::output(path,n,q,ops);
	}
	return 0;
}

