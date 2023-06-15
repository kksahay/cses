#include<bits/stdc++.h>

/*
 * dp[i][j] = number of ways to reach i, j
 * dp[0][0] = 0
 * dp[i][j] = dp[i - 1][j] + dp[i][j - 1] iff (i, j) != '*'
*/

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	char c;
	const int m = 1e9 + 7;
	vector<vector<int>> grid(n, vector<int> (n));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> c;
			grid[i][j] = (c == '.' ? 0 : -1);
		}
	}
	vector<vector<int>> dp(n, vector<int> (n));
	if(grid[0][0] != -1) {
		dp[0][0] = 1;
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(grid[i][j] == -1) {
				continue;
			}
			if(i > 0 && grid[i - 1][j] != -1) {
				(dp[i][j] += dp[i - 1][j]) %= m;
			}
			if(j > 0 && grid[i][j - 1] != -1) {
				(dp[i][j] += dp[i][j - 1]) %= m;
			}
		}
	}
	cout << dp[n - 1][n - 1];
	return 0;
}

