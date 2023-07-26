#include<bits/stdc++.h>

using namespace std;

/*
 * dp[i][j] = number of transformation required to transform string i into string j
 * dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1) => replace, remove, insert
 * dp[i][j] = i + j, if i = 0 or j = 0
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	int n = a.length();
	int m = b.length();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= m; ++j) {
			if(i == 0 || j == 0) {
				dp[i][j] = i + j;
				continue;
			}
			if(a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
			}
		}
	}
	cout << dp[n][m];
	
	return 0;
}
 
