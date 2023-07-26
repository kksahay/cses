#include<bits/stdc++.h>

using namespace std;

/*
 * dp[i][2] = number of ways we can build tower of height i with blocks of width 1 or 2.
 * dp[i][1] = 4 * dp[i - 1][1] + dp[i - 1][2]
 * dp[i][2] = dp[i - 1][1] + 2 * dp[i - 1][2]
 * dp[1][1] = 1
 * dp[1][2] = 1
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	long long m = 1e9 + 7;
	vector<vector<long long>> dp(1000001, vector<long long>(2));
	dp[0][0] = 1;
	dp[0][1] = 1;
	for(int i = 1; i < 1000001; ++i) {
		dp[i][0] = (4 * dp[i - 1][0] + dp[i - 1][1]) % m;
		dp[i][1] = (dp[i - 1][0] + 2 * dp[i - 1][1]) % m;
	}
	while(t--) {
		int n;
		cin >> n;
		cout << (dp[n - 1][0] + dp[n - 1][1]) % m << '\n';
	}
	return 0;
}
 
