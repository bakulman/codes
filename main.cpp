
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

const int N = 5000 + 100, M = 998244353;
int dp[N][N];

signed main() {
//	freopen("an", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	dp[0][0] = 1;

	for(int i = 1; i <= m; ++i) dp[0][i] = 0;

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			dp[i][j] = dp[i-1][j-1] + j * dp[i-1][j];
			dp[i][j] %= M;
			de2(i, j)de(dp[i][j])
		}
	}

	int ans = 1;
	for(int i = 1; i <= m; ++i) ans = ans * i % M;
	cout << dp[n][m] * ans % M;
	return 0;
}
