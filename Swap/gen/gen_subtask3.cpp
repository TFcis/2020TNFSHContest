// subtask 3 : n,q <= 5000
#include "mylib.hpp"

#define path "../tests/3"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int kase=1;kase<=3;kase++) {
		int n = -1 , q = -1;
		vector<op> ops;

		if(kase == 1) {		// random case
			n = q = 5000;
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
		else {
			n = q = 5000;
			ops.reserve(q);
			for(int t=0;t<q;) {
				int l = Random::random(1,n-4000+1);
				int r = l + 4000 - 1;

				int max_num = (kase&1) ? 1 : 50;
				int num = -1;
				if(q - t - 3 < max_num + 10)
					num = q - t - 3;
				else
					num = Random::random(1,max_num);

				ops.emplace_back(op{1,l,l+Random::random(1,50),-1,-1});
				ops.emplace_back(op{1,r,r-Random::random(1,50),-1,-1});
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

