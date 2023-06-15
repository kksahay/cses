#include<bits/stdc++.h>

/*
 * dp[i] = minimum number steps required to reach i from 0
 * dp[0] = 0
 * dp[i] = min(dp[i], dp[i - j] + 1) for all j digits of i
*/

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	const int inf = 1e9 + 5;
	vector<int> dp(n + 1, inf);
	dp[0] = 0;
	for(int i = 1; i <= n; ++i) {
		string s = to_string(i);
		for(char c: s) {
			dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
		}
	}
	cout << dp[n];
	return 0;
}
//11 > 10 > 9 > 0
