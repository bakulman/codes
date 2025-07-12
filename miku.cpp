
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
	if(len <= 1) return;   //叶节点处理
	tree[p<<1] += mark[p] * (len - len/2);
	tree[p<<1 | 1] += mark[p] * (len/2);
	mark[p<<1] += mark[p];
	mark[p<<1 | 1] +=mark[p];
	mark[p] = 0;  //清除父节点
}


void build(int p = 1, int l = 1, int r = n) {
	if(l == r) return void(tree[p] = v[l]);

	int mid = (l + r) >> 1;

	build(p << 1 , l, mid);
	build(p << 1 | 1, mid + 1, r);
	tree[p] = tree[p << 1] + tree[p << 1 | 1];


} 
inline int query(int l, int r, int p = 1, int cl = 1, int cr = n) {
	if(l <= cl && r >= cr) return tree[p];

	push_down(p, cr - cl + 1);
	int mid = (cl + cr) >> 1, ans = 0;
	if(mid >= l) ans += query(l, r, p << 1, cl, mid);
	if(mid < r) ans += query(l, r, p << 1 | 1, mid + 1, cr);

	return ans;
}

inline void update(int l, int r, int d, int p = 1, int cl = 1, int cr = n) {
	if(l <= cl && r >= cr) {mark[p] += d, tree[p] += d * (cr - cl + 1);return;}  //更新标记，更新节点大小

	push_down(p, cr - cl + 1);
	int mid = (cl + cr) >> 1;
	if(mid >= l) update(l, r, d, p << 1, cl, mid);
	if(mid < r) update(l, r, d, p << 1 | 1, mid + 1, cr);
	tree[p] = tree[p<<1] + tree[p<<1 | 1];
}

signed main() {
//	freopen("an", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m;
	cin >> n >> m;
	for(int i = 1; i <= n;  ++i) cin >> v[i];

	build();

	while(m--) {
		int o, l, r, d;
		cin >> o >>l >> r;
		if(o == 1) cin >> d, update(l, r, d);
		else cout << query(l, r) << endl;
	}

	return 0;
}
