#include<bits/stdc++.h>

/*
 * dp[i][j] = Number of ways to form sum j using first i coins from n coins
 * dp[i][j] = sum(dp[i - c[j]][j]), 0<=j<=n and i >= j
 * dp[i][j] = 1 for all j = 0
*/

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	const int m = 1e9 + 7;
	int n, x;
	cin >> n >> x;
	vector<int> c(n + 1);
	for(int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	vector<vector<int>> dp(n + 1, vector<int> (x + 1, 0));
	for(int i = 1; i <= n; ++i) {
		dp[i][0] = 1;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= x; ++j) {
			dp[i][j] = dp[i - 1][j];
			if(j - c[i - 1] >= 0) {
				(dp[i][j] += dp[i][j - c[i - 1]]) %= m;
			}
		}
	}
	cout << dp[n][x];
	return 0;
}
