
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

const int N = 60;
char v[N][N];

int n, m, nx, ny;
void init() {
	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) 
		{
			cin >> v[i][j];
			if(v[i][j] == '*') nx = i, ny = j;
		}
	return;
}

int tx[8]{-1, -1,0, 1, 1, 1, 0, -1};
int ty[8]{0, 1, 1, 1, 0, -1, -1, -1};
int vs = 0;
int dx = 0, dy = 0;

int ddx, ddy;
bool is(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
void cu(int x, int y) {cout << "Crash!" << ' ' << x << ' ' << y << endl;}
void po() {
	if(vs == 0) {cout << nx << ' ' << ny << endl;dx = ddx, dy = ddy;}

	else if(ddx != dx && ddy != dy) {
		f(vs) {
			int nnx = nx + tx[ddx], nny = ny + ty[ddy];

			if(is(nnx, nny) && (v[nnx][ny] != '#' || v[nx][nny] != '#') && v[nnx][nny] != '#') {
				nx = nnx;ny = nny;
			}
			else {
				cu(nx, ny);	
				break;
			}
		}		
	}
	else{
		
		f(vs) {
			int nnx = nx + tx[ddx], nny = ny + ty[ddy];
			if(is(nnx, nny) && v[nnx][nny] != '#') {
				nx = nnx;ny = nny;
			}
			else {
				cu(nx, ny);
				break;
			}
		}	
	}

	dx = ddx;dy = ddy;
}

void sl(char ch) {
	ddx = dx;ddy = dy;
	if(ch == 'L') ddx = (dx + 8 - 1) % 8, dy = (ddy + 8 -1) % 8;
	else if(ch == 'R') ddx = (dx + 8 + 1)  % 8, ddy = (dy + 8 + 1) % 8;
	else  if(ch == 'U') vs++;
	else vs = (vs-1 > 0 ? vs -1 : 0);

	po();
}

signed main() {
	freopen("./an", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	init();
	int kk;
	cin >> kk;

	string s;
	cin >> s;
	for(auto c : s) sl(c);




	return 0;
}
