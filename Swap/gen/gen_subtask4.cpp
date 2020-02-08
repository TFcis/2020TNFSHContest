// subtask 4 : n,q <= 500000
#include "mylib.hpp"

#define path "../testdata/4"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int kase=1;kase<=8;kase++) {
		int n = -1 , q = -1;
		vector<op> ops;

		if(kase == 1) {		// random case
			n = q = 500000;
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
		else if(kase == 2) {	// 兩操作輪替且操作二長度足夠大 
			n = q = 500000;
			ops.reserve(q);
			for(int t=0;t<q;t+=2) {
				int l = Random::random(1,100000) , r = Random::random(n-100000+1,n);
				int a = (Random::random(50) ? Random::random(l,r) : Random::random(1,n));
				int b = (Random::random(50) ? Random::random(l,r) : Random::random(1,n));
				ops.emplace_back(op{1,a,b,-1,-1});
				ops.emplace_back(op{2,-1,-1,l,r});
			}
		}
		else {	// 操作二長度足夠大(700,300000) 操作二之前必有多次操作一(9,499,4999)
			n = q = 500000;
			ops.reserve(q);
			
			int op2_len[] = {700,300000};
			int op1_num_before_op2[] = {7,497,4997};	// this number doesnt' include line 56,57
			
			int len = op2_len[kase&1] , num = op1_num_before_op2[(kase-3)/2];
			for(int t=0;t<q;) {
				int l = Random::random(1,n-len+1);
				int r = l + len - 1;
					
				ops.emplace_back(op{1,l,l+Random::random(1,100),-1,-1});
				ops.emplace_back(op{1,r,r-Random::random(1,100),-1,-1});
				for(int i=0;i<num;i++)
					ops.emplace_back(op{1,Random::random(l,r),Random::random(1,n),-1,-1});
				ops.emplace_back(op{2,-1,-1,l,r});
				
				t += num + 3;
			}
		}
		
		Output::output(path,n,q,ops);
	}
	return 0;
}

