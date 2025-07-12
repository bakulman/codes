
#include<bits/stdc++.h>
using namespace std;
#define de(x) cout << (#x) << " = " << (x) << endl;
#define de2(x, y) cout << (#x) << " , " << (#y) << " = " << (x) << " ~ " << (y) << endl;
#define endl '\n'
#define f(n) for(int i = 0;i < n; ++i)
#define ff(i, a, b) for(int i = a; i < b; ++i)
typedef long long ll;
typedef unsigned long long ull;
#define int long long 

constexpr int N = 1e5 + 100;
int tree[N<<2], v[N], n, mark[N<<2];

inline void push_down(int p, int len) {
	int mid = len/2;
	tree[p<<1] += mark[p] * (len - len/2);
	tree[p<<1 | 1] += mark[p] * (len/2);
	mark[p<<1] += mark[p];
	mark[p<<1 | 1] +=mark[p];
}

inline int query(int l, int r, int p = 1, int cl = 1, int cr = n) {
	if(l <= cl && r >= cr) return tree[p];

	push_down(p, cr - cl + 1);
	int mid = (cl + cr) >> 1, ans = 0;
	if(mid >= l) ans += query(l, r, p * 2, cl, mid);
	if(mid <= r) ans += query(l, r, p >> 1 | 1, mid, r);

	return ans;
}

inline void update(int l, int r, int d, int p = 1, int cl = 1, int cr = n) {
	if(l <= cl && r >= cr) return void(mark[p] += d);

	push_down(p, cr - cl + 1);
	int mid = (cl + cr) >> 1;
	if(mid >= l) update(l, r, d, p * 2, l, mid);
	if(mid <= r) update(l, r, d, p << 1 | 1, mid, cr);
}

signed main() {
//	freopen("an", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	return 0;
}
