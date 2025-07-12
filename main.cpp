
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

const int N = 1e5 + 100;
int n, m, idx, root;

struct Node{
	int l, r, val, key, size, cnt;
}tr[N];

void pushup(int p) {
	tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}

int get_node(int key) {
	tr[++idx].key = key;
	tr[idx].val = rand();
	tr[idx].size = tr[idx].cnt = 1;
	return idx;
}

int INF = 1e8;
void build() {
	get_node(-INF), get_node(INF);
	root = 1, tr[root].l = 2;
	pushup(root);
}

void zig(int &p) {
	int q = tr[p].l;
	tr[p].l = tr[q].r;
	tr[q].r = p;
	p = q;
	pushup(tr[p].r), pushup(p);
}

void zag(int &p) {
	int q = tr[p].r;
	tr[p].r = tr[q].l;
	tr[q].l = p;
	p = q;
	pushup(tr[p].l), pushup(p);
}

void inser(int x, int &p = root) {
	if(!p) p = get_node(x);
	else if(tr[p].key == x) tr[p].cnt++;
	else if(tr[p].key < x) {
		inser(tr[p].r, x);
		if(tr[tr[p].r].val > tr[p].val)
			zag(p);
	}
	else if(tr[p].key > x) {
		inser(tr[p].l, x);
		if(tr[tr[p].l].val > tr[p].val)
			zig(p);
	}

	pushup(p);
}

void rm(int key, int &p = root) {
	if(!p) return;

	if(tr[p].key == key) {
		if(tr[p].cnt > 1) tr[p].cnt--;
		else if(tr[p].l || tr[p].r) {
			if(!tr[p].r || tr[tr[p].l].val > tr[tr[p].r].val) {
				zig(p);
				rm(key, tr[p].r);
			}
			else {
				zag(p);
				rm(key, tr[p].l);
			}
		}
		else p = 0;
	}
	else if(tr[p].key > key) rm(key, tr[p].l);
	else rm(key, tr[p].r); 

	pushup(p);
}

int get_rank_by_key(int key, int p = root) {
	if(!p) return 1;

	if(tr[p].key == key) return tr[tr[p].l].size + 1;
	else if(tr[p].key > key) return get_rank_by_key(key, tr[p].l);
	return tr[p].cnt + tr[tr[p].l].size + get_rank_by_key(key, tr[p].r);
}

int get_key_by_rank(int rank, int p = root) {
	if(!rank) return INF;

	if(rank <= tr[tr[p].l].size) return get_rank_by_key(rank, tr[p].l);
	if(rank <= tr[tr[p].l].size + tr[p].cnt) return tr[p].key;
	return get_key_by_rank(rank - tr[tr[p].l].size - tr[p].cnt, tr[p].r);
}

int get_prev(int key, int p = root) {
	if(!p) return -INF;
	if(tr[p].key >= key) return get_prev(tr[p].l, key);
	return max(tr[p].key, get_prev(tr[p].r, key));
}

int get_next(int key, int p = root) {
	if(!p) return INF;
	if(tr[p].key <= key) return get_next(key, tr[p].r);
	return min(tr[p].key, get_next(key, tr[p].l));
}

signed main() {
//	freopen("an", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	build();

	cin >> n;

	for(int i = 0;i < n; ++i) {
		int op, x;
		cin >> op >> x;

		if(op == 1) inser(x);
		else if(op == 2) rm(x);
		else if(op == 3) cout << get_rank_by_key(x) -1 << endl;
		else if(op == 4) cout << get_key_by_rank(x+1) << endl;
		else if(op == 5) cout << get_prev(x) << endl;
		else cout << get_next(x) << endl;
	}

	return 0;
}
